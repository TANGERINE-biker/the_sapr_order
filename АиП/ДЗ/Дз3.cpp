#include <iostream>
#include <cmath>
using namespace std;


int main() {
	double Y, A, B;
	cin >> A >> B; //a = 4, b = 13.6

	Y = log10(sqrt(B) + tan(A));
	cout << Y; //0.685351
}
//------------------------
#include <iostream>
#include <math.h>
using namespace std;


int main() {
	float Y, A, B;
	scanf("%f%f", &A, &B); //a = 4, b = 13.6

	Y = log10(sqrt(B) + tan(A));
	printf("%f", Y); //0.685351
}
