// Матрица хранится по строкам, меняются столбцы
#include <stdio.h>
#include <stdlib.h>
#define swap(x,y) {x = x + y; y = x - y; x = x - y; }
#define print printArr(&a, &column, &N)

void printArr(int a[], int *column, int *N){
    for(int i = 0; i < *N; i++){
        if(i % *column == 0) printf("\n");
        printf("%d\t", a[i]); 
    }
    printf("\n");
}

int main(){
    int N, row, column;
    printf("Кол-во строк в матрице: ");
    scanf("%d", &row);
    printf("Кол-во столбцов в матрице: ");
    scanf("%d", &column);
    int t = column-1;
    N = row*column;
    int a[N];
    int a1[row][column];

    for(int i = 0; i < row; i++) for (int j = 0; j < column; j++) a1[i][j] = rand() % 1000+1;
    for(int i = 0; i < row; i++) for (int j = 0; j < column; j++) a[i+column*j] = a1[i][j];

    printf("\n");
    for(int i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");
    print;

    for(int i = 0; i < N; i += 2){
        if(i == t){ t += column; i++; }
        swap(a[i+1], a[i]);
    }
    print;

}