#include "sort.hpp"

int main() {
    char arr[] = {'a', 'c', 'e', 'b', 'd'};
    SORT_METOD = heap;
    SORT_DIRECTION = ascending;
    sort(arr, sizeof(arr)/sizeof(char), sizeof(double), SORT_DIRECTION, SORT_METOD);
}
