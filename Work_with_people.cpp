#include"Work_with_people.h"
void Work_with_people:: show_tabl()//таблица
{
	dynamic_cast<Factory*>(this)->show_tabl();
	cout << "Доход копании" << setw(5) << "|";
}
istream& operator >>(istream& in, Work_with_people& ob)//операторы ввода/вывода
{
	in >> dynamic_cast<Factory&>(ob);
	cout << "Введите доход приносящий компании" << endl;
	cin >> ob.income;
	return in;
}

ostream& operator <<(ostream& out, Work_with_people& ob)
{
	out << dynamic_cast<Factory&>(ob);
	cout <<left << "|"<<setw(15) << ob.income<<"р.";
	return out;
}
ofstream& operator <<(ofstream& out, Work_with_people& obj)//операторы ввода/вывода (файл)
{
	out << dynamic_cast<Factory&>(obj);
	out << " " << obj.income;
	return out;
}

ifstream& operator >>(ifstream& in, Work_with_people& obj)
{
	in >> dynamic_cast<Factory&>(obj);
	in >> obj.income;
	return in;
}
