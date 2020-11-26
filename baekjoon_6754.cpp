#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int max_weight, n, sum, len;
    cin >> max_weight >> n;
    vector<int> weight(n);
    queue<int> q;
    for(auto& e : weight) cin >> e;
    sum = 0; len = 0;
    for(int i = 0; i < n; i++)
    {
        if(q.size() == 4)
        {
            sum -= q.front();
            q.pop();
        }
        if(i < n - 1 && sum + weight[i] <= max_weight)
        {
            sum += weight[i];
            q.push(weight[i]);
            len++;
        }
        else if(sum + weight[i] <= max_weight)
        {
            cout << ++len << endl;
        }
        else
        {
            cout << len << endl;
            break;
        }
    }
    return 0;
}
