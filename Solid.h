#pragma once
#include "Vector3D.h"
#include "Color.h"

class Solid
{
private:
	Vector3D coordinates;
	Color color;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D speed;

public:
	Solid() : coordinates(), color(), orientation(), orientationSpeed(), speed() {}
	Solid(Vector3D coords, Color color, Vector3D orient, Vector3D orientSpeed, Vector3D newSpeed) : coordinates(coords), color(color), orientation(orient), orientationSpeed(orientSpeed), speed(newSpeed) {}

	inline Vector3D getCoordinates() const {
		return this->coordinates;
	}

	inline Color getColor() const {
		return this->color;
	}

	inline Vector3D getOrientation() const {
		return this->orientation;
	}

	inline Vector3D getOrientationSpeed() const {
		return this->orientationSpeed;
	}

	inline Vector3D getSpeed() const {
		return this->speed;
	}

	inline void setCoordinates(Vector3D newCoordinates) {
		this->coordinates.setCoordinateX(newCoordinates.getCoordinateX());
		this->coordinates.setCoordinateY(newCoordinates.getCoordinateY());
		this->coordinates.setCoordinateZ(newCoordinates.getCoordinateZ());
	}

	inline void setColor(Color newColor) {
		this->color.setRedComponent(newColor.getRedComponent());
		this->color.setGreenComponent(newColor.getGreenComponent());
		this->color.setBlueComponent(newColor.getBlueComponent());
	}

	inline void setOrientation(Vector3D newOrientation) {
		this->orientation.setCoordinateX(newOrientation.getCoordinateX());
		this->orientation.setCoordinateY(newOrientation.getCoordinateY());
		this->orientation.setCoordinateZ(newOrientation.getCoordinateZ());
	}

	inline void setOrientationSpeed(Vector3D newOrientationSpeed) {
		this->orientationSpeed.setCoordinateX(newOrientationSpeed.getCoordinateX());
		this->orientationSpeed.setCoordinateY(newOrientationSpeed.getCoordinateY());
		this->orientationSpeed.setCoordinateZ(newOrientationSpeed.getCoordinateZ());
	}

	inline void setSpeed(Vector3D newSpeed) {
		this->speed.setCoordinateX(newSpeed.getCoordinateX());
		this->speed.setCoordinateY(newSpeed.getCoordinateY());
		this->speed.setCoordinateZ(newSpeed.getCoordinateZ());
	}

	virtual void Render() = 0;
	virtual void Update(const float& time);
};

