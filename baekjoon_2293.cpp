#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    vector<int> dp(k + 1, 0);
    for(auto& e : values) cin >> e;
    
    sort(values.begin(), values.end());
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = values[i]; j < k + 1; j++)
        {
            dp[j] += dp[j - values[i]];
        }
    }
    cout << dp[k] << endl;
    return 0;
}
