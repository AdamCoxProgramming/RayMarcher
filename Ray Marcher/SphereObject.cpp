
#include"SdfObject.cpp"

struct SphereObject : SdfObject
{
	
	float SDF(Vector3 & Point)
	{

		float DistanceToPoint = ((Position + Point).length()) - Size;

		return  DistanceToPoint;

	}

};