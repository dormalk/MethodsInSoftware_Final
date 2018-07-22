#include "EventEngine.h"
using namespace std;

EventEngine::EventEngine(DWORD input, DWORD output)
	:console(GetStdHandle(input)), graphics(output) {
	GetConsoleMode(console,&mode);
	SetConsoleMode(console, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

}


void EventEngine::run(Control& control) {
	for (bool repaint = true; ; ) {
		if (repaint) {
			graphics.setCursorVisibility(false);
			graphics.clearScreen();
			for (size_t i = 0; i < 5; i++) {
				control.draw(graphics, control.getLeft(), control.getTop(), i);
			}
			repaint = false;
		}
	}
}