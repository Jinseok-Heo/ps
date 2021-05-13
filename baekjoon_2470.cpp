/*
    backjoon 2470
    Two Pointers
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define p pair<int, int>
#define ll long long
#define INF 9876543211

using namespace std;

void input_data(int& n, vector<int>& num) {
    cin >> n;
    num.resize(n);
    for(int i = 0; i < n; i++)
        cin >> num[i];
}

p solution(int n, vector<int>& num) {
    p res;
    sort(num.begin(), num.end());
    int l_idx = 0, r_idx = n - 1;
    cout << num[l_idx] << " " << num[r_idx] << '\n';
    if(num[l_idx] > 0 && num[r_idx] > 0) {
        return make_pair(num[0], num[1]);
    }
    else if(num[l_idx] < 0 && num[r_idx] < 0) {
        return make_pair(num[n - 2], num[n - 1]);
    }
    ll min_sum = INF;
    while(l_idx < r_idx) {
        ll cur_sum = (ll)num[l_idx] + num[r_idx];
        if(cur_sum == 0) {
            return make_pair(num[l_idx], num[r_idx]);
        }
        else if(cur_sum > 0) {
            if(abs(min_sum) > abs(cur_sum)) {
                min_sum = cur_sum;
                res = make_pair(num[l_idx], num[r_idx]);
            }
            r_idx--;
        }
        else {
            if(abs(min_sum) > abs(cur_sum)) {
                min_sum = cur_sum;
                res = make_pair(num[l_idx], num[r_idx]);
            }
            l_idx++;
        }
    }
    return res;
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> num;
    input_data(n, num);
    p res = solution(n, num);
    cout << res.first << " " << res.second << '\n';
    return 0;
}
