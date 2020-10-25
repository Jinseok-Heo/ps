#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    iostream::sync_with_stdio(false);
    
    int n, k, i = 1;
    cin >> n >> k;
    //q contains numbers except kth num and ans contains the num sequence of Josephus
    queue<int> q, ans;
    for(int j = 1; j <= n; j++) q.push(j);
    
    while(ans.size() != n)
    {
        if(i == k)
        {
            ans.push(q.front());
            q.pop();
            i = 1;
            continue;
        }
        q.push(q.front());
        q.pop();
        i++;
    }
    cout << "<" << ans.front();
    ans.pop();
    while(!ans.empty())
    {
        cout << ", " << ans.front();
        ans.pop();
    }
    cout << ">" << endl;
    return 0;
}
