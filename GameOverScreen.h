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

class GameOverScreen : public Scene
{
private:
	Text* title;
	Text* info;
	Model* background;

public:
	GameOverScreen() : Scene() {};

	void init();
	void update(const float& time);
	void processKeyPressed(unsigned char key, int px, int py);

	inline const Text* getTitle() {
		return this->title;
	}

	inline const Text* getInfo() {
		return this->info;
	}

	inline void setTitle(Text* titleToSet) {
		this->title = titleToSet;
	}

	inline void setInfo(Text* infoToSet) {
		this->info = infoToSet;
	}
};

