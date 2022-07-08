#pragma once
#include"Work_with_people.h"
class Economist:public Work_with_people
{
protected:
	double height_income;
public:
	Economist()
	{
		this->height_income = 0.0;
		address = "Economist.txt";
	}
	Economist(MyString name1, double sallary1, MyString position1, double premium1, double income1, double height_income1) :Work_with_people(name1, sallary1, position1, premium1, income1)
	{
		height_income=height_income1;
	}
		MyString getAddress()
		{
			return this->address;
		}
	
	double get6()
	{
		return this->height_income;
	}
	void set6(int value)
	{
		this->height_income = value;
	}
	 void show_tabl() ;
	
	
	void searchPerson();
	virtual void editPerson() ;
	bool operator==(Economist& other);
  friend istream& operator >>(istream& in, Economist& ob);
  friend ostream& operator <<(ostream& out, Economist& ob);
  friend ifstream& operator >>(ifstream& in, Economist& obj);
  friend ofstream& operator <<(ofstream& out, Economist& obj);
	
		
	
};
