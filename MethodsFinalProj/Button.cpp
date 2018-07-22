#include "Button.h"

Button::Button(int width) : Label(width){}

void Button::mousePressed(int x, int y){
    
    if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight()))
    {
        if (canGetFocus())	Control::setFocus(*this);
        for (auto listener : _listeners)	listener->mousePressed(*this, x, y, isLeft);
    }
    
}
