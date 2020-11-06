#include <iostream>

using namespace std;

int min_func(int a, int b) { return a <= b ? a : b; }

int main()
{
	int x;
	cin >> x;
	int* dp = new int[x + 1] {0, };
	if (dp == nullptr)
		return -1;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i < x + 1; i++)
		dp[i] = min_func(dp[i / 3] + i % 3 + 1, dp[i / 2] + i % 2 + 1);

	cout << dp[x] << endl;

	delete[] dp;
	return 0;
}
