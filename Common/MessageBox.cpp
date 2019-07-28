#include "MessageBox.h"

Message_Box::Message_Box(string value, Color background, Color foreground, short left, short top) : Label(value, background, foreground, left, top) {
	string btnok = "Ok";
	string btncancel = "Cancel";
	setBorder(true);
	this->isFocus = false;
	this->isClick = true;
	ok.setValue(btnok);
	ok.setLeft(getLeft()+2);
	ok.setTop(getTop()+3);
	ok.setWidth((short)(btnok.size()));
	ok.setColor(background, foreground);
	cancel.setColor(background, foreground);
	cancel.setValue(btncancel);
	cancel.setLeft(ok.getLeft() + ok.getWidth() + 4);
	cancel.setTop(ok.getTop());
	cancel.setWidth((short)(btncancel.size()));
	if (((short)(value.size()) > ok.getWidth() + cancel.getWidth())) setWidth((short)(value.size()) + 5);
	else setWidth(ok.getWidth() + cancel.getWidth() + 4);
	setHeight(6);
}

void Message_Box::setColor(Color background, Color foreground) {
	Control::setColor(background, foreground);
	ok.setColor(background, foreground);
	cancel.setColor(background, foreground);
}

void Message_Box::draw(Graphics& g, bool doubleborder) {
	drawIt(g, this, doubleborder);
}
void Message_Box::drawInside(Graphics& g, bool doubleborder) {
	Label::drawInside(g,doubleborder);
	ok.draw(g,doubleborder);
	cancel.draw(g,doubleborder);
}
void Message_Box::mousePressed(int x, int y, bool isLeft){
	ok.setColor(getBackground(), getForeground()); //Reset Colors
	cancel.setColor(getBackground(), getForeground()); 
	if (isInside(x, y, &ok)) ok.setColor(Color::White,Color::Black);
	else if (isInside(x, y, &cancel)) cancel.setColor(Color::White, Color::Black);
}


Message_Box::~Message_Box() {
}
