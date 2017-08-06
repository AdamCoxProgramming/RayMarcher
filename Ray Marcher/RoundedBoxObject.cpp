
#include"SphereObject.cpp"

struct RoundedBoxObject : SdfObject
{
	float SDF(Vector3 & Point)
	{
		
		Vector3 Dif = ( (Position +  Point  ) .abs()  - Vector3(Size, Size, Size));

		Vector3 NewVec = Dif;

		if (Dif.x < 0)
		{
			NewVec.x = 0;
		}
		if (Dif.y < 0)
		{
			NewVec.y = 0;
		}
		if (Dif.z < 0)
		{
			NewVec.z = 0;
		}

		return NewVec.length() - 0.3f;
		
	}
};