#include <stdio.h>

void main(){
    int arr[10] = {0};
    int* p0 = &arr[9];
    int* p1 = &arr[9];
    for(int i = 0; i < 10; i++, p0++) printf("%ld\n", p0-p1);
}