#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 10000000000000
#define TRUE 1
#define FALSE 0

int* data;
int n, m;

char check(long long target){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += (long long)(target / data[i]);
    }
    if(sum >= m) return TRUE;
    else return FALSE;
}

long long bin_search(void){
    long long left, right, mid;
    left = 0; right = MAX; mid = (right + left) / 2;

    while(left != right){
        if(check(mid)) right = mid;
        else                       left  = mid + 1;
        mid = (right + left) / 2;
    }
    return left;
}

int main(){
    scanf("%d %d", &n, &m);
    data = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &data[i]);

    printf("%lld\n", bin_search());
    free(data);
	return 0;
}
