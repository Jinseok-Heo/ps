#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n, idx; //idx is index of vector which will be compared to stack
    idx = 0;
    cin >> n;
    vector<int> v_res(n); //this vector will be standard vector
    vector<char> ans; //this vector contains the answer '+' and '-'
    for(auto& e : v_res) cin >> e;
    stack<int> temp; //the number which stasifies condition will be contained to temp
    
    for(int i = 1; i <= n; i++)
    {
        if(i != v_res[idx]) //if i is different to v[idx] push i to temp
        {
            temp.push(i);
            ans.push_back('+');
        }
        else //if i is same with v[idx]
        {
            temp.push(i);
            ans.push_back('+');
            //if v[idx] equals to top of temp, pop all elements by increasing idx
            while(!temp.empty() && v_res[idx] == temp.top() && idx < n)
            {
                idx++;
                temp.pop();
                ans.push_back('-');
            }
        }
    }
    if(idx != n) cout << "NO" << endl;
    else
    {
        for(auto& e : ans)
            cout << e << "\n";
    }
    return 0;
}
