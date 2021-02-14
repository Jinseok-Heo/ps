#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>

using namespace std;

void input_data(int* n,int* m, vector<int>& arr) {
    cin >> *n;
    arr.resize(*n + 1, 0);
    for(int i = 1; i <= *n; i++){
        cin >> arr[i];
    }
    cin >> *m;
}

void dp_init(vector<int> arr, vector< vector<bool> >& dp) {
    for(int i = 1; i < dp.size(); i++) {
        dp[i][i] = true;
    }
    for(int i = 1; i < dp.size() - 1; i++) {
        dp[i][i + 1] = (arr[i] == arr[i + 1]);
    }
}

void palindrome(vector<int>& arr, vector< vector<bool> >& dp) {
    int n = arr.size() - 1;
    for(int d = 2; d <= n; d++) {
        for(int i = 1; i + d <= n; i++) {
            if(arr[i] != arr[i + d]) {
                dp[i][i + d] = false;
            }
            else {
                dp[i][i + d] = dp[i + 1][i + d - 1] ? true : false;
            }
        }
    }
}

void print_dp(vector< vector<bool> >& dp) {
    int n = dp.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<int> arr;
    input_data(&n, &m, arr);
    vector< vector<bool> > dp(n + 1, vector<bool>(n + 1, false));
    dp_init(arr, dp);
    palindrome(arr, dp);

    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        //cout << dp[s][e] << "\n";
    }
    print_dp(dp);
    return 0;
}