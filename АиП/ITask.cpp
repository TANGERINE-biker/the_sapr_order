#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct client
{
	string name, number;
};

struct service
{
	string name, index;
};

struct usage
{
	string number, index, d, m, y, time;
};

int str_counter(ifstream& file)
{
	string tmp;
	int counter = 0;
	while (getline(file, tmp)) if (!tmp.empty()) counter++;
	return counter;
}

int main()
{
	setlocale(LC_ALL, "RU");
	ifstream clients, services, usages;
	clients.open("clients_info.txt", ios::in);
	services.open("services_info.txt", ios::in);
	usages.open("usage_data.txt", ios::in);
	ofstream output;
	output.open("output.txt");

	client c;
	service s;
	usage u, tme1, tme2;

	string srv1, srv2;
	cout << "¬ведите наименование первой услуги:\n";
	getline(cin, srv1);
	cout << "¬ведите наименование второй услуги:\n";
	getline(cin, srv2);

	cout << "¬ведите начальную дату дд.мм.гггг :\n";
	getline(cin, tme1.d, '.');
	getline(cin, tme1.m, '.');
	getline(cin, tme1.y);
	cout << "¬ведите конечную дату дд.мм.гггг :\n";
	getline(cin, tme2.d, '.');
	getline(cin, tme2.m, '.');
	getline(cin, tme2.y);

	string* arrSrv;
	arrSrv = new string[str_counter(services)];
	for (int i = 0; i < sizeof(arrSrv); i++)
	{
		string extra1;
		getline(services, s.name, ',');
		getline(services, s.index, ',');
		getline(services, extra1);
		if (s.name == srv1 || s.name == srv2) arrSrv[i] = s.index
			cout << arrSrv[i];

	}

	string* arrNum;
	arrNum = new string[str_counter(usages)];
	for (int i = 0; i < sizeof(arrNum); i++)
	{
		while (!usages.eof())
		{
			string extra2;
			getline(usages, u.number, ',');
			getline(usages, u.index, ',');
			getline(usages, u.d, '.');
			getline(usages, u.m, '.');
			getline(usages, u.y, ' ');
			getline(usages, u.time, ',');
			getline(usages, extra2);
			for (int j = 0; j < (sizeof(arrSrv)); j++)
			{
				if (u.index == arrSrv[j])
					if ((stoi(tme1.y) <= stoi(u.y) && stoi(u.y) <= stoi(tme2.y)) && (stoi(tme1.m) <= stoi(u.m) && stoi(u.m) <= stoi(tme2.m)) && (tme1.m <= u.m && u.m <= tme2.m))
						arrNum[j] = u.number;
			}
		}
	}

	string* arrClnt;
	arrClnt = new string[str_counter(clients)];
	for (int i = 0; i < sizeof(arrClnt); i++)
	{
		while (!clients)
		{
			string extra3;
			getline(clients, c.name, ',');
			getline(clients, c.number, ',');
			getline(clients, extra3);
			for (int j = 0; j < (sizeof(arrNum)); j++)
			{
				if (c.number == arrNum[j]) output << c.name;
			}
		}
	}

}
