#include "Camera.h"
#include <GL/glut.h>

void Camera::Render() {
	glTranslatef(-1 * this->getCoordinates().getCoordinateX(), -1 * this->getCoordinates().getCoordinateY(), -1 * this->getCoordinates().getCoordinateZ());
	glRotatef(this->getOrientation().getCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->getOrientation().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->getOrientation().getCoordinateZ(), 0.0, 0.0, 1.0);
}