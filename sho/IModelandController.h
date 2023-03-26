#pragma once
class IModelandController
{
public:
	virtual bool LogIn() = 0;
	virtual void SignUp() = 0;
	virtual void showCategories() = 0;
	virtual void showLoved() = 0;
	virtual void showBasket() = 0;
	virtual int ussize() = 0;
};

