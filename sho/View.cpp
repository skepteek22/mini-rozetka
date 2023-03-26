#include "View.h"



View::View(Controller* controller)
{
	_controller = controller;
}

void View::Start()
{
	int userchoose;
	int a = 0;
	bool abc = false;
	do
	{
		cout << "|    Hi    |\n\n";
		cout << "1 - Log In\n2 - Sign Up";
		userchoose = _getch();
		switch (userchoose)
		{
			case 49:
			{
				abc = _controller->LogIn();
				break;
			}
			case 50:
			{
				a = _controller->ussize();
				if (a == 1)
				{
					system("cls");
					cout << "you already have an account";
					Sleep(700);
					goto again;
				}
				else
				{
					_controller->SignUp();
					goto ai;
				}
			}
			case 113:
				exit(0);
			default:
			{
				again:
				system("cls");
				break;
			}
		}
	} while (!abc);
	ai:
	system("cls");
	int userchoose2;
	do
	{
		cout << "|    MENU    |\n\n";
		cout << "1 - Categories\n2 - Loved\n3 - Basket";
		userchoose = _getch();
		switch (userchoose)
		{
		case 49:
		{
			system("cls");
			_controller->showCategories();
			break;
		}
		case 50:
		{
			system("cls");
			_controller->showLoved();
			break;
		}
		case 51:
		{
			system("cls");
			_controller->showBasket();
			break;
		}
		case 113:
			exit(0);
		default:
		{
			system("cls");
			break;
		}
		}
	} while (userchoose !=113);
}
