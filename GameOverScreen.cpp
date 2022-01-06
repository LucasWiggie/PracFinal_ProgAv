#include "GameOverScreen.h"

void GameOverScreen::init() {
	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// FONDO
	ModelLoader* backgroundLoader = new ModelLoader();
	backgroundLoader->setScale(10.0);
	backgroundLoader->loadModel("3D\\sideRoad.obj");
	Model* backgroundAuxPtr = new Model();
	*backgroundAuxPtr = backgroundLoader->getModel();
	this->background = backgroundAuxPtr;
	this->background->setCoordinates(Vector3D(0.0, 0.0, -3.0));
	this->background->setOrientation(Vector3D(90.0, 0.0, 0.0));
	this->background->paintColor(Color(0.0, 0.0, 0.0));

	// TITULO
	this->title = new Text();
	string newTitle = "GAME OVER";
	this->title->setText(newTitle);
	this->title->setCoordinates(Vector3D(0.2, 0.3, 6.0));
	this->title->setColor(Color(1.0, 1.0, 1.0));

	// VEHÍCULOS
	ModelLoader* vehicleLoader = new ModelLoader();
	vehicleLoader->setScale(1.1);

	vehicleLoader->loadModel("3D\\sportsCar.obj");
	Model* car = new Model();
	*car = vehicleLoader->getModel();
	vehicleLoader->clear();

	car->setCoordinates(Vector3D(-2.0, 0.0, 0.0));
	car->paintColor(Color(0.7, 0.0, 0.3));
	car->setOrientation(Vector3D(-90.0, -110.0, 60.0));


	// AÑADIR OBJETOS A LA ESCENA
	this->addGameObject(camera);
	this->addGameObject(background);
	this->addGameObject(car);
	this->addGameObject(title);
}

void GameOverScreen::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

}

void GameOverScreen::update(const float& time) {
	this->setChangeScene(-1);

	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
}