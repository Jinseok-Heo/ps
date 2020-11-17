#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool check(char c, vector<char> s)
{
    bool ans{true};
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] == c || s[i] == c - 32 || s[i] == c + 32)
        {
            ans = false;
            break;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> data(n + 1), ans(n + 1);
    vector<char> shrcut;
    for(int i = 0; i < n + 1; i++) getline(cin, data[i]);
    
    for(int i = 1; i < n + 1; i++)
    {
        int idx = -1;
        int j = 0;
        while(data[i][j] != '\0')
        {
            if(j == 0 && check(data[i][j], shrcut))
            {
                idx = 0;
                shrcut.push_back(data[i][j]);
                break;
            }
            else if(data[i][j] == ' ')
            {
                if(check(data[i][j + 1], shrcut))
                {
                    shrcut.push_back(data[i][j + 1]);
                    idx = j + 1;
                    break;
                }
            }
            j++;
        }
        if(idx == -1)
        {
            j = 0;
            while(data[i][j] != '\0')
            {
                if(data[i][j] != ' ' && check(data[i][j], shrcut))
                {
                    idx = j;
                    shrcut.push_back(data[i][j]);
                    break;
                }
                j++;
            }
        }
        if(idx != -1)
        {
            if(idx != 0)
            {
                ans[i] = data[i].substr(0, idx);
            }
            ans[i].push_back('[');
            ans[i].push_back(data[i][idx]);
            ans[i].push_back(']');
            j = idx + 1;
            ans[i] += data[i].substr(idx + 1);
        }
        else
        {
            ans[i] = data[i];
        }
    }
    for(int i = 1; i < n + 1; i++) cout << ans[i] << "\n";
    return 0;
}
