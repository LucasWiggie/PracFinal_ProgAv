#include "Game.h"

#include <iostream>
using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	activeScene->processKeyPressed(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del mouse: " << x << "," << y << endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Clic: " << button << endl;
}

void Game::Init() {
	// ESCENAS DEL JUEGO
	// Inicializamos la escena
	InitScreen* titleScreen = new InitScreen();
	titleScreen->init();
	IntroLevelOne* introLevelOne = new IntroLevelOne();
	introLevelOne->init();
	LevelOne* firstLevel = new LevelOne();
	firstLevel->init();
	IntroLevelTwo* introLevelTwo = new IntroLevelTwo();
	introLevelTwo->init();
	LevelTwo* secondLevel = new LevelTwo();
	secondLevel->init();
	VictoryScreen* victoryScreen = new VictoryScreen();
	victoryScreen->init();
	GameOverScreen* gameOverScreen = new GameOverScreen();
	gameOverScreen->init();
	
	// AÑADIR LAS ESCENAS AL JUEGO
	this->scenes.push_back(titleScreen); // 0
	this->scenes.push_back(introLevelOne); // 1
	this->scenes.push_back(firstLevel); // 2
	this->scenes.push_back(introLevelTwo); // 3
	this->scenes.push_back(secondLevel); // 4
	this->scenes.push_back(victoryScreen); // 5
	this->scenes.push_back(gameOverScreen); // 6
	
	// ESCENA ACTIVA
	activeScene = titleScreen;
}

void Game::Render() {
	activeScene->Render();
}

void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD) {
		this->activeScene->update(TIME_INCREMENT);

		// Cambio de Escenas
		if (this->activeScene->getChangeScene() == 0) {
			this->activeScene = scenes[1];
		}
		else if (this->activeScene->getChangeScene() == 1) {
			this->activeScene = scenes[2];
		}
		else if (this->activeScene->getChangeScene() == 2) {
			this->activeScene = scenes[3];
		}
		else if (this->activeScene->getChangeScene() == 3) {
			this->activeScene = scenes[6];
		}
		else if (this->activeScene->getChangeScene() == 4) {
			this->activeScene = scenes[4];
		}
		else if (this->activeScene->getChangeScene() == 5) {
			this->activeScene = scenes[6];
		}
		else if (this->activeScene->getChangeScene() == 6) {
			this->activeScene = scenes[5];
		}
		else if (this->activeScene->getChangeScene() == 7) {
			this->activeScene = scenes[0];
		}

		for (Scene* s : scenes) {
			s->setChangeScene(-1);
		}

		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
}