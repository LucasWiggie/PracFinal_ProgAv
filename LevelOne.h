#pragma once
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Road.h"
#include "Border.h"
#include "Vehicle.h"
#include <vector>
#include <cstdlib>
#include <random>

class LevelOne : public Scene
{
private:
	Player* player; // jugador
	Road* road; // calzada
	Border* leftBorder; // acera de la izquierda
	Border* rightBorder; // acera de la derecha
	
	vector<float> boundaries; // Límites del escenario en el que el jugador puede moverse
	vector<Vehicle*> vehicles;
	int lanes[3];
	vector<Model*> vehicleModels;
	Vector3D vehicleSpeeds[6];
	Vector3D vehiclePositions[3];
	Color vehicleColors[6];

public:
	LevelOne() : player(nullptr), road(nullptr), leftBorder(nullptr), rightBorder(nullptr), Scene() {}

	void init();
	void update(const float& time);
	void processKeyPressed(unsigned char key, int px, int py);
	void vehicleRandomizer();
	void vehicleCheck();
};

