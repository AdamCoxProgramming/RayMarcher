
//#include"MeshObject.cpp"
#include"DisplacementObject.cpp"
//#include"RoundedBoxObject.cpp"
class Camera
{
	public:

	Camera(int Width, int Height) : WindowWidth(Width), WindowHeight(Height) {};

	Vector3 Position;
	Vector3 Forward;
	Vector3 Up;

	Vector3 Rotation;

	float FeildOfVeiwX, FeildOfVeiwY;

	float Zfar = 1000, Znear = 1;

	const int WindowWidth;
	const int WindowHeight;

	 inline Vector3 & CalculateRayDirection( int &  PixilXpos, int & PixilYpos) const
	{

		float Xpoint = -(((WindowWidth / 2.f) - PixilXpos) / WindowWidth) * 10;
		float Ypoint = (((WindowHeight / 2.f) - PixilYpos) / WindowHeight) * 10 * (WindowHeight *1.0f / WindowWidth);

		return Vector3(-Xpoint, -Ypoint, 10);

	}

};


//vector<MeshObject> ConvertToProjectionSpace(vector<MeshObject>  Object, Camera Cam) {
//
//	for (size_t i = 0; i < Object.size(); i++)
//	{
//
//		Matrix WorldPosMat(4, 4);
//		WorldPosMat[0][0] = 1;
//		WorldPosMat[1][1] = 1;
//		WorldPosMat[2][2] = 1;
//		WorldPosMat[3][3] = 1;
//		WorldPosMat[0][3] = Object[i].Position.x;
//		WorldPosMat[1][3] = Object[i].Position.y;
//		WorldPosMat[2][3] = Object[i].Position.z;
//
//		cout << WorldPosMat << endl;
//
//		Matrix YRotationMat(4, 4);
//		YRotationMat[0][0] = cos(Object[i].Rotation.y);
//		YRotationMat[0][2] = sin(Object[i].Rotation.y);
//		YRotationMat[2][0] = -sin(Object[i].Rotation.y);
//		YRotationMat[2][2] = cos(Object[i].Rotation.y);
//		YRotationMat[1][1] = 1;
//		YRotationMat[3][3] = 1;
//
//		Matrix XRotationMat(4, 4);
//		YRotationMat[0][0] = 1;
//		YRotationMat[1][1] = cos(Object[i].Rotation.x);
//		YRotationMat[1][2] = -sin(Object[i].Rotation.x);
//		YRotationMat[2][1] = sin(Object[i].Rotation.x);
//		YRotationMat[2][2] = cos(Object[i].Rotation.x);
//
//		Matrix WorldTransform = WorldPosMat; // *YRotationMat * XRotationMat;
//
//		Matrix CameraPosMat(4, 4);
//		CameraPosMat[0][0] = 1;
//		CameraPosMat[1][1] = 1;
//		CameraPosMat[2][2] = 1;
//		CameraPosMat[3][3] = 1;
//		CameraPosMat[0][3] = -Cam.Position.x;
//		CameraPosMat[1][3] = -Cam.Position.y;
//		CameraPosMat[2][3] = -Cam.Position.z;
//
//		cout << CameraPosMat << endl;
//
//		Matrix CamYRotationMat(4, 4);
//		CamYRotationMat[0][0] = cos(Cam.Rotation.y);
//		CamYRotationMat[0][2] = sin(Cam.Rotation.y);
//		CamYRotationMat[2][0] = -sin(Cam.Rotation.y);
//		CamYRotationMat[2][2] = cos(Cam.Rotation.y);
//		CamYRotationMat[1][1] = 1;
//		CamYRotationMat[3][3] = 1;
//
//		Matrix CamXRotationMat(4, 4);
//		CamXRotationMat[0][0] = 1;
//		CamXRotationMat[1][1] = cos(Cam.Rotation.x);
//		CamXRotationMat[1][2] = -sin(Cam.Rotation.x);
//		CamXRotationMat[2][1] = sin(Cam.Rotation.x);
//		CamXRotationMat[2][2] = cos(Cam.Rotation.x);
//
//
//		cout << endl << CameraPosMat << endl;
//
//		cout << CamYRotationMat << endl;
//
//		cout << CamXRotationMat << endl;
//
//		Matrix WorldToView = CameraPosMat;// *CamYRotationMat * CamXRotationMat;
//
//										  //Matrix CamProjectionMat(4, 4);
//										  //CamXRotationMat[0][0] = atan(Cam.FeildOfVeiwX /2);
//										  //CamXRotationMat[1][1] = atan(Cam.FeildOfVeiwY / 2);
//										  //CamXRotationMat[2][2] = -(Cam.Zfar - Cam.Znear)/(Cam.Zfar +Cam.Znear);
//										  //CamXRotationMat[2][3] = - (2*(Cam.Zfar * Cam.Znear)) / (Cam.Zfar + Cam.Znear);
//										  //CamXRotationMat[3][2] = -1;
//
//		Matrix FinalMatrix = WorldToView * WorldTransform;
//
//		Matrix PosVec3Mat(4, 1);
//		PosVec3Mat[3][0] = 1;
//		for (size_t v = 0; v < Object[i].Triangles.size(); v++)
//		{
//			PosVec3Mat[0][0] = Object[i].Triangles[v].V1.Pos.x;
//			PosVec3Mat[1][0] = Object[i].Triangles[v].V1.Pos.y;
//			PosVec3Mat[2][0] = Object[i].Triangles[v].V1.Pos.z;
//
//
//			Matrix TranslatedMat(4, 1);
//			TranslatedMat = FinalMatrix* PosVec3Mat;
//
//			cout << Object[i].Triangles[v].V1.Pos.x << endl;
//			cout << Object[i].Triangles[v].V1.Pos.y << endl;
//			cout << Object[i].Triangles[v].V1.Pos.z << endl;
//
//			Object[i].Triangles[v].V1.Pos.x = TranslatedMat[0][0];
//			Object[i].Triangles[v].V1.Pos.y = TranslatedMat[1][0];
//			Object[i].Triangles[v].V1.Pos.z = TranslatedMat[2][0];
//
//
//			cout << Object[i].Triangles[v].V1.Pos.x << endl;
//			cout << Object[i].Triangles[v].V1.Pos.y << endl;
//			cout << Object[i].Triangles[v].V1.Pos.z << endl;
//
//			/////////////////////////////////////////////////////
//
//			PosVec3Mat[0][0] = Object[i].Triangles[v].V2.Pos.x;
//			PosVec3Mat[1][0] = Object[i].Triangles[v].V2.Pos.y;
//			PosVec3Mat[2][0] = Object[i].Triangles[v].V2.Pos.z;
//
//
//			TranslatedMat = FinalMatrix* PosVec3Mat;
//
//			cout << Object[i].Triangles[v].V2.Pos.x << endl;
//			cout << Object[i].Triangles[v].V2.Pos.y << endl;
//			cout << Object[i].Triangles[v].V2.Pos.z << endl;
//
//			Object[i].Triangles[v].V2.Pos.x = TranslatedMat[0][0];
//			Object[i].Triangles[v].V2.Pos.y = TranslatedMat[1][0];
//			Object[i].Triangles[v].V2.Pos.z = TranslatedMat[2][0];
//
//
//			cout << Object[i].Triangles[v].V3.Pos.x << endl;
//			cout << Object[i].Triangles[v].V3.Pos.y << endl;
//			cout << Object[i].Triangles[v].V3.Pos.z << endl;
//
//
//			/////////////////////////////////////////////////////
//
//			PosVec3Mat[0][0] = Object[i].Triangles[v].V3.Pos.x;
//			PosVec3Mat[1][0] = Object[i].Triangles[v].V3.Pos.y;
//			PosVec3Mat[2][0] = Object[i].Triangles[v].V3.Pos.z;
//
//
//			TranslatedMat = FinalMatrix* PosVec3Mat;
//
//			cout << Object[i].Triangles[v].V3.Pos.x << endl;
//			cout << Object[i].Triangles[v].V3.Pos.y << endl;
//			cout << Object[i].Triangles[v].V3.Pos.z << endl;
//
//			Object[i].Triangles[v].V3.Pos.x = TranslatedMat[0][0];
//			Object[i].Triangles[v].V3.Pos.y = TranslatedMat[1][0];
//			Object[i].Triangles[v].V3.Pos.z = TranslatedMat[2][0];
//
//
//			cout << Object[i].Triangles[v].V3.Pos.x << endl;
//			cout << Object[i].Triangles[v].V3.Pos.y << endl;
//			cout << Object[i].Triangles[v].V3.Pos.z << endl;
//
//		}
//
//	}
//	return Object;
//}
