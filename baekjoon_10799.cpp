#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<char> st;
	string str;
	unsigned long res = 0;
	bool flag = false;

	cin >> str;
	for (auto &c : str) {
		if (c == '(') {
			st.push(c);
			flag = true;
		}
		else {
			st.pop();
			if (flag) {
				res += st.size();
			} else {
				res += 1;
			}
			flag = false;
		}
	}
	cout << res << "\n";
	return 0;
}