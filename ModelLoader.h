#pragma once
#include "Model.h"
#include "Vector3D.h"
#include <vector>
#include "Triangle.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class ModelLoader
{
private:
	float scale;
	Model model;
	vector<Vector3D> vertexList;
	vector<Vector3D> normalList;
	float maxX;
	float minX;
	float maxY;
	float minY;
	float maxZ;
	float minZ;

	float getWidth();
	float getHeight();
	float getLength();
	void calcBoundaries(Vector3D vertex);

	Triangle center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& line);
	Triangle parseObjTriangle(const string& line);

public:
	inline float getScale() const {
		return this->scale;
	}

	inline Model getModel() const {
		return this->model;
	}

	inline void setScale(const float& newScale) {
		this->scale = newScale;
	}

	inline void setModel(const Model& newModel) {
		this->model = newModel;
	}

	void loadModel(const string& filePath);

	void clear();
};

