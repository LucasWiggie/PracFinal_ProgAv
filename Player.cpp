#include "Player.h"

void Player::Render() {
	this->modelPtr->Render();
}

void Player::movementRight() {
	this->getModel().setCoordinates(
		Vector3D(
			this->getModel().getCoordinates().getCoordinateX() + 0.1,
			this->getModel().getCoordinates().getCoordinateY(), 
			this->getModel().getCoordinates().getCoordinateZ()));
}

void Player::movementLeft() {
	this->getModel().setCoordinates(
		Vector3D(
			this->getModel().getCoordinates().getCoordinateX() - 0.1,
			this->getModel().getCoordinates().getCoordinateY(),
			this->getModel().getCoordinates().getCoordinateZ()));
}

void Player::movementForward() {
	this->getModel().setCoordinates(
		Vector3D(
			this->getModel().getCoordinates().getCoordinateX(),
			this->getModel().getCoordinates().getCoordinateY() + 0.1,
			this->getModel().getCoordinates().getCoordinateZ()));
}

void Player::movementBack() {
	this->getModel().setCoordinates(
		Vector3D(
			this->getModel().getCoordinates().getCoordinateX(),
			this->getModel().getCoordinates().getCoordinateY() - 0.1,
			this->getModel().getCoordinates().getCoordinateZ()));
}