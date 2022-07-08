#pragma once
#include"Production_department.h"
class Paint_department :public Production_department
{
protected:
	MyString color;
public:
	Paint_department()
	{
		this->color = "";
		address = "Paint_department.txt";
	}
	Paint_department(MyString name1, double sallary1, MyString position1, double premium1, int defect1, MyString color1) :Production_department(name1, sallary1, position1, premium1, defect1)
	{
		color = color1;
	}
	MyString getAddress()
	{
		return this->address;
	}
	
	void set6(MyString value)
	{
		this->color = value;
	}
	MyString get6()
	{
		return this->color;
	}
	 void show_tabl();
	virtual void editPerson();
	void searchPerson();
	bool operator==(Paint_department& other);
	 friend istream& operator >>(istream& in, Paint_department& ob);
	 friend ostream& operator <<(ostream& out, Paint_department& ob);
	 friend ifstream& operator >>(ifstream& in,Paint_department& obj);
	 friend ofstream& operator <<(ofstream& out, Paint_department& obj);
};
