#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

int b_cnt = 0, w_cnt = 0;

void quadtree(vector<vector<char>> data, int begin_x, int begin_y, int size)
{
    char check = data[begin_x][begin_y];
    for(int i = begin_x; i < begin_x + size; i++)
    {
        for(int j = begin_y; j < begin_y + size; j++)
        {
            if(check != data[i][j])//if data[begin_x][begin_y] is different to other elements
            {
                check = '2';
                //devide to 4 sections
                quadtree(data, begin_x, begin_y, size / 2);
                quadtree(data, begin_x + size / 2, begin_y, size / 2);
                quadtree(data, begin_x, begin_y + size / 2, size / 2);
                quadtree(data, begin_x + size / 2, begin_y + size / 2, size / 2);
                return;
            }
        }
    }
    if(check == '0') w_cnt++;      //if all elements are white count white
    else if(check == '1') b_cnt++; //if all elements are blue count blue
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> data(n, vector<char>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> data[i][j];
    }
    quadtree(data, 0, 0, n);
    
    cout << w_cnt << "\n" << b_cnt << endl;
    
    return 0;
}
