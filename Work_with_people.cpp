#include"Work_with_people.h"
void Work_with_people:: show_tabl()//�������
{
	dynamic_cast<Factory*>(this)->show_tabl();
	cout << "����� �������" << setw(5) << "|";
}
istream& operator >>(istream& in, Work_with_people& ob)//��������� �����/������
{
	in >> dynamic_cast<Factory&>(ob);
	cout << "������� ����� ���������� ��������" << endl;
	cin >> ob.income;
	return in;
}

ostream& operator <<(ostream& out, Work_with_people& ob)
{
	out << dynamic_cast<Factory&>(ob);
	cout <<left << "|"<<setw(15) << ob.income<<"�.";
	return out;
}
ofstream& operator <<(ofstream& out, Work_with_people& obj)//��������� �����/������ (����)
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
