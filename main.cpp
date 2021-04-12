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

vector<vector<p>> transFares(vector<vector<int>>& fares, int n) {
    int v = fares.size();
    vector<vector<p>> f(n);
    for(int i = 0; i < v; i++) {
        f[fares[i][0] - 1].push_back(make_pair(fares[i][1] - 1, fares[i][2]));
        f[fares[i][1] - 1].push_back(make_pair(fares[i][0] - 1, fares[i][2]));
    }
    return f;
}

vector<int> dijkstra(vector<vector<int>>& origin_fares, int n, int s) {
    vector<vector<p>> fares = transFares(origin_fares, n);
    vector<int> ret(n, INF);
    priority_queue<p, vector<p>, compare> pq;
    ret[s] = 0;
    pq.push(make_pair(s, 0));
    while(!pq.empty()) {
        p cur = pq.top(); pq.pop();
        if(ret[cur.first] < cur.second) continue;

        for(int i = 0; i < fares[cur.first].size(); i++) {
            p next = fares[cur.first][i];
            if(ret[next.first] <= ret[cur.first] + next.second) continue;
            ret[next.first] = ret[cur.first] + next.second;
            pq.push(make_pair(next.first, ret[next.first]));
        }
    }
    return ret;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<int> s_dist = dijkstra(fares, n, s - 1);
    vector<int> a_dist = dijkstra(fares, n, a - 1);
    vector<int> b_dist = dijkstra(fares, n, b - 1);

    for(int i = 0; i < n; i++) {
        ll cost = (ll)s_dist[i] + a_dist[i] + b_dist[i];
        answer = answer < cost ? answer : cost;
    }

    answer = answer < (ll)s_dist[a - 1] + s_dist[b - 1] ? answer : (ll)s_dist[a - 1] + s_dist[b - 1];
    return answer;
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, a, b, v;
    cin >> n >> s >> a >> b >> v;
    vector<vector<int>> fares(v, vector<int>(3));
    for(int i = 0; i < v; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        fares[i] = {a, b, c};
    }
    int ans = solution(n, s, a, b, fares);
    cout << ans << '\n';
    return 0;
}