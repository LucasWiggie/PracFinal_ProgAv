#include "InitScreen.h"

void InitScreen::init() {

	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// VEHÍCULOS
	ModelLoader* vehicleLoader = new ModelLoader();
	vehicleLoader->setScale(0.9);
	vector<Model*> vehicleModels;
	
	vehicleLoader->loadModel("3D\\normalCar1.obj");
	Model* modelAuxPtr3 = new Model();
	*modelAuxPtr3 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr3);
	vehicleLoader->clear();

	vehicleLoader->loadModel("3D\\normalCar2.obj");
	Model* modelAuxPtr4 = new Model();
	*modelAuxPtr4 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr4);
	vehicleLoader->clear();

	vehicleLoader->loadModel("3D\\sportsCar.obj");
	Model* modelAuxPtr5 = new Model();
	*modelAuxPtr5 = vehicleLoader->getModel();
	vehicleModels.push_back(modelAuxPtr5);
	vehicleLoader->clear();

	vehicleModels[0]->setCoordinates(Vector3D(-2.0, -2.0, 0.0));
	vehicleModels[0]->setOrientation(Vector3D(30.0, 20.0, 0.0));
	vehicleModels[0]->setOrientationSpeed(Vector3D(0.0, 0.2, 0.0));
	vehicleModels[0]->paintColor(Color(0.8, 0.8, 0.0));

	vehicleModels[1]->setCoordinates(Vector3D(3.0, 1.0, 0.0));
	vehicleModels[1]->setOrientation(Vector3D(-30.0, -20.0, 0.0));
	vehicleModels[1]->setOrientationSpeed(Vector3D(0.0, 0.2, 0.05));
	vehicleModels[1]->paintColor(Color(0.8, 0.0, 0.0));

	vehicleModels[2]->setCoordinates(Vector3D(-2.0, 2.5, 0.0));
	vehicleModels[2]->setOrientation(Vector3D(30.0, 20.0, 0.0));
	vehicleModels[2]->setOrientationSpeed(Vector3D(0.0, -0.2, -0.2));
	vehicleModels[2]->paintColor(Color(0.0, 0.0, 0.8));

	// TEXTO
	Text* title = new Text();
	string newTitle = "COCHE101";
	title->setText(newTitle);
	title->setCoordinates(Vector3D(-0.1, 0.0, 6.0));
	title->setColor(Color(1.0, 1.0, 1.0));

	Text* author1 = new Text();
	string newAuthor1 = "Fabio Elias Rengifo Garcia";
	author1->setText(newAuthor1);
	author1->setCoordinates(Vector3D(0.2, -0.15, 6.0));
	author1->setColor(Color(1.0, 1.0, 1.0));

	Text* author2 = new Text();
	string newAuthor2 = "Lucas Rubio Lezana";
	author2->setText(newAuthor2);
	author2->setCoordinates(Vector3D(0.2, -0.21, 6.0));
	author2->setColor(Color(1.0, 1.0, 1.0));

	Text* info = new Text();
	string newInfo = "PULSE 'E' PARA JUGAR";
	info->setText(newInfo);
	info->setCoordinates(Vector3D(0.2, -0.40, 6.0));
	info->setColor(Color(1.0, 1.0, 1.0));

	// FONDO
	ModelLoader* backgroundLoader = new ModelLoader();
	backgroundLoader->setScale(10.0);
	backgroundLoader->loadModel("3D\\sideRoad.obj");
	Model* background = new Model();
	*background = backgroundLoader->getModel();
	background->setCoordinates(Vector3D(0.0, 0.0, -3.0));
	background->setOrientation(Vector3D(90.0, 0.0, 0.0));
	background->paintColor(Color(0.0, 0.0, 0.0));

	// AÑADIR OBJETOS
	this->addGameObject(camera);
	this->addGameObject(title);
	this->addGameObject(author1);
	this->addGameObject(author2);
	this->addGameObject(info);
	this->addGameObject(background);
	for (int i = 0; i < vehicleModels.size(); i++) {
		this->addGameObject(vehicleModels[i]);
	}
}

void InitScreen::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

	if (key == 'e') {
		this->setChangeScene(0);
	}
}

void InitScreen::update(const float& time) {

	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
}
