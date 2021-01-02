#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 100001
#define TRUE 1
#define FALSE 0

int nodes[MAX][100];
char isPassed[MAX];
int parent_nodes[MAX];

void bfs(void){
    int q[MAX] = { 0, };
    int top, bot, q_size;
    top = 0; bot = 1; q_size = bot - top;
    q[0] = 1;
    isPassed[1] = TRUE;

    while(q_size){
        int q_top = q[top];
        for(int i = 1; i <= nodes[q_top][0]; i++){
            if(!isPassed[nodes[q_top][i]]){
                parent_nodes[nodes[q_top][i]] = q_top;
                isPassed[nodes[q_top][i]] = TRUE;
                q[bot++] = nodes[q_top][i];
            }
        }
        top++;
        q_size = bot - top;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        nodes[x][++nodes[x][0]] = y;
        nodes[y][++nodes[y][0]] = x;
        isPassed[i] = FALSE;
    }
    bfs();
    for(int i = 2; i <= n; i++){
        printf("%d\n", parent_nodes[i]);
    }

	return 0;
}