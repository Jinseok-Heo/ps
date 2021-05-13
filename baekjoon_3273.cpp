/*
    backjoon 3273
    Two Pointers
*/

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
#define INF 987654321

using namespace std;

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) 
        cin >> num[i];
    
    cin >> x;
    
    int res = 0;
    sort(num.begin(), num.end());
    int left_idx = 0, right_idx = n - 1;
    while(left_idx < right_idx) {
        if(num[left_idx] + num[right_idx] == x) {
            left_idx++;
            res++;
        }
        else if(num[left_idx] + num[right_idx] < x) {
            left_idx++;
        }
        else {
            right_idx--;
        }
    }
    cout << res << '\n';
    return 0;
}
