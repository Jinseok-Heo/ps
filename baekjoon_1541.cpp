#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    stack<char> bracket;
    stack<char> end_brk;
    
    getline(cin, str);
    while(str.front() != '.')//stop till string is just '.'
    {
        int i = 0;
        //make a string with only brackets
        while(str[i] != '.')
        {
            if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
                bracket.push(str[i]);
            i++;
        }
        while(!bracket.empty())
        {
            //when the top element is ) or ], push it into end_brk stack
            if(bracket.top() == ')' || bracket.top() == ']')
            {
                end_brk.push(bracket.top());
                bracket.pop();
                continue;
            }
            //when the top element is ( or [, compare to top element of end_brk
            else if(bracket.top() == '(')
            {
                //if a pair of brackets exists '(', ')' or '[', ']', pop it
                if(!end_brk.empty() && end_brk.top() == ')')
                {
                    bracket.pop();
                    end_brk.pop();
                    continue;
                }
                //if there's no pair of brakets, it's not balanced string
                break;
            }
            else if(bracket.top() == '[')
            {
                if(!end_brk.empty() && end_brk.top() == ']')
                {
                    bracket.pop();
                    end_brk.pop();
                    continue;
                }
                break;
            }
        }
        //when all brackets popped out, print "yes" if not print "no"
        if(bracket.empty() && end_brk.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        
        //clear stacks and string
        while(!bracket.empty()) bracket.pop();
        while(!end_brk.empty()) end_brk.pop();

        str.clear();
        getline(cin, str);
    }
    return 0;
}
