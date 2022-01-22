#include <stdio.h>
#include <stdlib.h>

int main(void){
    int arr[25];
    for(int i = 0; i < 25; i++){
        arr[i] = rand() % 9999 + 1;
        if(i % 5 == 0 && i > 0) printf("\n");
        printf("%4.d ", arr[i]);
    }
}