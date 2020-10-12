#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long sum(vector<int> t){
    int t_size;
    unsigned long long sum = 0;
    t_size = int(t.size());
    for(int i = 0; i < t_size; i++){
        sum += (unsigned long long)t[i] * (t_size - i);
        cout << sum << " ";
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n, 1000);
    //for(auto& e : v)
        //cin >> e;
    
    sort(v.begin(), v.end());
    
    cout << "\n" << sum(v) << endl;
    
    return 0;
}
