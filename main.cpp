#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <functional>
#include <unordered_map>
#define p pair<int, int>
#define ll long long
#define INF 9876543211

using namespace std;

void input_data(int& n, int& s, vector<int>& v) {
    cin >> n >> s;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

int solution(int s, vector<int>& v) {
    int n = v.size();
    int res = n + 1;
    int left_idx = 0, right_idx = 0;
    ll sum = v[left_idx];
    
    while (left_idx < n && right_idx < n) {
        if (sum >= s) {
            res = res < right_idx - left_idx + 1 ? res : right_idx - left_idx + 1;
            sum -= v[left_idx++];
        }
        else {
            right_idx++;
            if (right_idx < n)
                sum += v[right_idx];
        }
    }

    if (res == n + 1)
        return 0;
    return res;
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    vector<int> v;
    input_data(n, s, v);

    cout << solution(s, v) << '\n';  
    return 0;
}