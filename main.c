#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 501

int w, h;
int map[MAX][MAX], dp[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y){
    if(x == h - 1 && y == w - 1){
        return 1;
    }
    if(dp[x][y] == -1){
        dp[x][y] = 0;
        int n_x, n_y;
        for(int i = 0; i < 4; i++){
            n_x = x + dx[i];
            n_y = y + dy[i];
            if(n_x >= 0 && n_y >= 0 && n_x < h && n_y < w && map[n_x][n_y] < map[x][y]){
                dp[x][y] += dfs(n_x, n_y);
            }
        }
    }
    return dp[x][y];
}

int main(){
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
    printf("%d\n", dfs(0, 0));
    return 0;
}