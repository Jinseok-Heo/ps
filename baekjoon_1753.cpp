#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#define MAX 1000000000

using namespace std;

typedef struct _node{
    int loc;
    int weight;
} node;

struct compare{
    bool operator()(node a, node b){
        return a.weight > b.weight;
    }
};

int V, e, k;
vector< vector<node> > weights;
vector<int> dist;

void dijkstra(void){
    priority_queue<node, vector<node>, compare> pq;
    vector<bool> visited(V + 1, false);
    pq.push((node){k, 0});
    visited[k] = true;
    while(!pq.empty()){
        int loc = pq.top().loc;
        int weight = pq.top().weight;
        pq.pop();
        visited[loc] = true;
        for(int i = 0; i < weights[loc].size(); i++){
            int t_loc = weights[loc][i].loc;
            int t_weight = weights[loc][i].weight;
            if(visited[t_loc]) continue;
            if(dist[t_loc] > dist[loc] + t_weight){
                dist[t_loc] = dist[loc] + t_weight;
                pq.push((node){t_loc, dist[t_loc]});
            }
        }
    }
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int u, v, w;
    cin >> V >> e;
    weights.resize(V + 1);
    cin >> k;
    for(int i = 0; i < e; i++){
        cin >> u >> v >> w;
        weights[u].push_back((node){v, w});
    }
    dist.resize(V + 1, MAX);
    dist[k] = 0; 
    dijkstra();

    for(int i = 1; i < V + 1; i++){
        if(dist[i] == MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
