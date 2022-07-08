# pragma once
#include "inter.h"
#include "File.cpp"

template<class T>
void Interface<T>::funAdmin()
{
	T value;
	File <T> ob(value.getAddress());//чтение из файла
	Queue<T> st;
	readOutFile(st);
	int ch=0;
	bool flag = true;
		while (flag)
		{
			system("cls");
			cout << "1 Просмотр" << endl;
			cout << "2 Редактирование" << endl;
			cout << "3 Удаление" << endl;
			cout << "4 Поиск" << endl;
			cout << "0 Выход" << endl;
			cout << ": ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				if (st.getSizeQueue() >= 0) {
					st.getItem(st.getSizeQueue()).show_tabl();//вывод таблицы
					st.show();//вывод содержание очереди
				}
				else
				{
					cout << "Ничего нет" << endl;
				}
				system("pause");
				break;

			case 2:
				system("cls");
				int ch;
				if (st.getSizeQueue() >= 0) {
					st.getItem(st.getSizeQueue()).show_tabl();
					st.show();
					cout << "Номер редактируемой записи:" << endl;
					cout << ": ";
					cin >> ch;
					value.show_tabl();
					st.showItem(ch - 1);//вывод элемента
					st.editItem(ch - 1);//редактирование элемента
				}
				else
				{
					cout << "Ничего нет" << endl;
				}
			
			break;
			case 3:
			{
				system("cls");
				cout << "Количество элементов в очереди:" << st.getSizeQueue() + 1 << endl;
				cout << "1-удаления с начала,2-удаления с конца" << endl;
				cin >> ch;
				switch (ch)
				{
				case 1:
				{
					cout << "Введите номер удаляемого элемента " << endl;
					cin >> ch;
					st.deleteItemBeggin(ch);//улаление элемента сначала
				}

				break;
				case 2:
				{
					cout << "Введите номер удаляемого элемента " << endl;
					cin >> ch;
					st.deleteItemEnd(ch - 1);//удаление элемента с конца
				}
				break;
				}
				break;
			case 4:
			{
				T value1;
				int k, counter = 0, temp;
				if (st.getSizeQueue() >= 0)
				{
					st.getItem(0).show_tabl();
					st.show();
					value1.editPerson();
					st.getItem(0).show_tabl();
					File <T> ob1("search_user.txt");
					if (ob1.isOutputOpen())
					{
						
						for (int j = 0; j < st.getSizeQueue() + 1; j++)
						{
							if (st.getItem(j) == value1)//проверка на совпадение полей
							{
								ob1.write(st.getItem(j));
								st.showItem(j);//вывод элемента на экран
							}

						}
						cout << endl << endl << "Результаты поиска вы можете посмотреть в файле search_user.txt" << endl;
					}
					system("pause");
				}
				else
				{
					cout << "Ничего нет" << endl;
				}
			}
			}
			break;

			case 0:
				flag = false;
				break;
			}
		}
		writeInFile(st);
	}



template<class T>
void Interface<T>::menuAdd(MyString log, MyString pass)
{
	bool proccess = true;
	Queue<T> st;
	T value;
	File <T> ob(value.getAddress());
	readOutFile(st);
		value.setLogin(log);
		value.setPassword(pass);
		value.setBlock(0);
		st.addItemEnd(value);//добавление элемента в конец
		writeInFile(st);
	}


