/*
Написать программу, которая создает срез случайного массива по четным элементам
и вычисляет сумму элементов полученного среза.
*/

#include <stdio.h>
#define size 5

int main(){

    int a[size];
    int b, summ = 0;

    for(int i = 0; i < size; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    b = sizeof(a) / sizeof(int) / 2 + 1;
    int slice[b];

    for(int i = 0; i <= b; i++) slice[i] = i*2;

    for(int i = 0; i < b; i++){
        summ += a[slice[i]];
    }

    printf("sum of elems in the slice = %d\n", summ);
    
}