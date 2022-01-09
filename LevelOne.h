#pragma once
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Road.h"
#include "Border.h"
#include "Vehicle.h"
#include "Text.h"
#include "Level.h"
#include <vector>
#include <cstdlib>
#include <random>

class LevelOne : public Level
{
public:
	LevelOne() : Level() {}

	void init();
	void update(const float& time);
};

