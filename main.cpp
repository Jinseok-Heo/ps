#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#define MAX_APP 101
#define MAX_COST 10001

using namespace std;

void input_data(int* n, int* m, vector<int>& memory, vector<int>& cost);
void init_dp(vector< vector<int> >& dp, vector<int>& memory, vector<int>& cost);
void update_dp(vector< vector<int> >& dp, vector<int>& memory, vector<int>& cost);
int find_ans(vector< vector<int> >& dp, int n, int m);
void print_dp(vector< vector<int> >& dp, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 20; j++) cout << setfill(' ') << setw(4) << dp[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<int> memory, cost;
    vector< vector<int> > dp(MAX_APP, vector<int>(MAX_COST, 0));
    input_data(&n, &m, memory, cost);
    init_dp(dp, memory, cost);
    update_dp(dp, memory, cost);
    cout << find_ans(dp, n, m) << "\n";
    print_dp(dp, n);
    return 0;
}
void input_data(int* n, int* m, vector<int>& memory, vector<int>& cost) {
    cin >> *n >> *m;
    memory.resize(*n);
    cost.resize(*n);
    for(int i = 0; i < *n; i++) cin >> memory[i];
    for(int i = 0; i < *n; i++) cin >> cost[i];
}

void init_dp(vector< vector<int> >& dp, vector<int>& memory, vector<int>& cost) {
    for(int i = cost[0]; i < dp[0].size(); i++) dp[0][i] = memory[0];
}

void update_dp(vector< vector<int> >& dp, vector<int>& memory, vector<int>& cost) {
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 0; j < MAX_COST; j++) {
            if(j >= cost[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
}

int find_ans(vector< vector<int> >& dp, int n, int m) {
    for(int i = 0; i < MAX_COST; i++) {
        if(dp[n - 1][i] >= m) return i;
    }
    return -1;
}