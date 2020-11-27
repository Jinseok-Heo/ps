#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#define I (int)temp.size() - 1
using namespace std;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, cnt, idx;
    cin >> n;
    if(n > 1022)
    {
        cout << -1 << endl;
        return 0;
    }
    cnt = 0; idx = 0;
    string temp = "0";
    while(cnt != n)
    {
        if(temp.size() == 1 && temp[0] < '9')
        {
            temp[0] += 1;
            cnt++;
            continue;
        }
        if(temp[idx] < '9' && temp[idx - 1] - temp[idx] > 1)
        {
            temp[idx] += 1;
            cnt++;
            continue;
        }
        if(idx > 0 && temp[idx - 1] < '9')
        {
            if(idx == 1 || (idx > 1 && temp[idx - 2] - temp[idx - 1] > 1))
            {
                temp[--idx] += 1;
                for(int i = I; i > idx; i--)
                {
                    temp[i] = I - i + 48;
                }
                idx = I;
                cnt++;
            }
            else idx--;
        }
        else
        {
            for(int i = 0; i < temp.size(); i++)
            {
                temp[i] = temp.size() - i + 48;
            }
            temp.push_back('0');
            cnt++;
            idx = I;
        }
    }
    cout << temp << endl;
    return 0;
}
