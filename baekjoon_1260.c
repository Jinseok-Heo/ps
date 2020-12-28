#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 1000

int n, m, v, res_size;
int map[MAX][MAX];
int res[MAX];

//If target location "loc" is already exist return 0, if not return 1
int check(int* arr, int loc, int len){
    for(int i = 0; i < len; i++){
        if(arr[i] == loc) return 0;
    }
    return 1;
}
//Find Graph With DFS Algorithm
void dfs(int level, int loc){
    if(level == 1) {
        res[0] = loc;
        res_size = 1;
    }
    for(int i = 0; i < n; i++){
        if(check(res, i, res_size) && map[loc][i]){
            res[res_size++] = i;
            dfs(level + 1, i);
        }
    }
}
//Find Graph With BFS Algorithm
void bfs(int loc){
    for(int i = 0; i < n; i++) res[i] = 0;  //Initialize res which functions like Queue
    int top = 0, bot = 0, q_size;
    res[0] = loc; bot = 1; q_size = bot - top;
    while(q_size){
        int t_loc = res[top];
        for(int i = 0; i < n; i++){
            if(check(res, i, bot) && map[t_loc][i]){
                //q.push(i)
                res[bot++] = i;
            }
        }
        //q.pop()
        top++;
        q_size = bot - top;
    }
    for(int i = 0; i < bot; i++) printf("%d ", res[i] + 1);
    printf("\n");
}

int main(){
    scanf("%d %d %d", &n, &m, &v);
    int x, y;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        getchar();
        map[x - 1][y - 1] = 1;
        map[y - 1][x - 1] = 1;
    }
    if(n == 1){
        if(x == v && y == v) printf("%d\n", v);
        return 0;
    }
    v--;
    dfs(1, v);
    for(int i = 0; i < res_size; i++){
        printf("%d ", res[i] + 1);
    }
    printf("\n");
    bfs(v);
    return 0;
}
