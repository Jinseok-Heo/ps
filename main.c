#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>

long long min(long long a, long long b) { return a < b ? a : b; }

long long check(long long n, long long k, long long target){
    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += min(n, target / i);
    }
    if(cnt >= k) return 1;
    else return 0;
}

long long bin_search(long long n, long long k){
    long long left = 1, right = n * n, mid = 0;
    while(left <= right){
        mid = (left + right) % 2 ? (left + right) / 2 + 1 : (left + right) / 2;
        if(check(n, k, mid) && !check(n, k, mid - 1)) return mid;
        if(check(n, k, mid)) right = mid - 1;
        else left = mid;
    }
    return left;
}

int main(){
    long long n, k;
    scanf("%lld %lld", &n, &k);
    if(n == 1){
        printf("1\n");
        return 0;
    }
    printf("%lld\n", bin_search(n, k));
    return 0;
}