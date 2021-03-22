#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <functional>
#include <unordered_map>
#define p pair<int, int>

using namespace std;

vector<int> db[3][2][2][2];

int bin_search(vector<int>& v, int key, int s, int e) {
    int mid = 0;
    while(1) {
        if(s == e) break;
        mid = (s + e) / 2;
        if(v[mid] >= key) e = mid;
        else              s = mid + 1;
    }
    if(v[s] >= key) return v.size() - s;
    else return v.size() - s - 1;
}

vector<int> processedInfo(string info) {
    vector<int> ret;
    string sub_str = "";
    for(char c : info) {
        if(c == ' ') {
            if(sub_str == "java" || sub_str == "frontend" || sub_str == "junior" || sub_str == "chicken") {
                ret.push_back(0);
            }
            else if(sub_str == "python") {
                ret.push_back(2);
            }
            else {
                ret.push_back(1);
            }
            sub_str = "";
        }
        else {
            sub_str.push_back(c);
        }
    }
    ret.push_back(stoi(sub_str));
    return ret;
}

vector<int> processedQuery(string query) {
    vector<int> ret;
    string sub_str = "";
    for(char c : query) {
        if(c == ' ') {
            if(sub_str == "-") {
                ret.push_back(-1);
            }
            else if(sub_str == "java" || sub_str == "frontend" || sub_str == "junior" || sub_str == "chicken") {
                ret.push_back(0);
            }
            else if(sub_str == "python") {
                ret.push_back(2);
            }
            else if(sub_str == "cpp" || sub_str == "backend" || sub_str == "senior" || sub_str == "pizza") {
                ret.push_back(1);
            }
            sub_str = "";
        }
        else {
            sub_str.push_back(c);
        }
    }
    ret.push_back(stoi(sub_str));
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> ans;
    for(string i : info) {
        vector<int> infovec = processedInfo(i);
        db[infovec[0]][infovec[1]][infovec[2]][infovec[3]].push_back(infovec[4]);
    }
    for(string q : query) {
        vector<int> queryvec = processedQuery(q);
        int sum = 0;
        
        int s[4], e[4];
        s[0] = 0; e[0] = 2;
        for(int i = 0; i < 4; i++) {
            if(queryvec[i] != -1) {
                s[i] = queryvec[i];
                e[i] = queryvec[i];
            }
            else if(queryvec[i] == -1 && i != 0) {
                s[i] = 0; e[i] = 1;
            }
        }

        for(int i = s[0]; i <= e[0]; i++) {
            for(int j = s[1]; j <= e[1]; j++) {
                for(int k = s[2]; k <= e[2]; k++) {
                    for(int l = s[3]; l <= e[3]; l++) {
                        if(!db[i][j][k][l].empty()) {
                            sort(db[i][j][k][l].begin(), db[i][j][k][l].end());
                            sum += bin_search(db[i][j][k][l], queryvec[4], 0, db[i][j][k][l].size() - 1);
                        }
                    }
                }
            }
        }
        ans.push_back(sum);
    }
    return ans;
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<string> info(n), query(m);
    for(int i = 0; i < n; i++) getline(cin, info[i]);
    for(int i = 0; i < m; i++) getline(cin, query[i]);

    vector<int> ans = solution(info, query);
    for(int i : ans) cout << i << "\n";


    return 0;
}