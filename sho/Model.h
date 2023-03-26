#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "IModelandController.h"
#include "UserProduct.h"
#include <sstream>
#include <algorithm>
using namespace std;

class Model : public IModelandController
{
private:
	ifstream in;
	ofstream out;
	vector<Product*> furniture;
	vector<Product*> kitchen;
	vector<Product*> forpc;
	vector<Product*> loved;
	vector<Product*> basket;
	vector<User*> users;
	void IntoMass(string path, vector<Product*>& vec);
	void displayCat(vector<Product*>& vec);
public:
	Model();
	bool LogIn() override;
	void SignUp() override;
	void showCategories() override;
	void showLoved() override;
	void showBasket() override;
	int ussize() override;
};

