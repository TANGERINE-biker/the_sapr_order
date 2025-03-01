// написать функцию, которая в одномерном м целых чисел находит сумму заданного количества элем массива (блока), записать сумму в каждого блока в новый массив 


#include <iostream>
using namespace std;

int counter(int n, int* a1, int* a2);
int main()
{
	int n; // длина массива должна быть кратна n
	int a1[20] = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4,4,4,4,5,5,5,5 };
	int a2[20];
	cin >> n;

	counter(n, a1, a2);

	for (int k = 0; k < (20 / n); k++) cout << a2[k] << ' ';

}
int counter(int n, int* a1, int* a2) {
	int i = 0;
	while (i < 20) {
		for (int k = 0; k < (20 / n); k++) {
			int sum = 0;
			for (int j = 0; j < n; j++) sum += a1[i + j];
			i += n;
			a2[k] = sum;
		}

	}
	return *a2;
}
