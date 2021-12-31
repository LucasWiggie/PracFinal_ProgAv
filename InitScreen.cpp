#include "InitScreen.h"

void InitScreen::init() {

	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// VEHÍCULOS
	ModelLoader* vehicleLoader = new ModelLoader();
	vehicleLoader->setScale(0.55);
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
	vehicleModels[0]->setOrientationSpeed(Vector3D(0.0, 0.05, 0.0));
	vehicleModels[0]->paintColor(Color(0.8, 0.8, 0.0));

	vehicleModels[1]->setCoordinates(Vector3D(3.0, 2.0, 0.0));
	vehicleModels[1]->setOrientation(Vector3D(-30.0, -20.0, 0.0));
	vehicleModels[1]->setOrientationSpeed(Vector3D(0.0, 0.0, 0.05));
	vehicleModels[1]->paintColor(Color(0.8, 0.0, 0.0));

	vehicleModels[2]->setCoordinates(Vector3D(0.0, 4.0, 0.0));
	vehicleModels[2]->setOrientation(Vector3D(30.0, 20.0, 0.0));
	vehicleModels[2]->setOrientationSpeed(Vector3D(0.0, 0.05, 0.0));
	vehicleModels[2]->paintColor(Color(0.0, 0.0, 0.8));

	// TÍTULO
	this->title = new Text();
	string newTitle = "COCHE101";
	this->title->setText(newTitle);
	this->title->setCoordinates(Vector3D(0.0, 0.0, 6.0));

	// AÑADIR OBJETOS
	this->addGameObject(camera);
	this->addGameObject(title);
	for (int i = 0; i < vehicleModels.size(); i++) {
		this->addGameObject(vehicleModels[i]);
	}
}

void InitScreen::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

}

void InitScreen::update(const float& time) {
	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
}
