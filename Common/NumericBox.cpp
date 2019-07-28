#include "NumericBox.h"


NumericBox::NumericBox(int min=0,int max=99,short left=0,short top=0) : TextBox(left,top, (short)(to_string(max).size())+1){
	this->min = min;
	this->max = max;
	setActual(min);
	isFocus = false; 
	if (min >=0) setTxt(" " + to_string(min));
	else setTxt(to_string(min));
	setHeight(1);


	plus.setValue(" + ");					//+ symbol
	plus.setLeft(getLeft() + getWidth() + 2);
	plus.setTop(getTop());		
	plus.setWidth(3);


	minus.setValue(" - ");					//- symbol
	minus.setLeft(plus.getLeft() + plus.getWidth() + 2 );
	minus.setTop(getTop());
	minus.setWidth(3);
	setWidth(plus.getWidth() + minus.getWidth() + getWidth()+4);


	
}


void NumericBox::setColor(Color background, Color foreground) {
	Control::setColor(background, foreground);
	plus.setColor(background, foreground);
	minus.setColor(background, foreground);
	num.setColor(background, foreground);
}


void NumericBox::draw(Graphics& g, bool doubleborder) {
	drawIt(g, this, doubleborder);
}


void NumericBox::drawInside(Graphics& g, bool doubleborder) {
	TextBox::drawInside(g,doubleborder);
	plus.draw(g,doubleborder);
	minus.draw(g,doubleborder);
	
}

void NumericBox::mousePressed(int x, int y, bool isLeft){
	int actual = getActual();
	if (isInside(x, y, &plus) && actual < max) {
		setActual(++actual);
		num.setNum(actual);
	}
	else if (isInside(x, y, &minus) && actual > min)setActual(--actual);

	if (actual >= -9) setTxt(" " + to_string(actual));
	else setTxt(to_string(actual));
}
//Destructor
NumericBox::~NumericBox() {
}