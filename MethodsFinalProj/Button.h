#pragma once
using namespace std;
#include <string>
#include "Label.h"

class Button : public Label
{
public:

    Button(int width);
    virtual ~Button() = default;
    
    void addListener(struct MouseListener &listener);
    virtual void mousePressed(int x, int y, bool isLeft);

private:

	vector<struct MouseListener*> _listeners;

};

struct MouseListener
{
	virtual void mousePressed(Button &b, int x, int y, bool isLeft) = 0;
};
