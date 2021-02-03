#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#define NUM 1000000007
using namespace std;

vector< vector<long long> > mul(vector< vector<long long> >& a, vector< vector<long long> >& b){
    int n = a.size();
    vector< vector<long long> > res(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] += ((a[i][k] * b[k][j]) % NUM);
                res[i][j] %= NUM;
            }
        }
    }
    return res;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector< vector<long long> > base_arr(2, vector<long long>(2, 1));
    vector< vector<long long> > res_arr(2, vector<long long>(2, 0));
    base_arr[1][1] = 0;
    res_arr[0][0] = 1; res_arr[1][1] = 1;
    
    while(n){
        if(n % 2){
            res_arr = mul(res_arr, base_arr);
        }
        base_arr = mul(base_arr, base_arr);
        n /= 2;
    }

    cout << res_arr[0][1] << endl;
    
    return 0;
}
