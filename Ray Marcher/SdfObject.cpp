
#include<vector>
//#include"Triangle.cpp"
#include"Material.cpp"

struct SdfObject
{
protected:

		float Size = 1;
		Material Mat;
		Vector3 Position = Vector3(0, 0, 0);
		
public:

		virtual float SDF(Vector3 & Point) = 0;

		Vector3  estimateNormal(Vector3 p, float EPSILON)
	{

		Vector3 Estiemate(SDF(Vector3(p.x + EPSILON, p.y, p.z)) - SDF(Vector3(p.x - EPSILON, p.y, p.z)),
			SDF(Vector3(p.x, p.y + EPSILON, p.z)) - SDF(Vector3(p.x, p.y - EPSILON, p.z)),
			SDF(Vector3(p.x, p.y, p.z + EPSILON)) - SDF(Vector3(p.x, p.y, p.z - EPSILON)));

		Estiemate.Normalize();

		return Estiemate;

	}

		void SetSize(float size)
		{
			Size = size;
		}

		void SetMat(Material MaterialIn)
		{
			Mat = MaterialIn;
		}
		
		Material GetMaterial()
		{
			return Mat;
		}
		
		Vector3 GetPosition()
		{
			return Position;
		}

		void SetPosition( Vector3 & NewPos )
		{
			Position = NewPos;
		}

		virtual ~SdfObject(){}

};