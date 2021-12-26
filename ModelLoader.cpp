#include "ModelLoader.h"

float ModelLoader :: getWidth() {
	return (maxX - minX);
}

float ModelLoader :: getHeight() {
	return (maxY - minY);
}

float ModelLoader :: getLength() {
	return (maxZ - minZ);
}

void ModelLoader :: calcBoundaries(Vector3D vertex) {
	
	this->maxX = fmax(this->maxX, vertex.getCoordinateX());
	this->maxY = fmax(this->maxY, vertex.getCoordinateY());
	this->maxZ = fmax(this->maxZ, vertex.getCoordinateZ());

	this->minX = fmin(this->minX, vertex.getCoordinateX());
	this->minY = fmin(this->minY, vertex.getCoordinateY());
	this->minZ = fmin(this->minZ, vertex.getCoordinateZ());
	
}

Triangle ModelLoader :: center(Triangle triangle) {

	Vector3D modelCenter(this->minX + this->getWidth() / 2.0,
		this->minY + this->getHeight() / 2.0,
		this->minZ + this->getLength() / 2.0);

	Triangle centeredTriangle(
		triangle.getVertex0() - modelCenter,
		triangle.getVertex1() - modelCenter,
		triangle.getVertex2() - modelCenter,
		triangle.getVertexNormal0(),
		triangle.getVertexNormal1(),
		triangle.getVertexNormal2());

	return centeredTriangle;

}

Vector3D ModelLoader :: parseObjLineToVector3D(const string& line) {
	
	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Vector3D vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint * this->getScale();
}

Triangle ModelLoader::parseObjTriangle(const string& line) {
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;

	istringstream stringStream(line);
	stringStream >> c; 
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D vertex0 = this->vertexList[idxVertex0 - 1];
	Vector3D vertex1 = this->vertexList[idxVertex1 - 1];
	Vector3D vertex2 = this->vertexList[idxVertex2 - 1];
	Vector3D normal = this->normalList[idxNormal0 - 1];

	Triangle parsedTriangle = Triangle(vertex0, vertex1, vertex2, normal, normal, normal);
	
	return parsedTriangle;
}

void ModelLoader::loadModel(const string& filePath) {
	try {
		ifstream objFile(filePath);
		
		if (objFile.is_open()) {

			string line;
			int count = 0;
			
			while (getline(objFile, line)) {

				if (line[0] == 'v' && line[1] == 'n') {
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->normalList.push_back(normal);
				}
				else if (line[0] == 'v') {
					Vector3D vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertexList.push_back(vertex);
				}
				else if (line[0] == 'f') {
					Triangle triangle = this->parseObjTriangle(line);
					this->model.addTriangle(this->center(triangle));
				}

			}

			objFile.close();

		}
		else {
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}

	}
	catch (exception& ex) {
		cout << "Excepcion al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}

void ModelLoader::clear(){
	
	vertexList.clear();
	normalList.clear();
	model.getTriangleList().clear();

}