#include "sort.hpp"

int main(){
    //int arr[] = {12, 5, 0, 78, 123};
    short arr[] = {12, 0, 15, 7, 99};
    //double arr[] = {12.1, 0.5, 132.71, 5.7, 67.1};
    SORT_METOD = heap;
    SORT_DIRECTION = ascending;
    sort(arr, 5, sizeof(double), SORT_DIRECTION, SORT_METOD);
    print_array(arr, 5);
}
