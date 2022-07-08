#pragma once
#include "MyString.h"
#include"File.cpp"
class Factory
{
protected:
	MyString name;
	double sallary;
	MyString position;
	double premium;
	MyString address;


public:
	Factory()
	{
		this->name = "";
		this->sallary = 0.0;
		this->position = "";
		this->premium = 0.0;
		
	}
	Factory(MyString name1, double sallary1, MyString position1, double premium1)
	{
		name = name1;
		sallary = sallary1;
		position = position1;
		premium = premium1;
	}
	void setName(MyString value)
	{
		this->name = value;
	}
	MyString getName()
	{
		return this->name;
	}
	MyString get1()
	{
		return this->name;
	}
	double getSallary()
	{
		return this->sallary;
	}
	void setSallary(int value)
	{
		this->sallary = value;
	}
	void setPosition(MyString value)
	{
		this->position = value;
	}
	MyString getPosition()
	{
		return this->position;
	}
	double getPremium()
	{
		return this->premium;
	}
	void setPremium(int value)
	{
		this->premium = value;
	}
	MyString getAddress()
	{
		return address;
	}

	 void show_tabl() ;
	 friend istream& operator >>(istream& in, Factory& ob);
	 friend ostream& operator <<(ostream& out,  Factory& ob);
	 friend ifstream& operator >>(ifstream& in, Factory& ob);
	 friend ofstream& operator <<(ofstream& out, Factory& ob);
};
