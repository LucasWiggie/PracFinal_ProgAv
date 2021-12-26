#include "Scene.h"
#include <iostream>

void Scene::addGameObject(Solid* ptr) {
	
	this->gameObjects.push_back(ptr);

}

void Scene::Render() {
	for (int i = 0; i < this->gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

