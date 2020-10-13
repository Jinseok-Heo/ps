#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int temp, j, ans;
    string equ;
    stack<char> num;//char of numbers 0~9
    vector<int> v_num;//integer number which come from stack num
    vector<char> v_op;//vector of operations
    cin >> equ;
    
    for(int i = 0; i < equ.size(); i++)
    {
        if(equ[i] >= '0' && equ[i] <= '9')//if a letter is number, push it to stack
        {
            num.push(equ[i]);
            if(i != equ.size() - 1)
                continue;
        }
        //if a letter is not number, chagne char number to int number
        j = 0;
        temp = 0;
        while(!num.empty())
        {
            temp += (num.top() - '0') * (int)pow(10, j);
            num.pop();
            j++;
        }
        v_num.push_back(temp);//push integer number into stack
        v_op.push_back(equ[i]);//push operation into stack
    }
    //calculate + from back to front ex)3+4+5+6->3+4+11+0->3+15+0+0->18+0+0+0
    for(int i = (int)v_op.size() - 1; i >= 0; i--)
    {
        if(v_op[i] == '+')
        {
            v_num[i] += v_num[i + 1];
            v_num[i + 1] = 0;
        }
    }
    //calcuate - from front to back
    ans = v_num[0];
    for(int i = 0; i < v_op.size(); i++)
    {
        if(v_op[i] == '-')
        {
            ans -= v_num[i + 1];
        }
    }
    
    cout << ans << endl;
    return 0;
}
