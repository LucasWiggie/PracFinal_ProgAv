#include "Triangle.h"
#include <GL/glut.h>

void Triangle::Render() {

	glBegin(GL_TRIANGLES);

	//vértice 0
	glColor3f(getVertexColor0().getRedComponent(), getVertexColor0().getGreenComponent(), getVertexColor0().getBlueComponent());
	glNormal3f(getVertexNormal0().getCoordinateX(), getVertexNormal0().getCoordinateY(), getVertexNormal0().getCoordinateZ());
	glVertex3f(getVertex0().getCoordinateX(), getVertex0().getCoordinateY(), getVertex0().getCoordinateZ());
	

	//vértice 1
	glColor3f(getVertexColor1().getRedComponent(), getVertexColor1().getGreenComponent(), getVertexColor1().getBlueComponent());
	glNormal3f(getVertexNormal1().getCoordinateX(), getVertexNormal1().getCoordinateY(), getVertexNormal1().getCoordinateZ());
	glVertex3f(getVertex1().getCoordinateX(), getVertex1().getCoordinateY(), getVertex1().getCoordinateZ());

	//vértice 2
	glColor3f(getVertexColor2().getRedComponent(), getVertexColor2().getGreenComponent(), getVertexColor2().getBlueComponent());
	glNormal3f(getVertexNormal2().getCoordinateX(), getVertexNormal2().getCoordinateY(), getVertexNormal2().getCoordinateZ());
	glVertex3f(getVertex2().getCoordinateX(), getVertex2().getCoordinateY(), getVertex2().getCoordinateZ());

	glEnd();

}