
#include "TestScene.cpp"

struct Scene2 : Scene
{

	SdfObject * TestCompound;
	SdfObject * Box1;
	SdfObject * Sphere1;	

	Scene2(int WindowWidth, int WindowHeight) : Scene(WindowWidth, WindowHeight)
	{
		BackgroundColor = Vector3(255, 255, 255);

		//Cam.Position.y = -4;
		Cam.Position.z = -20;

		LightPos = Vector3(20, 10, -20);
		
		Material TestMat; 
		Vector3 DarkColor(20, 20, 20);
		TestMat.SetColor(DarkColor);

		Box1 = new RoundedBoxObject;
		Box1->SetMat(TestMat);
		Box1->SetSize(2);		
		Sphere1 = new SphereObject;	
		Sphere1->SetMat(TestMat);
		Sphere1->SetSize(3);
		TestCompound = new CompoundObject;

		Vector3 CurrentPos = TestCompound->GetPosition();
		TestCompound->SetPosition(Vector3(CurrentPos.x, CurrentPos.y , CurrentPos.z));

		((CompoundObject*)TestCompound)->AddSDFObject(Sphere1, false);
		((CompoundObject*)TestCompound)->AddSDFObject(Box1, true);
		TestCompound->SetMat(TestMat);		
		AddToScene(TestCompound);

	}

	void SceneTick()
	{
		Vector3 CurrentPos = TestCompound->GetPosition();
		TestCompound->SetPosition(Vector3(CurrentPos.x, CurrentPos.y - Time::GetDeltaTime() , CurrentPos.z));
	}


};