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
	LevelOne* firstLevel = new LevelOne();
	firstLevel->init();
	GameOverScreen* gameOverScreen = new GameOverScreen();
	gameOverScreen->init();
	
	// AÑADIR LAS ESCENAS AL JUEGO
	this->scenes.push_back(titleScreen);
	this->scenes.push_back(firstLevel);
	this->scenes.push_back(gameOverScreen);
	
	// ESCENA ACTIVA
	activeScene = firstLevel;
}

void Game::Render() {
	activeScene->Render();
}

void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD) {
		this->activeScene->update(TIME_INCREMENT);

		// Cambio de Escenas
		if (this->activeScene->getChangeScene() == 3) {
			this->activeScene = this->scenes[2];
		}
		else if (this->activeScene->getChangeScene() == 6) {
			this->activeScene = this->scenes[0];
		}
		else if (this->activeScene->getChangeScene() == 1) {
			this->activeScene = this->scenes[1];
		}

		for (Scene* s : scenes) {
			s->setChangeScene(-1);
		}

		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
}