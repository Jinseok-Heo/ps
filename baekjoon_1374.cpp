#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>

typedef struct _classroom{
    int s;
    int e;
} classroom;

using namespace std;

bool compare(const classroom& a, const classroom& b){
    if(a.s == b.s){
        return a.e < b.e;
    }
    else{
        return a.s < b.s;
    }
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<classroom> data(n + 1);
    vector<int> room;
    bool flag;
    for(int i = 0; i < n; i++){
        int idx, s, e;
        cin >> idx >> s >> e;
        data[idx] = (classroom){s, e};
    }
    sort(data.begin(), data.end(), compare);

    room.push_back(data[1].e);

    for(int i = 2; i <= n; i++){
        int s_time = data[i].s;
        int e_time = data[i].e;
        flag = false;
        for(int j = 0; j < room.size(); j++){
            if(room[j] <= s_time){
                room[j] = e_time;
                flag = true;
                break;
            }
        }
        if(!flag) room.push_back(e_time);
    }
    cout << room.size() << endl;
    return 0;
}
