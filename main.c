#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 100005
#define TRUE 1
#define FALSE 0

//Queue
typedef struct _node{
    int value;
    struct _node* next;
} node;

typedef struct _queue{
    int q_size;
    node* left;
    node* right;
} queue;

void q_init(queue* q){
    q->left = NULL;
    q->right = NULL;
    q->q_size = 0;
}

char q_isempty(queue* q){
    if(q->left == NULL) return TRUE;
    else                return FALSE;
}

void q_push(queue* q, int x){
    node* new_ele = (node*)malloc(sizeof(node));
    new_ele->value = x;
    new_ele->next = NULL;
    q->q_size += 1;

    if(q_isempty(q)){
        q->left = new_ele;
        q->right = new_ele;
    }
    else{
        q->right->next = new_ele;
        q->right = new_ele;
    }
}

int q_pop(queue* q){
    if(q_isempty(q)){
        printf("Error!\n");
        exit(-1);
    }
    int top_value = q->left->value;
    node* top_node = q->left;
    q->left = top_node->next;
    q->q_size -= 1;

    free(top_node);
    return top_value;
}

int n, k;
int dx[3] = {1, -1, 0};

int bfs(queue* q){
    int days = 0;
    char flags[MAX] = { FALSE, };
    flags[n] = TRUE;
    while(!q_isempty(q)){
        days++;
        printf("days : %d\n", days);
        int q_size = q->q_size;
        while(q_size--){
            int loc = q_pop(q);
            if(loc == k){
                return days;
            }
            //Move
            if(loc + 1 >= 0 && loc + 1 < MAX && !flags[loc + 1]){
                q_push(q, loc + 1);
                flags[loc + 1] = TRUE;
            }
            if(loc - 1 >= 0 && loc - 1 < MAX && !flags[loc - 1]){
                q_push(q, loc - 1);
                flags[loc - 1] = TRUE;
            }
            if(loc > 0 && loc * 2 < MAX && !flags[loc * 2]){
                q_push(q, loc * 2);
                flags[loc * 2] = TRUE;
            }
        }
    }
    return days;
}

int main(){
    queue q;
    q_init(&q);
    scanf("%d %d", &n, &k);
    q_push(&q, n);
    printf("%d\n", bfs(&q) - 1);
	return 0;
}