#include "VictoryScreen.h"

void VictoryScreen::init() {
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
	background->paintColor(Color(0.04, 0.035, 0.0));

	// TITULO
	Text* title = new Text();
	string newTitle = "HAS DESPISTADO A LA POLICIA!";
	title->setText(newTitle);
	title->setCoordinates(Vector3D(-0.35, 0.4, 6.0));
	title->setColor(Color(0.0, 0.0, 0.0));

	// STORY
	Text* story = new Text();
	string newStory = "Juego realizado por Fabio Elias Rengifo Garcia y Lucas Rubio Lezana";
	story->setText(newStory);
	story->setCoordinates(Vector3D(-0.64, 0.3, 6.0));
	story->setColor(Color(0.0, 0.0, 0.0));

	// INFO
	Text* info = new Text();
	string newInfo = "PULSE 'E' PARA REGRESAR A LA PANTALLA DE INICIO";
	info->setText(newInfo);
	info->setCoordinates(Vector3D(-0.6, -0.4, 6.0));
	info->setColor(Color(0.0, 0.0, 0.0));

	// VEHÍCULOS
	ModelLoader* vehicleLoader = new ModelLoader();
	vehicleLoader->setScale(1.4);

	vehicleLoader->loadModel("3D\\sportsCar.obj");
	Model* car = new Model();
	*car = vehicleLoader->getModel();
	vehicleLoader->clear();

	car->setCoordinates(Vector3D(0.0, -0.3, 0.0));
	car->paintColor(Color(0.7, 0.0, 0.3));
	car->setOrientation(Vector3D(0.0, 0.0, 0.0));

	// ESTRELLA
	ModelLoader* starLoader = new ModelLoader();
	starLoader->setScale(0.8);

	starLoader->loadModel("3D\\starPrice.obj");
	Model* star = new Model();
	*star = starLoader->getModel();
	Model* star2 = new Model();
	*star2 = starLoader->getModel();	
	starLoader->clear();

	star->setCoordinates(Vector3D(-2.5, -0.4, 0.0));
	star->paintColor(Color(0.0, 0.0, 0.2));
	star->setOrientation(Vector3D(0.0, 0.0, 0.0));

	star2->setCoordinates(Vector3D(2.5, -0.4, 0.0));
	star2->paintColor(Color(0.0, 0.0, 0.2));
	star2->setOrientation(Vector3D(0.0, 0.0, 0.0));

	// AÑADIR OBJETOS A LA ESCENA
	this->addGameObject(camera);
	this->addGameObject(background);
	this->addGameObject(car);
	this->addGameObject(star);
	this->addGameObject(star2);
	this->addGameObject(title);
	this->addGameObject(story);
	this->addGameObject(info);
}

void VictoryScreen::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

	if (key == 'e') {
		this->setChangeScene(7);
	}
}

void VictoryScreen::update(const float& time) {
	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
}