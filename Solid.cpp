#include "Solid.h"

void Solid::Update(const float& time) {
	
	this->setCoordinates(this->getCoordinates() + this->getSpeed() * time);
	this->setOrientation(this->getOrientation() + this->getOrientationSpeed() * time);
	
}