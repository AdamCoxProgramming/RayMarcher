
class SdfObject;

struct CollisionInfo{

	CollisionInfo() :DistanceToObject(0){}

	CollisionInfo(float DistanceToObject , SdfObject * Object): DistanceToObject(DistanceToObject) , ObjectHit(Object){}

	float DistanceToObject;
	SdfObject * ObjectHit;

};