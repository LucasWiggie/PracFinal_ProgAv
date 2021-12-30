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

class LevelOne : public Scene
{
private:
	Player* player; // jugador
	Road* road; // calzada
	Border* leftBorder; // acera de la izquierda
	Border* rightBorder; // acera de la derecha
	
	vector<float> boundaries; // Límites del escenario en el que el jugador puede moverse
	vector<Vehicle*> vehicles;
	vector<Model*> vehicleModels;
	vector<Vector3D> vehicleSpeeds;
	vector<Vector3D> vehiclePositions;
	vector<Color> vehicleColors;

public:
	LevelOne() : player(nullptr), road(nullptr), leftBorder(nullptr), rightBorder(nullptr), Scene() {}

	void init();
	void update(const float& time);
	void processKeyPressed(unsigned char key, int px, int py);
	void vehicleRandomizer();
};

