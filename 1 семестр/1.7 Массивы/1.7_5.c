#include <stdio.h>
#include <stdlib.h>

main(void){
    int arr1[15];
    int arr2[15];
    int arr3[21];
    for(int i = 0; i < 21; i++) arr3[i] = 0;
    for(int i = 0; i < 15; i++){
        arr1[i] = rand() % 20 + 1;
        arr2[i] = rand() % 10 + 1;
    }
    for(int i = 0; i < 15; i++) printf("|%d| ", arr1[i]);
    printf("\n");
    for(int i = 0; i < 15; i++) printf("|%d| ", arr2[i]);
    printf("\n");
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(arr3[arr1[i]] == 0 && arr1[i] == arr2[j]){
                printf("%d - общий элемент\n", arr1[i]);
                arr3[arr1[i]] = 1;
            }
        }
    }
}