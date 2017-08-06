
#include "Scene3.cpp"

struct Scene4 : Scene
{
	SdfObject * DisplacementObj;
	
	Scene4(int WindowWidth, int WindowHeight) : Scene(WindowWidth, WindowHeight)
	{

		BackgroundColor = Vector3(51, 255, 189);

		Cam.Position.z = -20;

		LightPos = Vector3(20, 10, -20);

		Material TestMat;
		Vector3 LightGrey(200, 200, 200);
		TestMat.SetColor(LightGrey);

		DisplacementObj = new DisplacementObject;
		DisplacementObj->SetMat(TestMat);
		DisplacementObj->SetSize(2);

		AddToScene(DisplacementObj);
		
	}

	void SceneTick()
	{	
	}

};