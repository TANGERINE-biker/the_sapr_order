#include<iostream>
using namespace std;

int main()
{
	int m = 5, n = 6;
	int** X = new int* [m];
	for (int i = 0; i < m; i++)
		X[i] = new int[n]; // �������� ���������� ������ � ���. ������

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			X[i][j] = rand() % 150;

		} // ���������� ������� ���������� ������� �� 0 �� 100

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << X[i][j] << "\t";
		}
		cout << endl;
	} // ������������� ����� �������

	cout << endl;

	int min = 1000, mi, mj;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (X[i][j] < min)
			{
				min = X[i][j];
				mi = i;
				mj = j;
			}
		}

	}

	for (int i = 0; i < m; i++)
		X[i][mj] = 0;
	for (int j = 0; j < n; j++)
		X[mi][j] = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << X[i][j] << "\t";
		}
		cout << endl;
	} // �������� ����� �������
}