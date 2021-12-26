#pragma once
#include "Model.h"
#include "Solid.h"

class Road : public Solid
{
private:
	Model* modelPtr;

public:
	Road() : modelPtr(nullptr) {};

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

