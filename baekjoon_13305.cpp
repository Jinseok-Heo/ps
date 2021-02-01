#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#define MAX 1000000000

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> dist(n - 1, 0);
    vector<int> cost(n, 0);
    for(int i = 0; i < n - 1; i++){
        cin >> dist[i];
    }
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    int max_cost = cost[0];
    long long sum_dist = 0;
    for(int i = 1; i < n; i++){
        sum_dist = 0;
        while(i < n && max_cost < cost[i]){
            sum_dist += dist[i - 1];
            i++;
        }
        sum_dist += dist[i - 1];
        ans += sum_dist * (long long)max_cost;
        max_cost = cost[i];
    }
    cout << ans << endl;
    return 0;
}
