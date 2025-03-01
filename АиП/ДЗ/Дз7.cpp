#include <iostream>
#include <string>

using namespace std;

struct person {
	string name;
	int age;
};


int main() {
	person m[30];
	int n = 30;
	for (int i = 0; i < n; i++) {
		string s, ex;
		cout << " 1 - to add, 0 - exit\n";
		cin >> s;
		if (s == "1") {
			cout << "Enter name and age\n";
			cin >> m[i].name >> m[i].age;
			for (int j = 0; j <= i; j++) cout << "Name " << m[j].name << "  Age " << m[j].age << "\n";
		}
		if (s == "0") break;
	}
}
