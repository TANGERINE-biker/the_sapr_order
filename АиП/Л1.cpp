#include <iostream>

using namespace std;

int main()
{
	float C, F, K;
	setlocale(LC_ALL, "RU");
	cout << "Лабораторная работа №1\n" << "Сколько градусов по Цельсию?\n";
	cin >> C;
	cout << "Градусов по Цельсию: " << C << "\n";
	K = C + 273.15;
	cout << "По Кельвину это равно " << K << "\n";
	F = K * 1.8 - 459.67;
	cout << "По Фаренгейту это равно " << F << "\n";

	return 0;
}