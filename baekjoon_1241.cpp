#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, d_max = 0;
    cin >> n;
    vector<int> num, data(n);
    for(int i = 0; i < n; i++) {
        cin >> data[i];
        d_max = d_max > data[i] ? d_max : data[i];
    }
    num.resize(d_max + 1);
    for(int i = 0; i < n; i++) num[data[i]]++;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 1; j * j <= data[i]; j++){
            if(data[i] % j == 0){
                if(data[i] / j != j) sum += (num[j] + num[data[i] / j]);
                else sum += num[j];
            }
        }
        cout << sum - 1 << "\n";
    }
    return 0;
}
