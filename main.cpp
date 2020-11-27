#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#define MAX 500001

using namespace std;

int card[MAX];

int binary(int n, int target)
{
    int begin_idx[2]{0, 0}, end_idx[2]{n - 1, n - 1}, mid_idx[2];
    while(begin_idx[0] != end_idx[0])
    {
        mid_idx[0] = (begin_idx[0] + end_idx[0] + 1) / 2;
        if(card[mid_idx[0]] > target)
        {
            end_idx[0] = mid_idx[0] - 1;
        }
        else
        {
            begin_idx[0] = mid_idx[0];
        }
    }
    if(card[begin_idx[0]] == target)
    {
        while(begin_idx[1] != end_idx[1])
        {
            mid_idx[1] = (begin_idx[1] + end_idx[1] + 1) / 2;
            if(card[mid_idx[1]]  == target)
            {
                if(mid_idx[1] == 0 || card[mid_idx[1] - 1] != target)
                {
                    begin_idx[1] = mid_idx[1];
                    break;
                }
                end_idx[1] = mid_idx[1] - 1;
            }
            else if(card[mid_idx[1]] > target)
            {
                end_idx[1] = mid_idx[1] - 1;
            }
            else
            {
                begin_idx[1] = mid_idx[1];
            }
        }
        return begin_idx[0] - begin_idx[1] + 1;
    }
    else return 0;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    vector<int> ans;
    cin >> n;
    for(int i = 0; i < n ; i++) cin >> card[i];
    cin >> k;
    sort(card, card + n);
    for(int i = 0; i < k; i++)
    {
        int target;
        cin >> target;
        ans.push_back(binary(n, target));
    }
    for(auto& e : ans) cout << e << "\n";
    return 0;
}
