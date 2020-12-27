#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){
    int n;
    scanf("%d", &n);
    int* d = (int*)calloc(n + 1, sizeof(int));
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for(int i = 0; i <= n; i++) dp[i] = (int*)calloc(n + 1, sizeof(int));
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        getchar();
        d[i] = a;
        if(i == n - 1) d[i + 1] = b;
    }
    for(int i = 0; i <= n; i++) printf("%d ", d[i]);
    printf("\n");
    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            int m = INT_MAX;
            for(int k = j; k < i; k++){
                m = m < dp[j][k] + dp[k + 1][i] + d[j - 1] * d[k] * d[i] ? m : dp[j][k] + dp[k + 1][i] + d[j - 1] * d[k] * d[i];
            }
            dp[j][i] = m;
        }
    }
    printf("%d\n", dp[1][n]);
    free(d);
    for(int i = 0; i <= n; i++) free(dp[i]);
    free(dp);
    return 0;
}