#include "CheckList.h"


CheckList::CheckList(short left, short top, int optNum) : Control(left, top), arrow(0) { 
	this->isClick = true;
	isLast = false;
	for (int i = 0; i < optNum; i++) 
		this->list.push_back({ "select: ("  + to_string(i) + ")" , false }); 
	this->height = optNum;
	this->width = this->list.at(0).name.size();
};
CheckList::CheckList() : Control(), arrow(0) {
	this->isClick = true;
	isLast = false;
	for (int i = 0; i < 5; i++)
		this->list.push_back({ "select: (" + to_string(i) + ")" , false });
	this->height = 5;
	this->width = this->list.at(0).name.size();

}
CheckList::~CheckList()
{
}


void CheckList::draw(Graphics& g, bool doubleborder) {
	drawIt(g, this, doubleborder);
}

void CheckList::drawInside(Graphics& g, bool doubleborder) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selected) ? "[*] " : "[ ] ") + list.at(i).name + ((i == arrow) ? " <" : "");
		g.write(this->getLeft(), this->getTop() + i, temp);
	}
}

void CheckList::goUp() { 
	if (arrow == 0) arrow = list.size();
	arrow = --arrow % list.size();
}

void CheckList::goDown() { 
	arrow = ++arrow % list.size();
}


void CheckList::goTab() { 
	if (arrow + 1 == list.size()) isLast = true;
	else this->goDown();
}


void CheckList::choose() { 
	list.at(arrow).selected = !list.at(arrow).selected;
}

void CheckList::keyDown(int keyCode, char character, Graphics& g){
	if (keyCode == VK_DOWN ) this->goDown();
	else if (keyCode == VK_UP) this->goUp();
	else if (keyCode == VK_TAB) this->goTab();
	else if (keyCode == VK_SPACE) this->choose();
}