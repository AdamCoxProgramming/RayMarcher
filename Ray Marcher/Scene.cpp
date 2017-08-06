
#include<vector>
#include<algorithm>
#include"Camera.cpp"
#include"Time.cpp"
#include "CollisionInformation.cpp"

using namespace std;

struct Scene
{

public:

	Scene(int WindowWidth, int WindowHeight) : Cam(WindowWidth, WindowHeight)
	{

	}

	CollisionInfo SceneSDF(Vector3 & Point)
	{

		float Closest = 100000;
		float TempDist;

		SdfObject * ClosestObject = nullptr;

		for (size_t i = 0; i < Objects.size(); i++)
		{
			TempDist = Objects[i]->SDF(Point);
			if ( TempDist < Closest)
			{
				Closest = TempDist;
				ClosestObject = Objects[i];
			}
		}

		CollisionInfo Info( Closest, ClosestObject);
		
		return Info;
		
	}

	virtual void SceneTick() = 0;

	Vector3 LightPos = Vector3(0,0,0);

	Camera Cam;	

	Vector3 BackgroundColor = Vector3(0, 0, 0);

	virtual ~Scene()
	{
		for each (SdfObject* Object in Objects)
		{
			delete Object;
		}
	}

private:

	vector<SdfObject*> Objects;

protected:

	void AddToScene(SdfObject * Object)
	{
		Objects.push_back(Object);
	}

};