#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void rotate(deque<int> &dq) {
	if (dq.empty()) {
		return;
	}
	const int front = dq.front();

	dq.pop_front();
	dq.push_back(front);
}

void rotate_n(deque<int> &dq, int n) {
	while (n) {
		rotate(dq);
		n--;
	}
}

int main() {
	deque<int> dq;
	vector<int> res;
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	rotate_n(dq, k - 1);
	while (!dq.empty()) {
		res.push_back(dq.front());
		dq.pop_front();
		rotate_n(dq, k - 1);
	}
	cout << "<";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1) {
			cout << ", ";
		}
	}
	cout << ">";
	return 0;
}