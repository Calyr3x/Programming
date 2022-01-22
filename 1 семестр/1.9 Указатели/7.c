#include <stdio.h>

void main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5];
    //for(int i = 0; i < 5; i++) arr2[i] = 0;
    int* p1 = arr1;
    int* p2 = arr2;
    for(int i = 0; i < 5; p1++, p2++, i++){
        *p2 = *p1;
    }
    for(int i = 0; i < 5; i++) printf("%d ", arr2[i]);
}