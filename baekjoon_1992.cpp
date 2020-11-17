#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

void quadtree(vector<string> data, int begin_x, int begin_y, int size);

int main()
{
    int n;
    cin >> n;
    vector<string> data(n);
    for(auto& e:data) cin >> e;
    
    quadtree(data, 0, 0, n);
    cout << "\n";
    return 0;
}
void quadtree(vector<string> data, int begin_x, int begin_y, int size)
{
    char check = data[begin_x][begin_y];
    
    for(int i = begin_x; i < begin_x + size; i++)
    {
        for(int j = begin_y; j < begin_y + size; j++)
        {
            if(check != data[i][j])
            {
                cout << "(";
                quadtree(data, begin_x, begin_y, size / 2);
                quadtree(data, begin_x, begin_y + size / 2, size / 2);
                quadtree(data, begin_x + size / 2, begin_y, size / 2);
                quadtree(data, begin_x + size / 2, begin_y + size / 2, size / 2);
                cout << ")";
                return;
            }
        }
    }
    if(check == '0') cout << "0";
    else if(check == '1') cout << "1";
}
