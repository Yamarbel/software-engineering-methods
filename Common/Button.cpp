#include "Button.h"


Button::Button() : Label(){
	this->isFocus = false;
	this->isClick = true;
	setWidth((short)(getValue().size()));
	setHeight(1);
	setBorder(true);
}


Button::Button(string value) : Label(value){ 
	setWidth((short)(getValue().size()));
	this->isClick = true;
	setHeight(1);
	setBorder(true);
}

Button::Button(string value, Color background, Color foreground) : Label(value,background,foreground){
	setWidth((short)(getValue().size()));
	this->isClick = true;
	setHeight(1);
	setBorder(true);
}
void Button::mousePressed(int x, int y, bool isLeft) {

	if (this->pressed) {
		this->pressed = !this->pressed;
		setColor(Color::Black, Color::White);
	}
	else {
		this->pressed = !this->pressed;
		setColor(Color::White, Color::Black);
	}
	
}

//Destructor
Button::~Button(){
}