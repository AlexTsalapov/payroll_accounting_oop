#pragma once

#include<conio.h>
#include<fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
class MyString
{
private:
	int size;
	char* str;

public:
	MyString()
	{
		str = nullptr;
		size = 1;
	}
	MyString(const char s[])
	{
		if (s != NULL)
		{
			size = strlen(s);
			str = new char[size + 1];
			for (int i = 0; i < size; i++)
			{
				str[i] = s[i];
			}
			str[size] = '\0';
		}
		else
		{
			size = 0;
			str = nullptr;
		}
	}
	MyString(const MyString& other)
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
		else {
			size = strlen(other.str);
			str = new char[size + 1];
			for (int i = 0; i < size; i++)
			{
				str[i] = other.str[i];
			}
			str[size] = '\0';
		}
	}

	char* getStr()
	{
		return str;
	}

	~MyString()
	{
		
			size = 0;
			str = nullptr;
			delete[] str;
		
	}
	void getPassWord(MyString &s);
	friend ofstream& operator<<(std::ofstream& out, MyString& s);
	friend ifstream& operator>>(std::ifstream& in, MyString& s);
	friend ostream& operator<<(std::ostream& stream, MyString& s);
	friend istream& operator>>(std::istream& stream, MyString& s);
	MyString& operator=(const  MyString& other);
	MyString& operator=(const char s[]);

	void operator++();
	void operator--();
	void operator+=(int n);
	void operator-=(int n);

	MyString operator+(const MyString& other);
	MyString& operator+=(const MyString& other);

	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	bool operator>(const MyString& other);
	bool operator<(const MyString& other);

	char& operator[](int i);

	void copy(char s[]);
};
