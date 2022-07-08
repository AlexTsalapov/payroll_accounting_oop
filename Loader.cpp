#include"Loader.h"
void Loader::show_tabl()
{
	cout << setw(65) << "" << "��������" << endl;
	cout << setw(69) << "" << "|" << endl;
	cout << setw(68) << "" << "\\|/" << endl;
	cout << setw(69) << "" << "V" << endl;
	dynamic_cast<Production_department*>(this)->show_tabl();
	cout  << setw(10) << "��� �������" << setw(9) << "|" << endl;
	cout << setfill('_') << setw(3) << "|" << setfill('_') << setw(42) << "|" << setfill('_') << setw(10) << "|" << setfill('_') << setw(30) << "|" << setfill('_')
		<< setw(11) << "|" << setfill('_') << setw(18) << "|" << setfill('_') << setw(20) << "|" << setfill(' ') << endl;
}

bool Loader::operator==(Loader& other)
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
	if (other.defect != 0 && other.defect != this->defect && this->defect != 0)
	{
		return false;
	}
	if (other.type_loader != 0 && other.type_loader != this->type_loader && this->type_loader != 0)
	{
		return false;
	}

	return true;
}

void Loader::searchPerson()
{
	cout << "1-���" << endl;
	cout << "2-��������" << endl;
	cout << "3-���������" << endl;
	cout << "4-������" << endl;
	cout << "5-������" << endl;
	cout << "6-������� �� ������� ��������" << endl;
}
void Loader::editPerson()
{
	int choice = 0,process=0;
	while (process == 0)
	{
		cout << "����� ���� �� ������ ���������?" << endl;
		cout << "1-���" << endl;
		cout << "2-��������" << endl;
		cout << "3-���������" << endl;
		cout << "4-������" << endl;
		cout << "5-������" << endl;
		cout << "6-������� �� ������� ��������" << endl;
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
			cout << "������� ���������� ��������" << endl;
			cin >> defect;
			break;
		case 6:

			cout << "������� ������� �� ������� �������� " << endl;
			cin >> type_loader;

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
			cout << "������� ���������� ��������" << endl;
			cin >> defect;
			cout << "������� ����� ������� ��������" << endl;
			cin >> type_loader;
			break;
		case 0:
			process = 1;
			break;
		default:
			cout << "�������� ����" << endl;

		}
	}
}
 istream& operator >>(istream& in, Loader& ob)
{
	 in>> dynamic_cast<Production_department&>(ob);
	 cout << "������� �� ����� ������� ��������" << endl;
	 cin >> ob.type_loader;
	 if (ob.defect < 5)
	 {
		 ob.premium = ob.sallary * 0.1;
		 if (ob.defect == 0)
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

 ostream& operator <<(ostream& out,  Loader & ob)
 {
	 out << dynamic_cast<Production_department&>(ob);
	 cout << "|" << setw(19) << ob.type_loader << "|" << internal << endl;
	 cout << setfill('_') << setw(3) << "|" << setfill('_') << setw(42) << "|" << setfill('_') << setw(10) << "|" << setfill('_') << setw(30) << "|" << setfill('_')
		 << setw(11) << "|" << setfill('_') << setw(18) << "|" << setfill('_') << setw(20) << "|" << setfill(' ') << endl;
	 return out;
 }
 ofstream& operator <<(ofstream& out, Loader& obj)
 {
	 out << dynamic_cast<Production_department&>(obj);
	 out << " " << obj.type_loader << std::endl;
	 return out;
 }

 ifstream& operator >>(ifstream& in, Loader& obj)
 {
	 in >> dynamic_cast<Production_department&>(obj);
	 in >> obj.type_loader;
	 return in;
 }
