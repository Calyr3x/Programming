#include <stdio.h>

int main(void){
    
    int dim = 4;
    int i, j, N[dim], n[dim], num;

    num = 1;
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++) printf("%d ", n[j]);
        printf("\n");
        j = 0;
        do{
            n[j] = (n[j] + 1) % N[j];
        } while(!n[j] && ++j < dim);
    }
}