template <class T> void Interface<T>::editAdmin()//редактирование администратора
{
	MyString log, pass;
	cout << "Введите логин" << endl;
	cin >> log;
	cout << "Введите пароль" << endl;
	cin >> pass;
	bool proccess = true;
	int counter = 0,choice=-1;
	Queue<T> st;
	readOutFile(st);
	for (int i = 0; i < st.getSizeQueue()+1; i++)
	{
		if (st.getItem(i).getLogin() == log && st.getItem(i).getPassword() == pass)
		{
			choice = counter;
			break;
		}
	}
		if (choice != -1)
		{
			st.getItem(choice).show_tabl();//вывод таблицы
			st.showItem(choice);//вывод элемента на экран
			st.editItem(choice);//редактирование элемента
			st.getItem(choice).show_tabl();
			st.showItem(choice);
			system("pause");
			
			
			writeInFile(st);
		}
			
}
template<class T>
void Interface<T>::fun()
{
	T value;
	Queue<T> st;
	readOutFile(st);
		system("pause");
		system("color 6");
		MyString temp_string;

		int ch;
		bool flag = true;
		while (flag)
		{
			system("cls");
			cout << "1 Просмотр" << endl;
			cout << "2 Добавление" << endl;
			cout << "3 Удаление" << endl;
			cout << "4 Поиск" << endl;
			cout << "5 Редактирование" << endl;
			cout << "6 Сортировка" << endl;
			cout << "0  Выход" << endl;
			cout << ": ";

			cin >> ch;
			switch (ch)
			{
			case 1:
				if (st.getSizeQueue() >= 0) {
					st.getItem(st.getSizeQueue()).show_tabl();
				}
				else
				{
					cout << "Ничего нет" << endl;
				}
				st.show();
				system("pause");
				break;
			case 2:
			{
				system("cls");
				int ch;
				cout << "1-добавить в начале очереди,2- в конец очереди" << endl;
				cout << ": ";
				cin >> ch;
				cin >> value;
				switch (ch)
				{
				case 1:
				{

					st.addItemBegin(value);
				}
				break;

				case 2:
				{
					st.addItemEnd(value);
				}
				break;
				}
			}

			break;
			case 3:
			{
				system("cls");
				cout << "Количество элементов в очереди:" << st.getSizeQueue() + 1 << endl;
				cout << "1-удаления с начала,2-удаления с конца" << endl;
				cin >> ch;
				switch (ch)
				{
				case 1:
				{
					cout << "Введите номер удаляемого элемента " << endl;
					cin >> ch;
					st.deleteItemBeggin(ch);
				}

				break;
				case 2:
				{
					cout << "Введите номер удаляемого элемента " << endl;
					cin >> ch;
					st.deleteItemEnd(ch - 1);
				}
				break;
				}
				break;
			case 4:
			{

				int k, counter = 0, temp;
				if (st.getSizeQueue() >= 0)
				{
					T temp1;
					int counter = 0;
					st.getItem(0).show_tabl();
					st.show();
					temp1.editPerson();
					st.getItem(0).show_tabl();
					File <T> ob1("search_worker.txt");
					if (ob1.isOutputOpen())
					{
						for (int j = 0; j < st.getSizeQueue() + 1; j++)
						{
							if (st.getItem(j) == temp1)
							{
								ob1.write(st.getItem(j));
								st.showItem(j);
								counter++;
							}

						}
					}
					cout << endl << endl << "Результаты поиска вы можете посмотреть в файле search_worker.txt" << endl;
					if (counter == 0)
					{
						cout << "Ничего не найдено" << endl;
					}
					system("pause");
				}
				else
				{
					cout << "Ничего нет" << endl;
				}


			}
			}
			break;
			case 5:
			{

				cout << "Номер редактируемой записи:" << endl;
				cout << ": ";
				cin >> ch;
				st.getItem(ch - 1).show_tabl();
				st.showItem(ch - 1);
				st.editItem(ch - 1);


			}
			break;
			case 6:
			{
				sort(st);//сортировка 
			}
				break;

			case 0:
				flag = false;
				break;
			}

		}
		writeInFile(st);
	}

	template<class T>
	void Interface <T> ::readOutFile(Queue<T>& st)
	{
		T value;
		File<T> ob(value.getAddress());//
		if (ob.isInputOpen())
		{
			while (!ob.isEof())
			{

				ob.read(value);
				if (value.get1() != "")
				{
					st.addItemEnd(value);
				}

			}
		}
		else
		{
			cout << "Указанного файла не существует" << endl;
		}
		
	}
	template<class T>
	void Interface <T> ::writeInFile(Queue<T>& st)
	{
		T value;
		File<T> ob(value.getAddress());//получение адреса
		int counter = 0;
		if (ob.isOutputOpen())
		{
			while (st.getSizeQueue()+1 != counter)
			{
				ob.write(st.getItem(counter));
				counter++;
			}
		}
		else
		{
			cout << "Указанного файла не существует" << endl;
		}

	}
