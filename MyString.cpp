#include "MyString.h"
#include <conio.h>
#include<algorithm>

ofstream& operator<<(ofstream& out, MyString& s)
{
	for (int i = 0; i < s.size; i++)
	{
		if (s.str[i] == ' ')
		{
			s.str[i] = '_';
		}
	}
	out << s.str;
	return out;
}
ifstream& operator>>(ifstream& in, MyString& s)
{
	s.str = new char[256];
	in >> s.str;
	s.size = strlen(s.str);

	for (int i = 0; i < s.size; i++)
	{
		if (s.str[i] == '_')
		{
			s.str[i] = ' ';
		}
	}
	return in;
}

ostream& operator<<(ostream& stream, MyString& s)
{
	stream << s.str;
	return stream;
}
void MyString::getPassWord(MyString &s)
{
	char input[256];
	int temp, len = 0;
	while (true && (len < 255))
	{
		temp = _getch();

		if (temp == 13)
		{

			break;
		}
		
		if (temp == 8)
		{
			if (len != 0)
			{
				cout << (char)8 << ' ' << char(8);
				len--;
				input[len] = '\0';
			}
		}
		else if(temp!=8)
		{
			cout << "*";
			input[len] = char(temp);
			len++;
		}
	}

	cout << endl;

	input[len] = '\0';

	if (s.str != NULL)
	{
		memset(s.str, 0, s.size);
	}

	s.str = new char[len];
	s.size = len;

	s.copy(input);
}

istream& operator>>(istream& stream, MyString& s)
{
	char input[256];
	int temp, len = 0,k=0;
	while (true && (len < 255))
	{
		temp = _getch();

		if (temp == 13)
		{
			break;
		}
		if (temp == 8)
		{
			if (len != 0)
			{
				cout << (char)8 << ' ' << char(8);
				len--;
				input[len] = '\0';

			}
		}
		else
		{
			cout << (char)temp;
			input[len] = char(temp);
			len++;
		}
	}

	cout << endl;

	input[len] = '\0';
	

	if (s.str != NULL)
	{
		memset(s.str, 0, s.size);
	}

	s.str = new char[len];
	s.size = len;

	s.copy(input);

	return stream;
}


MyString& MyString::operator=( const MyString& other)
{
	if (size != 0)
	{
		str = nullptr;
		size = 0;
		delete[] str;
	}
	if (other.size == 0)
	{
		str = nullptr;
		size = 0;
	}

	else
	{
		size = strlen(other.str);
		str = new char[size + 1];

		for (int i = 0; i < size + 1; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[size] = '\0';
		size++;
	}
	return *this;
}

MyString& MyString::operator=(const char s[])
{
	if (size != 0)
	{
		str = nullptr;
		size = 0;
		delete[] str;
	}
	if (s==NULL|| s=="")
	{
		str = nullptr;
		size = 0;
	}
	else {
		size = strlen(s);
		str = new char[size + 1];

		for (int i = 0; i < size; i++)
		{
			str[i] = s[i];
		}

		str[size] = '\0';
		size++;
	}
	return *this;
}


void MyString::operator++()
{
	for (int j = size - 2; j > 0; j--)
	{
		swap(str[j], str[j - 1]);
	}

}

void MyString::operator--()
{
	for (int j = 0; j < size - 2; j++)
	{
		swap(str[j], str[j + 1]);
	}
}

void MyString::operator+=(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = size - 2; j > 0; j--)
		{
			swap(str[j], str[j - 1]);
		}
	}
}

void MyString::operator-=(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < size - 2; j++)
		{
			swap(str[j], str[j + 1]);
		}
	}
}


MyString MyString::operator+(const MyString& other)
{
	MyString new_str;
	new_str.size = size + other.size - 1;

	char* temp = new char[new_str.size];

	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < other.size; i++)
	{
		temp[i + size - 1] = other.str[i];
	}

	new_str.str = temp;
	return new_str;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* new_str = new char[size + other.size];

	for (int i = 0; i < size - 1; i++)
	{
		new_str[i] = str[i];
	}
	for (int i = 0; i < other.size; i++)
	{
		new_str[i + size - 1] = other.str[i];
	}

	delete[] this->str;
	this->str = new_str;
	this->size = size + other.size - 1;
	return *this;
}


bool MyString::operator==(const MyString& other)
{
	if (this->size != other.size)
	{
		return false;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (tolower(this->str[i]) != tolower(other.str[i]))
		{
			return false;
		}
	}

	return true;
}

bool MyString::operator!=(const MyString& other)
{
	if (this->str == NULL)
	{
		return false;
	}
	
	if (this->size != other.size)
	{
		return true;
	}
	
	for (int i = 0; i < this->size; i++)
	{
		if (tolower(this->str[i]) != tolower(other.str[i]))
		{
			return true;
		}
	}
	return false;
}
bool MyString::operator>(const MyString& other)
{
	for (int i = 0; i < this->size; i++)
	{
		if (tolower(this->str[i]) > tolower(other.str[i]))
		{
			return true;
		}
		if (tolower(this->str[i]) < tolower(other.str[i]))
		{
			return false;
		}
	}
	return false;
}

bool MyString::operator<(const MyString& other)
{
	for (int i = 0; i < this->size; i++)
	{
		if (tolower(this->str[i]) < tolower(other.str[i]))
		{
			return true;
		}
		if (tolower(this->str[i]) > tolower(other.str[i]))
		{
			return false;
		}
	}
	return false;
}


char& MyString::operator[](int i)
{
	return str[i];
}


void MyString::copy(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		str[i] = s[i];
	}
	str[size ] = '\0';
}