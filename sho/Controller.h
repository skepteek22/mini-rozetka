#pragma once
#include <iostream>
#include "Model.h"
using namespace std;


class Controller : public IModelandController
{
	Model* _model;
public:
	Controller(Model* model);

	bool LogIn() override;
	void SignUp() override;
	void showCategories() override;
	void showLoved() override;
	void showBasket() override;
	int ussize() override;
};

