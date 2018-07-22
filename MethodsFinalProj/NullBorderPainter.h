#pragma once

#include "BorderPainter.h"

class NullBorderPainter : public BorderPainter {
	virtual void draw(Graphics &g, int top, int left, int width, int height) const {}
};