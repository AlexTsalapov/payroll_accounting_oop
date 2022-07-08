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
	std::cout << " " << std::setfill('-') << std::setw(50) << "��������" << std::setw(41) << "-" << std::setfill(' ') << std::endl << std::endl;
	std::cout << std::left << std::setw(8) << "  �" << std::setw(15) << "��������" << std::setw(16) << "��� �������" << std::setw(14) << "���������" << std::setw(14)
		<< "����� ������" << std::setw(32) << "��������� ������" << std::endl << std::internal << std::endl;
}

void Notebook::showEditMenu()
{
	std::cout << "  7 - �� ������� ������ (�� �����������)" << std::endl << "  8 - �� ������� ������ (�� ��������)" << std::endl;
	std::cout << "  9 - �� ��������� ������ (�� �����������)" << std::endl << "  10 - �� ��������� ������ (�� ��������)" << std::endl;
}

void Notebook::editItem()
{
	int your_choice = 0;
	bool process = true;

	while (process)
	{
		std::cout << " �������� ��������, ������� ������ ���������:" << std::endl << "  1 - �������� ����������" << std::endl << "  2 - ��� ������� ����������" << std::endl
			<< "  3 - ��������� ����������" << std::endl << "  4 - ����� ������" << std::endl << "  5 - ��������� ������" << std::endl << "  0 - ������" << std::endl << " ��� �����: ";
		std::cin >> your_choice;
		std::cout << std::endl;

		switch (your_choice)
		{
		case 1:
			std::cout << " ������� �������� ����������: ";
			std::cin >> name;
			std::cout << std::endl;
			break;
		case 2:
			std::cout << " ������� ��� ������� ����������: ";
			std::cin >> year;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl << " ������� ��������� ����������: ";
			std::cin >> cost;
			std::cout << std::endl;
			break;
		case 4:
			std::cout << " ������� ����� ������ ����������: ";
			std::cin >> working_hours;
			std::cout << std::endl;
			break;
		case 5:
			std::cout << " ������� ��������� ������: ";
			std::cin >> screen_diagonal;
			std::cout << std::endl;
			break;
		case 0:
			std::cout << " �������������� ���������." << std::endl << std::endl;
			process = false;
			break;
		default:
			system("color 4");
			std::cout << "  ������: ������������ ����." << std::endl << std::endl << " ";
			system("pause");
			system("cls");
			system("color 2");
			break;
		}
	}
}

void Notebook::showSearch()
{
	std::cout << " ��������� ��������� ��� ������: " << std::endl;

	if (name == "") {}
	else
	{
		std::cout << "  ��������: " << name << std::endl;
	}
	if (year != 0)
	{
		std::cout << "  ��� �������: " << year << std::endl;
	}
	if (cost != 0)
	{
		std::cout << "  ���������: " << cost << std::endl;
	}
	if (working_hours != 0)
	{
		std::cout << "  ����� ������:" << working_hours << std::endl;
	}
	if (screen_diagonal == 0) {}
	else
	{
		std::cout << "  ��������� ������: " << screen_diagonal << std::endl;
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
	std::cout << std::endl << " ������� ��������� ������ ��������: ";
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