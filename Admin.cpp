#include "Admin.h"
void Admin::show_tabl()
{
	cout << setw(47) << "" << "�������������" << endl;
	cout << setw(51) << "" << "|" << endl;
	cout << setw(50) << "" << "\\|/" << endl;
	cout << setw(51) << "" << "V" << endl;
	cout << setfill('_') << setw(100) << "_" << setfill(' ') << endl;
	cout << setw(15) << "�����" << setw(30) << "|" << setw(16) << "������" << setw(16) << "|" << setw(12) << "�������" << setw(12) << "|" << endl;
	cout << setfill('_') << setw(45) << "|" << setfill('_') << setw(32) << "|" << setfill('_') << setw(24) << "|" << setfill('_') << setfill(' ') << endl;
}

void Admin::editPerson()
{
	int choice, process = 0;
	while (process == 0)
	{
		cout << "����� ���� �� ������ ���������?" << endl;
		cout << "1-�����" << endl;
		cout << "2-�������" << endl;
		cout << "3-������( ����� �� ���� ����������)" << endl;
		cout << "4-���" << endl;
		cout << "0-�����" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << " ������� �����" << endl;
			cin >> login;
			break;

		case 2:
			cout << " �������" << endl;
			cin >> surname;
			break;

		case 3:
			cout << " ������� ������" << endl;
			cin >> password;
			break;

		case 4:
			cout << " ������� �����" << endl;
			cin >> login;
			cout << " ������� ������" << endl;
			cin >> password;
			cout << " �������" << endl;
			cin >> surname;
			break;
		case 0:
			process = 1;
			break;
		default:
			cout << "�������� ����" << endl;
		}
	}
}
	istream& operator >>(istream & in, Admin & ob)
	{
		in >> dynamic_cast<Autorization&>(ob);
		cout << "������� ���� �������" << endl;
		ob.surname;
		return in;
	}

	ostream& operator <<(ostream & out, Admin & ob)
	{
		out << dynamic_cast<Autorization&>(ob);
		cout << left << setw(31) << ob.password << "|" << setw(23) << ob.surname << "|" << internal << endl;
		cout << setfill('_') << setw(3) << "|" << setfill('_') << setw(42) << "|" << setfill('_') << setw(32) << "|" << setfill('_') << setw(24) << "|" << setfill(' ') << endl;
		return out;

	}
	ofstream& operator <<(ofstream & out, Admin & obj)
	{
		out << dynamic_cast<Autorization&>(obj);
		out << " " << obj.surname << std::endl;
		return out;
	}

	ifstream& operator >>(ifstream & in, Admin & obj)
	{
		in >> dynamic_cast<Autorization&>(obj);
		in >> obj.surname;
		return in;
	}


