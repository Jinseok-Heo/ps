#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> res;
    stack<int> s;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    res.push_back(-1);
    s.push(nums[n - 1]);
    for(int i = n - 2; i >= 0; i--){
        int top = s.top();
        if(nums[i] < top){
            res.push_back(top);
            s.push(nums[i]);
        }
        else{
            while(!s.empty()){
                top = s.top();
                if(nums[i] < top) break;
                s.pop();
            }
            if(s.empty()) res.push_back(-1);
            else          res.push_back(top);
            s.push(nums[i]);
        }
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
