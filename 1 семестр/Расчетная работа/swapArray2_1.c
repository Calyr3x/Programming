// Матрица хранится по столбцам, меняются столбцы
#include <stdio.h>
#include <stdlib.h>
#define swap(x,y) {x = x + y; y = x - y; x = x - y; }
#define print printArr(&a, &row, &N)

void printArr(int a[], int *row, int *N){
    int t = 0;
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *N; j += *row){
            printf("%d\t", a[i+j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int N, row, column, t = 0;
    printf("Кол-во строк в матрице: ");
    scanf("%d", &row);
    printf("Кол-во столбцов в матрице: ");
    scanf("%d", &column);
    N = row*column;
    int a[N];
    int a1[row][column];
    int k = -1;
    for(int i = 0; i < row; i++) for (int j = 0; j < column; j++) a1[i][j] = rand() % 1000+1;

    for(int j = 0; j < column; j++){
        for(int i = 0; i < row; i++){
            k++;
            a[k] = a1[j][i];
        }
    }

    printf("\n");
    for(int i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");
    print;

    for(int i = 0; i < ((row+1) % 2 ? N : N - row); i++){
        if(t < row){ swap(a[i+row], a[i]); t++; }
        else{
            i += row-1;
            t = 0;
        }
    }
    print;

}