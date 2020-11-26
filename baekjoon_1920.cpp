#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10001];

bool bin_search(int n, int k)
{
    int begin_idx, end_idx, mid_idx;
    begin_idx = 0; end_idx = n - 1;
    while(begin_idx != end_idx)
    {
        mid_idx = (begin_idx + end_idx + 1) / 2;
        if(arr[mid_idx] == k) return true;
        else if(arr[mid_idx] > k)
        {
            end_idx = mid_idx - 1;
        }
        else
        {
            begin_idx = mid_idx;
        }
    }
    if(arr[begin_idx] == k) return true;
    else return false;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<bool> ans;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        ans.push_back(bin_search(n, temp));
    }
    for(auto e:ans) cout << e << "\n";
    return 0;
}
