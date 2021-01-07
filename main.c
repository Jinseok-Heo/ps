#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 102
#define TRUE 1
#define FALSE 0

typedef struct  _loc
{
    int x;
    int y;
    int z;
} loc;

typedef struct _node{
    loc value;
    struct _node* next;
} node;

typedef struct _queue{
    int q_size;
    node* front;
    node* back;
} queue;

void queueInit(queue* q);
char qIsEmpty(queue* q);
void queuePush(queue* q, loc data);
loc queuePop(queue* q);
void dataInit(void);
void inputData(void);
void bfs(void);

queue q;
loc max_size;
int dayAfter;
int tomatoes[MAX][MAX][MAX];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(){
    inputData();
    bfs();
    
    //If there's not yet ripped fruit, print -1
    for(int k = 1; k <= max_size.z; k++){
        for(int i = 1; i <= max_size.y; i++){
            for(int j = 1; j <= max_size.x; j++){
                if(tomatoes[i][j][k] == 0){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    printf("%d\n", dayAfter - 1);
	return 0;
}

void queueInit(queue* q){
    q->q_size = 0;
    q->back = NULL;
    q->front = NULL;
}
char qIsEmpty(queue* q){
    if(q->front == NULL) return 1;
    else                 return 0;
}
void queuePush(queue* q, loc data){
    node* n_node = (node*)malloc(sizeof(node));
    n_node->next = NULL;
    n_node->value = data;
    q->q_size += 1;

    if(qIsEmpty(q)){
        q->front = n_node;
        q->back = n_node;
    }
    else{
        q->back->next = n_node;
        q->back = n_node;
    }
}
loc queuePop(queue* q){
    loc topData;
    node* topNode;
    q->q_size -= 1;

    if(qIsEmpty(q)){
        printf("Error.\n");
        exit(-1);
    }

    topNode = q->front;
    topData = q->front->value;
    q->front = q->front->next;

    free(topNode);
    return topData;
}
void dataInit(void){
    for(int k = 0; k < MAX; k++){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++) tomatoes[i][j][k] = -1;
        }
    }
}
void inputData(void){
    scanf("%d %d %d", &max_size.x, &max_size.y, &max_size.z);    
    dataInit();
    queueInit(&q);
    for(int k = 1; k <= max_size.z; k++){
        for(int i = 1; i <= max_size.y; i++){
            for(int j = 1; j <= max_size.x; j++) {
                scanf("%d", &tomatoes[i][j][k]);
                if(tomatoes[i][j][k] == 1){
                    queuePush(&q, (loc){i, j, k});
                }
            }
        }
    }
}
void bfs(void){
    while(q.q_size){
        dayAfter++;
        int size_temp = q.q_size;
        while(size_temp--){
            loc q_top = queuePop(&q);
            for(int i = 0; i < 6; i++){
                loc n_loc;
                n_loc.x = q_top.x + dx[i];
                n_loc.y = q_top.y + dy[i];
                n_loc.z = q_top.z + dz[i];
                if(tomatoes[n_loc.x][n_loc.y][n_loc.z] == 0){
                    tomatoes[n_loc.x][n_loc.y][n_loc.z] = 2;
                    queuePush(&q, n_loc);
                }
            }
        }
    }
    return;
}