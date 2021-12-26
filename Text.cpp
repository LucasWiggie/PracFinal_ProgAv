#include "Text.h"

void Text :: Render() {
	glPushMatrix();
	glColor3f(this->getColor().getRedComponent(), this->getColor().getGreenComponent(), this->getColor().getBlueComponent());
	glTranslatef(this->getCoordinates().getCoordinateX(), this->getCoordinates().getCoordinateY(), this->getCoordinates().getCoordinateZ());
	glRasterPos3d(0, 0, 0);
	for (char c : text)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	glPopMatrix();
}