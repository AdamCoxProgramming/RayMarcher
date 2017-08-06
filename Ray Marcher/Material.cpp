
#include "Vector3.cpp"

struct Material
{

public:

	Material() : Color(100, 100, 100) , Shininess(1)
	{		
	}		

	void SetColor(Vector3 NewColor)
	{
		Color = NewColor;
	}

	void SetShininess( float NewShininess)
	{
		Shininess = NewShininess;
	}

	Vector3 CalculatePixil(Vector3 & Normal, Vector3   Pos, Vector3  LightPos, Vector3 & CamPos)
	{

		Vector3 NormalizedLightDirection = (LightPos - Pos);
		NormalizedLightDirection.Normalize();

		float Brightness = Vector3::dot( Normal , NormalizedLightDirection );
		//Brightness = clamp(Brightness, 0.2, 1);

		if (Brightness < 0) Brightness *= -0.2;
		
		float specularIntensity = 1;

		
		Vector3 LightPosDif; 
		LightPosDif = LightPos - Pos;
		//LightPosDif = LightPosDif * -1;
		LightPosDif.Normalize();

		float lambertianTerm = Vector3::dot(Normal, LightPosDif);

		Vector3 PointPosDif( CamPos - Pos );
		PointPosDif.Normalize();

		Vector3 halfVector = (LightPosDif + PointPosDif);
		halfVector.Normalize();

		float specularFactor = Vector3::dot(halfVector, Normal);

		specularFactor = clamp(specularFactor, 0, 100);

		specularIntensity = pow(specularFactor, 14);

		
		Vector3 Combined = ( Color * (Brightness) + ( Vector3(150,150,150) * specularIntensity ) + (Color / 5.0f) ) ;

		Vector3 ClampedFinal = Vector3(clamp(Combined.x, 0, 255), clamp(Combined.y, 0, 255), clamp(Combined.z, 0, 255));

		return ClampedFinal;

	}

private:

	Vector3 Color;

	float Shininess;

	float clamp(float In, float Min, float Max)
	{
		if (In < Min)
		{
			return Min;
		}
		if (In > Max)
		{
			return Max;
		}
		return In;
	}

};