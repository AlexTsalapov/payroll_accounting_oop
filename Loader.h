#pragma once
#include"Production_department.h"
class Loader :public Production_department
{
protected:
	MyString type_loader;
public:
	Loader()
	{
		this->type_loader = "";
		address = "Loader.txt";
	}
	Loader(MyString name1, double sallary1, MyString position1, double premium1, int defect1, MyString type_loader1) :Production_department(name1, sallary1, position1, premium1, defect1)
	{
		type_loader=type_loader1;
	}
	
	MyString getAddress()
	{
		return this->address;
	}
	void set6(MyString value)
	{
		this->type_loader = value;
	}
	MyString get6()
	{
		return this->type_loader;
	}
	 void show_tabl() ;
	
	
	void searchPerson();
	bool operator==(Loader& other);
	virtual void editPerson();
	friend ifstream& operator >>(ifstream& in, Loader& obj);
	friend ofstream& operator <<(ofstream& out, Loader& obj);
    friend istream& operator >>(istream& in, Loader& ob);
	 friend ostream& operator <<(ostream& out,  Loader & ob);
};