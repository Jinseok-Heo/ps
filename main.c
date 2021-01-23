#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 100005
#define TRUE 1
#define FALSE 0

long long recursive(long long x, long long y, long long z){
    if(y == 0) return 1;
    if(y == 1) return x % z;
    long long res = recursive(x, y / 2, z) % z;
    if(y % 2){
        return ((res * res) % z * x) % z;
    }
    else{
        return (res * res) % z;
    }
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%lld\n", recursive(a, b, c) % c);
	return 0;
}