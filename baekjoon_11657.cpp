#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <functional>
#include <unordered_map>

#define p pair<ll, ll>
#define ll long long
#define INF 200000000000

using namespace std;

void inputData(int* n, int* m, vector< vector<p> >& distInfo);
vector<ll> Bellman_Ford(vector< vector<p> >& distInfo, int start_loc);

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    vector< vector<p> > distInfo;
    vector<ll> ans;
    inputData(&n, &m, distInfo);
    ans = Bellman_Ford(distInfo, 0);

    for(int i = 1; i < ans.size(); i++) cout << ans[i] << "\n";
    return 0;
}

void inputData(int *n, int *m, vector< vector<p> > &distInfo) {
    cin >> *n >> *m;
    distInfo.resize(*n);
    for(int i = 0; i < *m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        distInfo[x - 1].push_back(make_pair(y - 1, z));
    }
}

vector<ll> Bellman_Ford(vector< vector<p> > &distInfo, int start_loc) {
    int n = distInfo.size();
    vector<ll> dist(n, INF);
    dist[start_loc] = 0;
    vector<bool> isPassed(n, false);
    isPassed[start_loc] = true;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            if(!isPassed[j]) continue;
            for(p ele : distInfo[j]) {
                ll cur_loc = ele.first;
                ll d = ele.second;
                isPassed[cur_loc] = true;

                if(dist[cur_loc] > dist[j] + d) {
                    dist[cur_loc] = dist[j] + d;
                }
            }
        }
    }

    for(int j = 0; j < n; j++) {
        if(!isPassed[j]) continue;
        for(p ele : distInfo[j]) {
            ll cur_loc = ele.first;
            ll d = ele.second;
            isPassed[cur_loc] = true;

            if (dist[cur_loc] > dist[j] + d){
                vector<ll> ret(2, -1);
                return ret;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(dist[i] == INF) dist[i] = -1;
    }
    return dist;
}
