#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 100000

typedef struct _priority_queue{
    int numOfData;
    int arr[MAX_LEN];
} priority_queue;

int compare(const int a, const int b){
    if(abs(a) < abs(b)) return 1;
    else if(abs(a) > abs(b)) return -1;
    else{
        return b - a;
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pqInit(priority_queue* pq){
    pq->numOfData = 0;
}

int minEleIdx(priority_queue* pq, int idx){
    int left_child = idx * 2, right_child = idx * 2 + 1;
    if(left_child > pq->numOfData) return -1;
    else if(left_child == pq->numOfData) return left_child;
    else{
        if(compare(pq->arr[left_child], pq->arr[right_child]) >= 0) return left_child;
        else return right_child;
    }
}

void pqInsert(priority_queue* pq, int data){
    if(pq->numOfData >= MAX_LEN) return;
    int idx = pq->numOfData + 1;
    pq->arr[idx] = data;
    while(idx != 1){
        if(compare(pq->arr[idx], pq->arr[idx / 2]) > 0){
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
    child_idx = minEleIdx(pq, parent_idx);
    while(child_idx >= 0){
        if(compare(pq->arr[parent_idx], pq->arr[child_idx]) >= 0) break;
        swap(&pq->arr[parent_idx], &pq->arr[child_idx]);
        parent_idx = child_idx;
        child_idx = minEleIdx(pq, parent_idx);
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