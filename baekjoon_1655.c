#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 100000

typedef struct _priority_queue{
    int (*compare)(int a, int b);
    int numOfData;
    int arr[MAX_LEN];
} priority_queue;

int l_compare(const int a, const int b);
int r_compare(const int a, const int b);
void swap(int* a, int* b);
void pqInit(priority_queue* pq, int (*compare)(int a, int b));
int highPriEleIdx(priority_queue* pq, int idx);
void pqInsert(priority_queue* pq, int data);
int pqDelete(priority_queue* pq);

int main(){
    int n, mid;
    scanf("%d", &n);
    priority_queue l_pq; //Decreasing Array which has to use max_function
    priority_queue r_pq; //Increasing Array which has to use min_function
    pqInit(&l_pq, l_compare);
    pqInit(&r_pq, r_compare);
    for(int i = 0; i < n; i++){
        int command;
        scanf("%d", &command);
        if(i == 0) {
            pqInsert(&l_pq, command);
            mid = command;
        }
        else{
            if(command >= mid) pqInsert(&r_pq, command);
            else               pqInsert(&l_pq, command);

            while(1){
                if(l_pq.numOfData - r_pq.numOfData == 0 || l_pq.numOfData - r_pq.numOfData == 1){
                    mid = l_pq.arr[1];
                    break;
                }
                else if(l_pq.numOfData - r_pq.numOfData == -1){
                    mid = r_pq.arr[1];
                    break;
                }
                else{
                    if(l_pq.numOfData > r_pq.numOfData){
                        pqInsert(&r_pq, pqDelete(&l_pq));
                    }
                    else{
                        pqInsert(&l_pq, pqDelete(&r_pq));
                    }
                }
            }
            
        }
        printf("%d\n", mid);
    }
    return 0;
}

int l_compare(const int a, const int b){
    return a - b;
}
int r_compare(const int a, const int b){
    return b - a;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pqInit(priority_queue* pq, int (*compare)(int a, int b)){
    pq->numOfData = 0;
    pq->compare = compare;
}

int highPriEleIdx(priority_queue* pq, int idx){
    int left_child = idx * 2, right_child = idx * 2 + 1;
    if(left_child > pq->numOfData) return -1;
    else if(left_child == pq->numOfData) return left_child;
    else{
        if(pq->compare(pq->arr[left_child], pq->arr[right_child]) >= 0) return left_child;
        else return right_child;
    }
}

void pqInsert(priority_queue* pq, int data){
    if(pq->numOfData >= MAX_LEN) return;
    int idx = pq->numOfData + 1;
    pq->arr[idx] = data;

    while(idx != 1){
        if(pq->compare(pq->arr[idx], pq->arr[idx / 2]) > 0){
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
    child_idx = highPriEleIdx(pq, parent_idx);
    while(child_idx >= 0){
        if(pq->compare(pq->arr[parent_idx], pq->arr[child_idx]) >= 0) break;
        swap(&pq->arr[parent_idx], &pq->arr[child_idx]);
        parent_idx = child_idx;
        child_idx = highPriEleIdx(pq, parent_idx);
    }
    return retData;
}
