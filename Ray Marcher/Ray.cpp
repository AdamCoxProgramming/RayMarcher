//
//#include"Vector3.cpp"
//
//
//Vector3 RayTriangleIntersection(Vector3   V1, Vector3  V2, Vector3   V3, Vector3  O, Vector3  D)
//{
//	float EPSILONnum = 0.05;
//
//	Vector3 TriEdge1, TriEdge2;  //Edge1, Edge2
//	Vector3 P, Q, T;
//	float det, inv_det, u, v;
//	float t;
//
//	//Find vectors for two edges sharing V1
//	TriEdge1 = V2 - V1;
//	TriEdge2 = V3 - V1;
//	//Begin calculating determinant - also used to calculate u parameter
//	P = Vector3::Vector3::cross(D, TriEdge2);
//	//if determinant is near zero, ray lies in plane of triangle or ray is parallel to plane of triangle
//	det = Vector3::Vector3::dot(TriEdge1, P);
//	//NOT CULLING
//	if (det > -EPSILONnum && det < EPSILONnum) return  Vector3(-1, -1, -1);
//	inv_det = 1.f / det;
//
//	//calculate distance from V1 to ray origin
//	T = O - V1;
//
//	//Calculate u parameter and test bound
//	u = Vector3::Vector3::dot(T, P) * inv_det;
//	//The intersection lies outside of the triangle
//	if (u < 0.f || u > 1.f) return Vector3(-1, -1, -1);
//
//	//Prepare to test v parameter
//	Q = Vector3::cross(T, TriEdge1);
//
//	//Calculate V parameter and test bound
//	v = Vector3::dot(D, Q) * inv_det;
//	//The intersection lies outside of the triangle
//	if (v < 0.f || u + v  > 1.f) return  Vector3(-1, -1, -1);
//
//	t = Vector3::dot(TriEdge2, Q) * inv_det;
//
//	if (t > EPSILONnum) { //ray intersection
//
//		return Vector3(1, 1, 1);
//	}
//
//	// No hit, no win
//	return  Vector3(-1, -1, -1);
//}
//
