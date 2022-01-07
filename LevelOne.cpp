#include "levelOne.h"

void LevelOne :: init() {

	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7.5);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// LOADER
	ModelLoader* playerLoader = new ModelLoader();
	playerLoader->setScale(0.45);
	ModelLoader* vehicleLoader = new ModelLoader();
	vehicleLoader->setScale(0.50);
	ModelLoader* roadLoader = new ModelLoader();
	roadLoader->setScale(5.5);
	ModelLoader* borderLoader = new ModelLoader();
	borderLoader->setScale(5.5);
	
	// CARRETERA
	this->road = new Road();
	roadLoader->loadModel("3D\\straightRoad.obj");
	Model* auxPtr1 = new Model();
	*auxPtr1 = roadLoader->getModel();
	road->setModel(auxPtr1);
	road->getModel().setCoordinates(Vector3D(0.0, 0.0, -2.0));
	road->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	road->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	road->getModel().paintColor(Color(0.0, 0.0, 0.0));

	// ACERAS
	this->leftBorder = new Border();
	borderLoader->loadModel("3D\\sideRoad.obj");
	Model* auxPtr2 = new Model();
	*auxPtr2 = borderLoader->getModel();
	leftBorder->setModel(auxPtr2);
	leftBorder->getModel().setCoordinates(Vector3D(8.0, 0.0, -1.8));
	leftBorder->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	leftBorder->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	leftBorder->getModel().paintColor(Color(0.1, 0.1, 0.1));
	borderLoader->clear();

	this->rightBorder = new Border();
	borderLoader->loadModel("3D\\sideRoad.obj");
	Model* auxPtr3 = new Model();
	*auxPtr3 = borderLoader->getModel();
	rightBorder->setModel(auxPtr3);
	rightBorder->getModel().setCoordinates(Vector3D(-8.0, 0.0, -1.8));
	rightBorder->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	rightBorder->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	rightBorder->getModel().paintColor(Color(0.1, 0.1, 0.1));


	// LÍMITES
	this->boundaries.push_back(-1.6);
	this->boundaries.push_back(1.6);
	this->boundaries.push_back(-3.2);
	this->boundaries.push_back(3.2);


	// VEHÍCULOS EN SENTIDO CONTRARIO
	// Vector de modelos obj
	vehicleLoader->loadModel("3D\\suvCar.obj");
	Model* modelAuxPtr1 = new Model();
	*modelAuxPtr1 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr1);
	vehicleLoader->clear();

	/*vehicleLoader->loadModel("3D\\taxiCar.obj");
	Model* modelAuxPtr2 = new Model();
	*modelAuxPtr2 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr2);
	vehicleLoader->clear();*/
	
	vehicleLoader->loadModel("3D\\normalCar1.obj");
	Model* modelAuxPtr3 = new Model();
	*modelAuxPtr3 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr3);
	vehicleLoader->clear();

	/*vehicleLoader->loadModel("3D\\normalCar2.obj");
	Model* modelAuxPtr4 = new Model();
	*modelAuxPtr4 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr4);
	vehicleLoader->clear();*/

	vehicleLoader->loadModel("3D\\sportsCar.obj");
	Model* modelAuxPtr5 = new Model();
	*modelAuxPtr5 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr5);
	vehicleLoader->clear();

	/*vehicleLoader->loadModel("3D\\sportsCar2.obj");
	Model* modelAuxPtr6 = new Model();
	*modelAuxPtr6 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr6);
	vehicleLoader->clear();*/

	// Vector de posibles VELOCIDADES en el eje Y
	vehicleSpeeds[0] = Vector3D(0.0, -0.03, 0.0);
	vehicleSpeeds[1] = Vector3D(0.0, -0.055, 0.0);
	vehicleSpeeds[2] = Vector3D(0.0, -0.070, 0.0);
	vehicleSpeeds[3] = Vector3D(0.0, -0.085, 0.0);
	
	// Vector de POSICIONES en el eje X
	vehiclePositions[0] = Vector3D(-1.4, 8.5, 0.0);
	vehiclePositions[1] = Vector3D(0.0, 6.0, 0.0);
	vehiclePositions[2] = Vector3D(1.4, 7.0, 0.0);

	// Carriles
	lanes[0] = 0;
	lanes[1] = 1;
	lanes[2] = 2;

	// Vector de COLORES de los vehículos
	/*
	1.0 0.0 0.0 red, duh
	0.0 1.0 0.0 green, duh
	0.0 0.0 1.0 blue, duh
	1.0 1.0 0.0 yellow
	1.0 0.0 1.0 purple
	0.0 1.0 1.0 cyan
	1.0 1.0 1.0 white

	1.0 0.5 0.0 orange
	0.5 1.0 0.0 greenish yellow
	…
	0.5 1.0 0.5 light green
	0.0 0.5 0.0 dark green
	*/
	vehicleColors[0] = Color(0.0, 0.2, 0.8);
	vehicleColors[1] = Color(0.8, 0.8, 0.0);
	vehicleColors[2] = Color(0.0, 0.8, 0.1);
	vehicleColors[3] = Color(0.8, 0.3, 0.0);
	vehicleColors[4] = Color(0.3, 0.8, 0.6);
	vehicleColors[5] = Color(0.9, 0.2, 0.0);

	random_shuffle(vehicleColors, vehicleColors + 6);

	// Añadimos objetos de la clase Vehicle vector vehicles<> y le asignamos a cada uno un modelo 3D aleatorio
	for (int i = 0; i < 3; i++) {
		vehicles.push_back(new Vehicle());
		Model* vehicleModelPtr = vehicleModels[i];
		vehicles[i]->setModel(vehicleModelPtr);
		vehicles[i]->getModel().setCoordinates(vehiclePositions[i]);

		// Lo colocamos en su posición inicial correspondiente
		vehicles[i]->getModel().setCoordinates(vehiclePositions[i]);
		vehicles[i]->setInitPos(vehiclePositions[i]);
		vehicles[i]->getModel().setOrientation(Vector3D(90.0, 0.0, 0.0));
		vehicles[i]->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));

		// Lo coloreamos de un color aleatorio
		vehicles[i]->getModel().paintColor(vehicleColors[i]);
	}
	

	// PLAYER
	this->player = new Player();
	playerLoader->loadModel("3D\\sportsCar.obj");
	Model* auxPtr4 = new Model();
	*auxPtr4 = playerLoader->getModel();
	player->setModel(auxPtr4);
	player->getModel().setCoordinates(Vector3D(0.0, -2.0, 0.0));
	player->getModel().setOrientation(Vector3D(90.0, 180.0, 0.0));
	player->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	player->getModel().paintColor(Color(0.7, 0.0, 0.3));


	// AÑADIR OBJETOS
	this->addGameObject(camera);
	this->addGameObject(this->leftBorder->getModelPtr());
	this->addGameObject(this->rightBorder->getModelPtr());
	this->addGameObject(this->road->getModelPtr());
	this->addGameObject(this->player->getModelPtr());
	for (int j = 0; j < vehicles.size(); j++) {
		this->addGameObject(this->vehicles[j]->getModelPtr());
	}

}

