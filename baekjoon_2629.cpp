#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#define MAX_SUM 15000

using namespace std;

void input_data(int* n_weight, vector<int>& weights) {
    cin >> *n_weight;
    weights.resize(*n_weight + 1, 0);
    for(int i = 1; i < *n_weight + 1; i++) cin >> weights[i];
}

void init_dp(vector< vector<bool> >& dp) {
    int n_weight = dp.size();
    for(int i = 0; i < n_weight; i++) dp[i][0] = true;
}

void update_dp(vector< vector<bool> >& dp, vector<int> weights) {
    int n_weight = dp.size();
    for(int i = 0; i < n_weight - 1; i++) {
        for(int j = 0; j < MAX_SUM; j++) {
            if(dp[i][j]) {
                dp[i + 1][j + weights[i + 1]] = true;
                dp[i + 1][(int)abs(j - weights[i + 1])] = true;
                dp[i + 1][j] = true;
            }
        }
    }
}

void print_res(vector< vector<bool> >& dp) {
    int n_marble;
    cin >> n_marble;
    vector<char> res;
    for(int i = 0; i < n_marble; i++) {
        int marble;
        cin >> marble;
        if(dp[dp.size() - 1][marble]) res.push_back('Y');
        else                          res.push_back('N');
    }

    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << "\n";
}

void print_dp(vector< vector<bool> >& dp) {
    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[0].size(); j++) cout << dp[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n_weight, n_marble;
    vector<int> weights;
    input_data(&n_weight, weights);

    vector< vector<bool> > dp(n_weight + 1, vector<bool>(MAX_SUM, false));
    init_dp(dp);
    update_dp(dp, weights);
    print_dp(dp);

    print_res(dp);
    return 0;
}
