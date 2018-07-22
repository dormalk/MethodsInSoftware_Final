// MethodsInSoftware_Final.cpp : Defines the entry point for the console application.
//
#include "Panel.h"
#include "Label.h"
#include "EventEngine.h"

int main()
{
	Panel form;
	Label label(10);
	label.setText("Hello");
	form.addControl(label, 10, 50);

	EventEngine engine;
	engine.run(form);
	return 0;
}

