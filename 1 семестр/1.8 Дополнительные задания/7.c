/*
Написать программу, которая создает срез главной диагонали квадратной матрицы и
вычисляет сумму элементов полученного среза. Матрицу задать прямо в программе.
*/

#include <stdio.h>
#define size 3

int main(){

    int a[size][size] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int slice[size];
    int summ = 0;

    for(int i = 0; i < size; i++) slice[i] = i;

    for(int i = 0; i < size; i++){
        summ += a[slice[i]][slice[i]]; 
    }

    printf("%d\n", summ); 

}