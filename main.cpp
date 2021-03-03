#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>

using namespace std;

int n, m;
vector<string> map;
vector< vector<int> > cnt_map;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input_data(void);
int find_ans();
bool isPossible(int col, int row);

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    input_data();
    cout << find_ans() << "\n";
    return 0;
}

void input_data(void) {
    cin >> n >> m;
    map.resize(n);
    cnt_map.resize(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        cin >> map[i];
    }
}

int find_ans() {
    queue< pair<int, int> > q;
    q.push(make_pair(0, 0));
    map[0][0] = '2';
    cnt_map[0][0] = 1;

    while(!q.empty()) {
        int cur_col, cur_row;
        cur_col = q.front().first;
        cur_row = q.front().second;
        q.pop();
        if(cur_col == n - 1 && cur_row == m - 1) return cnt_map[cur_col][cur_row];
        for(int i = 0; i < 4; i++) {
            int new_col, new_row;
            new_col = cur_col + dy[i];
            new_row = cur_row + dx[i];
            if(isPossible(new_col, new_row) && map[new_col][new_row] == '1') {
                q.push(make_pair(new_col, new_row));
                map[new_col][new_row] = '2';
                cnt_map[new_col][new_row] = cnt_map[cur_col][cur_row] + 1;
            }
        }
    }
    return -1;
}

bool isPossible(int col, int row) {
    if(col >= 0 && row >= 0 && col < n && row < m) return true;
    else                                           return false;
}