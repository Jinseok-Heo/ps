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

/*
use Two Pointers
time limits: 2sec
mem limits: 128MB

n <= 4000000
*/

using namespace std;

bool is_prime(int num) {
    if (num == 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (!(num % i)) return false;
    }
    return true;
}

vector<int> prime_numbers(int n) {
    vector<int> pn;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) pn.push_back(i);
    }
    return pn;
}

int solution(int n) {
    int count = 0, sum = 2;
    int left_idx = 0, right_idx = 0;

    vector<int> pn = prime_numbers(n);

    while (left_idx <= right_idx) {
        if (sum == n) {
            count++;
            if (pn.size() - 1 == right_idx) return count;
            sum += pn[++right_idx];
            sum -= pn[left_idx++];
        } else if (sum < n) {
            if (pn.size() - 1 == right_idx) return count;
            sum += pn[++right_idx];
        } else {
            sum -= pn[left_idx++];
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1) cout << 0 << endl;
    else if (n <= 3) cout << 1 << endl;
    else cout << solution(n) << endl;

    return 0;
}