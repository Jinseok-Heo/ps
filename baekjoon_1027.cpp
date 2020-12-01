#include <iostream>
#include <vector>
using namespace std;

vector<int> height;

int compareSlope(int first, int sec, int std){
    long long a = (long long)(height[std] - height[first]) * (std - sec);
    long long b = (long long)(height[std] - height[sec]) * (std - first);
    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans = 0;
    cin >> n;
    height.resize(n);
    for(auto& e : height) cin >> e;
    for(int i = 0; i < n; i++){
        int l_idx = 0, r_idx = n - 1, cnt = 0, target_idx = 0;
        l_idx = i - 1;
        r_idx = i + 1;
        target_idx = l_idx;
        if(l_idx >= 0) cnt++;
        while(l_idx >= 0){
            if(target_idx != l_idx && compareSlope(target_idx, l_idx, i) == 1){
                target_idx = l_idx;
                cnt++;
            }
            l_idx--;
        }
        if(r_idx < n) cnt++;
        target_idx = r_idx;
        while(r_idx < n){
            if(target_idx != r_idx && compareSlope(target_idx, r_idx, i) == -1){
                target_idx = r_idx;
                cnt++;
            }
            r_idx++;
        }
        ans = ans > cnt ? ans : cnt;
    }
    cout <<  ans << endl;
}
