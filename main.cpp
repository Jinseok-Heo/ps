/*
baekjoon 12852
Make 1
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i / 2] + i % 2 + 1 < dp[i / 3] + i % 3 + 1 ? dp[i / 2] + i % 2 + 1 : dp[i / 3] + i % 3 + 1;
        dp[i] = dp[i] < dp[i - 1] + 1 ? dp[i] : dp[i - 1] + 1;
    }
    cout << dp[n] << '\n';
    while (n > 0) {
        cout << n << " ";
        int first = dp[n / 3] + n % 3 + 1;
        int second = dp[n / 2] + n % 2 + 1;
        int third = dp[n - 1] + 1;
        if (first <= second && first <= third) {
            while (n % 3) {
                cout << --n << " ";
            }
            n /= 3;
        }
        else if (second <= first && second <= third) {
            while (n % 2) {
                cout << --n << " ";
            }
            n /= 2;
        }
        else
            n--;
    }
    cout << '\n';
    return 0;
}