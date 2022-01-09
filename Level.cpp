#include "Level.h"

void Level::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

	if (key == 'w' || key == 'W') {
		if (player->getModel().getCoordinates().getCoordinateY() < boundaries[3]) {
			this->player->movementForward();
		}
	}
	else if (key == 's' || key == 'S') {
		if (player->getModel().getCoordinates().getCoordinateY() > boundaries[2]) {
			this->player->movementBack();
		}
	}
	else if (key == 'a' || key == 'A') {
		if (player->getModel().getCoordinates().getCoordinateX() > boundaries[0]) {
			this->player->movementLeft();
		}
	}
	else if (key == 'd' || key == 'D') {
		if (player->getModel().getCoordinates().getCoordinateX() < boundaries[1]) {
			this->player->movementRight();
		}
	}
}

void Level::vehicleRandomizer() {
	for (Vehicle* car : vehicles) {
		if (car->getModel().getCoordinates().getCoordinateY() >= 6.0) {
			if (car->getModel().getSpeed().getCoordinateY() == 0.0) {
				car->getModel().setSpeed(vehicleSpeed);
			}
		}
	}
}

void Level::vehicleCheck() {
	int i = 0;
	random_shuffle(vehicleColors.begin(), vehicleColors.end());
	random_shuffle(vehiclePositions.begin(), vehiclePositions.end());

	// Comprueba si el vehículo se ha salido del carril y en ese caso, lo vuelve a enviar a su posición inicial	con otro color distinto
	for (Vehicle* car : vehicles) {
		if (car->getModel().getCoordinates().getCoordinateY() <= -6.0) {
			car->getModel().setCoordinates(vehiclePositions[i]);
			car->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
			car->getModel().paintColor(vehicleColors[i]);
		}
		i++;
	}

	if (vehicles[0]->getModel().getCoordinates().getCoordinateY() == vehiclePositions[0].getCoordinateY() &&
		vehicles[1]->getModel().getCoordinates().getCoordinateY() == vehiclePositions[1].getCoordinateY() &&
		vehicles[2]->getModel().getCoordinates().getCoordinateY() == vehiclePositions[2].getCoordinateY()) {
		vehicleSpeed = vehicleSpeed + Vector3D(0.0, -0.003, 0.0);
	}
}

void Level::updateMeters(float time) {
	if ((int)time % 10 == 0) {
		this->mCount++;
		this->meters->setText(to_string(this->mCount) + " m");
	}
}

void Level::resetPositions() {
	random_shuffle(vehiclePositions.begin(), vehiclePositions.end());
	int i = 0;
	for (Vehicle* v : vehicles) {
		v->getModel().setCoordinates(vehiclePositions[i]);
		i++;
	}
	player->getModel().setCoordinates(Vector3D(0.0, -2.0, 0.0));
	vehicleSpeed = Vector3D(0.0, -0.038, 0.0);
	this->mCount = 0;
}