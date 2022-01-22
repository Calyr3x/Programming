#include <stdio.h>

void main(){
    int temp;
    int arr[] = {1, 2, 3, 4, 5};
    int* p0 = arr;
    int* p4 = &arr[4];
    for(int i = 0; i < 2; i++, p0++, p4--){
        temp = *p0;
        *p0 = *p4;
        *p4 = temp;
    }
    for(int i = 0; i < 5; i++) printf("%d ", arr[i]);
}