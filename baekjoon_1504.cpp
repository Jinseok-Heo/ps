#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#define p pair<int, int>
#define INT_MAX 1000000

using namespace std;

struct compare {
    bool operator()(p a, p b){
        return a.second < b.second;
    }
};

void input_data(int* n, int* e, int* v_1, int* v_2, vector< vector<p> >& dist) {
    cin >> *n >> *e;
    dist.resize(*n);
    for(int i = 0; i < *e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a - 1].push_back(make_pair(b - 1, c));
        dist[b - 1].push_back(make_pair(a - 1, c));
    }
    cin >> *v_1 >> *v_2;
}

int dijkstra(vector< vector<p> >& dist, int start_loc, int end_loc) {
    if(start_loc == end_loc) return 0;
    int n = dist.size();
    vector<int> min_dist(n, INT_MAX);
    min_dist[start_loc] = 0;

    priority_queue<p, vector<p>, compare> pq;
    pq.push(make_pair(start_loc, 0));

    while(pq.size()) {
        int cur_loc = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        
        if(min_dist[cur_loc] < d) continue;
        for(int i = 0; i < dist[cur_loc].size(); i++) {
            int next_loc = dist[cur_loc][i].first;
            int next_dist = d + dist[cur_loc][i].second;
            
            if(min_dist[next_loc] > next_dist) {
                min_dist[next_loc] = next_dist;
                pq.push(make_pair(next_loc, next_dist));
            }
        }
    }
    return min_dist[end_loc];
}

int minDist(vector< vector<p> >& dist, int v_1, int v_2) {
    int n = dist.size();
    int toV1, toV2, V1toV2, fromV1, fromV2, route_1, route_2;
    toV1 = dijkstra(dist, 0, v_1);
    toV2 = dijkstra(dist, 0, v_2);
    V1toV2 = dijkstra(dist, v_2, v_1);
    fromV1 = dijkstra(dist, v_1, n - 1);
    fromV2 = dijkstra(dist, v_2, n - 1);

    route_1 = INT_MAX;
    route_2 = INT_MAX;

    if(toV1 != INT_MAX && V1toV2 != INT_MAX && fromV2 != INT_MAX)
        route_1 = toV1 + V1toV2 + fromV2;

    if(toV2 != INT_MAX && V1toV2 != INT_MAX && fromV1 != INT_MAX)
        route_2 = toV2 + V1toV2 + fromV1;

    if(route_1 != INT_MAX || route_2 != INT_MAX) return min(route_1, route_2);
    else                               return -1;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, e, v_1, v_2;
    vector< vector<p> > dist;
    input_data(&n, &e, &v_1, &v_2, dist);
    v_1--; v_2--;
    cout << minDist(dist, v_1, v_2) << "\n";
    
    return 0;
}
