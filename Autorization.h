#pragma once
#include"MyString.h"
#include"File.cpp"
#include<fstream>

class Autorization
{
protected:
	MyString login;
	MyString password;
	
	MyString address;
public:
	Autorization()
	{
		login = "";
		password = "";
		
	}
	Autorization(MyString login1, MyString password1) 
	{
		login = login1;
		password = password1;
	}
	MyString getAddres()
	{
		return this->address;
	}
	void setPassword(MyString value)
	{
		this->password = value;
	}

	MyString getPassword()
	{
		return this->password;
	}
	void setLogin(MyString value)
	{
		this->login = value;
	}
	virtual int getBlock()
	{
		return 1;
	}
	MyString getLogin()
	{
		return this->login;
	}
	MyString get1()
	{
		return this->login;
	}
	virtual MyString getSurname()
	{
		return "";
	}
	friend istream& operator >>(istream& in, Autorization& ob);
	friend ostream& operator <<(ostream& out, Autorization& ob);
	friend ifstream& operator >>(ifstream& in, Autorization& obj);
	friend ofstream& operator <<(ofstream& out, Autorization& obj);
};
