#pragma once
#include "Graphics.h"

class BorderPainter {
	public:
		virtual void draw(Graphics &g, int top, int left, int width, int height) const = 0;
};