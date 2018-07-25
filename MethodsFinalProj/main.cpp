#include "Panel.h"
#include "Label.h"
#include "TextBox.h"
#include "EventEngine.h"
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

	Control::setFocus(from);

	EventEngine engine;
	engine.run(form);

	return 0;
}

