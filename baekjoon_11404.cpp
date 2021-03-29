#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <functional>
#include <unordered_map>

#define INF 1000000000

using namespace std;

void inputData(int *n, int *m, vector<vector<int>> &distInfo);
void Floyd_Warshall(vector<vector<int>> &distInfo);

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    vector<vector<int>> distInfo;
    inputData(&n, &m, distInfo);
    Floyd_Warshall(distInfo);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << distInfo[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

void inputData(int *n, int *m, vector<vector<int>> &distInfo) {
    cin >> *n;
    cin >> *m;
    distInfo.resize(*n, vector<int>(*n, INF));
    for(int i = 0; i < *m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        distInfo[x - 1][y - 1] = distInfo[x - 1][y - 1] < z ? distInfo[x - 1][y - 1] : z;
    }
}

void Floyd_Warshall(vector<vector<int>> &dist) {
    int n = dist.size();
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF) dist[i][j] = 0;
        }
    }
}
