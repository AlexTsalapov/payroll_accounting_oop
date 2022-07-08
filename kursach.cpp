#include"Inter.cpp"
#include"Autorization_shablon.cpp"
int main()
{
    system("chcp 1251");
    system("cls");
    setlocale(LC_ALL, "");
    Autorization_shablon<int> ob;
    ob.menuAutorization();
    return 0;
}
