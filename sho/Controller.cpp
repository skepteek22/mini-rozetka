#include "Controller.h"

Controller::Controller(Model* model)
{
	_model = model;
}



bool Controller::LogIn()
{
	if (_model->LogIn())
		return true;
	else
		return false;
}

void Controller::SignUp()
{
	_model->SignUp();
}

void Controller::showCategories()
{
	_model->showCategories();
}

void Controller::showLoved()
{
	_model->showLoved();
}

void Controller::showBasket()
{
	_model->showBasket();
}

int Controller::ussize()
{
	int a = _model->ussize();
	return a;
}
