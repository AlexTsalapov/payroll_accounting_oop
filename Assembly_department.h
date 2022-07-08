#pragma once
#include "Production_department.h"
class Assembly_department:public Production_department
{
	MyString type;
public:
	Assembly_department()
	{
		this->type = "";
		address = "Assembly_department.txt";
	}
	Assembly_department(MyString name1, double sallary1, MyString position1, double premium1, int defect1,MyString type1) :Production_department( name1,  sallary1,  position1,  premium1, defect1)
	{
		type = type1;
	}
	/*Assembly_department(const Assembly_department& ob)
	{
		this->name = ob.name;
		this->sallary = ob.sallary;
		this->position = ob.position;
		this->premium = ob.premium;
		this->defect = ob.defect;
		this->type = ob.type;
	}*/
	MyString getAddress()
	{
		return this->address;
	}
	void set6(MyString value)
	{
		this->type = value;
	}
	MyString get6()
	{
		return this->type;
	}
	virtual void show_tabl() ;
	
	
	virtual void editPerson();
	void searchPerson();
    bool operator==(Assembly_department& other);
    friend istream& operator >>(istream& in, Assembly_department& ob);
	 friend ostream& operator <<(ostream& out, Assembly_department& ob);
	 friend ifstream& operator >>(ifstream& in, Assembly_department& obj);
	 friend ofstream& operator <<(ofstream& out, Assembly_department& obj);
};
