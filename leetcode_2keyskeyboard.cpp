#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        while(n > 1){
            res += getDivisor(n);
            n /= getDivisor(n);
        }
        return res;
    }
    int getDivisor(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return i;
        }
        return n;
    }
};
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    cout << sol.minSteps(n) << endl;
    return 0;
}  