template<class T>
void Interface<T>::sort(Queue<T>&st)
{
	cout << "По какому полю вы хотите отсортировать " << endl;

	if (st.getSizeQueue() >= 0)
	{
		int ch;
		int  k = st.getSizeQueue();
		int z = 0;
		st.getItem(k).searchPerson();//вывод шапки сортировки

		cin >> ch;
		cout << "1-от меньшего к большему и от а до я, 2-от большего к меньшему и от я до а" << endl;
		cin >> z;
		for (int i = 0; i < k; i++)
		{
			for (int j = i + 1; j < k + 1; j++)//вложенный цикл для сортировки
			{
				switch (ch)
				{
				case 1:
				{
					if (z == 1)
					{

						if (st.getItem(i).getName() > st.getItem(j).getName())
						{

							st.swap2Item(i, j);
						}
					}
					if (z == 2)
					{
						if (st.getItem(i).getName() < st.getItem(j).getName())
						{

							st.swap2Item(i, j);
						}

					}
				}
				break;
				case 2:
				{
					if (z == 1)
					{
						if (st.getItem(i).getSallary() > st.getItem(j).getSallary())
						{

							st.swap2Item(i, j);
						}
					}
					if (z == 2)
					{
						if (st.getItem(i).getSallary() < st.getItem(j).getSallary())
						{

							st.swap2Item(i, j);
						}
					}

				}
				break;
				case 3:
				{
					if (z == 1)
					{
						if (st.getItem(i).getPosition() > st.getItem(j).getPosition())
						{

							st.swap2Item(i, j);
						}
					}
					if (z == 2)
					{
						if (st.getItem(i).getPosition() < st.getItem(j).getPosition())
						{

							st.swap2Item(i, j);
						}
					}
				}
				break;
				case 4:
				{
					if (z == 1)
					{
						if (st.getItem(i).getPremium() > st.getItem(j).getPremium())
						{

							st.swap2Item(i, j);
						}
					}
					if (z == 2)
					{
						if (st.getItem(i).getPremium() < st.getItem(j).getPremium())
						{

							st.swap2Item(i, j);
						}
					}
				}
				break;
				case 5:
				{
					if (z == 1)
					{
						if (st.getItem(i).get5() > st.getItem(j).get5())
						{

							st.swap2Item(i, j);
						}
					}
					if (z == 2)
					{
						if (st.getItem(i).get5() < st.getItem(j).get5())
						{

							st.swap2Item(i, j);
						}
					}
				}
				break;
				case 6:
				{
					if (z == 1)
					{
						if (st.getItem(i).get6() > st.getItem(j).get6())
						{

							st.swap2Item(i, j);
						}
					}
					if (z == 2)
					{
						if (st.getItem(i).get6() < st.getItem(j).get6())
						{

							st.swap2Item(i, j);
						}
					}
				}
				break;
				}
			}
		}

	}
	else
	{
		cout << "Ничего нет" << endl;
	}

}
template<class T>
void Interface<T>::menuAdmin()
{
	system("color  6");
	int ch;
	bool flag = true;

	while (flag)
	{
		system("cls");
		cout << "1 Работа с пользователями" << endl;
		cout << "2 Работа с выплатой зарплат" << endl;
		cout << "3 Редактироване своего поля" << endl;
		cout << "0  Выход" << endl;
		cout << ": ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{

			Interface<User> obj1;
			obj1.funAdmin();

		}
		break;
		case 2:
		{
			Interface<int> obj1;
			obj1.menu();
		}

		break;
		case 3:
		{
			Interface<Admin> obj2;
			obj2.editAdmin();
		}

		break;
		
		case 0:
			flag = false;
			break;
		}
	}
}
template<class T>
void Interface<T>::menu()
{
	system("color  3");
	int ch;
	bool flag = true;

	while (flag)
	{
		system("cls");
		cout << "1 Экономисты" << endl;
		cout << "2 Маркетологи" << endl;
		cout << "3 Грузчики" << endl;
		cout << "4 Маляры" << endl;
		cout << "5 Сборщики " << endl;
		cout << "6 Работа с паролем и логином(для пользователей)" << endl;
		cout << "0  Выход" << endl;
		cout << ": ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			Interface<Economist> obj1;
			obj1.fun();
			
		}
		break;
		case 2:
		{
				Interface<Marketolog> obj1;
				obj1.fun();
		}
		break;
		case 3:
		{
				Interface<Loader> obj1;
				obj1.fun();
		}
		
		break;
		case 4:
		{
				Interface<Paint_department> obj1;
				obj1.fun();
		}
		break;
		case 5:
		{
			Interface<Assembly_department> obj1;
			obj1.fun();	
		}
		
		break;
		case 6:
		{
			Interface<User> obj2;
			obj2.editAdmin();
		}

		break;
		case 0:
			flag = false;
			break;
		}

	}
}


