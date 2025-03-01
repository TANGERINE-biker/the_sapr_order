#include <iostream>
#include <cmath>

using namespace std;


int sign(float a) {
	if (a < 0) return -1;
	if (a = 0) return 0;
	if (a > 0) return 1;
}

int main() {
	float z, x, y;
	cin >> x >> y;
	z = (sign(x) + sign(y)) * sign(x + y);
	cout << z;
}