void LevelOne::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

	if (key == 'w') {
		if (player->getModel().getCoordinates().getCoordinateY() < boundaries[3]) {
			this->player->movementForward();
		}
	}
	else if (key == 's') {
		if (player->getModel().getCoordinates().getCoordinateY() > boundaries[2]) {
			this->player->movementBack();
		}
	}
	else if (key == 'a') {
		if (player->getModel().getCoordinates().getCoordinateX() > boundaries[0]) {
			this->player->movementLeft();
		}
	}
	else if (key == 'd') {
		if (player->getModel().getCoordinates().getCoordinateX() < boundaries[1]) {
			this->player->movementRight();
		}
	}
}

void LevelOne::vehicleCheck() {
	// Comprueba si el vehículo se ha salido del carril y en ese caso, lo vuelve a enviar a su posición inicial	con otro color distinto
	random_shuffle(vehicleColors, vehicleColors + 6);
	for (int i = 0; i < vehicles.size(); i++) {
		Color randColor = vehicleColors[i];

		if (vehicles[i]->getModel().getCoordinates().getCoordinateY() <= -6.0) {
			vehicles[i]->getModel().setCoordinates(vehicles[i]->getInitPos());
			vehicles[i]->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
			vehicles[i]->getModel().paintColor(randColor);
		}
	}
}

void LevelOne::vehicleRandomizer() {
	random_shuffle(lanes, lanes+3);
	int i = lanes[1];
	if (vehicles[i]->getModel().getCoordinates().getCoordinateY() >= 6.0) {
		if (vehicles[i]->getModel().getSpeed().getCoordinateY() == 0.0) {
			random_shuffle(vehicleSpeeds, vehicleSpeeds + 6);
			vehicles[i]->getModel().setSpeed(vehicleSpeeds[1]);
		}
	}
}

void LevelOne::resetPositions() {
	for (Vehicle* v : vehicles) {
		v->getModel().setCoordinates(v->getInitPos());
	}
	player->getModel().setCoordinates(Vector3D(0.0, -2.0, 0.0));
}

void LevelOne::update(const float& time) {

	vehicleCheck();
	vehicleRandomizer();
	
	// Colisiones
	for (Vehicle* v : vehicles) {
		// Si hay colision
		if (v->detectCollision(this->player->getModelPtr())) {
			std::cout << "COLISION DETECTADA: " << this->player->getModel().getCoordinates().getCoordinateY() << endl;			
			for (Vehicle* car : vehicles) {
				car->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
			}
			this->resetPositions();
			this->setChangeScene(3);
		}
	}

	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
}


