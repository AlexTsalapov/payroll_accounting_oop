#include"Marketolog.h"
void Marketolog::show_tabl()
{
	cout << setw(65) << "" << "�����������" << endl;
	cout << setw(69) << "" << "|" << endl;
	cout << setw(68) << "" << "\\|/" << endl;
	cout << setw(69) << "" << "V" << endl;
	dynamic_cast<Work_with_people*>(this)->show_tabl();
	cout << setw(1) << "������� (���-��)" << setw(4) << "|" << endl;
	cout << setfill('_') << setw(3) << "|" << setfill('_') << setw(42) << "|" << setfill('_') << setw(10) << "|" << setfill('_') << setw(30) << "|" << setfill('_')
		<< setw(11) << "|" << setfill('_') << setw(18) << "|" << setfill('_') << setw(20) << "|" << setfill(' ') << endl;

}


bool Marketolog::operator==(Marketolog& other)
{

	if (other.name != "" && other.name != this->name && this->name != "")
	{
		return false;
	}
	if (other.sallary != 0 && other.sallary != this->sallary && this->sallary != 0)
	{
		return false;
	}
	if (other.position != 0 && other.position != this->position && this->position != 0)
	{
		return false;
	}
	if (other.premium != 0 && other.premium != this->premium && this->premium != 0)
	{
		return false;
	}
	if (other.income != 0 && other.income != this->income && this->income != 0)
	{
		return false;
	}
	if (other.number != 0 && other.number != this->number && this->number != 0)
	{
		return false;
	}
	return true;
}
void Marketolog::editPerson()
{
	int  choice ,process=0;
	while(process==0)
	{ 
	cout << "����� ���� �� ������ ���������?" << endl;
	cout << "1-���" << endl;
	cout << "2-��������" << endl;
	cout << "3-���������" << endl;
	cout << "4-������" << endl;
	cout << "5-�����" << endl;
	cout << "6-���� ����������" << endl;
	cout << "7-���" << endl;
	cout << "0-�����" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << " ������� ���" << endl;
		cin >> name;

		break;
	case 2:
		cout << " ������� ��������" << endl;
		cin >> sallary;
		break;
	case 3:
		cout << " ������� ���������" << endl;
		cin >> position;
		break;
	case 4:
		cout << " ������� ������" << endl;
		cin >> premium;
		break;

	case 5:
		cout << "������� ����� ���������� ��������" << endl;
		cin >> income;
		break;
	case 6:

		cout << "���������� ��������� �������" << endl;
		cin >> number;
		break;
	case 7:
		cout << " ������� ���" << endl;
		cin >> name;
		cout << "������� ��������" << endl;
		cin >> sallary;
		cout << "������� ���������" << endl;
		cin >> position;
		cout << "������� ������" << endl;
		cin >> premium;
		cout << "������� ����� ����� �������� " << endl;
		cin >> income;
		cout << "������� ���������� ��������� �������" << endl;
		cin >> number;
		break;
	case 0:
		process = 1;
		break;
	default:
		cout << "�������� ����" << endl;
	}
	}
}void Marketolog::searchPerson()
{
	cout << "1-���" << endl;
	cout << "2-��������" << endl;
	cout << "3-���������" << endl;
	cout << "4-������" << endl;
	cout << "5-�����" << endl;
	cout << "6-���� ����������" << endl;
}
	
istream& operator >>(istream& in, Marketolog& ob)
{
	in >> dynamic_cast<Work_with_people&>(ob);
	cout << "������� ���������� ��������� ���������" << endl;
	cin >> ob.number;
	if (ob.income > 10000)
	{
		ob.premium = ob.sallary * 0.1;
		if (ob.income > 20000)
		{
			ob.premium = ob.sallary * 0.2;
		}

	}
	else
	{
		ob.premium = 0;
	}
	return in;
}

ostream& operator <<(ostream& out, Marketolog& ob)
{
	out<< dynamic_cast<Work_with_people&>(ob);
	cout << "|" << setw(19) << ob.number << "|" << internal << endl;
	cout << setfill('_') << setw(3) << "|" << setfill('_') << setw(42) << "|" << setfill('_') << setw(10) << "|" << setfill('_') << setw(30) << "|" << setfill('_')
		<< setw(11) << "|" << setfill('_') << setw(18) << "|" << setfill('_') << setw(20) << "|" << setfill(' ') << endl;
	return out;
}
ofstream& operator <<(ofstream& out,Marketolog& obj)
{
	out << dynamic_cast<Work_with_people&>(obj);
	out << " " << obj.number << std::endl;
	return out;
}

ifstream& operator >>(ifstream& in, Marketolog& obj)
{
	in >> dynamic_cast<Work_with_people&>(obj);
	in >> obj.number;
	return in;
}

