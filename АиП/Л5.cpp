#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct usage_data {
	string lname, name, ptrnmc, birth_y, ph_num, adress, polis, bld_gp, rh_factor, diag;

	void p_write(ofstream& file) {
		file
			<< lname << "\t"
			<< name << "\t"
			<< ptrnmc << "\t"
			<< birth_y << "\t"
			<< ph_num << "\t"
			<< adress << "\t"
			<< polis << "\t"
			<< bld_gp << "\t"
			<< rh_factor << "\t"
			<< diag << "\n";
	}

	void p_print() {
		cout
			<< "\n"
			<< "Data: " << "\n"
			<< "Surname " << lname << "\n"
			<< "Name: " << name << "\n"
			<< "Patronymic: " << ptrnmc << "\n"
			<< "Year: " << birth_y << "\n"
			<< "Phone number: " << ph_num << "\n"
			<< "Adress: " << adress << "\n"
			<< "Polis No: " << polis << "\n"
			<< "Blood group: " << bld_gp << "\n"
			<< "RH-factor: " << rh_factor << "\n"
			<< "Diagnosis: " << diag << "\n\n";
	}
};


struct Node {
	usage_data val;
	Node* next;

	Node(usage_data val) {
		this->val = val;
		this->next = NULL;
	}
};

usage_data assign(usage_data x);
struct list {						//односвязный список
	Node* first, * last;

	list() : first(nullptr), last(nullptr) {}

	void push_back(usage_data data) { // добавляет в конец списка
		Node* node = new Node(data);
		if (first == NULL) first = node;
		if (last != NULL) last->next = node;
		last = node;
	}

	void push_front(usage_data data) { // добавляет в начало списка
		Node* node = new Node(data);
		node->next = first;
		first = node;
		if (last = NULL) last = node;
	}

	void pop_back() {       //  удаляет последний объект
		if (last == NULL) return;
		if (first == last) {
			delete last;
			first = last = NULL;
			return;
		}
		Node* node = first;
		for (; node->next != last; node = node->next);
		node->next = NULL;
		delete last;
		last = node;
	}

	void pop_front() {		// удаляет первый объект
		if (first == NULL) return;
		if (first == last) {
			delete last;
			first = last = NULL;
			return;
		}
		Node* node = first;
		first = node->next;
		delete node;
	}

	void print() {
		Node* node = first;
		for (; node != NULL; node = node->next) {
			node->val.p_print();

		}
	}

	void write(ofstream& file) {
		Node* node = first;
		for (; node != NULL; node = node->next)
			node->val.p_write(file);
	}

	void scan(string sname) {		//поиск по фамилии
		Node* node = first;
		for (; node != NULL; node = node->next) {
			if (node->val.lname == sname) node->val.p_print();
		}
	}

	void sort() {
		bool swapped = true;
		Node* node, * last = NULL;

		if (first == NULL)
			return;

		while (swapped) {
			swapped = false;
			node = first;
			while (node->next != last) {
				if (node->val.polis > node->next->val.polis) {
					swap(node->val, node->next->val);
					swapped = true;
				}
				node = node->next;
			}
			last = node;

		}
	}

	void creator(int amount) {
		for (int i = 0; i < amount; i++) {
			usage_data p;
			p = assign(p);
			push_back(p);

		}
	}
};

usage_data assign(usage_data x) {
	getline(cin, x.lname, ' ');
	getline(cin, x.name, ' ');
	getline(cin, x.ptrnmc, ' ');
	getline(cin, x.birth_y, ' ');
	getline(cin, x.ph_num, ' ');
	getline(cin, x.adress, ' ');
	getline(cin, x.polis, ' ');
	getline(cin, x.bld_gp, ' ');
	getline(cin, x.rh_factor, ' ');
	getline(cin, x.diag);
	return x;
}

//----------------------------------------------------

int main() {
	list lst;

	int n1;
	string n, s;

	cout << "Enter ";
	getline(cin, n);
	n1 = stoi(n);

	lst.creator(n1);

	ofstream f;
	f.open("patients.txt");

	lst.write(f);

	cout << "\n";
	cin >> s;
	lst.scan(s);

	lst.sort();
	lst.print();

	f.close();
}

