#pragma once
#include "Model.h"
#include "Solid.h"

class Player : public Solid
{
private:
	Model* modelPtr;

public:
	Player() : modelPtr(nullptr) {};

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
	void movementRight();
	void movementLeft();
	void movementForward();
	void movementBack();

};

