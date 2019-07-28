#pragma once
#include "Label.h"
#include "Button.h"
#include <string>


class Message_Box : public Label {
protected:
	Button ok, cancel;
public:
	Message_Box(string value, Color background, Color foreground, short left, short top);
	virtual ~Message_Box();
	virtual void setColor(Color background, Color foreground);
	void draw(Graphics& g, bool doubleborder);
	virtual void drawInside(Graphics& g, bool doubleborder);
	virtual void setParentDimensions(short left, short top) { 
		this->parentTop = top; 
		this->parentLeft = left; 
		ok.setParentDimensions(left, top);
		cancel.setParentDimensions(left, top);
	};
	virtual void mousePressed(int x, int y, bool isLeft);

};
