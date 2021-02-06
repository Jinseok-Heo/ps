#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>

using namespace std;

void init_tree(vector<int>& v, vector<int>& t, int node, int s, int e){
    if(s == e) t[node] = s;
    else{
        int mid = (s + e) / 2;
        init_tree(v, t, node * 2, s, mid);
        init_tree(v, t, node * 2 + 1, mid + 1, e);
        if(v[t[node * 2]] < v[t[node * 2 + 1]]){
            t[node] = t[node * 2];
        }
        else{
            t[node] = t[node * 2 + 1];
        }
    }
}

int min_rec(vector<int>& v, vector<int>& t, int node, int s, int e, int i, int j){
    if(e < i || s > j) return -1;
    else if(s >= i && e <= j) return t[node];

    int mid = (s + e) / 2;
    int left_min = min_rec(v, t, node * 2, s, mid, i, j);
    int right_min = min_rec(v, t, node * 2 + 1, mid + 1, e, i, j);

    if(left_min == -1) return right_min;
    else if(right_min == -1) return left_min;
    else if(v[left_min] < v[right_min]) return left_min;
    else return right_min;
}

long long seg_tree(vector<int>& v, vector<int>& t, int start_idx, int end_idx){
    if(start_idx == end_idx) return v[start_idx];
    int min_i = min_rec(v, t, 1, 0, v.size() - 1, start_idx, end_idx);
    long long min_h, max_rec, r_max, l_max;

    min_h = v[min_i];
    max_rec = (long long)min_h * (long long)(end_idx - start_idx + 1);
    r_max = 0, l_max = 0;
    if(min_i > start_idx) l_max = seg_tree(v, t, start_idx, min_i - 1);
    if(min_i < end_idx) r_max = seg_tree(v, t, min_i + 1, end_idx);

    max_rec = max_rec > r_max ? max_rec : r_max;
    max_rec = max_rec > l_max ? max_rec : l_max;

    return max_rec;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int n;
        cin >> n;
        if(!n) break;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int h = (int)ceil(log2(n));
        int t_size = (1 << (h + 1));

        vector<int> tree(t_size);
        init_tree(arr, tree, 1, 0, n - 1);
        
        cout << seg_tree(arr, tree, 0, n - 1) << "\n";
    }
    return 0;
}
