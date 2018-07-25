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

		INPUT_RECORD input_record;
		DWORD flags = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

		ReadConsoleInput(console, &input_record, 1, &flags);

		switch (input_record.EventType) {
		case KEY_EVENT:
		{
			Control* focused = Control::getFocus();
			auto rec_code = input_record.Event.KeyEvent.wVirtualKeyCode;
			auto rec_asciiChar = input_record.Event.KeyEvent.uChar.AsciiChar;
			if (rec_code == VK_TAB) {
				onChangeFocuse(control, focused);
			}
			else {
				focused->keyDown(rec_code, rec_asciiChar);
				repaint = true;
			}
			break;
		}
		case MOUSE_EVENT:
		{
			COORD pos = input_record.Event.MouseEvent.dwMousePosition;
			auto btn = input_record.Event.MouseEvent.dwButtonState;
			
			int y = pos.Y - control.getTop();
			int x = pos.X - control.getLeft();

			if (btn == FROM_LEFT_1ST_BUTTON_PRESSED || btn == RIGHTMOST_BUTTON_PRESSED) {
				control.mousePressed(x, y, btn == FROM_LEFT_1ST_BUTTON_PRESSED);
				repaint = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

void EventEngine::onChangeFocuse(Control &src, Control *dst) {
	vector<Control*> controls;
	src.getAllControls(&controls);

	auto it = find(controls.begin(), controls.end(), dst);
	do {
		if (++it == controls.end()) {
			it = controls.begin();
		}
	} while (!(*it)->canGetFocus());
	Control::setFocus(**it);
}

