#include <stdio.h>
#include <stdlib.h>
#define m 15
#define n 20

int Sum(int A[n][m]){
    int summ = 0;
    int maxInStr = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (A[i][j] > maxInStr) maxInStr = A[i][j];
            printf("%d ", maxInStr);
        }
        printf("\n");
        summ += maxInStr;
        maxInStr = 0;
    }
    return summ;
}

int main(){
    int Matrix[n][m];
    int summ = 0;
    int maxInStr = 0;
    int a = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {Matrix[i][j] = a; a++;};
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {printf("%3.d ", Matrix[i][j]); if(j == m-1) printf("\n");};
    printf("\n%d\n", Sum(Matrix));
}