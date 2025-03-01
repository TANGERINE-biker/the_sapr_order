#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char replace(string str, ofstream& f);

int main()
{
    ifstream fin;
    fin.open("input.txt", ios::in);
    ofstream fout;
    fout.open("output.txt"); // ios::out по умолчанию
    string a;
    while (!fin.eof())
    {
        getline(fin, a);
        replace(a, fout);

    }
    fin.close();
    fout.close();
    return 0;
}

char replace(string str, ofstream& f) // передача файла в качестве аргумента функции через ссылку &
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a') str[i] = 'b';
        if (str[i] == 'A') str[i] = 'B';

    }
    f << str;
    f << endl;
    return 0;
}
