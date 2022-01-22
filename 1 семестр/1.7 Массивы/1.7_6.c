#include <stdlib.h>
#include <stdio.h>
#define size 10
#define max(a, b) ((a) > (b) ? (a) : (b))

main(void){
    int arr1[size];
    int arr2[size];
    int arr3[size*2];
    int k = 1, l = 10, v1 = 0, v2 = 0;
    
    for(int i = 0; i < size; i++){
        arr1[i] = rand() % l + k;
        arr2[i] = rand() % l + k;
        k += 10;
    }
    
    for(int i = 0; i < size; i++) printf("%d | ", arr1[i]);
    printf("\n");
    for(int i = 0; i < size; i++) printf("%d | ", arr2[i]);
    printf("\n");

    for(int i = 0; i < size*2; i++){
        printf("%d %d\n", arr1[v1], arr2[v2]);
        if(arr1[v1] < arr2[v2]){
            arr3[i] = arr1[v1];
            v1++;
        }
        else {
            arr3[i] = arr2[v2];
            v2++;
        }
        if(arr1[v1] == 0 || arr2[v2] == 0) arr3[19] = max(arr1[v1], arr2[v2]);
    }
    
    printf("\n");
    for(int i = 0; i < size*2; i++) printf("%d | ", arr3[i]);

}