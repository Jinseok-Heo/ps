#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct priority
{
    int idx;
    int pri;
};

int main()
{
    cin.tie(NULL);
    iostream::sync_with_stdio(false);
    
    int t;
    cin >> t; //test case
    for(int i = 0; i < t; i++)
    {
        int n, k, p, idx = 0;
        cin >> n >> k;
        queue<priority> q;//contains sequence(index) and priority
        vector<int> v_pri;//contains priority
        for(int j = 0; j < n; j++)
        {
            cin >> p;
            q.push({j, p});
            v_pri.push_back(p);
        }
        sort(v_pri.begin(), v_pri.end(), greater<>());//sort priority in decreasing
        while(1)
        {
            if(q.front().pri != v_pri[idx])//when there's larger priority, move the priority to the end
            {
                q.push(q.front());
                q.pop();
                continue;
            }
            idx++;
            if(q.front().idx == k)
                break;
            q.pop();
        }
        cout << idx << "\n";
    }
    return 0;
}
