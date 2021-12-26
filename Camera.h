#pragma once
#include "Solid.h"

class Camera : public Solid
{
public:
	Camera() : Solid() {}
	Camera(Vector3D coords, Color color, Vector3D orientation, Vector3D orientSpeed, Vector3D speed) : 
		Solid(coords, color, orientation, orientSpeed, speed) {}

	void Render();
};

