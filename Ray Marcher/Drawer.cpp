//#include<SDL.h>
//#include <Eigen/Dense>
//#include<algorithm>
//#include<vector>
//using namespace Eigen;
////
////bool LargerY(Vector2d p1, Vector2d p2){
////	return p1(1) > p2(1);
////}
//
//class Drawer 
//{
//public:
//
//	void DrawTriangle(std::vector<Vector2d> Points , SDL_Renderer *renderer, SDL_Window *window) {
//
//		//std::sort(Points.begin(),Points.end(), LargerY);
//		
//		for (size_t i = 0; i < Points[0](0) - Points[3](1); i++)
//		{
//			float Ycoord = (Points[0](1) - i);
//
//			float gradL1 = (Points[0](0) - Points[2](0)) / (Points[0](1) - Points[2](1));
//			float YinterceptL1 = Points[0](1) - gradL1* Points[0](0);
//
//			float Xcord1 = (Ycoord - YinterceptL1) / gradL1;
//		
//			if (Ycoord > Points[1](1))
//			{
//				float gradL2 = (Points[0](0) - Points[1](0)) / (Points[0](1) - Points[1](1));
//				float YinterceptL2 = Points[0](1) - gradL2* Points[0](0);
//				float Xcord2 = (Ycoord - YinterceptL2) / gradL2;
//
//				DrawLine(Vector2d(Xcord1,Ycoord), Vector2d(Xcord2, Ycoord),renderer);
//
//			}
//			else
//			{
//				float gradL3 = (Points[2](0) - Points[1](0)) / (Points[2](1) - Points[1](1));
//				float YinterceptL3 = Points[2](1) - gradL3* Points[2](0);
//				float Xcord3 = (Ycoord - YinterceptL3) / gradL3;
//				DrawLine(Vector2d(Xcord1, Ycoord), Vector2d(Xcord3, Ycoord), renderer);
//			}
//
//
//
//		}
//
//	}
//
//	void DrawLine(Vector2d p1 , Vector2d p2, SDL_Renderer *renderer)
//	{
//		for (size_t i = 0; i <  p2(0)  - p1(0)  ; i++)
//		{
//			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//			SDL_RenderDrawPoint(renderer, p2(0) + i, p2(1)); //Renders on middle of screen.			
//		}
//	}
//	
//
//};