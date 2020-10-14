#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int euclidian(int a, int b)
{
    if(b == 0) return a;
    return euclidian(b, a % b);
}

int main()
{
    int n, gcd;
    cin >> n;
    vector<int> v(n);
    vector<int> temp(n - 1);
    vector<int> ans;
    for(auto& e : v) cin >> e;
    
    sort(v.begin(), v.end());
        
    for(int i = 0; i < n - 1; i++)
    {
        temp[i] = v[i + 1] - v[i];
    }
        
    gcd = euclidian(temp[1], temp[0]);
    for(int i = 2; i < n - 1; i++)
    {
        gcd = euclidian(gcd, temp[i]);
    }

    for(int i = 1; i * i <= gcd; i++)
    {
        if(gcd % i == 0)
        {
            ans.push_back(i);
            if(i != gcd / i)
                ans.push_back(gcd / i);
        }
    }
    sort(ans.begin(), ans.end());
    
    for(auto& e : ans)
        if(e != 1) cout << e << " ";
    return 0;
}

