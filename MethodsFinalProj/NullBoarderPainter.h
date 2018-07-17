#pragma once

#include "BoarderPainter.h";

class NullBoarderPainter : public BoarderPainter {
	virtual void draw(Graphics &g, int top, int left, int width, int height) const {}
};