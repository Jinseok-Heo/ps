#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>

using namespace std;

bool isAlphabet(char c) {
    if(c > 'z' || c < 'a') return false;
    else return true;
}

bool isNumber(char c) {
    if(c > '9' || c < '0') return false;
    else return true;
}

void first_step(string* id) {
    for(int i = 0; i < (*id).size(); i++) {
        (*id)[i] = tolower((*id)[i]);
    }
}
void sec_step(string* id) {
    string new_id = (*id);
    for(int i = 0; i < new_id.size(); i++) {
        if(!isNumber(new_id[i]) && !isAlphabet(new_id[i]) && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
            new_id.erase(i--, 1);
        }
    }
    *id = new_id;
}
void third_step(string* id) {
    string new_id = (*id);
    int firstDot_idx = -2, cnt = 1;
    for(int i = 0; i < new_id.size(); i++) {
        if(new_id[i] == '.') {
            if(firstDot_idx == -2) {
                firstDot_idx = i;
                continue;
            }
            if(firstDot_idx + 1 == i) {
                new_id.erase(i--, 1);
            }
            else {
                firstDot_idx = i;
            }
        }
    }
    *id = new_id;
}
void fourth_step(string* id) {
    if((*id)[0] == '.') {
        (*id).erase(0, 1);
    }
    if((*id)[(*id).size() - 1] == '.') {
        (*id).erase((*id).size() - 1, 1);
    }
}
void fifth_step(string* id) {
    if(!(*id).size()) (*id) = "a";
}
void sixth_step(string* id) {
    if((*id).size() >= 16) (*id).erase(15);
    fifth_step(id);
    fourth_step(id);
}
void seventh_step(string* id) {
    if((*id).size() < 3) {
        (*id) += (*id)[(*id).size() - 1];
    }
    else return;
    seventh_step(id);
}

string find_id(string current_id) {
    first_step(&current_id);
    sec_step(&current_id);
    third_step(&current_id);
    fourth_step(&current_id);
    fifth_step(&current_id);
    sixth_step(&current_id);
    seventh_step(&current_id);
    return current_id;
}

string solution(string new_id) {
    string answer = "";
    answer = find_id(new_id);
    return answer;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    string cur_id;
    cin >> cur_id;
    cout << solution(cur_id) << "\n";

    return 0;
}
