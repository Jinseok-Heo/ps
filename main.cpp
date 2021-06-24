#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <random>
#include <ctime>

// #define p pair<int, vector<int>>
// #define ll long long
// #define INF 9876543211

using namespace std;

void input_data(vector<int>& v) {
    int n;
    cin >> n;
    v.resize(n);
    for(int& ele : v) cin >> ele;
}

vector<int> find_res(const vector<int>& v, const vector<int>& dp, int max_idx) {
    // assert(dp.size());
    vector<int> res;
    res.push_back(v[max_idx]);
    while (max_idx >= 0) {
        for (int i = max_idx; i >= 0; i--) {
            if (dp[i] == dp[max_idx] - 1 && v[i] < v[max_idx]) {
                res.push_back(v[i]);
                max_idx = i;
                break;
            }
        }
        if (dp[max_idx] == 1)
            break;
    }
    reverse(res.begin(), res.end());
    return res;
}

void LIS(const vector<int>& v) {
    // assert(v.size());
    int l = 1;
    int max_idx = 0;
    vector<int> res;
    vector<int> dp(v.size(), 1);

    for (int i = 1; i < dp.size(); i++) {
        int max_ele = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j] && max_ele < dp[j]) {
                max_ele = dp[j];
            }
        }
        dp[i] = max_ele + 1;
        if (dp[i] > l) {
            max_idx = i;
            l = dp[i];
        }
    }
    res = find_res(v, dp, max_idx);

    cout << l << '\n';

    // cout << "dp: ";
    // for (int& ele : dp)
    //     cout << ele << " ";
    // cout << "res: ";
    for (int &ele : res)
        cout << ele << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> data;
    input_data(data);
    LIS(data);
    return 0;
}