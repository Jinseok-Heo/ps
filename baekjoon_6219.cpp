#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool PrimeChecker(int n)//if the number n is prime number, return true
{
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

bool NumChecker(int n, int d)//if the number n includes the number i, return true
{
    int len_d = 0, temp = d;
    while(temp != 0)
    {
        len_d++;
        temp /= 10;
    }
    len_d = (int)pow(10, len_d);
    while(n != 0)
    {
        if(n % len_d == d) return true;
        n /= 10;
    }
    return  false;
}

int main()
{
    int a, b, d, cnt = 0;
    cin >> a >> b >> d;
    
    for(int i = a; i <= b; i++)
    {
        if(PrimeChecker(i) == true && NumChecker(i, d) == true) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
