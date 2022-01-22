#include <stdio.h>

int main(){
    int arr[5][5] = {0};
    int* p0 = &arr[24];
    int* p1 = &arr[24];
    for(int i = 0; i < 5*5; i++, p0++){
        printf("%ld\n", p0-p1);
    }
}