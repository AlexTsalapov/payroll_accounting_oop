#pragma once
#include "Autorization.h"
class User:public Autorization
{
protected:
	int block;
public:
	User()
	{
		address = "User.txt";
		block = 0;
	}
	User(MyString login1, MyString password1, int block1 ) :Autorization(login1,password1)
	{
		block = block1;
	}
	MyString getAddress()
	{
		return this->address;
	}
	virtual int getBlock()
	{
		return this->block;
	}
	void setBlock(int value)
	{
		 this->block=value;
	}
	void show_tabl();
	void editPerson();
	bool operator==(User& other);
    friend istream& operator >>(istream& in, User& ob);
	friend ostream& operator <<(ostream& out, User& ob);
	friend ifstream& operator >>(ifstream& in, User& obj);
	friend ofstream& operator <<(ofstream& out, User& obj);
};