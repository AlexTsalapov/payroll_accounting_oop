#include"Production_department.h"
void Production_department::show_tabl()//таблица
{
	dynamic_cast<Factory*>(this)->show_tabl();
	cout<< "Дефект" << setw(12) << "|";
}

istream& operator >>(istream& in, Production_department& ob)//операторы ввода вывода
{
	in >> dynamic_cast<Factory&>(ob);
	cout << "Введите количество дефектов" << endl;
	cin >> ob.defect;
	return in;
}

ostream& operator <<(ostream& out, Production_department& ob)
{
	out << dynamic_cast<Factory&>(ob);
	out << left << "|" << setw(17) << ob.defect;
	return out;
}
ofstream& operator <<(ofstream& out, Production_department& obj)
{
	out << dynamic_cast<Factory&>(obj);
	out << " " << obj.defect ;
	return out;
}

ifstream& operator >>(ifstream& in, Production_department& obj)
{
	in >> dynamic_cast<Factory&>(obj);
	in >> obj.defect;
	return in;
}

