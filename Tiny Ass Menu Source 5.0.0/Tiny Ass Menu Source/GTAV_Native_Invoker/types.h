/*Alexander Blade*/

#pragma once
typedef long long int ui64;
typedef void* Void;
typedef int Any;
typedef unsigned int uint;
typedef int Hash;
typedef int BOOL;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

typedef struct
{
	float x;
	float y;
	float z;
} Vector3;
Vector3 new_Vector3(float x, float y, float z)
{
	Vector3 coords;
	coords.x = x;
	coords.y = y;
	coords.z = z;
	return coords;
}
float GetVectorDistance(Vector3 left, Vector3 right)
{
	float x = (right.x - left.x);
	float y = (right.y - left.y);
	float z = (right.z - left.z);
	return (float)sqrt((x * x) + (y * y) + (z * z));
}

struct opd_s { int32_t sub; int32_t toc; };