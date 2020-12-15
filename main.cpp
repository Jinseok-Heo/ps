#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

bool check(vector<int> v, long long n, long long k){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += (v[i] / n);
    }
    if(cnt >= k) return true;
    else return false;
}

long long bin_search(vector<int> v, long long k, long long max){
    long long min = 1; long long mid = (min + max) / 2 + 1;
    while(min != max){
        int i_check = check(v, mid, k);
        if(i_check) min = mid;
        else max = mid - 1;
        mid = (min + max) % 2 ? (min + max) / 2 + 1 : (min + max) / 2;
    }
    return min;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> lengths(n);
    for(int i = 0; i < n; i++) cin >> lengths[i];
    sort(lengths.begin(), lengths.end());
    cout << bin_search(lengths, k, (long long)lengths[n - 1]) << endl;
    
    return 0;
}