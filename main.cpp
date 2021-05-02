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
#define ll long long
#define INF 987654321

using namespace std;

int new_time(string time_str) {
    int sec;
    sec = stoi(time_str.substr(0, 2)) * 3600;
    sec += stoi(time_str.substr(3, 2)) * 60;
    sec += stoi(time_str.substr(6, 2));
    return sec;
}

p new_log(string log) {
    p n_log;
    n_log.first = new_time(log.substr(0, 8));
    n_log.second = new_time(log.substr(9, 8));
    return n_log;
}

string itosPartial(int t) {
    const int dif = '0' - 0;
    string ret = "";
    while(t) {
        char c = t % 10 + dif;
        ret.push_back(c);
        t /= 10;
    }
    while(ret.size() != 2) {
        ret.push_back('0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string itos(int sec) {
    string ret = "";
    int hour, min, idx = 0;
    hour = sec / 3600;
    min = (sec % 3600) / 60;
    sec = (sec % 3600) % 60;

    ret.append(itosPartial(hour));
    ret.push_back(':');
    ret.append(itosPartial(min));
    ret.push_back(':');
    ret.append(itosPartial(sec));

    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int play_t = new_time(play_time);
    int adv_t = new_time(adv_time);
    int n = logs.size();

    vector<p> new_logs(n);
    for(int i = 0; i < n; i++) {
        new_logs[i] = new_log(logs[i]);
    }
    vector<int> n_playing(play_t + 1, 0);
    for(int i = 0; i < n; i++)
        for(int s = new_logs[i].first; s < new_logs[i].second; s++)
            n_playing[s]++;

    int sum = 0, ans = 0, max_sum;
    for(int i = 0; i < adv_t; i++){
        sum += n_playing[i];
    }
    max_sum = sum;
    for(int i = 1; i < play_t - adv_t + 1; i++) {
        sum = sum - n_playing[i - 1] + n_playing[i + adv_t - 1];
        if(sum > max_sum) {
            max_sum = sum;
            ans = i;
        }
    }
    cout << max_sum << '\n';
    return itos(ans);
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    string play_time, adv_time;
    int n;
    cin >> n;
    vector<string> logs(n);
    cin >> play_time >> adv_time;
    for(int i = 0; i < n; i++) cin >> logs[i];

    cout << solution(play_time, adv_time, logs) << '\n';
    return 0;
}