#pragma once

#include <string>
#include "Control.h"
using namespace std;

class Label :public Control {

public:
	Label(int width);
	virtual ~Label() = default;
	void setText(string value);
	virtual string getText() const;
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
private:
	string _text;
	static const size_t TEXT_HEIGHT = 1;
};
