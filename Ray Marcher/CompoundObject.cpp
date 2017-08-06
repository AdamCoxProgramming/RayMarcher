
#include"RoundedBoxObject.cpp"
#include<vector>

using namespace std;

struct CompoundObject : SdfObject
{
	vector< pair< SdfObject * , bool >> Objects;

	float SDF(Vector3 & Point)
	{
		float SDF_RESULT = 10000;
		for (size_t i = 0; i < Objects.size(); i++)
		{

			float CurrentObjectsSDF = Objects[i].first->SDF( Point + Position );

			if ( Objects[i].second == true ) // If Additive
			{

				if (CurrentObjectsSDF > SDF_RESULT)	SDF_RESULT = CurrentObjectsSDF;
				
			}
			else // If Subtractive 
			{
				if (CurrentObjectsSDF < SDF_RESULT)	SDF_RESULT = CurrentObjectsSDF;
			}
		}

		return  SDF_RESULT;
	}

	void AddSDFObject( SdfObject * Object , bool Additive )
	{

		Objects.push_back(pair< SdfObject * , bool >(Object, Additive));

	}

};