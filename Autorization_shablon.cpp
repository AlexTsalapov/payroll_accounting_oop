#include"Autorization_shablon.h"
#include"File.cpp"
#include"User.h"
#include"Admin.h"
#include"Inter.cpp"
template <typename T>  void Autorization_shablon<T>::menuAutorization()//���� �����������
{
	int ch;
	bool flag = true;

	while (flag)
	{
		system("color F4");
		MyString login, password;
		system("cls");
		cout << "1 ����" << endl<<endl;
		cout  << "2 �����������" << endl<<endl;
		cout  << "0 �����" << endl<<endl;
		cout << ": ";
		cin >> ch;
		if (ch == 1 || ch == 2)
		{
			cout << "������� �����" << endl;
			cin >> login;
			cout << "������� ������" << endl;
			 password.getPassWord(password);
		}
		switch (ch)
		{
		case 1:
		{
			
			Autorization_shablon<User> value;


			if (value.setQueue(login, password))//�������� ������ � ������ ������������
			{
				system("color 2");
        		cout <<setw(65)<< "�� ����� � ������� ��� �������:" << login<<endl;
				system("pause");
				Interface<User> value1;
				value1.menu();//����� ���� ����������
				break;

			}
			 
			Autorization_shablon<Admin> value2;//�������� ������ � ������ �������������
			if (value2.setQueue(login, password))
			{
				system("color 2");
				cout << setw(65) << "�� ����� � ������� ��� �������:" << login << endl;
				system("pause");
				Interface<Admin> value3;
				value3.menuAdmin();// ����� ���� ��������������
				break;
			}

		  
		else
			{
			cout << "�������� �����, ������ ��� ���� ������ ��� �� ��������" << endl;
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
			if (value1.isLoginNew(login))//�������� �� ������������ ������
			{
				Interface<User> value3;
				value3.menuAdd(login,password);
				system("color 1");
				cout << "�������� ��������� ��������������� " << endl <<setw(35)<< "����������" << endl;
				
			}
			else
			{
				cout << "���� ����� ��� ����� ������� �����" << endl;
			}
		}
		else
		{
			cout << "���� ����� ��� ����� ������� �����" << endl;
		}
		system("pause");
		
	}
	break;
		case 0:
		{
			flag = false;
			cout << setw(65) << "����������" << endl;
		}
		
		break;
		default:
			cout << "������� ����" << endl;
			
		}
	}
}
	
	


template <typename T>  bool Autorization_shablon<T>::isLoginNew(MyString login)//�������� ������������ ������
{
	T temp;
	File <T> obj(temp.getAddress());
	if (obj.isInputOpen())//�������� �� �������� �����
	{
		while (!obj.isEof())//���� �� ���������� ���������� � �����
		{
			obj.read(temp);//������ � ������
			if (temp.getLogin() == login )//�������� �� ���������� ������
			{
					return false;
			}
		}
		return true;
	}
	return false;

}
	
template <typename T>  bool Autorization_shablon<T>::setQueue( MyString login, MyString password)//�������� ���������� ������ � ������
{
	T temp;
	File <T> obj(temp.getAddress());
	if (obj.isInputOpen())//�������� �������� �����
	{
		while (!obj.isEof())//���� �� ���������� ���������� � �����
		{
			obj.read(temp);//������ � ������
			if (temp.getLogin() == login&&temp.getBlock()==1&& temp.getPassword() == password)//�������� �� ���������� ������ � ������
			{
					return true;
			}
		}
		return false;
	}
	return false;

}
