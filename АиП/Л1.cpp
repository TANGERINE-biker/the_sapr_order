#include <iostream>

using namespace std;

int main()
{
	float C, F, K;
	setlocale(LC_ALL, "RU");
	cout << "������������ ������ �1\n" << "������� �������� �� �������?\n";
	cin >> C;
	cout << "�������� �� �������: " << C << "\n";
	K = C + 273.15;
	cout << "�� �������� ��� ����� " << K << "\n";
	F = K * 1.8 - 459.67;
	cout << "�� ���������� ��� ����� " << F << "\n";

	return 0;
}