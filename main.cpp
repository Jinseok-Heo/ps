#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int arr[26]{0, };//A responds to arr[0]
    stack<double> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < (int)str.size(); i++)
    {
        if((int)str[i] >= 65 && (int)str[i] <= 90)
        {
            s.push(arr[(int)str[i] - 65]);
        }
        else
        {
            double temp;
            if(str[i] == '+')
            {
                temp = s.top();
                s.pop();
                temp += s.top();
                s.pop();
                s.push(temp);
            }
            else if(str[i] == '-')
            {
                temp = s.top();
                s.pop();
                temp = s.top() - temp;
                s.pop();
                s.push(temp);
            }
            else if(str[i] == '*')
            {
                temp = s.top();
                s.pop();
                temp *= s.top();
                s.pop();
                s.push(temp);
            }
            else if(str[i] == '/')
            {
                temp = s.top();
                s.pop();
                temp = s.top() / temp;
                s.pop();
                s.push(temp);
            }
        }
    }
    cout << setprecision(2) << fixed << s.top() << endl;
    return 0;
}
