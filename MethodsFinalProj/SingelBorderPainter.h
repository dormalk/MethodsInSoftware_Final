#pragma once

#include "BorderPainter.h"

class SingelBorderPainter : public BorderPainter {
public:
	SingelBorderPainter();
	virtual void draw(Graphics &g, int top, int left, int width, int height) const;
protected:
	char borders[6];
};