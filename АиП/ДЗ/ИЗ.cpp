#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct usage_data {
	string ph_num, id, d, m, y, extra, name, srv;
	bool flag = false;

	void ud_print() {
		cout
			<< name << "\t"
			<< ph_num << "\t"
			<< id << "\t"
			<< flag << "\t"
			<< srv << "\n";
	}

	void ud_write(fstream& file) {
		file
			<< name << "\t"
			<< ph_num << "\t"
			<< srv << "\t"
			<< d << "."
			<< m << "."
			<< y << "\n";

	}
};

struct services { string srv, id, extra; };
struct client { string name, ph_num, extra; };
struct date { string d, m, y; };


struct Node {
	usage_data val;
	Node* next;

	Node(usage_data val) {
		this->val = val;
		this->next = NULL;
	}
};
struct list {
	Node* first, * last;

	list() : first(nullptr), last(nullptr) {}

	void push_back(usage_data data) {
		Node* node = new Node(data);
		if (first == NULL) first = node;
		if (last != NULL) last->next = node;
		last = node;
	}

	void pop_back() {
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

	void srv_filter(ifstream& services_info, string srv1, string srv2) {
		Node* node = first;
		for (; node != NULL; node = node->next) {
			services_info.seekg(0);
			while (!services_info.eof()) {
				services serv;
				getline(services_info, serv.srv, ',');
				getline(services_info, serv.id, ',');
				getline(services_info, serv.extra);
				if (((serv.srv == srv1) || (serv.srv == srv2)) && (serv.id == node->val.id)) {
					node->val.flag = true;
					node->val.srv = serv.srv;
				}

			}
			//node->val.ud_print();

		}


	}

	void date_filter(date dt1, date dt2) {
		Node* node = first;
		for (; node != NULL; node = node->next) {
			if (node->val.flag == true) {
				int y = stoi(node->val.y);
				int m = stoi(node->val.m);
				int d = stoi(node->val.d);
				int y1 = stoi(dt1.y);
				int m1 = stoi(dt1.m);
				int d1 = stoi(dt1.d);
				int y2 = stoi(dt2.y);
				int m2 = stoi(dt2.m);
				int d2 = stoi(dt2.d);
				if (y1 < y && y < y2) node->val.flag = true;
				if (y == y1) {
					if (m > m1) node->val.flag = true;
					if (m = m1) {
						if (d > d1) node->val.flag = true;
						else node->val.flag = false;
					}
					else node->val.flag = false;
				}
				if (y == y2) {
					if (m < m2) node->val.flag = true;
					if (m = m2) {
						if (d < d2) node->val.flag = true;
						else node->val.flag = false;
					}
					else node->val.flag = false;
				}
				if (y < y1 || y2 < y) node->val.flag = false;
			}
			//node->val.ud_print();
		}
	}

	void num_filter(ifstream& clients_info) {
		Node* node = first;
		client clnt;
		for (; node != NULL; node = node->next) {
			clients_info.seekg(0);
			if (node->val.flag == true) {
				while (!clients_info.eof()) {
					getline(clients_info, clnt.name, ',');
					getline(clients_info, clnt.ph_num, ',');
					getline(clients_info, clnt.extra);
					if (clnt.ph_num == node->val.ph_num) {
						node->val.flag = true;
						node->val.name = clnt.name;
					}
				}
			}
		}
	}

	void write(fstream& file) {
		Node* node = first;
		for (; node != NULL; node = node->next)
			if (node->val.flag == true)
				node->val.ud_write(file);
	}

	void print() {
		Node* node = first;
		for (; node != NULL; node = node->next)
			if (node->val.flag == true)
				node->val.ud_print();
	}
};


void assign(ifstream& f_ud, list& lst) { //f_ud == file "usage_data.txt"
	while (!f_ud.eof()) {
		usage_data x;
		getline(f_ud, x.ph_num, ',');
		getline(f_ud, x.id, ',');
		getline(f_ud, x.d, '.');
		getline(f_ud, x.m, '.');
		getline(f_ud, x.y, ' ');
		getline(f_ud, x.extra);
		lst.push_back(x);
	}

}

//-------------------------------------------------------------------------------

int main() {
	list lst;

	ifstream f_ud, f_si, f_ci, f_ini;
	fstream f_out;
	f_ud.open("usage_data.txt");
	f_si.open("services_info.txt");
	f_ci.open("clients_info.txt");
	f_out.open("Report.txt", ios::out);
	f_ini.open("Param.ini");

	assign(f_ud, lst); // считал структуру и записал в список

	lst.print();

	string srv1, srv2;
	date dt1, dt2;


	getline(f_ini, srv1, ' ');
	getline(f_ini, srv2, ' ');
	getline(f_ini, dt1.d, '.');
	getline(f_ini, dt1.m, '.');
	getline(f_ini, dt1.y, ' ');
	getline(f_ini, dt2.d, '.');
	getline(f_ini, dt2.m, '.');
	getline(f_ini, dt2.y);


	lst.srv_filter(f_si, srv1, srv2);

	lst.date_filter(dt1, dt2);

	lst.num_filter(f_ci);

	lst.write(f_out);

	lst.print();

	if (f_out.peek() == EOF) cout << "No Data\n";

	f_ud.close();
	f_si.close();
	f_ci.close();
	f_out.close();
	f_ini.close();

}