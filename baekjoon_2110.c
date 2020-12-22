#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>

int* loc;
int n, c;

int cmp(const void* a, const void* b){
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}

int check(int k){
    int cnt = 1, temp = loc[0];
    for(int i = 1; i < n; i++){
        if(loc[i] - temp >= k) {
            cnt++;
            temp = loc[i];
        }
    }
    if(cnt >= c) return 1;
    else return 0;
}

long long bin_search(void){
    long long left = loc[0], right = loc[n - 1], mid = 0;
    while(left != right){
        mid = (left + right) % 2 ? (left + right) / 2 + 1 : (left + right) / 2;
        printf("%lld %lld %lld\n", left, mid, right);
        if(check(mid)) left = mid;
        else right = mid - 1;
    }
    return left;
}

int main(){
    scanf("%d %d", &n, &c);
    loc = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &loc[i]);
    qsort(loc, n, sizeof(int), cmp);
    
    printf("%lld\n", bin_search());
    free(loc);
    return 0;
}
