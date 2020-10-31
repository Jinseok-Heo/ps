#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <cstdio>
#define MAX 2187

using namespace std;

int res[3];
int data[MAX][MAX];

void quadtree(int begin_x, int begin_y, int size)
{
    int check = data[begin_x][begin_y];
    for(int i = begin_x; i < begin_x + size; i++)
    {
        for(int j = begin_y; j < begin_y + size; j++)
        {
            if(check != data[i][j])
            {
                size /= 3;
                quadtree(begin_x, begin_y, size);
                quadtree(begin_x, begin_y + size, size);
                quadtree(begin_x, begin_y + size * 2, size);
                
                quadtree(begin_x + size, begin_y, size);
                quadtree(begin_x + size, begin_y + size, size);
                quadtree(begin_x + size, begin_y + size * 2, size);
                
                quadtree(begin_x + size * 2, begin_y, size);
                quadtree(begin_x + size * 2, begin_y + size, size);
                quadtree(begin_x + size * 2, begin_y + size * 2, size);
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
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> data[i][j];
    }
    
    quadtree(0, 0, n);
    
    for(auto& e : res) cout << e << "\n";
    return 0;
}
