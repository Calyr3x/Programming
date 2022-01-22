#include <stdio.h>
#include <stdlib.h>

int main(void){
    int arr[10][10];
    int summ = 0, max = 1, summf = 0;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = rand() % 100 + 1;
            summ += arr[i][j];
            printf("%3.d ", arr[i][j]);
        }
        
        printf(" | %d\n", summ);
        //printf("\n\n%d %d %d\n\n", summ, summf, max);
        
        if(summ > summf){
            summf = summ;
            max+=i;
        }
        summ = 0;
    }
    
    printf("\n\n%d\n", max);
    
}