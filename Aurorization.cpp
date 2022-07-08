#include"Autorization.h"
istream& operator >>(istream& in, Autorization& ob)
{
	cout << "¬ведите логин" << endl;
	cin >> ob.login;
	cout << "¬ведите пароль" << endl;
	cin >> ob.password;
	return in;
}

ostream& operator <<(ostream& out, Autorization& ob)
{
	cout << setw(2) << left << setw(41) << ob.login << "|"  << internal ;
	return out;
}
ofstream& operator <<(ofstream& out, Autorization& obj)
{
	out << " ";
	out << obj.login;
	out << " ";
	out<< obj.password;
	return out;
}

ifstream& operator >>(ifstream& in, Autorization& obj)
{  
	in >> obj.login >> obj.password ;
	return in;
}

