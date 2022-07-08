#pragma once
#include "Factory.h"
class Work_with_people:public Factory
{
protected:
	double income;
public:
	Work_with_people()
	{
		this->income = 0.0;
		this->address = "Work_with_people.txt";
	}
	Work_with_people(MyString name1, double sallary1, MyString position1, double premium1, double income1) :Factory(name1, sallary1, position1, premium1)
	{
		income = income1;
	}
	double get5()
	{
		return this->income;
	}
	void set5(int value)
	{
		this->income = value;
	}
	 void show_tabl();
	
	virtual void editPerson() {};
	friend istream& operator >>(istream& in, Work_with_people& ob);
	friend ostream& operator <<(ostream& out, Work_with_people& ob);
	friend ifstream& operator >>(ifstream& in, Work_with_people& obj);
	friend ofstream& operator <<(ofstream& out, Work_with_people& obj);
};