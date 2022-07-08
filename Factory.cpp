#include "Factory.h"

void Factory::show_tabl()
{
	cout << setfill('_') << setw(133) << "_" << setfill(' ') << endl;
	cout << "� |" << setw(15) << "���" << setw(27) 
		<< "|" << setw(4) << "��������" << setw(2) << "|" << setw(15) 
		<< "���������" << setw(15) << "|" << setw(1) << "������" << setw(5) << "|" << setw(1);
}
istream& operator >>(istream& in, Factory& ob)
{
	cout << " ������� ���" << endl;
	cin >> ob.name;
	cout << "������� ��������" << endl;
	cin >> ob.sallary;
	cout << "������� ���������" << endl;
	cin >> ob.position;
	return in;
}

ostream& operator <<(ostream& out, Factory& ob)
{
	out << left << setw(41) << ob.name;
	out << "|" << setw(7);
		out<< ob.sallary << "�."
		<< "|" << setw(29) << ob.position  << "|" << setw(8) << ob.premium<<"�." << internal;
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