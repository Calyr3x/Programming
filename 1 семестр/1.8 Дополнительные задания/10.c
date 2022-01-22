/*
Написать программу, которая создает срез случайного массива по четным элементам и
«разворачивает» срез так, чтобы последний элемент стал первым и т.д., однако делает
это не физически, а посредством создания нового среза.
*/

#include <stdio.h>
#define size 9

int main(){
    int a[size];
    int b, summ = 0;

    for(int i = 0; i < size; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    b = sizeof(a) / sizeof(int) / 2 + 1;
    int slice1[b];
    int slice2[b];
    int k = b-1;

    for(int i = 0; i < b; i++){
        slice1[i] = i*2;
        slice2[i] = k;
        k--;
    }

    //for(int i = 0; i < b; i++) printf("\n%d\n", slice2[i]);
    
    for(int i = 0; i < b; i++){
        printf("%d\n", a[slice1[slice2[i]]]);
    }
    
}