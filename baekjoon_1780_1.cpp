//Didn't work, it works over time limits
//Can't understand why this code takes over time
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

int res[3];

void quadtree(vector<vector<int>> data, int begin_x, int begin_y, int size)
{
    int check = data[begin_x][begin_y];
    for(int i = begin_x; i < begin_x + size; i++)
    {
        for(int j = begin_y; j < begin_y + size; j++)
        {
            if(check != data[i][j])
            {
                size /= 3;
                quadtree(data, begin_x, begin_y, size);
                quadtree(data, begin_x, begin_y + size, size);
                quadtree(data, begin_x, begin_y + size * 2, size);
                
                quadtree(data, begin_x + size, begin_y, size);
                quadtree(data, begin_x + size, begin_y + size, size);
                quadtree(data, begin_x + size, begin_y + size * 2, size);
                
                quadtree(data, begin_x + size * 2, begin_y, size);
                quadtree(data, begin_x + size * 2, begin_y + size, size);
                quadtree(data, begin_x + size * 2, begin_y + size * 2, size);
                return;
            }
        }
    }
    if(check == 1) res[2]++;
    else if(check == 0) res[1]++;
    else if(check == -1) res[0]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> data(n, vector<int> (n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> data[i][j];
    }
    
    quadtree(data, 0, 0, n);
    
    for(auto& e : res) cout << e << "\n";
    return 0;
}
