#pragma once
#include "Solid.h";
#include <string>;
#include <GL/glut.h>;

using namespace std;

class Text : public Solid
{
private:
	string text;

public:
	Text(Vector3D coords, Color color, Vector3D orient, Vector3D orientSpeed, Vector3D speed, string text) : Solid(coords, color, orient, orientSpeed, speed), text(text) {};

	inline string getText() const {
		return this->text;
	}

	inline void setText(const string& newText) {
		this->text = newText;
	}

	void Render();
};

