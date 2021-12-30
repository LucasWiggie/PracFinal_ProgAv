#pragma once
#include "Solid.h"
#include "Model.h"

class Vehicle : public Solid
{
private:
	Model* modelPtr;

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

	inline void setModel(Model* newModel) {
		this->modelPtr = newModel;
	}

	void Render();

};

