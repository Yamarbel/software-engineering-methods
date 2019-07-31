#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/CheckList.h"
#include "../Common/NumericBox.h"
#include "../Common/MessageBox.h"
#include "../Common/RadioBox.h"

int main(int argc, char** argv){
	EventEngine e;
	
	//Panel
	Panel panel;
	panel.setWidth(80);
	panel.setHeight(22);
	panel.setTop(4);
	panel.setLeft(8);
	panel.setBorder(true);
	panel.setColor(Color::Black, Color::White);

	//Label
	Label label("Label", Color::Black, Color::White);
	label.setTop(1);
	label.setLeft(37);
	label.setBorder(false);
	panel.add(&label);

	//Button
	Button button("Button", Color::Black, Color::White);
	button.setTop(5);
	button.setLeft(37);
	panel.add(&button);

	//Text Box
	TextBox txtBox;
	txtBox.setColor(Color::Black, Color::White);
	txtBox.setWidth(15);
	txtBox.setHeight(1);
	txtBox.setTop(5);
	txtBox.setLeft(3);
	txtBox.setDoubleBorder(true);
	panel.add(&txtBox);

	//Numeric Box
	NumericBox numericBox(0, 99, 3, 12);
	numericBox.setColor(Color::Black, Color::White);
	numericBox.setDoubleBorder(true);
	panel.add(&numericBox);

	//Check List
	CheckList checlList(3, 16, 4);
	checlList.setColor(Color::Black, Color::White);
	panel.add(&checlList);

	//Message_Box
	Message_Box massegeBox(" MesasgeBox", Color::Black, Color::White, 60, 5);
	massegeBox.setDoubleBorder(true);
	panel.add(&massegeBox);

	//RadioBox
	RadioBox rb(60,15 , 5);
	panel.add(&rb);
	//Show Panel
	e.run(panel,true);


}
