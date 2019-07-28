#include "Label.h"
#include <iostream>


Label::Label() : Control(){ this->isFocus = false; }

Label::Label(string value) : Control(), value(value) {
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocus = false;
};

Label::Label(string value, Color background, Color foreground) : Control(), value(value) {
	setColor(background, foreground);
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocus = false;

};

Label::Label(string value, Color background, Color foreground, short left, short top) : Control(left, top), value(value) {
	setColor(background, foreground);
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocus = false;

};


string Label::getValue(){

	return this->value;
}

void Label::setValue(string value){
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->value = value;
}

void Label::setNum(int num) {
	this->setWidth(1);
	this->setHeight(1);
	this->num = num;
}


void Label::draw(Graphics& g, bool doubleborder) {
	drawIt(g, this, doubleborder);
}
void Label::drawInside(Graphics& g, bool doubleborder) {
	g.write(getLeft(), getTop(), this->value);
}