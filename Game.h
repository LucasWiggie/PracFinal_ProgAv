#pragma once

#include "Solid.h"
#include <vector>
#include "Scene.h"
#include "Camera.h"
#include "Model.h"
#include "ModelLoader.h"
#include <chrono>
#include "Text.h"
#include "Player.h"
#include "levelOne.h"

using namespace std::chrono;

class Game
{
private:
	const double TIME_INCREMENT = 0.8;
	const long UPDATE_PERIOD = 10;

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	Scene* activeScene;
	vector<Scene*> scenes;
		
public:
	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {};

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};

