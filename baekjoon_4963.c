//DFS Algorithm
#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 52

int w, h;
int map[MAX][MAX];

void bfs(int x, int y){
    if(map[x][y] == 1){
        map[x][y] = 2;
        bfs(x + 1, y);      //right
        bfs(x, y + 1);      //up
        bfs(x - 1, y);      //left
        bfs(x, y - 1);      //down
        bfs(x - 1, y - 1);  //left down
        bfs(x + 1, y + 1);  //right up
        bfs(x + 1, y - 1);  //right down
        bfs(x - 1, y + 1);  //left up
    }
    return;
}

int island(void){
    int cnt = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(map[i][j] == 1){
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main(){
    scanf("%d %d", &w, &h);
    while(w && h){
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++) scanf("%d", &map[i][j]);
        }
        printf("%d\n", island());
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++) map[i][j] = 0;
        }
        scanf("%d %d", &w, &h);
    }
    return 0;
}
