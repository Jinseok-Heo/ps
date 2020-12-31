#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 26
#define TRUE 1
#define FALSE 0

int n;
char map[MAX][MAX];
int res[1000];
int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

void dfs(int x, int y, int* res){
    *res += 1;
    map[x][y] = '0';
    for(int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx > 0 && newx <= n && newy >= 0 && newy < n && map[newx][newy] != '0'){
            dfs(newx, newy, res);
        }
    }
}

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(){
    int t_num = 0;
    scanf("%d", &n);
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) map[i][j] = '0';
        res[i] = 0;
    }

    for(int i = 0; i <= n; i++){
        fgets(map[i], MAX, stdin);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] != '0'){
                dfs(i, j, &res[t_num]);
                t_num++;
            }
        }
    }
    qsort(res, t_num, sizeof(int), cmp);
    printf("%d\n", t_num);
    for(int i = 0; i < t_num; i++) printf("%d ", res[i]);
    printf("\n");

    return 0;
}
