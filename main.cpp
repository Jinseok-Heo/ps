#include <iostream>
//#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* stack = new int[n];
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        string func;
        int x;
        cin >> func;
        if(func == "push")
        {
            cin >> x;
            stack[idx] = x;
            idx++;
        }
        else if(func == "pop")
        {
            if(idx == 0) cout << -1 <<"\n";
            else
            {
                cout << stack[idx - 1] << "\n";
                idx--;
            }
        }
        else if(func == "empty")
        {
            if(idx == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(func == "size")
        {
            cout << idx << "\n";
        }
        else if(func == "top")
        {
            if(idx == 0) cout << -1 << "\n";
            else cout << stack[idx - 1] << "\n";
        }
    }
    delete[] stack;
    stack = nullptr;
    return 0;
}
