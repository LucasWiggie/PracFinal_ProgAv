#pragma once
#include <vector>
#include "Solid.h"
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Torus.h"
#include "Cuboid.h"
#include "Cylinder.h"

using namespace std;

class Scene
{ 
private:
	vector<Solid*> gameObjects;

public:

	Scene() {}
	Scene(vector<Solid*> newGameObjects, Vector3D newBoundary) : gameObjects(newGameObjects) {};

	vector<Solid*> getGameObjects() {
		return this->gameObjects;
	}

	void addGameObject(Solid*);
	void Render();
	virtual void update(const float& time) = 0;
	virtual void init() = 0;
	virtual void processKeyPressed(unsigned char key, int px, int py) = 0;
};

