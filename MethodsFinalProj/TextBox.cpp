#include "TextBox.h"

TextBox::TextBox(int width) : Label(width), _cursPosition(0) {
	setCanGetFocus(true);
}

void TextBox::draw(Graphics & g, int left, int top, size_t layer) const {
	if (!isVisible()) {
		return;
	}
	Label::draw(g, left, top, layer);
	if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.moveTo(getLeft() + left + _cursPosition, getTop() + top);
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft) {
	if (!isLeft || !isVisible()) {
		return;
	}
	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {
		Control::setFocus(*this);
		_cursPosition = ((x - getLeft()) >= getText().size()) ? getText().size() - 1 : x - getLeft();
	}
}

void TextBox::keyDown(int keyCode, char character) {
	if ((this != Control::getFocus()) || !isVisible()) {
		return;
	}
    
	bool deleteChar = false;
	int currentcursPosition = _cursPosition;
    //check back/delete/return/left/right
	switch (keyCode) {
	case VK_BACK:
		if (_cursPosition > 0) {
			--_cursPosition;
		}
		deleteChar = true;
		break;
	case VK_DELETE:
		deleteChar = true;
		break;
	case VK_RETURN:
		return;
	case VK_LEFT:
		if (_cursPosition > 0) {
			--_cursPosition;
		}
		return;
	case VK_RIGHT:
		if (_cursPosition < getText().size() - 1) {
			++_cursPosition;
		}
		return;
	default:
		break;
	}
    
	if (deleteChar){
		if (currentcursPosition < getText().size()) {
			string newText = getText();
			newText = newText.substr(0, currentcursPosition) + newText.substr(currentcursPosition + 1, newText.size() - currentcursPosition);
			setText(newText);
		}
	}
    
	else if (character != '\0') {
		string newText;
		if (currentcursPosition < getText().size()) {
			newText = getText().substr(0, currentcursPosition) + character + getText().substr(currentcursPosition+1, getText().size() - currentcursPosition);
		}
		else {
			newText = getText() + character;
		}
		setText(newText);
		if (_cursPosition < getWidth()-1) {
			++_cursPosition;
		}
	}
}
