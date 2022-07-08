#include"User.h"
void User::show_tabl()
{
	cout << setw(35) << "" << "������������" << endl;
	cout << setw(39) << "" << "|" << endl;
	cout << setw(38) << "" << "\\|/" << endl;
	cout << setw(39) << "" << "V" << endl;
	cout << setfill('_') << setw(71) << "_" << setfill(' ') << endl;
	cout<< "� |" << setw(15)  << "�����" << setw(27) << "|" << setw(4) << "������(0-����,1-��������)" << setw(2) << "|" << endl;
	cout << setfill('_') << setw(3) << "|" << setfill('_') << setw(42) << "|" << setfill('_') << setw(27) << "|" << setfill('_')  << setfill(' ')<< endl;
}

void User::editPerson()
{
	int choice, process = 0;
	while (process == 0)
	{
		cout << "����� ���� �� ������ ���������?" << endl;
		cout << "1-�����" << endl;
		cout << "2-����������/������������" << endl;
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
			cout << " 1-��������������,0-�������������" << endl;
			cin >> block;
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
			cout << " 1-��������������,2-�������������" << endl;
			cin >> block;
			break;
		case 0:
			process = 1;
			break;
		default:
			cout << "�������� ����" << endl;
		}
	}
}

bool User::operator==(User& other)
{

	if (other.login != "" && other.login != this->login && this->login != "")
	{
		return false;
	}
	if (other.block != 0 && other.block != this->block && this->block != 0)
	{
		return false;
	}
	return true;
}


istream& operator >>(istream& in, User& ob)
{
	in >> dynamic_cast<Autorization&>(ob);
	ob.block=0;
	return in;
}

ostream& operator <<(ostream& out, User& ob)
{
	out << dynamic_cast<Autorization&>(ob);
	cout  << left<<setw(26) << ob.block << "|" << internal << endl;
	cout  << setfill('_') << setw(3) << "|" << setfill('_') << setw(42) << "|" << setfill('_') << setw(27) << "|"<<setfill(' ') << endl;
	return out;
}
ofstream& operator <<(ofstream& out,User& obj)
{
	out << dynamic_cast<Autorization&>(obj);
	out << " " << obj.block << std::endl;
	return out;
}

ifstream& operator >>(ifstream& in,User& obj)
{
	in >> dynamic_cast<Autorization&>(obj);
	in >> obj.block;
	return in;
}

