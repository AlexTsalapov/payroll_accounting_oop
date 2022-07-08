#include "Factory.h"

void Factory::show_tabl()
{
	cout << setfill('_') << setw(133) << "_" << setfill(' ') << endl;
	cout << "№ |" << setw(15) << "ФИО" << setw(27) 
		<< "|" << setw(4) << "Зарплата" << setw(2) << "|" << setw(15) 
		<< "Должность" << setw(15) << "|" << setw(1) << "Премия" << setw(5) << "|" << setw(1);
}
istream& operator >>(istream& in, Factory& ob)
{
	cout << " Введите имя" << endl;
	cin >> ob.name;
	cout << "Введите зарплату" << endl;
	cin >> ob.sallary;
	cout << "Введите должность" << endl;
	cin >> ob.position;
	return in;
}

ostream& operator <<(ostream& out, Factory& ob)
{
	out << left << setw(41) << ob.name;
	out << "|" << setw(7);
		out<< ob.sallary << "р."
		<< "|" << setw(29) << ob.position  << "|" << setw(8) << ob.premium<<"р." << internal;
	return out;
}
ofstream& operator <<(ofstream& out, Factory& obj)
{
	out << " ";
	out<< obj.name;
	out << " " << obj.sallary << " ";
	out<<obj.position<<" "<<obj.premium ;
	return out;
}

ifstream& operator >>(ifstream& in, Factory& obj)
{
	in >> obj.name >> obj.sallary;
	in>> obj.position >> obj.premium;
	return in;
}