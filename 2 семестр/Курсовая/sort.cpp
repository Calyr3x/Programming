#include "sort.hpp"
#include <iostream>
#include <cstring>
#include <string>

void move(void *a, void *b, int elemsize){ std::memcpy(a, b, elemsize); }

template <typename T>
void bubble_sort(T *arr, int n, int SORT_DIRECTION){

    bool swapped = false;

    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(comp(&arr[j], &arr[j+1]) == SORT_DIRECTION){
                T temp;
                move(&temp, &arr[j], sizeof(T));
                move(&arr[j], &arr[j+1], sizeof(T));
                move(&arr[j+1], &temp, sizeof(T));
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

/*    COMB SORT    */
template <typename T>
void comb_sort(T *arr, int n, int SORT_DIRECTION){
    int i, h = n;
    double shrink = 1.33;
    while (h > 1){
        h = h / shrink;
        if (h <= 1) break;
        for (i = 0; i + h < n; i++){
            if (comp(&arr[i], &arr[i+h]) == SORT_DIRECTION){
                T temp;
                move(&temp, &arr[i], sizeof(T));
                move(&arr[i], &arr[i+h], sizeof(T));
                move(&arr[i+h], &temp, sizeof(T));
            }
        }
    }
    bubble_sort(arr, n, SORT_DIRECTION);
}

/*    SHELL SORT    */
template <typename T>
void shell_sort(T *arr, int n, int SORT_DIRECTION){
    int i, j, h;
    double shrink = 1.88;
    for(h = n/shrink; h > 0; h/=shrink) {
        for(i = h; i < n; i ++){
            T temp;
            move(&temp, &arr[i], sizeof(arr[i]));
            for(j=i; j>=h; j-=h){
                if (comp( &arr[j-h], &temp) == SORT_DIRECTION){
                arr[j] = arr[j-h];
                move(&arr[j], &arr[j-h], sizeof(T));
                }
                else break;
            }
            move(&arr[j], &temp, sizeof(T));
        }
    }
}

/*    QUICK SORT    */
template <typename T>
int partition(T *arr, int n, int SORT_DIRECTION){
    T x = arr[n/2];
    T temp;
    int i = 0, j = n - 1;
    while (1){
    while (comp( &x, &arr[i]) == SORT_DIRECTION) {
        i++;
    }
    while (comp( &arr[j], &x) == SORT_DIRECTION) {
        j--;
    }
    if (i >= j) break;
    move(&temp, &arr[i], sizeof(T));
    move(&arr[i], &arr[j], sizeof(T));
    move(&arr[j], &temp, sizeof(T));
    i++;
    j--;
    }
    return i;
}
template <typename T>
void quick_sort(T *arr, int n, int SORT_DIRECTION){
    if (n < 2) return;
    int i = partition(arr, n, SORT_DIRECTION);
    quick_sort(arr, i, SORT_DIRECTION);
    quick_sort(arr + i, n - i, SORT_DIRECTION);
}

template <typename T>
void merge(T *A, int high, int mid, int SORT_DIRECTION)
{
    int i, j, k;
	T* c = new T [high];
    int low = 1;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (comp( &A[i], &A[j]) == SORT_DIRECTION)
        {
            c[k] = A[i];
            k++;
            i++;
        }
        else
        {
            c[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        A[i] = c[i];
    }
	delete [] c;
}

template <typename T>
void mergeSort(T *a, int high, int SORT_DIRECTION){
	if(0 < high){
        int low = 0;
		int mid = high/2;

		mergeSort(a, mid, SORT_DIRECTION);
		mergeSort(a, high, SORT_DIRECTION);

		merge(a, high, mid, SORT_DIRECTION);
	}
	return;
}

/*    HEAP SORT    */
template <typename T>
void heap(T *array, int len_a, int k, int SORT_DIRECTION){
    int nmax = k, l = 2*k + 1, r = 2*k + 2;
    T temp;
    if(l < len_a && comp(&array[l], &array[nmax]) == SORT_DIRECTION) nmax = l;
    if(r < len_a && comp(&array[r], &array[nmax]) == SORT_DIRECTION) nmax = r;
    if(nmax != k){
        move(&temp, &array[k], sizeof(T));
        move(&array[k], &array[nmax], sizeof(T));
        move(&array[nmax], &temp, sizeof(T));
        heap(array, len_a, nmax, SORT_DIRECTION);
    }
}

template <typename T>
void heap_sort(T *array, int len_a, int SORT_DIRECTION){
    int k;
    T temp;
    for(k = len_a/2-1; k >= 0; k--) heap(array, len_a, k, SORT_DIRECTION);
    for(k = len_a-1; k >= 0; k--){
        move(&temp, &array[0], sizeof(T));
        move(&array[0], &array[k], sizeof(T));
        move(&array[k], &temp, sizeof(T));
        heap(array,k,0, SORT_DIRECTION);
    }
}