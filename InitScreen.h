#pragma once
#include "Scene.h"
#include "Solid.h"
#include "Text.h"
#include "Camera.h"
#include "Model.h"
#include "ModelLoader.h"
#include <string>
#include "Vector3D.h"
#include "Color.h"

class InitScreen : public Scene
{
private:
	Text* title;

public:
	InitScreen() : Scene() {};

	void init();
	void update(const float& time);
	void processKeyPressed(unsigned char key, int px, int py);

	inline Text* getTitle() {
		return this->title;
	}

	inline void setTitle(Text* titleToSet) {
		this->title = titleToSet;
	}
};

