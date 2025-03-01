#include <iostream>
#include <cmath>

using namespace std;


int sum(int* m, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (m[i] > 0) sum += m[i];
	}
	return sum;
}
int amount(int* m, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (m[i] > 0) k++;
	}
	return k;
}

int main() {
	int s1 = 0, k1 = 0, s2 = 0, k2 = 0;
	float z;
	int a[10] = { 1,1,-1,-1,2,2,2,-2,-3,-3 };
	int b[15] = { 4,4,-4,4,-4,5,-5,5,5,-5, 7,7,-7,7,7 };

	z = (sum(a, 10) + sum(b, 15)) / (amount(a, 10) * amount(b, 15));
	cout << z;
}

