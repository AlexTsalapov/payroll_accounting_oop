#include "Notebook.h"

Notebook::Notebook()
{
	screen_diagonal = 0;
	FILE_WITH_DATA = "Notebooks.txt";
}

Notebook::Notebook(MyString name, double cost, int year, int working_hours, double screen_diagonal) : Portable(name, cost, year, working_hours)
{
	this->screen_diagonal = screen_diagonal;
}


void Notebook::setScreenDiagonal(double number)
{
	screen_diagonal = number;
}

double Notebook::getFifthVariable()
{
	return screen_diagonal;
}


void Notebook::showHeader()
{
	std::cout << " " << std::setfill('-') << std::setw(50) << "Ноутбуки" << std::setw(41) << "-" << std::setfill(' ') << std::endl << std::endl;
	std::cout << std::left << std::setw(8) << "  №" << std::setw(15) << "Название" << std::setw(16) << "Год выпуска" << std::setw(14) << "Стоимость" << std::setw(14)
		<< "Время работы" << std::setw(32) << "Диагональ экрана" << std::endl << std::internal << std::endl;
}

void Notebook::showEditMenu()
{
	std::cout << "  7 - По времени работы (по возрастанию)" << std::endl << "  8 - По времени работы (по убыванию)" << std::endl;
	std::cout << "  9 - По диагонали экрана (по возрастанию)" << std::endl << "  10 - По диагонали экрана (по убыванию)" << std::endl;
}

void Notebook::editItem()
{
	int your_choice = 0;
	bool process = true;

	while (process)
	{
		std::cout << " Выберите параметр, который хотите настроить:" << std::endl << "  1 - Название устройства" << std::endl << "  2 - Год выпуска устройства" << std::endl
			<< "  3 - Стоимость устройства" << std::endl << "  4 - Время работы" << std::endl << "  5 - Диагональ экрана" << std::endl << "  0 - Отмена" << std::endl << " Ваш выбор: ";
		std::cin >> your_choice;
		std::cout << std::endl;

		switch (your_choice)
		{
		case 1:
			std::cout << " Введите название устройства: ";
			std::cin >> name;
			std::cout << std::endl;
			break;
		case 2:
			std::cout << " Введите год выпуска устройства: ";
			std::cin >> year;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl << " Введите стоимость устройства: ";
			std::cin >> cost;
			std::cout << std::endl;
			break;
		case 4:
			std::cout << " Введите время работы устройства: ";
			std::cin >> working_hours;
			std::cout << std::endl;
			break;
		case 5:
			std::cout << " Введите диагональ экрана: ";
			std::cin >> screen_diagonal;
			std::cout << std::endl;
			break;
		case 0:
			std::cout << " Редактирование завершено." << std::endl << std::endl;
			process = false;
			break;
		default:
			system("color 4");
			std::cout << "  Ошибка: некорректный ввод." << std::endl << std::endl << " ";
			system("pause");
			system("cls");
			system("color 2");
			break;
		}
	}
}

void Notebook::showSearch()
{
	std::cout << " Выбранные параметры для поиска: " << std::endl;

	if (name == "") {}
	else
	{
		std::cout << "  Название: " << name << std::endl;
	}
	if (year != 0)
	{
		std::cout << "  Год выпуска: " << year << std::endl;
	}
	if (cost != 0)
	{
		std::cout << "  Стоимость: " << cost << std::endl;
	}
	if (working_hours != 0)
	{
		std::cout << "  Время работы:" << working_hours << std::endl;
	}
	if (screen_diagonal == 0) {}
	else
	{
		std::cout << "  Диагональ экрана: " << screen_diagonal << std::endl;
	}
}


bool Notebook::operator==(const Notebook& other)
{
	MyString temp = other.name;

	if (!name.isTextInStr(temp))
	{
		return false;
	}
	if ((other.year != 0) && (year != other.year))
	{
		return false;
	}
	if ((other.cost != 0) && (cost != other.cost))
	{
		return false;
	}
	if ((other.working_hours != 0) && (other.working_hours != working_hours))
	{
		return false;
	}
	if ((other.screen_diagonal != 0) && (other.screen_diagonal != screen_diagonal))
	{
		return false;
	}

	return true;
}


std::istream& operator >>(std::istream& input, Notebook& obj)
{
	input >> dynamic_cast<Portable&>(obj);
	std::cout << std::endl << " Введите диагональ экрана ноутбука: ";
	std::cin >> obj.screen_diagonal;
	std::cout << std::endl;

	return input;
}

std::ostream& operator <<(std::ostream& output, Notebook& obj)
{
	std::cout << std::left << std::setw(15) << obj.name << std::setw(16) << obj.year << std::setw(14) << obj.cost << std::setw(14) << obj.working_hours << obj.screen_diagonal << std::endl << std::internal;
	return output;
}


std::ofstream& operator <<(std::ofstream& out, Notebook& obj)
{
	out << dynamic_cast<Portable&>(obj);
	out << " " << obj.screen_diagonal << std::endl;
	return out;
}

std::ifstream& operator >>(std::ifstream& in, Notebook& obj)
{
	in >> dynamic_cast<Portable&>(obj);
	in >> obj.screen_diagonal;
	return in;
}