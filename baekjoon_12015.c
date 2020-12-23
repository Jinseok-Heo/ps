//LIS Problem using binary search
#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int bin_search(int* arr, int n, int target){
    int left = 0, right = n, mid = 0;
    while(left != right){
        mid = (left + right) / 2;
        if(arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(){
    int n, s;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    int* storage = (int*)malloc(MAX * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    s = 0;
    storage[0] = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > storage[s]) storage[++s] = arr[i];
        else{
            int idx = bin_search(storage, s, arr[i]);
            storage[idx] = arr[i];
        }
    }
    printf("%d\n", s + 1);
    free(arr);
    return 0;
}
