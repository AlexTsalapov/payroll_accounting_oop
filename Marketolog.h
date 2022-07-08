#pragma once
#include"Work_with_people.h"
class Marketolog:public Work_with_people
{
protected:
	int number;
public:
	Marketolog()
	{
		this->number = 0;
		address = "Marketolog.txt";
	}
	Marketolog(MyString name1, double sallary1, MyString position1, double premium1, double income1, int number1) :Work_with_people(name1, sallary1, position1, premium1, number1)
	{
		number = number1;
	}
	
	MyString getAddress()
	{
		return this->address;
	}
	void set6(int value)
	{
		this->number = value;
	}
	int get6()
	{
		return this->number;
	}
	 void show_tabl() ;
	void searchPerson();
	virtual void editPerson();
	bool operator==(Marketolog& other);
	 friend istream& operator >>(istream& in, Marketolog& ob);
	 friend ostream& operator <<(ostream& out, Marketolog& ob);
	 friend ifstream& operator >>(ifstream& in, Marketolog& obj);
	 friend ofstream& operator <<(ofstream& out, Marketolog& obj);
};
