#pragma once
#include "Solid.h"
#include "Model.h"

class Vehicle : public Solid
{
private:
	Model* modelPtr;
	Vector3D initPos;

public:
	Vehicle() : modelPtr(nullptr) {};

	//Devuelve el contenido del puntero  Models
	inline Model& getModel() {
		return *this->modelPtr;
	}

	//Devuelve el puntero a Models
	inline Model* getModelPtr() {
		return modelPtr;
	}

	inline Vector3D getInitPos() const{
		return this->initPos;
	}

	inline void setModel(Model* newModel) {
		this->modelPtr = newModel;
	}

	inline void setInitPos(Vector3D newPos) {
		this->initPos = newPos;
	}

	void Render();

};

