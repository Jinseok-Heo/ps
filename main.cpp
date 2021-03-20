#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <unordered_map>
#define p pair<int, int>

using namespace std;

bool compare(p a, p b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<p> classInfo(n);
    priority_queue< int, vector<int>, cmp > classroom;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        classInfo[i] = make_pair(s, e);
    }

    sort(classInfo.begin(), classInfo.end(), compare);
    
    classroom.push(classInfo[0].second);

    for(int i = 1; i < n; i++) {
        if(classroom.top() > classInfo[i].first) {
            classroom.push(classInfo[i].second);
        }
        else {
            classroom.pop();
            classroom.push(classInfo[i].second);
        }
    }
    cout << classroom.size() << endl;

    return 0;
}