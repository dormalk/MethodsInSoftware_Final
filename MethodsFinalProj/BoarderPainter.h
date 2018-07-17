#pragma once
#include "Graphics.h";

class BoarderPainter {
	virtual void draw(Graphics &g, int top, int left, int width, int height) const = 0;
};