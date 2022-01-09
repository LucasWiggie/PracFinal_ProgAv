#include "LevelTwo.h"

void LevelTwo::init() {

	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// CONTADOR DE KILOMETROS
	this->meters = new Text();
	string newMeters = to_string(mCount) + " m";
	this->meters->setText(newMeters);
	this->meters->setCoordinates(Vector3D(0.5, 0.5, 6.0));
	this->meters->setColor(Color(0.0, 0.0, 0.0));

	// CONTROLES
	Text* w = new Text();
	string newW = "[W] = Arriba";
	w->setText(newW);
	w->setCoordinates(Vector3D(-0.763, -0.2, 6.0));
	w->setColor(Color(0.0, 0.0, 0.0));

	Text* s = new Text();
	string newS = "[S] = Abajo";
	s->setText(newS);
	s->setCoordinates(Vector3D(-0.763, -0.3, 6.0));
	s->setColor(Color(0.0, 0.0, 0.0));

	Text* a = new Text();
	string newA = "[A] = Izquierda";
	a->setText(newA);
	a->setCoordinates(Vector3D(-0.763, -0.4, 6.0));
	a->setColor(Color(0.0, 0.0, 0.0));

	Text* d = new Text();
	string newD = "[D] = Derecha";
	d->setText(newD);
	d->setCoordinates(Vector3D(-0.763, -0.5, 6.0));
	d->setColor(Color(0.0, 0.0, 0.0));

	
	// LOADER
	ModelLoader* playerLoader = new ModelLoader();
	playerLoader->setScale(0.5);
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
	this->leftBorder = new Road();
	borderLoader->loadModel("3D\\sideRoad.obj");
	Model* auxPtr2 = new Model();
	*auxPtr2 = borderLoader->getModel();
	leftBorder->setModel(auxPtr2);
	leftBorder->getModel().setCoordinates(Vector3D(-8.5, 0.0, -1.8));
	leftBorder->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	leftBorder->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	leftBorder->getModel().paintColor(Color(0.1, 0.1, 0.1));
	borderLoader->clear();

	this->rightBorder = new Road();
	borderLoader->loadModel("3D\\sideRoad.obj");
	Model* auxPtr3 = new Model();
	*auxPtr3 = borderLoader->getModel();
	rightBorder->setModel(auxPtr3);
	rightBorder->getModel().setCoordinates(Vector3D(8.5, 0.0, -1.8));
	rightBorder->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	rightBorder->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	rightBorder->getModel().paintColor(Color(0.1, 0.1, 0.1));


	// LÍMITES
	this->boundaries.push_back(-2.2);
	this->boundaries.push_back(2.2);
	this->boundaries.push_back(-3.2);
	this->boundaries.push_back(3.2);


	// VEHÍCULOS EN SENTIDO CONTRARIO
	// Vector de modelos obj
	vehicleLoader->loadModel("3D\\normalCar1.obj");
	Model* modelAuxPtr1 = new Model();
	*modelAuxPtr1 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr1);
	vehicleLoader->clear();

	vehicleLoader->loadModel("3D\\normalCar1.obj");
	Model* modelAuxPtr3 = new Model();
	*modelAuxPtr3 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr3);
	vehicleLoader->clear();

	vehicleLoader->loadModel("3D\\normalCar1.obj");
	Model* modelAuxPtr5 = new Model();
	*modelAuxPtr5 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr5);
	vehicleLoader->clear();

	// VELOCIDAD de los vehiculos en sentido contrario
	vehicleSpeed = Vector3D(0.0, -0.038, 0.0);

	// Vector de POSICIONES en el eje X
	vehiclePositions.push_back(Vector3D(-1.8, 6.0, 0.0));
	vehiclePositions.push_back(Vector3D(-0.6, 6.0, 0.0));
	vehiclePositions.push_back(Vector3D(0.6, 6.0, 0.0));
	vehiclePositions.push_back(Vector3D(1.8, 6.0, 0.0));

	// Vector de COLORES de los vehículosz
	vehicleColors.push_back(Color(0.0, 0.2, 0.8));
	vehicleColors.push_back(Color(0.8, 0.8, 0.0));
	vehicleColors.push_back(Color(0.0, 0.8, 0.1));
	vehicleColors.push_back(Color(0.8, 0.3, 0.0));
	vehicleColors.push_back(Color(0.3, 0.8, 0.6));
	vehicleColors.push_back(Color(0.9, 0.2, 0.0));

	random_shuffle(vehicleColors.begin(), vehicleColors.end());
	random_shuffle(vehiclePositions.begin(), vehiclePositions.end());

	// Añadimos objetos de la clase Vehicle vector vehicles<> y le asignamos a cada uno un modelo 3D aleatorio
	for (int i = 0; i < 3; i++) {
		vehicles.push_back(new Vehicle());
		Model* vehicleModelPtr = vehicleModels[i];
		vehicles[i]->setModel(vehicleModelPtr);
		vehicles[i]->getModel().setCoordinates(vehiclePositions[i]);

		// Lo colocamos en su posición inicial correspondiente
		vehicles[i]->getModel().setCoordinates(vehiclePositions[i]);
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
	this->addGameObject(this->meters);
	this->addGameObject(w);
	this->addGameObject(s);
	this->addGameObject(a);
	this->addGameObject(d);
	this->addGameObject(this->leftBorder->getModelPtr());
	this->addGameObject(this->rightBorder->getModelPtr());
	this->addGameObject(this->road->getModelPtr());
	this->addGameObject(this->player->getModelPtr());
	for (int j = 0; j < vehicles.size(); j++) {
		this->addGameObject(this->vehicles[j]->getModelPtr());
	}

}

void LevelTwo::update(const float& time) {

	vehicleCheck();
	vehicleRandomizer();
	updateMeters(time);

	// Colisiones
	for (Vehicle* v : vehicles) {
		// Si hay colision
		if (v->detectCollision(this->player->getModelPtr())) {
			std::cout << "COLISION DETECTADA: " << this->player->getModel().getCoordinates().getCoordinateY() << endl;
			for (Vehicle* car : vehicles) {
				car->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
			}
			this->resetPositions();
			this->setChangeScene(5);
		}
	}

	// Victoria
	if (this->mCount >= 5000) {
		this->setChangeScene(6);
		this->resetPositions();
	}

	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
}