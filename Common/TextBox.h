#pragma once
#include "Control.h"

class TextBox : public Control
{
	string txt;
public:
	void addTxt(char newTxt);
	void DEL(bool type);
	void goBack(int x);
	void goForward(int x);
	void draw(Graphics& g, bool doubleborder);
	string getTxt() { return this->txt; };
	void setTxt(string value) { this->txt = value; };
	TextBox() : Control(){setBorder(true);};
	TextBox(short left, short top, short width);
	void keyDown(int keyCode, char character, Graphics& g);
	virtual void drawInside(Graphics& g, bool doubleborder);

	~TextBox();
};

