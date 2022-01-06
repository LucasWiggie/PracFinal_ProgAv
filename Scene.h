#pragma once
#include <vector>
#include "Solid.h"

using namespace std;

class Scene
{ 
private:
	vector<Solid*> gameObjects;
	int changeScene;

public:

	Scene() : changeScene(-1) {};
	Scene(vector<Solid*> newGameObjects, Vector3D newBoundary) : gameObjects(newGameObjects) {};

	vector<Solid*> getGameObjects() {
		return this->gameObjects;
	}

	int getChangeScene(){
		return this->changeScene;
	}

	void setChangeScene(int n) {
		this->changeScene = n;
	}

	void addGameObject(Solid*);
	void Render();
	virtual void update(const float& time) = 0;
	virtual void init() = 0;
	virtual void processKeyPressed(unsigned char key, int px, int py) = 0;
};

