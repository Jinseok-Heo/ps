#include <iostream>

using namespace std;

int main()
{
	int n_test, n, m, x, y;
	int res[1000];
	cin >> n_test;

	for (int i = 0; i < n_test; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < m; j++)
			cin >> x >> y;

		res[i] = n - 1;
	}

	for (int i = 0; i < n_test; i++)
		cout << res[i] << "\n";
	return 0;
}