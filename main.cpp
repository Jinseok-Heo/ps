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

struct compare {
    bool operator()(p& a, p& b) {
        return a.second > b.second;
    }
};

void inputData(int* v, int* e, vector<vector<p>>& dist);
vector<int> dijkstra(vector<vector<p>>& dist, int start);
int solution(vector<vector<p>>& dist);

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, ans;
    vector<vector<p>> dist;
    inputData(&v, &e, dist);
    ans = solution(dist);

    if(ans == INF) cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}

void inputData(int *v, int *e, vector<vector<p>> &dist) {
    cin >> *v >> *e;
    dist.resize(*v);
    for(int i = 0; i < *e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a - 1].push_back(make_pair(b - 1, c));
    }
}
vector<int> dijkstra(vector<vector<p>> &dist, int start) {
    int n = dist.size();
    priority_queue<p, vector<p>, compare> pq;
    vector<int> d(n, INF);
    
    pq.push(make_pair(start, 0));
    d[start] = 0;

    while(!pq.empty()) {
        p cur = pq.top(); pq.pop();
        if(d[cur.first] < cur.second) continue;

        for(p next : dist[cur.first]) {
            int next_loc = next.first;
            int next_dist = d[cur.first] + next.second;

            if(d[next_loc] <= next_dist) continue;
            d[next_loc] = next_dist;
            pq.push(make_pair(next_loc, next_dist));
        }
    }
    return d;
}
int solution(vector<vector<p>> &dist) {
    int n = dist.size();
    int ans = INF;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) {
        d[i] = dijkstra(dist, i);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(d[i][j] == INF || d[j][i] == INF) continue;
            ans = ans < d[i][j] + d[j][i] ? ans : d[i][j] + d[j][i];
        }
    }
    return ans;
}