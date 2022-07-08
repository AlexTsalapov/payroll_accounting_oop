#pragma once
#include"Autorization.h"
class Admin :public Autorization
{
protected:
	MyString surname;
public:
	Admin()
	{
		surname = "";
		address = "Admin.txt";
	}
	Admin(MyString login1, MyString password1, MyString surname1) :Autorization(login1, password1)
	{
		surname = surname1;
	}
	void setSurname(MyString value)
	{
		this->surname = value;
	}

	MyString getSurname()
	{
		return this->surname;
	}
	MyString getAddress()
	{
		return this->address;
	}
	void show_tabl();
	void editPerson();
	friend istream& operator >>(istream& in, Admin& ob);
	friend ostream& operator <<(ostream& out, Admin& ob);
	friend ifstream& operator >>(ifstream& in, Admin& obj);
	friend ofstream& operator <<(ofstream& out, Admin& obj);
};
