#include <stdio.h>

void main(){
    int a = 15;
    int* p = &a;
    printf("%d %d %d\n", a, *p, *&a);
}