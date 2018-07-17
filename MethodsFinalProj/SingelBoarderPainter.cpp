#include "SingelBoarderPainter.h"

SingelBoarderPainter::SingelBoarderPainter() {
	borders[0] = 218;
	borders[1] = 191;
	borders[2] = 196;
	borders[3] = 179;
	borders[4] = 192;
	borders[5] = 217;
}

void SingelBoarderPainter::draw(Graphics &g, int top, int left, int width, int height) const {
	if (top > 0 && left > 0) {
		g.write(left - 1, top - 1, string("") + borders[0]);
	}
	else if (top > 0 && !left > 0) {
		g.write(left, top - 1, string(width, borders[2]) + borders[1]);
	}

	for (int i = 0; i < height; i++){
		if (left > 0){
			g.write(left - 1, top + i, string(1, borders[3]));
		}

		g.write(left + width, top + i, string(1, borders[3]));
	}

	if (left > 0){
		g.write(left - 1, top + height, string("") + borders[4]);
	}
	g.write(left, top + height, string(width, borders[2]) + borders[5]);

};
