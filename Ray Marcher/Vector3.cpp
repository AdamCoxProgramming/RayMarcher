
#include<numeric>
#include <math.h> 

struct Vector3
{
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(float  X, float  Y, float Z): x(X), y(Y), z(Z)
	{

	};

	Vector3 operator + (const Vector3 & other)
	{
		Vector3 Ret;
		Ret.x = x + other.x;
		Ret.y = y + other.y;
		Ret.z = z + other.z;

		return  Ret;

	}

	Vector3 operator - (const Vector3 & other)
	{

		Vector3 Ret;
		Ret.x = x - other.x;
		Ret.y = y - other.y;
		Ret.z = z - other.z;

		return  Ret;

	}

	Vector3 operator * (const Vector3 & other)
	{
		Vector3 Ret;
		Ret.x = x * other.x;
		Ret.y = y * other.y;
		Ret.z = z *other.z;

		return  Ret;

	}

	Vector3 operator * (const float & other)
	{
		Vector3 Ret;
		Ret.x = x * other;
		Ret.y = y * other;
		Ret.z = z *other;

		return  Ret;

	}

	Vector3 operator / (const float & other)
	{
		Vector3 Ret;
		Ret.x = x / other;
		Ret.y = y / other;
		Ret.z = z / other;

		return  Ret;

	}

	Vector3 operator / (const Vector3 & other)
	{
		Vector3 Ret;
		Ret.x = x / other.x;
		Ret.y = y / other.y;
		Ret.z = z / other.z;

		return  Ret;

	}

	bool operator == (const Vector3 & other)
	{
		if (x == other.x && y == other.y && z == other.z )
		{
			return true;
		}
		return false;
	}

	bool operator != (const Vector3 & other)
	{
		if (x == other.x && y == other.y && z == other.z)
		{
			return false;
		}
		return true;
	}

	static float length(Vector3 & In)
	{
		return (sqrtf( In.x*In.x + In.y*In.y + In.z*In.z));
	}

	float length()
	{
		return (sqrtf(x*x + y*y + z*z));
	}

	static float dot(Vector3 & vec1, Vector3 & vec2)
	{

		Vector3 Ret;

		double a[] = { vec1.x, vec1.y, vec1.z};
		double b[] = { vec2.x, vec2.y, vec2.z };
		
		float Result = std::inner_product(std::begin(a), std::end(a), std::begin(b), 0.0);

		return Result;

	}

	static Vector3 cross(Vector3 & vec1, Vector3 & vec2)
	{

		Vector3 Ret;

		Ret.x = (vec1.y*vec2.z) - (vec1.z*vec2.y);

		Ret.y = -((vec1.x*vec2.z) - (vec1.z*vec2.x));

		Ret.z = (vec1.x*vec2.y) - (vec1.y*vec2.x);

		return Ret;
	}
	
	void Normalize()
	{
		float Length = Vector3::length(*this);
		x = x / Length;
		y = y / Length;
		z = z / Length;
	}

	Vector3 abs( )
	{
		Vector3 ReturnTemp;
				
		if ( x > 0)
		{
			ReturnTemp.x = x;
		}
		else 
		{
			ReturnTemp.x = -1 * x;
		}

		if (y > 0)
		{
			ReturnTemp.y = y;
		}
		else
		{
			ReturnTemp.y = -1 * y;
		}

		if (z > 0)
		{
			ReturnTemp.z = z;
		}
		else
		{
			ReturnTemp.z = -1 * z;
		}

		return ReturnTemp;

	}

	public:
	float x, y, z;

};