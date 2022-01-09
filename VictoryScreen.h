#pragma once
#include "Scene.h"
#include "Solid.h"
#include "Text.h"
#include "Camera.h"
#include "Model.h"
#include "ModelLoader.h"
#include <string>
#include "Vector3D.h"
#include "Color.h"

class VictoryScreen : public Scene
{
public:
	VictoryScreen() : Scene() {};

	void init();
	void update(const float& time);
	void processKeyPressed(unsigned char key, int px, int py);
};

