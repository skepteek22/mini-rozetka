#pragma once
#include "Controller.h"
#include <conio.h>

class View
{
	Controller* _controller;
public:
	View(Controller* controller);
	void Start();
};

