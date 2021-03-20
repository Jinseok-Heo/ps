#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <unordered_map>

using namespace std;

int findMax(vector< vector<int> >& map) {
    int n = map.size(); int m = map[0].size();
    int ret, temp;
    ret = 0; temp = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            temp = map[i][j] + map[i][j + 1];
            pair<int, int> partial_max = pair<int, int>(-1, -1);
            if(i != 0) {
                for(int k = 0; k < 2; k++) {
                    if(partial_max.first < map[i - 1][j + k]) {
                        partial_max.second = partial_max.first;
                        partial_max.first = map[i - 1][j + k];
                    }
                    else if(partial_max.second < map[i - 1][j + k]) partial_max.second = map[i - 1][j + k];
                }
            }
            if(i != n - 1) {
                for(int k = 0; k < 2; k++) {
                    if(partial_max.first < map[i + 1][j + k]) {
                        partial_max.second = partial_max.first;
                        partial_max.first = map[i + 1][j + k];
                    }
                    else if(partial_max.second < map[i + 1][j + k]) partial_max.second = map[i + 1][j + k];
                }
            }
            temp += (partial_max.first + partial_max.second);
            ret = ret > temp ? ret : temp;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            temp = map[i + 1][j] + map[i][j];
            pair<int, int> partial_max = pair<int, int>(-1, -1);
            if(j != 0) {
                for(int k = 0; k < 2; k++) {
                    if(partial_max.first < map[i + k][j - 1]) {
                        partial_max.second = partial_max.first;
                        partial_max.first = map[i + k][j - 1];
                    }
                    else if(partial_max.second < map[i + k][j - 1]) partial_max.second = map[i + k][j - 1];
                }
            }
            if(j != m - 1) {
                for(int k = 0; k < 2; k++) {
                    if(partial_max.first < map[i + k][j + 1]) {
                        partial_max.second = partial_max.first;
                        partial_max.first = map[i + k][j + 1];
                    }
                    else if(partial_max.second < map[i + k][j + 1]) partial_max.second = map[i + k][j + 1];
                }
            }
            temp += (partial_max.first + partial_max.second);
            ret = ret > temp ? ret : temp;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 2; j++) {
            temp = map[i][j] + map[i][j + 1] + map[i][j + 2];
            int partial_max = 0;
            if(i != 0) {
                for(int k = 0; k < 3; k++) {
                    partial_max = partial_max > map[i - 1][j + k] ? partial_max : map[i - 1][j + k];
                }
            }
            if(i != n - 1) {
                for(int k = 0; k < 3; k++) {
                    partial_max = partial_max > map[i + 1][j + k] ? partial_max : map[i + 1][j + k];
                }
            }
            if(j != m - 3) {
                partial_max = partial_max > map[i][j + 3] ? partial_max : map[i][j + 3];
            }
            temp += partial_max;
            ret = ret > temp ? ret : temp;
        }
    }

    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m; j++) {
            temp = map[i][j] + map[i + 1][j] + map[i + 2][j];
            int partial_max = 0;
            if(j != 0) {
                for(int k = 0; k < 3; k++) {
                    partial_max = partial_max > map[i + k][j - 1] ? partial_max : map[i + k][j - 1];
                }
            }
            if(j != m - 1) {
                for(int k = 0; k < 3; k++) {
                    partial_max = partial_max > map[i + k][j + 1] ? partial_max : map[i + k][j + 1];
                }
            }
            if(i != n - 3) {
                partial_max = partial_max > map[i + 3][j] ? partial_max : map[i + 3][j];
            }
            temp += partial_max;
            ret = ret > temp ? ret : temp;
        }
    }
    return ret;
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector< vector<int> > map(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> map[i][j];
    }

    cout << findMax(map) << endl;

    return 0;
}