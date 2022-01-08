#include "IntroLevelTwo.h"

void IntroLevelTwo::init() {
	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// FONDO
	ModelLoader* backgroundLoader = new ModelLoader();
	backgroundLoader->setScale(20.0);
	backgroundLoader->loadModel("3D\\sideRoad.obj");
	Model* background = new Model();
	*background = backgroundLoader->getModel();
	background->setCoordinates(Vector3D(0.0, 0.0, -3.0));
	background->setOrientation(Vector3D(90.0, 0.0, 0.0));
	background->paintColor(Color(0.01, 0.03, 0.0));

	// TITULO
	Text* title = new Text();
	string newTitle = "NIVEL 2";
	title->setText(newTitle);
	title->setCoordinates(Vector3D(-0.07, 0.4, 6.0));
	title->setColor(Color(0.0, 0.0, 0.0));

	// STORY
	Text* story = new Text();
	string newStory = "Has recorrido los 5 KM, pero la policia te sigue pisando las llantas";
	story->setText(newStory);
	story->setCoordinates(Vector3D(-0.65, 0.3, 6.0));
	story->setColor(Color(0.0, 0.0, 0.0));

	// STORY2
	Text* story2 = new Text();
	string newStory2 = "Intenta recorrer 5 KM mas y te libraras de ellos definitivamente";
	story2->setText(newStory2);
	story2->setCoordinates(Vector3D(-0.62, 0.2, 6.0));
	story2->setColor(Color(0.0, 0.0, 0.0));

	// INFO
	Text* info = new Text();
	string newInfo = "PULSE 'E' PARA JUGAR";
	info->setText(newInfo);
	info->setCoordinates(Vector3D(-0.25, -0.4, 6.0));
	info->setColor(Color(0.0, 0.0, 0.0));

	// VEHÍCULOS
	ModelLoader* vehicleLoader = new ModelLoader();
	vehicleLoader->setScale(1.4);

	vehicleLoader->loadModel("3D\\sportsCar.obj");
	Model* car = new Model();
	*car = vehicleLoader->getModel();
	vehicleLoader->clear();

	car->setCoordinates(Vector3D(0.17, -0.3, 0.0));
	car->paintColor(Color(0.7, 0.0, 0.3));
	car->setOrientation(Vector3D(0, -90.0, 0.0));


	// AÑADIR OBJETOS A LA ESCENA
	this->addGameObject(camera);
	this->addGameObject(background);
	this->addGameObject(car);
	this->addGameObject(title);
	this->addGameObject(story);
	this->addGameObject(story2);
	this->addGameObject(info);
}

void IntroLevelTwo::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

	if (key == 'e') {
		this->setChangeScene(4);
	}
}

void IntroLevelTwo::update(const float& time) {
	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
}