#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &s) {
	stringstream ss;
	string ele;
	vector<string> res;

	ss.str(s);
	while (ss >> ele) {
		res.push_back(ele);
	}
	return res;
}

int main()
{
	int n;
	queue<int> q;

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		vector<string> data;
		getline(cin, s);
		data = split(s);
		if (data.size() == 2 && data[0] == "push") {
			q.push(stoi(data[1]));
		} else if (data.size() == 1) {
			if (data[0] == "front") {
				if (q.empty())
					cout << "-1" << "\n";
				else
					cout << q.front() << "\n";
			} else if (data[0] == "back") {
				if (q.empty())
					cout << "-1" << "\n";
				else
					cout << q.back() << "\n";
			} else if (data[0] == "pop") {
				if (q.empty())
					cout << "-1" << "\n";
				else {
					cout << q.front() << "\n";
					q.pop();
				}
			} else if (data[0] == "empty") {
				cout << q.empty() << "\n";
			} else if (data[0] == "size") {
				cout << q.size() << "\n";
			}
		}
	}
	return 0;
}
