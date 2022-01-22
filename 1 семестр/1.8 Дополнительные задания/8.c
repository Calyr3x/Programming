/*
Написать программу, которая создает срез обеих диагоналей квадратной матрицы и
сливает срезы в новый массив. Матрицу задать прямо в программе.
*/

#include <stdio.h>
#define size 3

int main(){

    int a[size][size] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int slice1[size];
    int slice2[size*2];
    int k1 = 0, k2 = size-1;
    int summ = 0;

    for(int i = 0; i < size; i++) slice1[i] = i;
    /* Побочная диагональ
    Первый элемент - i,
    Второй - j. */
    for(int i = 0; i < size*2; i++){
        if(i % 2 == 0){
            slice2[i] = k1;
            k1++;
        }
        else{
            slice2[i] = k2;
            k2--;
        }
    }

    /* Слияние двух срезов в один массив
    Первая строка - первый срез
    Вторая - второй срез
    */
    int slice[2][size*2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < size*2; j++){
            if(i == 0){
                slice[i][j] = slice1[j];
            }
            if(i == 0 && j == size-1) break;
            if(i == 1) slice[i][j] = slice2[j];
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < size*2; j++){
            if(i == 0){
                summ += a[slice[i][j]][slice[i][j]];
            }
            if(i == 0 && j == size-1) break;
            if(j % 2 == 0 && i == 1) summ += a[slice[i][j]][slice[i][j+1]];
        }
    }

    printf("%d\n", summ); 

}
