#include "Panel.h"
#include "Label.h"
#include "TextBox.h"
#include "Button.h"
#include "EventEngine.h"

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

int main()
{
	Panel form;
	Label label(50);
	label.setText("Where you wants to FLY?!");
	form.addControl(label, 1, 1);

	TextBox from(20);
	from.setBorder(BorderType::SINGEL);
	from.setText("From");
	form.addControl(from, 2, 3);

	TextBox to(20);
	to.setBorder(BorderType::SINGEL);
	to.setText("To");
	form.addControl(to, 25, 3);

	Button submit(10);
	submit.setText("Submit");
	submit.setBorder(BorderType::DOUBLE);
	form.addControl(submit, 2, 15);

	Listener listener1(to);
	submit.addListener(listener1);

	Listener listener2(from);
	submit.addListener(listener2);

	Control::setFocus(from);

	EventEngine engine;
	engine.run(form);

	return 0;
}

