#pragma once
#include "Factory.h"
class Production_department:public Factory
{
protected:
	int defect;
	public:
		Production_department()
		{
			this->defect = 0;
			this->address = "Production_department.txt";
		}
		Production_department(MyString name1, double sallary1, MyString position1, double premium1, int defect1) :Factory(name1, sallary1, position1, premium1)
		{
			defect= defect1;
		}
		void set5(int value)
		{
			this->defect = value;
		}
		int get5()
		{
			return this->defect;
		}
		void show_tabl() ;
		friend istream& operator >>(istream& in, Production_department& ob);
		friend ostream& operator <<(ostream& out, Production_department& ob);
		friend ifstream& operator >>(ifstream& in, Production_department& ob);
		friend ofstream& operator <<(ofstream& out, Production_department& ob);
};
