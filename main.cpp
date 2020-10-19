#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

pair<long long, long long> CountZero(long long n)
{
    long long cnt_2 = 0, cnt_5 = 0;
    for(long long i = 2; i <= n; i *= 2) cnt_2 += n / i;
    for(long long i = 5; i <= n; i *= 5) cnt_5 += n / i;
    
    return pair<long long, long long>(cnt_2, cnt_5);
}

int main()
{
    long long n, m, t_two, t_five, min;
    pair<long long, long long> cnt_n, cnt_r, cnt_nr;
    cin >> n >> m;
    cnt_n = CountZero(n);
    cnt_r = CountZero(m);
    cnt_nr = CountZero(n - m);
    
    t_two = cnt_n.first - cnt_r.first - cnt_nr.first;
    t_five = cnt_n.second - cnt_r.second - cnt_nr.second;
    
    min = t_two < t_five ? t_two : t_five;
    
    cout << min << endl;
    return 0;
}
