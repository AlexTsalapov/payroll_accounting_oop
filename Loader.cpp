#include"Loader.h"
void Loader::show_tabl()
{
	cout << setw(65) << "" << "Грузчики" << endl;
	cout << setw(69) << "" << "|" << endl;
	cout << setw(68) << "" << "\\|/" << endl;
	cout << setw(69) << "" << "V" << endl;
	dynamic_cast<Production_department*>(this)->show_tabl();
	cout  << setw(10) << "Тип техники" << setw(9) << "|" << endl;
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
	cout << "1-Имя" << endl;
	cout << "2-Зарплату" << endl;
	cout << "3-Должность" << endl;
	cout << "4-Премию" << endl;
	cout << "5-Дефект" << endl;
	cout << "6-Техника на которой работает" << endl;
}
void Loader::editPerson()
{
	int choice = 0,process=0;
	while (process == 0)
	{
		cout << "Какое поле вы хотите настроить?" << endl;
		cout << "1-Имя" << endl;
		cout << "2-Зарплату" << endl;
		cout << "3-Должность" << endl;
		cout << "4-Премию" << endl;
		cout << "5-Дефект" << endl;
		cout << "6-Техника на которой работает" << endl;
		cout << "7-Все" << endl;
		cout << "0-Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << " Введите имя" << endl;
			cin >> name;

			break;
		case 2:
			cout << " Введите зарплату" << endl;
			cin >> sallary;
			break;
		case 3:
			cout << " Введите должность" << endl;
			cin >> position;
			break;
		case 4:
			cout << " Введите премию" << endl;
			cin >> premium;
			break;

		case 5:
			cout << "Введите количество дефектов" << endl;
			cin >> defect;
			break;
		case 6:

			cout << "Введите техника на которой работает " << endl;
			cin >> type_loader;

			break;
		case 7:
			cout << " Введите имя" << endl;
			cin >> name;
			cout << "Введите зарплату" << endl;
			cin >> sallary;
			cout << "Введите должность" << endl;
			cin >> position;
			cout << "Введите премию" << endl;
			cin >> premium;
			cout << "Введите количество дефектов" << endl;
			cin >> defect;
			cout << "Введите какую технику собирает" << endl;
			cin >> type_loader;
			break;
		case 0:
			process = 1;
			break;
		default:
			cout << "Неверный ввод" << endl;

		}
	}
}
 istream& operator >>(istream& in, Loader& ob)
{
	 in>> dynamic_cast<Production_department&>(ob);
	 cout << "Введите на какой технике работает" << endl;
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
