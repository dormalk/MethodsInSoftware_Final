#pragma once

#include "BoarderPainter.h";

class SingelBoarderPainter : public BoarderPainter {
public:
	SingelBoarderPainter();
	virtual void draw(Graphics &g, int top, int left, int width, int height) const;
protected:
	char borders[6];
};