#include<iostream>
using namespace std;

void average(int* arr);
int max(int* arr);
int min(int* arr);

int main()
{
	int a[10] = { 6,20,13,4,5,46,7,8,9,10 }, n = 10, i;
	setlocale(0, "");
	cout << "Лабораторная работа №2\n";
	cout << "Исходный массив: ";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << "Среднее арифметическое элементов не учитывая максимальный и минимальный жлемент:" << endl;
	average(a);
}

void average(int* arr)
{
	int i, n = 10; float summ = 0;
	for (i = 0; i < n; i++)
	{
		summ += arr[i];
	}
	cout << ((summ - max(arr) - min(arr)) / (n - 2));

}
int max(int* arr)
{
	int i, n = 10, maxa = -10000;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > maxa)
		{
			maxa = arr[i];
		}
	}
	return maxa;
}
int min(int* arr)
{
	int i, n = 10, mina = 100000;
	for (i = 0; i < n; i++)
	{
		if (arr[i] < mina)
		{
			mina = arr[i];
		}
	}
	return mina;
}