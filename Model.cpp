#include "Model.h"
#include <GL/glut.h>

void Model::addTriangle(Triangle triangle) {
	triangleList.push_back(triangle);
};

void Model::clear() {
	triangleList.clear();
};

void Model::paintColor(Color color) {
	
	for (Triangle& triangle : this->triangleList) {
		triangle.setVertexColor0(color);
		triangle.setVertexColor1(color);
		triangle.setVertexColor2(color);
	}
};

void Model::Render() {

	glPushMatrix();
	glTranslatef(this->getCoordinates().getCoordinateX(), this->getCoordinates().getCoordinateY(), this->getCoordinates().getCoordinateZ());
	glColor3f(this->getColor().getRedComponent(), this->getColor().getGreenComponent(), this->getColor().getBlueComponent());
	glRotatef(this->getOrientation().getCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->getOrientation().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->getOrientation().getCoordinateZ(), 0.0, 0.0, 1.0);
	
	//Por cada(Triangulo t en triángulos) t.Render();
	for (Triangle& triangle : this->triangleList) {
		triangle.Render();
	}

	glPopMatrix();

}
