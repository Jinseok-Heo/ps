#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

bool check(vector<long long> lengths, long long m, long long k){
    long long sum = 0;
    for(int i = 0; i < lengths.size(); i++){
        if(lengths[i] >= k) sum += (long long)(lengths[i] - k);
    }
    if(sum >= m) return true;
    else return false;
}

long long bin_search(vector<long long> lengths, long long m){
    long long min = 0; long long max = lengths[lengths.size() - 1]; long long mid = 0;
    while(min != max){
        mid = (min + max) % 2 ? (min + max) / 2 + 1 : (min + max) / 2;
        cout << min << " " << mid << " " << max << endl;
        if(check(lengths, m, mid)) min = mid;
        else max = mid - 1;
    }
    return min;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long> lengths(n);
    for(int i = 0; i < n; i++) cin >> lengths[i];
    sort(lengths.begin(), lengths.end());
    cout << bin_search(lengths, m) << endl;    
    return 0;
}
