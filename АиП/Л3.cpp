//Лабораторная работа №3, вариант 5
#include <iostream>
#include <Windows.h>
using namespace std;

char replace(char str[100]);

int main()
{
    int const n = 29;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i;
    char str[n + 1];
    gets_s(str, n);
    cout << str << endl;
    replace(str);
    cout << str << endl;
}

char replace(char str[100])
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'ь')
            str[i] = 'ъ';
        if (str[i] == 'Ь')
            str[i] = 'Ъ';
    }
    return 0;
}
