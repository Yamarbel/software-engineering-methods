#pragma once
#include "Label.h"

class Button : public Label {
public:
	Button();
	Button(string str);
	Button(string value, Color background, Color foreground);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual ~Button();
	BOOLEAN pressed = false;
};

