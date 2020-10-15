#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n, vector<int>(1000, 1));
    
    dp[0].resize(2);
    for(int i = 1; i < n; i++)//using Pascal Triangle, to find nCk
    {
        dp[i].resize(i + 2);
        for(int j = 1; j < i + 1; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[n - 1][k] << endl;
    return 0;
}
