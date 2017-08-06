
#include<vector>
#include"Triangle.cpp"
#include<string>

#include <iostream>
#include <fstream>

using namespace std;

class MeshObject
{

	MeshObject()
	{
		
	}
	
	public:

	std::vector<Triangle> Triangles;

	MeshObject(std::string FileLocation) 
	{

		vector<Vertex> Vertexbits;
		vector<pair<int, int>> Facebits;

		LoadFromFile(FileLocation,Vertexbits, Facebits);

		FillInTrianlges( Vertexbits, Facebits);

		Position.x = 0;
		Position.y = 0;
		Position.z = 0;

	}
	
	void LoadFromFile(std::string FileLocation, vector<Vertex> & Vertexbits, vector<pair<int, int>> & Facebits)
	{
		fstream Stream(FileLocation);
		string Temp;
		
		while (getline(Stream, Temp))
		{
			Vertex TempVert;
			size_t pos = 0;
			size_t newpos;

			if (Temp[0] == 'v'  && Temp[1] != 'n')
			{
				int count = 0;

				while (pos != string::npos) {
					newpos = Temp.find_first_of(" ", pos);

					string Peice = Temp.substr(pos, newpos - pos);
					if (Peice != " " && Peice != "v" && Peice != "")
					{
						switch (count)
						{

						case 0:

							TempVert.Pos.x = (stof(Temp.substr(pos, newpos - pos)));
							break;

						case 1:

							TempVert.Pos.y = (stof(Temp.substr(pos, newpos - pos)));
							break;
						case 2:

							TempVert.Pos.z = (stof(Temp.substr(pos, newpos - pos)));
							break;
						}


						count++;

						if (count == 3)
						{
							Vertexbits.push_back(TempVert);
							count = 0;
						}

					}
				
					if (newpos > Temp.length()) break;
					pos = ++newpos;
				}
				
			}

			if (Temp[0] == 'f'  && Temp[1] != 'n')
			{
				int count = 0;
				pair<int, int> TempPair;
				while (pos != string::npos) 
				{
					newpos = Temp.find_first_of(" /", pos);
					
				
					string Peice = Temp.substr(pos, newpos - pos);
					if (Peice != " " && Peice != "f" && Peice != "" && Peice != "/")
						{
						if (count == 0)
						{
							TempPair.first = stoi(Temp.substr(pos, newpos - pos));
						}
						else
						{
							TempPair.second = stoi(Temp.substr(pos, newpos - pos));
							Facebits.push_back(TempPair);
						}										
							count++;
							if (count == 2)
							{
								count = 0;
							}
						}

					if (newpos > Temp.length()) break;
					pos = ++newpos;
				}

			}
			
			}
	

	}

	void FillInTrianlges(vector<Vertex> & Vertexbits, vector<pair<int, int>> & Facebits)
	{
		Triangle TempTri;

		int count = 0;

		for (size_t i = 0; i < Facebits.size(); i++)
		{

			switch (count)
			{
			
			case 0 :
				TempTri.V1 = Vertexbits[Facebits[i].first -1];
				break;
			case 1:
				TempTri.V2 = Vertexbits[Facebits[i].first -1];
				break;
			case 2:
				TempTri.V3 = Vertexbits[Facebits[i].first -1];
				break;
				
			}

			count++;

			if (count == 3)
			{
				Triangles.push_back(TempTri);
				count = 0;
			}
			
		}
	}

	Vector3 Position;

	Vector3 Rotation;

};