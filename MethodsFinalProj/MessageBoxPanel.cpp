#include "Button.h"
#include "Label.h"
#include "MessageBoxPanel.h"

MessageBoxPanel::MessageBoxPanel(int height, int width):Panel(height, width), _lblText(width), _lblTitle(width-2){
	struct AnswerListener* listener = new struct AnswerListener(*this);

	if ((width < 12) || (height < 7))   throw "Width or Height is INVALID";
	auto btnOk = new Button(2);
	btnOk->setText("Ok");
	btnOk->addListener(*listener);

	auto btnCnl = new Button(6);
	btnCnl->setText("Cnl");
	btnCnl->addListener(*listener);

	setBorder(BorderType::Single);
	_lblTitle.setBorder(BorderType::Single);
	addControl(_lblTitle, 1, 1);
	addControl(_lblText, 0, 3);
	btnOk->setBorder(BorderType::Single);
	addControl(*btnOk, 1, 5);
	btnCnl->setBorder(BorderType::Single);
	addControl(*btnCnl, width-7, 5);
	hide();
}

void MessageBoxPanel::setLayer(size_t layer){
    for (auto c : _controls)
        c->setLayer(layer);
    Panel::setLayer(layer);
}

void MessageBoxPanel::addControl(Control & control, int left, int top)  Panel::addControl(control, left, top);
string MessageBoxPanel::getTitle()  return _lblTitle.getText();
void MessageBoxPanel::setTitle(string title)    _lblTitle.setText(title);
string MessageBoxPanel::getText()   return _lblText.getText();
void MessageBoxPanel::setText(string text)  _lblText.setText(text);
string MessageBoxPanel::getResult() return _result;
void MessageBoxPanel::show(){
	_result = "";
	Panel::show();
}

