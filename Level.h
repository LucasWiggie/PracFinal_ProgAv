#pragma once
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Road.h"
#include "Vehicle.h"
#include "Text.h"
#include <vector>
#include <cstdlib>
#include <random>

class Level : public Scene
{
protected:
	Player* player; // jugador
	Road* road; // calzada
	Road* leftBorder; // acera de la izquierda
	Road* rightBorder; // acera de la derecha
	Text* meters; // texto que muestra los metros
	int mCount; // contador de los metros recorridos

	vector<float> boundaries; // LÝmites del escenario en el que el jugador puede moverse
	vector<Vehicle*> vehicles; // vehÝculos de la escena
	vector<Model*> vehicleModels; // modelos obj de los vehÝculos de la escena
	Vector3D vehicleSpeed; // velocidad de los vehÝculos de la escena
	vector<Vector3D> vehiclePositions; // posibles posiciones de los vehÝculos
	vector<Color> vehicleColors; // posibles colores de los vehÝculos

public:
	Level() : player(nullptr), road(nullptr), leftBorder(nullptr), rightBorder(nullptr), meters(nullptr), mCount(0), Scene() {}

	virtual void init() = 0;
	virtual void update(const float& time) = 0;
	void processKeyPressed(unsigned char key, int px, int py);
	void vehicleRandomizer();
	void vehicleCheck();
	void updateMeters(float time);
	void resetPositions();
};

