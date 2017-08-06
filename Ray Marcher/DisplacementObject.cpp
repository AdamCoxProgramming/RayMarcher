
#include"CompoundObject.cpp"

struct DisplacementObject : SdfObject
{
	float SDF(Vector3 & Point)
	{

		Vector3 Dif = ((Position + Point).abs() - Vector3(Size, Size, Size));

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
				
		return NewVec.length() - 0.3f  + displacement(Point); ;

	}

	float displacement(Vector3 p)
	{

		float Displace = sin(2 * p.x)*sin(2 * p.y)*sin(2 * p.z);

		if(Displace > 0 )	return  0;
		else return Displace;

	}

	
};