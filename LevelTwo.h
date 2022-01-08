#pragma once
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Road.h"
#include "Border.h"
#include "Vehicle.h"
#include "Text.h"
#include <vector>
#include <cstdlib>
#include <random>

class LevelTwo : public Scene
{
private:
	Player* player; // jugador
	Road* road; // calzada
	Border* leftBorder; // acera de la izquierda
	Border* rightBorder; // acera de la derecha
	Text* meters;
	int mCount;

	vector<float> boundaries; // Límites del escenario en el que el jugador puede moverse
	vector<Vehicle*> vehicles;
	vector<Model*> vehicleModels;
	Vector3D vehicleSpeed;
	Vector3D vehiclePositions[5];
	Color vehicleColors[6];

public:
	LevelTwo() : player(nullptr), road(nullptr), leftBorder(nullptr), rightBorder(nullptr), meters(nullptr), mCount(0), Scene() {}

	void init();
	void update(const float& time);
	void processKeyPressed(unsigned char key, int px, int py);
	void vehicleRandomizer();
	void vehicleCheck();
	void updateMeters(float time);
	void resetPositions();
};

