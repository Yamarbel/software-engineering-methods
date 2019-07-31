#include "TextBox.h"


TextBox::TextBox(short left, short top, short width = 30) : Control(left,top){
	this->width = width;
	setBorder(true);
	this->isClick = true;
}

//Destructor 
TextBox::~TextBox()
{
}


void TextBox::draw(Graphics& g, bool doubleborder) {
	drawIt(g, this, doubleborder);
}

void TextBox::drawInside(Graphics& g, bool doubleborder) {
	string tmp = getTxt();
	for (int i = tmp.size(); i<getWidth(); i++)
		tmp.push_back(' ');
	g.write(getLeft(), getTop(), tmp);
}


void TextBox::addTxt(char newTxt)
{
	short tmploca = getCursorLoc();
	if ((short)(this->txt.size()) < this->width) {
		this->txt.insert(this->txt.begin()+ (tmploca++ - getLeft()), newTxt); 
		setCursorLoc(tmploca);
	}
}

void TextBox::DEL(bool type)
{
	short tmploca = getCursorLoc();
	if (this->txt.size() && ((tmploca - getLeft() > 0 && !type) || (type && (tmploca - getLeft())<= (short)(this->txt.size())))) {
		if (!type) this->txt.erase(--tmploca - getLeft(), 1); 
		else this->txt.erase(tmploca - getLeft(), 1);
		setCursorLoc(tmploca);
	}
}


void TextBox::goBack(int x)
{
	if (getLeft() <= --x) setCursorLoc(x);	
}

void TextBox::goForward(int x){
	if((short)(this->txt.size()) > (x - getLeft())) setCursorLoc(x + 1);
}


void TextBox::keyDown(int keyCode, char character, Graphics& g)
{
	switch (keyCode)
	{
	case VK_DELETE:
	case VK_BACK:
		this->DEL(VK_DELETE == keyCode);
		return;
	case VK_LEFT:
		this->goBack(g.GetCursorPosition().X);
		return;

	case VK_RIGHT:			
		this->goForward(g.GetCursorPosition().X);
		return;

	default:
		if (keyCode >= 48 && keyCode <= 126 || keyCode==32) 
		this->addTxt(character); 
		
		break;
	}

}