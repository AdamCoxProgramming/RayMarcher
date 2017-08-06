#include<algorithm>
#include "Scene4.cpp"

float Time::last = 0;
float Time::deltaTime = 0;

const int WindowWidth = 300;
const int WindowHeight = 300;
const int MAX_MARCHING_STEPS = 100 ;
const int MIN_DIST = 0.0;
const int MAX_DIST = 500.0;
const float EPSILON = 0.01;
const float CamMoveSpeed = 5;

vector<Scene*> Scenes;
int SceneIndex = 0;

CollisionInfo shortestDistanceToSurface(Vector3 & CameraPos, Vector3  & marchingDirection,float start , float MaximumDistance, Scene & CurrScene ) {

	 float depth = start;
	 CollisionInfo HitInfo , NoCollision;
	 Vector3 PhotonPos;

	 for (int i = 0; i < MAX_MARCHING_STEPS; i++) {

		 PhotonPos = CameraPos + (marchingDirection * depth);
		 HitInfo = CurrScene.SceneSDF(PhotonPos);

		 bool Collision = HitInfo.DistanceToObject < EPSILON;

		 if (Collision)
		 {
			 HitInfo.DistanceToObject = depth;
			 return HitInfo;
		 }

		 depth += HitInfo.DistanceToObject;

		 bool GoneFurtherThanLimit = depth >= MaximumDistance;

		 if (GoneFurtherThanLimit)
		 {
			 return NoCollision;
		 }
	
	 }

	 return NoCollision;
 }
 
 void DrawPixel(SDL_Renderer* renderer, const Vector3 & Color, int Xpos, int YPos)
 {
	 SDL_SetRenderDrawColor(renderer, Color.x, Color.y, Color.z, 255);
	 SDL_RenderDrawPoint(renderer, Xpos, YPos);
 }

 void Render( SDL_Renderer* renderer, Scene & CurrScene)
{
	Vector3 Direction, Normal, HitPos , DrawColor;
	int PixelPosX, PixelPosY;	 // Varibles for use in the loop
	CollisionInfo HitInfo;

	int NumberOfPixels = WindowWidth * WindowHeight;

	for (size_t PixelNum = 0; PixelNum < NumberOfPixels; PixelNum++)
	{		
		PixelPosX = PixelNum % WindowWidth;
		PixelPosY = PixelNum / WindowWidth;

		Direction = CurrScene.Cam.CalculateRayDirection(PixelPosX, PixelPosY);
		Direction.Normalize();
		
		HitInfo = shortestDistanceToSurface(CurrScene.Cam.Position ,Direction ,	MIN_DIST , MAX_DIST , CurrScene );
		float DistanceToObject = HitInfo.DistanceToObject;

		bool CollidedWithObject = DistanceToObject <MAX_DIST && DistanceToObject > MIN_DIST && HitInfo.ObjectHit != nullptr;

			if (CollidedWithObject)
			{

				HitPos = CurrScene.Cam.Position + (Direction * DistanceToObject);

				Normal = HitInfo.ObjectHit->estimateNormal(HitPos, EPSILON);

				DrawColor = HitInfo.ObjectHit->GetMaterial().CalculatePixil( Normal , HitPos , CurrScene.LightPos , CurrScene.Cam.Position );

				DrawPixel(renderer, DrawColor, PixelPosX, PixelPosY); //  if there is a collision draw the object

			} 
			else {			
				DrawPixel(renderer, CurrScene.BackgroundColor, PixelPosX, PixelPosY); //  if no collision draw background color
			}

	}

	SDL_RenderPresent(renderer);

}

 void Update(SDL_Renderer* renderer, Scene & Scene)
 {

	 Time::Update();

	 Scene.SceneTick();

	 Render(renderer, Scene);

 }

 SDL_Renderer * InitilizeSDLRenderer()
 {
	 SDL_Init(SDL_INIT_EVERYTHING);
	 SDL_Window *window;
	 SDL_Renderer *Renderer;
	 SDL_CreateWindowAndRenderer(WindowWidth, WindowHeight, 0, &window, &Renderer);
	 return Renderer;
 }

 void CreateScenes()
 {
	 Scene* SceneThree = new Scene3(WindowWidth, WindowHeight);
	 Scenes.push_back(SceneThree);

	 Scene* SceneFour = new Scene4(WindowWidth, WindowHeight);
	 Scenes.push_back(SceneFour);

	 Scene* SceneTwo = new Scene2(WindowWidth, WindowHeight);
	 Scenes.push_back(SceneTwo);

	 Scene* test = new TestScene(WindowWidth, WindowHeight);
	 Scenes.push_back(test);
 }
 
 void ProccessInput(const Uint8 * state , bool & Escape)
 {

	 if (state[SDL_SCANCODE_RETURN]) {
		 SceneIndex++;
		 SceneIndex %= Scenes.size();
	 }

	 if (state[SDL_SCANCODE_ESCAPE]) Escape = true;

	 if (state[SDL_SCANCODE_RIGHT]) Scenes[SceneIndex]->Cam.Position.x -= Time::GetDeltaTime() * CamMoveSpeed;
	 if (state[SDL_SCANCODE_LEFT]) Scenes[SceneIndex]->Cam.Position.x += Time::GetDeltaTime()  * CamMoveSpeed;
	 if (state[SDL_SCANCODE_UP]) Scenes[SceneIndex]->Cam.Position.z += Time::GetDeltaTime()  * CamMoveSpeed;
	 if (state[SDL_SCANCODE_DOWN]) Scenes[SceneIndex]->Cam.Position.z -= Time::GetDeltaTime()  * CamMoveSpeed;

 }
 
 int main(int argc, char* argv[]) {
	 	
	SDL_Renderer * Renderer = InitilizeSDLRenderer();

	CreateScenes();
	
	bool Escape = false;
	while( !Escape )
	{
		SDL_PumpEvents();
		const Uint8 *state = SDL_GetKeyboardState(NULL);		

		ProccessInput( state , Escape );

		Update(Renderer, *Scenes[ SceneIndex ]);
	}

	for (size_t i = 0; i < Scenes.size(); i++)
	{
		delete Scenes[i];
	}

	return 0;

}

