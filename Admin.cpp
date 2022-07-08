#include "Admin.h"
void Admin::show_tabl()
{
	cout << setw(47) << "" << "Администратор" << endl;
	cout << setw(51) << "" << "|" << endl;
	cout << setw(50) << "" << "\\|/" << endl;
	cout << setw(51) << "" << "V" << endl;
	cout << setfill('_') << setw(100) << "_" << setfill(' ') << endl;
	cout << setw(15) << "Логин" << setw(30) << "|" << setw(16) << "Пароль" << setw(16) << "|" << setw(12) << "Фамилия" << setw(12) << "|" << endl;
	cout << setfill('_') << setw(45) << "|" << setfill('_') << setw(32) << "|" << setfill('_') << setw(24) << "|" << setfill('_') << setfill(' ') << endl;
}

void Admin::editPerson()
{
	int choice, process = 0;
	while (process == 0)
	{
		cout << "Какое поле вы хотите настроить?" << endl;
		cout << "1-Логин" << endl;
		cout << "2-Фамилию" << endl;
		cout << "3-Пароль( поиск по полю невозможен)" << endl;
		cout << "4-Все" << endl;
		cout << "0-Выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << " Введите логин" << endl;
			cin >> login;
			break;

		case 2:
			cout << " Фамилия" << endl;
			cin >> surname;
			break;

		case 3:
			cout << " Введите пароль" << endl;
			cin >> password;
			break;

		case 4:
			cout << " Введите логин" << endl;
			cin >> login;
			cout << " Введите пароль" << endl;
			cin >> password;
			cout << " Фамилия" << endl;
			cin >> surname;
			break;
		case 0:
			process = 1;
			break;
		default:
			cout << "Неверный ввод" << endl;
		}
	}
}
	istream& operator >>(istream & in, Admin & ob)
	{
		in >> dynamic_cast<Autorization&>(ob);
		cout << "Введите свою фамилмю" << endl;
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


