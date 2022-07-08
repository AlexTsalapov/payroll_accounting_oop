#include"Marketolog.h"
void Marketolog::show_tabl()
{
	cout << setw(65) << "" << "Маркетологи" << endl;
	cout << setw(69) << "" << "|" << endl;
	cout << setw(68) << "" << "\\|/" << endl;
	cout << setw(69) << "" << "V" << endl;
	dynamic_cast<Work_with_people*>(this)->show_tabl();
	cout << setw(1) << "Продажи (кол-во)" << setw(4) << "|" << endl;
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
	cout << "Какое поле вы хотите настроить?" << endl;
	cout << "1-Имя" << endl;
	cout << "2-Зарплату" << endl;
	cout << "3-Должность" << endl;
	cout << "4-Премию" << endl;
	cout << "5-Доход" << endl;
	cout << "6-Рост доходности" << endl;
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
		cout << "Введите доход приносящий компании" << endl;
		cin >> income;
		break;
	case 6:

		cout << "Количество проданной техники" << endl;
		cin >> number;
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
		cout << "Введите какой доход приносит " << endl;
		cin >> income;
		cout << "Введите количество проданной техники" << endl;
		cin >> number;
		break;
	case 0:
		process = 1;
		break;
	default:
		cout << "Неверный ввод" << endl;
	}
	}
}void Marketolog::searchPerson()
{
	cout << "1-Имя" << endl;
	cout << "2-Зарплату" << endl;
	cout << "3-Должность" << endl;
	cout << "4-Премию" << endl;
	cout << "5-Доход" << endl;
	cout << "6-Рост доходности" << endl;
}
	
istream& operator >>(istream& in, Marketolog& ob)
{
	in >> dynamic_cast<Work_with_people&>(ob);
	cout << "Введите количество проданной продукции" << endl;
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

