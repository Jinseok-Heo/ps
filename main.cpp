#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Closet
{
    string sort;
    int number;
};

int main()
{
    int test_case;

    cin >> test_case;
    for(int i = 0; i < test_case; i++)
    {
        int n_clothes, ans = 1;
        cin >> n_clothes;
        vector<Closet> v_c;
        for(int j = 0; j < n_clothes; j++)
        {
            string clt;
            string srt;
            bool flag{false};
            cin >> clt >> srt;
            for(int k = 0; k < v_c.size(); k++)
            {
                if(v_c[k].sort == srt)
                {
                    v_c[k].number++;
                    flag = true;
                    break;
                }
            }
            if(flag == false) v_c.push_back(Closet{srt, 1});
        }
        for(int j = 0; j < v_c.size(); j++)
            ans *= (v_c[j].number + 1);
        
        cout << ans - 1 << "\n";
        //for(int j = 0; j < v_c.size(); j++)
            //cout << v_c[j].sort << " " << v_c[j].number << "\n";
    }
    
    return 0;
}
