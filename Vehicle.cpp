#include "Vehicle.h"

void Vehicle::Render() {
	this->modelPtr->Render();
}

bool Vehicle::detectCollision(Model* p) {
	if ((p->getCoordinates().getCoordinateX() > (this->modelPtr->getCoordinates().getCoordinateX() + 0.8) || p->getCoordinates().getCoordinateX() < (this->modelPtr->getCoordinates().getCoordinateX() - 0.8)) ||
		(p->getCoordinates().getCoordinateY() > (this->modelPtr->getCoordinates().getCoordinateY() + 1.75) || p->getCoordinates().getCoordinateY() < (this->modelPtr->getCoordinates().getCoordinateY() - 1.75)))
	{
		return false;
	}
	else {
		return true;
	}
}