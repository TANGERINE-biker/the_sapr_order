#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print() {
	cout
		<< "\n1. List of students\n"
		<< "2. List of students who has only 5\n"
		<< "3. List of students who has at least one 3\n"
		<< "4. List of students who has at least one 2\n"
		<< "Choose number: ";
}

void fio(ifstream& f) {
	while (!f.eof()) {
		string s, ex;
		getline(f, s, ',');
		getline(f, ex);
		cout << s << "\n";
	}
}

void five(ifstream& f) {
	while (!f.eof()) {
		string s, a1, a2, a3, a4, a5;
		getline(f, s, ',');
		getline(f, a1, ' ');
		getline(f, a2, ' ');
		getline(f, a3, ' ');
		getline(f, a4, ' ');
		getline(f, a5);
		if (a1 == "5" && a2 == "5" && a3 == "5" && a4 == "5" && a5 == "5")
			cout << s << "\n";
	}
}
void morethanonethree(ifstream& f) {
	while (!f.eof()) {
		string s, a1, a2, a3, a4, a5;
		getline(f, s, ',');
		getline(f, a1, ' ');
		getline(f, a2, ' ');
		getline(f, a3, ' ');
		getline(f, a4, ' ');
		getline(f, a5);
		if (a1 == "3" || a2 == "3" || a3 == "3" || a4 == "3" || a5 == "3")
			cout << s << "\n";
	}
}
void sometwos(ifstream& f) {
	while (!f.eof()) {
		int n = 0;
		string s, a1, a2, a3, a4, a5;
		getline(f, s, ',');
		getline(f, a1, ' ');
		getline(f, a2, ' ');
		getline(f, a3, ' ');
		getline(f, a4, ' ');
		getline(f, a5);
		if (a1 == "2") {
			n++;
			if (a2 == "2") {
				n++;
				if (a3 == "2") {
					n++;
					if (a4 == "2") {
						n++;
						if (a5 == "2")n++;
					}
				}

			}
		}
		if (n == 1)cout << s << "\n";
	}
}





int main() {
	ifstream f;
	int k;
	f.open("test.txt");

	for (int i = 0; i < 4; i++) {
		print();
		f.seekg(0);
		cin >> k;
		cout << "\n";
		if (k == 1) fio(f);
		if (k == 2) five(f);
		if (k == 3) morethanonethree(f);
		if (k == 4) sometwos(f);
		if (k < 1 || k > 4) cout << "ERROR";
	}
}
