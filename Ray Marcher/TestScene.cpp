
#include "Scene.cpp"

struct TestScene : Scene
{
	SdfObject * Temp;
	SdfObject * Temp2;
	SdfObject * TestCompound;
	SdfObject * Temp3;
	SdfObject * Temp4;
	SdfObject * Temp5;

	const int InitialX = 4;

	TestScene(int WindowWidth, int WindowHeight ) : Scene(WindowWidth, WindowHeight)
	{

		BackgroundColor = Vector3(51, 255, 189);
		Cam.Position.y = -4;
		Cam.Position.z = -20;

		LightPos = Vector3(0, -10, -4);

		Material Grey; 

		Material Red; 
		Vector3 RedColor(255, 189, 51);
		Red.SetColor(RedColor);

		Material Blue;
		Vector3 BlueColor(51, 255, 87);
		Blue.SetColor(BlueColor);

		Temp = new RoundedBoxObject;

		Temp->SetPosition( Vector3(4,0,4) );

		Temp4 = new RoundedBoxObject;
		Temp4->SetMat(Blue);
		Temp4->SetPosition(Vector3(4, 4, 4));		
		AddToScene(Temp4);

		Temp5 = new RoundedBoxObject;
		Temp5->SetMat(Blue);
		Temp5->SetPosition(Vector3(-3, 4, 7));
		AddToScene(Temp5);

		Temp2 = new SphereObject;
		Temp2->SetPosition(Vector3(4, 2,4));
		Temp2->SetMat(Grey);

		Temp3 = new SphereObject;
		Temp3->SetPosition(Vector3(-4,2, 5));
		Temp3->SetMat(Red);
		AddToScene(Temp3);

		TestCompound = new CompoundObject;

		((CompoundObject*)TestCompound)->AddSDFObject(Temp2, false );
		((CompoundObject*)TestCompound)->AddSDFObject(Temp, true);
		TestCompound->SetMat(Grey);
		AddToScene(TestCompound);


	}

	void SceneTick()
	{
		LightPos.x += Time::GetDeltaTime();
		LightPos.y += Time::GetDeltaTime();
		LightPos.z -= Time::GetDeltaTime();

		float newXPos = InitialX + sin(Time::time() / 1000.0f);
		Vector3 CurrentPos = Temp2->GetPosition();
		Temp2->SetPosition(Vector3(newXPos, CurrentPos.y, CurrentPos.z));

		Vector3 CurrentPos2 = Temp4->GetPosition();
		Temp4->SetPosition(Vector3(CurrentPos2.x , CurrentPos2.y - Time::GetDeltaTime() / 3.0f, CurrentPos2.z)); 
	}

};