#define _CRT_NO_SECURE_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 10000
#define NUM 3

int n;
char arr[MAX][MAX];

void stars(int size, int center_x, int center_y){
    if(size <= 0){
        return;
    }
    //Center blank
    for(int i = center_x - (size - 1) / 2; i <= center_x + (size - 1) / 2; i++){
        for(int j = center_y - (size - 1) / 2; j <= center_y + (size - 1) / 2; j++){
            arr[i][j] = ' ';
        }
    }
    //Other 8 blanks
    stars(size / 3, center_x - size, center_y - size);
    stars(size / 3, center_x       , center_y - size);
    stars(size / 3, center_x + size, center_y - size);
    stars(size / 3, center_x - size, center_y);
    stars(size / 3, center_x + size, center_y);
    stars(size / 3, center_x - size, center_y + size);
    stars(size / 3, center_x       , center_y + size);
    stars(size / 3, center_x + size, center_y + size);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) arr[i][j] = '*';
    }
    stars(n / 3, n / 2, n / 2);

    for(int i = 0; i < n / 3; i++){
        for(int j = 0; j < n / 3; j++) printf("%c", arr[i][j]);
        printf("\n");
    }
    return 0;
}