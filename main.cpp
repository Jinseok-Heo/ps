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
#define INF 1000000000

using namespace std;

class info {
public:
    int v, c, d;
};

struct compare {
    bool operator()(info a, info b) {
        if(a.d == b.d) return a.c > b.c;
        return a.d > b.d;
    }
};

void initDp(vector<vector<int>>& dp) {
    for(int i = 0; i < dp[0].size(); i++) dp[0][i] = 0;
}

int updateDp(vector<vector<int>>& dp, vector<vector<info>>& dist) {
    int n = dp.size(); int m = dp[0].size();
    priority_queue<info, vector<info>, compare> pq;

    pq.push(info{0, 0, 0});
    while(!pq.empty()) {
        info cur = pq.top();
        pq.pop();
        if(dp[cur.v][cur.c] < cur.d) continue;

        for(info next : dist[cur.v]) {
            int next_cost = cur.c + next.c;
            int next_dist = dp[cur.v][cur.c] + next.d;
            if(next_cost > m) continue;
            if(dp[next.v][next_cost] <= next_dist) continue;

            pq.push({next.v, next_cost, next_dist});
            dp[next.v][next_cost] = next_dist;
        }
    }

    int ret = INF;
    for(int i : dp[n - 1]) {
        ret = ret < i ? ret : i;
    }
    return ret;
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    cin >> test_case;
    for(int t = 0; t < test_case; t++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<info>> dist(n);
        for(int i = 0; i < k; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            dist[a - 1].push_back(info{b - 1, c, d});
        }
        vector<vector<int>> dp(n, vector<int>(m + 1, INF));
        initDp(dp);
        int ans = updateDp(dp, dist);

        if(ans == INF) cout << "Poor KCM\n";
        else cout << ans << "\n";
    }
    return 0;
}