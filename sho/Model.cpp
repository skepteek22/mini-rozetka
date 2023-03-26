#include "Model.h"
#include "View.h"


void Model::IntoMass(string path, vector<Product*>& vec)
{
	
	ifstream in;
	in.open(path);
	if (in.is_open())
	{
		string line;
		while (getline(in, line))
		{
			Product* newproduct = new Product;
			vector<char> fromtxt(line.begin(), line.end());
			stringstream ss;
			int i = 0;
			for (i; fromtxt[i] != '\t'; i++)
			{
				ss << fromtxt[i];
			}
			newproduct->name = ss.str();
			fromtxt.erase(fromtxt.begin(), fromtxt.begin() + (i + 1));
			string h(fromtxt.begin(), fromtxt.end());
			const int index = h.find('\t');
			stringstream ss1;
			for (int i = index; i < fromtxt.size(); i++)
			{
				ss1 << fromtxt[i];
			}
			newproduct->price = stod(ss1.str());
			fromtxt.erase(fromtxt.begin()+index, fromtxt.end());
			string tempinfo(fromtxt.begin(), fromtxt.end());
			newproduct->info = tempinfo;
			vec.push_back(newproduct);
		}
	}

	
}

void Model::displayCat(vector<Product*>& vec)
{
	int userchoose;
	do
	{
		cout << "Anable products:\n\n";
		for (int i = 0; i < vec.size(); i++)
		{
			cout << i + 1 << " - " << vec[i]->name << "\t" << vec[i]->info << "\t" << vec[i]->price << endl;
		}
		cout << endl;
		userchoose = _getch();
		switch (userchoose)
		{
		case 49:
		{
			while (true)
			{
				system("cls");
				cout << vec[0]->name << "\t" << vec[0]->info << "\t" << vec[0]->price << endl;
				cout << "1 - to Loved\n2 - to Basket\n";
				int userchoose2 = _getch();
				if (userchoose2 == 49)
				{
					out.open("loved.txt");
					if (out.is_open())
					{
						out << vec[0]->name << "\t" << vec[0]->info << "\t" << vec[0]->price << endl;
					}
					out.close();
					loved.push_back(vec[0]);
					cout << endl << "successfully added!";
					Sleep(700);
					system("cls");
					break;
				}
				else if (userchoose2 == 50)
				{
					out.open("basket.txt");
					if (out.is_open())
					{
						out << vec[0]->name << "\t" << vec[0]->info << "\t" << vec[0]->price << endl;
					}
					out.close();
					basket.push_back(vec[0]);
					cout << endl << "successfully added!";
					Sleep(700);
					system("cls");
					break;
				}
			}
			break;
		}

		case 50:
		{
			while (true)
			{
				system("cls");
				cout << vec[1]->name << "\t" << vec[1]->info << "\t" << vec[1]->price << endl;
				cout << "1 - to Loved\n2 - to Basket\n";
				int userchoose2 = _getch();
				if (userchoose2 == 49)
				{
					out.open("loved.txt");
					if (out.is_open())
					{
						out << vec[1]->name << "\t" << vec[1]->info << "\t" << vec[1]->price << endl;
					}
					out.close();
					loved.push_back(vec[1]);
					cout << endl << "successfully added!";
					Sleep(700);
					system("cls");
					break;
				}
				else if (userchoose2 == 50)
				{
					out.open("basket.txt");
					if (out.is_open())
					{
						out << vec[1]->name << "\t" << vec[1]->info << "\t" << vec[1]->price << endl;
					}
					out.close();
					basket.push_back(vec[1]);
					cout << endl << "successfully added!";
					Sleep(700);
					system("cls");
					break;
				}
			}
			break;
		}

		case 51:
		{
			while (true)
			{
				system("cls");
				cout << vec[2]->name << "\t" << vec[2]->info << "\t" << vec[2]->price << endl;
				cout << "1 - to Loved\n2 - to Basket\n";
				int userchoose2 = _getch();
				if (userchoose2 == 49)
				{
					out.open("loved.txt");
					if (out.is_open())
					{
						out << vec[2]->name << "\t" << vec[2]->info << "\t" << vec[2]->price << endl;
					}
					out.close();
					loved.push_back(vec[2]);
					cout << endl << "successfully added!";
					Sleep(700);
					system("cls");
					break;
				}
				else if (userchoose2 == 50)
				{
					out.open("basket.txt");
					if (out.is_open())
					{
						out << vec[2]->name << "\t" << vec[2]->info << "\t" << vec[2]->price << endl;
					}
					out.close();
					basket.push_back(vec[2]);
					cout << endl << "successfully added!";
					Sleep(700);
					system("cls");
					break;
				}
			}
			break;
		}
		default:
			system("cls");
		}
	}while (userchoose != 49 && userchoose != 50 && userchoose != 51);
}



