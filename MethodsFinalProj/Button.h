#pragma once

#include <string>

#include "Label.h"

using namespace std;

class Button : public Label
{
public:
	Button(int width);
	virtual ~Button() = default;


	void addListener(struct MouseListener &listener);
	virtual void mousePressed(int x, int y, bool isLeft);
};
