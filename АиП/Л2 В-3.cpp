#include<iostream>
using namespace std;

int count_zero(int* arr, int  n);

int main()
{
	int a[1000], n, i;
	setlocale(0, "");
	cout << "������������ ������ �2\n" << "��������� ��������\n";
	cout << "������� ����� ������� � ������: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "�������� ������: \n";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << "\n���������� ��������� ��������� �������: " << count_zero(a, n) << endl;
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
