#include"Autorization_shablon.h"
#include"File.cpp"
#include"User.h"
#include"Admin.h"
#include"Inter.cpp"
template <typename T>  void Autorization_shablon<T>::menuAutorization()//меню авторизации
{
	int ch;
	bool flag = true;

	while (flag)
	{
		system("color F4");
		MyString login, password;
		system("cls");
		cout << "1 Вход" << endl<<endl;
		cout  << "2 Регистрация" << endl<<endl;
		cout  << "0 Выход" << endl<<endl;
		cout << ": ";
		cin >> ch;
		if (ch == 1 || ch == 2)
		{
			cout << "Введите логин" << endl;
			cin >> login;
			cout << "Введите пароль" << endl;
			 password.getPassWord(password);
		}
		switch (ch)
		{
		case 1:
		{
			
			Autorization_shablon<User> value;


			if (value.setQueue(login, password))//проверка логина и пароля пользователя
			{
				system("color 2");
        		cout <<setw(65)<< "Вы вошли в систему под логином:" << login<<endl;
				system("pause");
				Interface<User> value1;
				value1.menu();//вызов меню интерфейса
				break;

			}
			 
			Autorization_shablon<Admin> value2;//проверка логина и пароля администратор
			if (value2.setQueue(login, password))
			{
				system("color 2");
				cout << setw(65) << "Вы вошли в систему под логином:" << login << endl;
				system("pause");
				Interface<Admin> value3;
				value3.menuAdmin();// вызов меню администратора
				break;
			}

		  
		else
			{
			cout << "Неверный логин, пароль или ваша заявка еще не одобрена" << endl;
			system("color 4");
			system("pause");
			}
		}
	      break;
	
	case 2:
	{
		Autorization_shablon<User> value;
		Autorization_shablon<Admin> value1;
		if (value.isLoginNew(login))
		{ 
			if (value1.isLoginNew(login))//проверка на уникальность логина
			{
				Interface<User> value3;
				value3.menuAdd(login,password);
				system("color 1");
				cout << "Ожидаете одобрение администратором " << endl <<setw(35)<< "Досвидание" << endl;
				
			}
			else
			{
				cout << "Этот логин уже занят введите новый" << endl;
			}
		}
		else
		{
			cout << "Этот логин уже занят введите новый" << endl;
		}
		system("pause");
		
	}
	break;
		case 0:
		{
			flag = false;
			cout << setw(65) << "Досвидание" << endl;
		}
		
		break;
		default:
			cout << "Невеный ввод" << endl;
			
		}
	}
}
	
	


template <typename T>  bool Autorization_shablon<T>::isLoginNew(MyString login)//проверка уникальности логина
{
	T temp;
	File <T> obj(temp.getAddress());
	if (obj.isInputOpen())//проверка на открытие файла
	{
		while (!obj.isEof())//пока не закончится информация в файле
		{
			obj.read(temp);//чтение в объект
			if (temp.getLogin() == login )//проверка на совпадение логина
			{
					return false;
			}
		}
		return true;
	}
	return false;

}
	
template <typename T>  bool Autorization_shablon<T>::setQueue( MyString login, MyString password)//проверка совпадения логина и пароля
{
	T temp;
	File <T> obj(temp.getAddress());
	if (obj.isInputOpen())//проверка открытия файла
	{
		while (!obj.isEof())//пока не закончится информация в файле
		{
			obj.read(temp);//чтение в объект
			if (temp.getLogin() == login&&temp.getBlock()==1&& temp.getPassword() == password)//проверка на совпадение логина и пароля
			{
					return true;
			}
		}
		return false;
	}
	return false;

}
