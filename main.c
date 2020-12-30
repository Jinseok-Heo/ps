#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 101
#define TRUE 1
#define FALSE 0

int n, m;
int arr[MAX][MAX];
int visited[MAX];

void dfs(int* res, int idx){
    visited[idx] = TRUE;
    *res += 1;
    for(int i = 1; i <= n; i++){
        if(arr[idx][i] && !visited[i]){
            printf("%d %d %d\n", *res, idx, i);
            dfs(res, i);
        }
    }
    return;
}

int main(){
    int res = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++) arr[i][j] = FALSE;
        visited[i] = FALSE;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x][y] = TRUE;
        arr[y][x] = TRUE;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }
    dfs(&res, 1);
    printf("%d\n", res - 1);
    return 0;
}