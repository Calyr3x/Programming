#include <stdio.h>

void main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int* p = &arr[5];
    printf("%d\n", arr[5]);
    *p = 10;
    printf("%d\n", arr[5]);
}