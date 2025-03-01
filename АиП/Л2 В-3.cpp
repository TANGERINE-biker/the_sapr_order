#include<iostream>
using namespace std;

int count_zero(int* arr, int  n);

int main()
{
	int a[1000], n, i;
	setlocale(0, "");
	cout << "Лабораторная работа №2\n" << "Обработка массивов\n";
	cout << "Введите длину массива и массив: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Исходный массив: \n";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << "\nКоличество ненулевых элементов массива: " << count_zero(a, n) << endl;
}
int count_zero(int* arr, int n)
{
	int i, counter = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			counter += 1;
		}
	}
	return counter;
}
