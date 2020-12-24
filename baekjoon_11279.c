//Priority Queue Problem
#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

typedef struct _priority_queue{
    int numOfData;
    int arr[MAX_LEN];
} priority_queue;

int compare(const int a, const int b){
    return b - a;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pqInit(priority_queue* pq){
    pq->numOfData = 0;
}

int maxEleIdx(priority_queue* pq, int idx){
    int left_child = idx * 2, right_child = idx * 2 + 1;
    if(left_child > pq->numOfData) return -1;
    else if(left_child == pq->numOfData) return left_child;
    else{
        if(pq->arr[left_child] < pq->arr[right_child]) return right_child;
        else return left_child;
    }
}

void pqInsert(priority_queue* pq, int data){
    if(pq->numOfData >= MAX_LEN) return;
    int idx = pq->numOfData + 1;
    pq->arr[idx] = data;
    while(idx != 1){
        if(compare(pq->arr[idx], pq->arr[idx / 2]) < 0){
            swap(&pq->arr[idx], &pq->arr[idx / 2]);
            idx /= 2;
        }
        else break;
    }
    pq->numOfData += 1;
}

int pqDelete(priority_queue* pq){
    if(pq->numOfData <= 0) return 0;
    int retData = pq->arr[1];
    int lastEle = pq->arr[pq->numOfData];
    pq->numOfData -= 1;
    pq->arr[1] = lastEle;

    int parent_idx = 1;
    int child_idx;
    child_idx = maxEleIdx(pq, parent_idx);
    while(child_idx >= 0){
        if(pq->arr[parent_idx] >= pq->arr[child_idx]) break;
        swap(&pq->arr[parent_idx], &pq->arr[child_idx]);
        parent_idx = child_idx;
        child_idx = maxEleIdx(pq, parent_idx);
    }
    return retData;
}

int main(){
    int n;
    scanf("%d", &n);
    priority_queue pq;
    pqInit(&pq);
    for(int i = 0; i < n; i++){
        int command;
        scanf("%d", &command);
        if(command) pqInsert(&pq, command);
        else printf("%d\n", pqDelete(&pq));
    }
    return 0;
}
