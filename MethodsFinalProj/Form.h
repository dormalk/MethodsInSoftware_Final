#pragma once
#include "Panel.h"
#include "Label.h"
#include "Button.h"
#include "TextBox.h"

class Form : public Panel {
public:
	void buildForm() {
		Label* label = new Label(50);
		label->setText("Where you wants to FLY?!");
		this->addControl(*label, 1, 1);

		TextBox* from = new TextBox(20);
		from->setBorder(BorderType::SINGEL);
		from->setText("From");
		this->addControl(*from, 2, 3);

		TextBox* to = new TextBox(20);
		to->setBorder(BorderType::SINGEL);
		to->setText("To");
		this->addControl(*to, 25, 3);

		Button* submit = new Button(10);
		submit->setText("Submit");
		submit->setBorder(BorderType::DOUBLE);
		this->addControl(*submit, 2, 15);

		Listener* listener1 = new Listener(*to);
		submit->addListener(*listener1);

		Control::setFocus(*from);
	}

	~Form() {
		while (this->_controls.size != 0) {
			Control* _toDelete = reinterpret_cast<Control*>(*_controls.pop_back());
			delete &_toDelete;
		}
	}
private:
	struct Listener : public MouseListener
	{
		Listener(Control &control) : _control(control) { }
		void mousePressed(Button &btn, int x, int y, bool isLeft) {
			_control.setBackground(Color::Purple);
			_control.setForeground(Color::White);
		};
	private:
		Control & _control;
	};
};
