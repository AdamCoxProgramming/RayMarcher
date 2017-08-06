
#include "Scene2.cpp"

struct Scene3 : Scene
{

	SdfObject * TestCompound;
	SdfObject * Box1;
	SdfObject * Sphere1;

	Scene3(int WindowWidth, int WindowHeight) : Scene(WindowWidth, WindowHeight)
	{

		BackgroundColor = Vector3(255, 87, 51);
		
		Cam.Position.z = -20;

		LightPos = Vector3(20, 10, -20);

		Material TestMat; 
		Vector3 LightGrey(200, 200, 200);
		TestMat.SetColor(LightGrey);

		Box1 = new RoundedBoxObject;
		Box1->SetMat(TestMat);
		Box1->SetSize(2);
		Sphere1 = new SphereObject;
		Sphere1->SetMat(TestMat);
		Sphere1->SetSize(3);
		TestCompound = new CompoundObject;
	
		((CompoundObject*)TestCompound)->AddSDFObject(Sphere1, false);
		((CompoundObject*)TestCompound)->AddSDFObject(Box1, true);
		TestCompound->SetMat(TestMat);
		AddToScene(TestCompound);

	}

	void SceneTick()
	{
		Sphere1->SetSize( sin( Time::time()/1000.0f ) + 3  );
	}
	
};