#pragma once
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Road.h"
#include "Border.h"
#include "Vehicle.h"
#include "Level.h"
#include "Text.h"
#include <vector>
#include <cstdlib>
#include <random>

class LevelTwo : public Level
{
public:
	LevelTwo() : Level() {}

	void init();
	void update(const float& time);
};

