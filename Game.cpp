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
	LevelOne* firstLevel = new LevelOne();
	firstLevel->init();

	// AÑADIR LAS ESCENAS AL JUEGO
	this->scenes.push_back(firstLevel);

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
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
}