#include "Panel.h"
#include "Label.h"
#include "TextBox.h"
#include "Button.h"
#include "NumericBox.h"
#include "EventEngine.h"
#include <fstream>

struct Listener : public MouseListener
{
	Listener(Panel &panel) : _panel(panel) {
		static int count;
		count = 0;
		out.open("order.txt", ofstream::out | ofstream::app);
	}
	void mousePressed(Button &btn, int x, int y, bool isLeft) {
		vector<Control*> controls;
		_panel.getAllControls(&controls);
		auto it = controls.begin();
		while (it != controls.end()) {
			out << (**it).getText() << "\n";
			it++;
		}
		out.close();
	};

private:
	Panel & _panel;
	ofstream out;
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

	NumericBox numeric(5, 10, 20);
	to.setBorder(BorderType::SINGEL);
	form.addControl(numeric, 2, 5);

	Button submit(10);
	submit.setText("Submit");
	submit.setBorder(BorderType::DOUBLE);
	form.addControl(submit, 2, 15);

	Listener listener(form);
	submit.addListener(listener);

	Control::setFocus(from);

	EventEngine engine;
	engine.run(form);

	return 0;
}