Model::Model()
{
	User* newuser = new User;
	in.open("userinfo.txt");
	if (in.is_open())
	{
		string line;
		for (int i = 0; getline(in, line); i++)
		{
			if (i == 0)
				newuser->login = line;
			if (i == 1)
				newuser->password = line;
		}
		if (newuser->login != "" && newuser->password != "")
			users.push_back(newuser);
		else
			delete newuser;
	}
	in.close();
	IntoMass("furniture.txt", furniture);
	IntoMass("forpc.txt", forpc);
	IntoMass("kitchentools.txt", kitchen);
	IntoMass("loved.txt", loved);
	IntoMass("basket.txt", basket);
}

bool Model::LogIn()
{
	system("cls");
	string templogin, temppass;
	cout << "login: ";
	getline(cin, templogin);
	cout << "password: ";
	getline(cin, temppass);
	in.open("userinfo.txt");
	if (in.is_open())
	{
		int i = 0;
		if (users[0]->login == templogin && users[0]->password == temppass)
		{
			system("cls");
			cout << "Welcome!";
			Sleep(700);
			system("cls");
			return true;
		}
		else
		{
			system("cls");
			cout << "incorrect login or password";
			Sleep(700);
			system("cls");
			return false;
		}
	}
}

void Model::SignUp()
{
	system("cls");
	User* newuser = new User;
	string templogin, temppassword;
	cout << "login: ";
	getline(cin, templogin);
	newuser->login = templogin;
	cout << "password: ";
	getline(cin, temppassword);
	newuser->password = temppassword;
	users.push_back(newuser);
	out.open("userinfo.txt");
	if (out.is_open())
		out << templogin << endl << temppassword;
	out.close();
	system("cls");
	cout << "account has been created";
	Sleep(700);
	system("cls");
}

void Model::showCategories() 
{
	int userchoose;
	do
	{
		cout << "|    CATEGORIES    |\n\n1 - Furniture\n2 - PC tools\n3 - Kitchen tools\n";
		userchoose = _getch();
		switch (userchoose)
		{
		case 49:
		{
			system("cls");
			displayCat(furniture);
			break;

		}
		case 50:
		{
			system("cls");
			displayCat(forpc);
			break;
		}
		case 51:
		{
			system("cls");
			displayCat(kitchen);
			break;
		}
		case 113:
			exit(0);
		default:
		{
			system("cls");
		}
		}
	} while (userchoose != 49 && userchoose != 50 && userchoose != 51);
}

void Model::showLoved()
{
	cout << "|    LOVED    |\n\n";
	for (int i = 0; i < loved.size(); i++)
	{
		cout << "TYPE: " << loved[i]->name << "\t" << "NAME: " << loved[i]->info << "\t" << "PRICE: " << loved[i]->price << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Model::showBasket()
{
	cout << "|    BASKET    |\n\n";
	for (int i = 0; i < basket.size(); i++)
	{
		cout << "TYPE: " << basket[i]->name << "\t" << "NAME: " << basket[i]->info << "\t" << "PRICE: " << basket[i]->price << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

int Model::ussize() 
{
	return users.size();
}

