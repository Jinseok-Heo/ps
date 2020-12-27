#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int test_case;
    scanf("%d", &test_case);
    getchar();
    for(int t = 0; t < test_case; t++){
        int n, storage = 0;
        scanf("%d", &n);
        getchar();
        int** dp = (int**)malloc(n * sizeof(int*));
        int* sum = (int*)calloc(n + 1, sizeof(int));
        for(int i = 0; i < n; i++){
            int temp;
            scanf("%d", &temp);
            dp[i] = (int*)calloc(n, sizeof(int));
            storage += temp;
            sum[i + 1] = storage;
        }
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(!dp[j][i]){
                    int m = 100000;
                    for(int k = j; k < i; k++){
                        m = m < dp[j][k] + dp[k + 1][i] + sum[i + 1] - sum[j] ? m : dp[j][k] + dp[k + 1][i] + sum[i + 1] - sum[j];
                    }
                    dp[j][i] = m;
                }
            }
        }
        printf("%d\n", dp[0][n - 1]);
        for(int i = 0; i < n; i++) free(dp[i]);
        free(dp);
        dp = NULL;
    }
    return 0;
}
