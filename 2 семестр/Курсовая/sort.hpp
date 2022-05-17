#pragma once

#include <iostream>
#include <cstring>
#include <string>

enum methods {
    bubble, insertion, selection, comb, shell, merge, quick, heap
} SORT_METOD;

enum directions {
    descending = -1, ascending = 1
} SORT_DIRECTION;

/*
Так как шаблон - это не функция а образец, по которому компилятор сделает функцию,
необходимо было перенести определение шаблона из .cpp в .hpp,
поскольку в точке использования должен быть доступ к определению шаблона,
иначе как компилятор узнает каким образом делать для нас функцию?
Однако есть несколько нюансов, но ничего плохого в них я не вижу.
*/

template <typename T> int comp(T *x1, T *x2){
    if ( *(T*)x1 < *(T*)x2 ) return -1;
    else if ( *(T*)x1 > *(T*)x2 ) return 1;
    else return 0;
}

void move(void *a, void *b, int elemsize){ std::memcpy(a, b, elemsize); }

template <typename T> void print_array(T *arr, int n){
    for(int i = 0; i < n; i++) std::cout << arr[i] << " ";
}

template <typename T>
void bubble_sort(T *array, int n, int SORT_DIRECTION){

    bool swapped = false;

    for(int i = 0; i < n-1; i++){
        swapped = false;
        T temp;
        for(int j = 0; j < n-i-1; j++){
            if(comp(&array[j], &array[j+1]) == SORT_DIRECTION){
                move(&temp, &array[j], sizeof(T));
                move(&array[j], &array[j+1], sizeof(T));
                move(&array[j+1], &temp, sizeof(T));
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

template <typename T>
void insertion_sort(T *array,int n, int SORT_DIRECTION){
    T temp;
	for(int i=1;i<n;i++){
		for(int j=i; j>0 && comp(&array[j-1], &array[j]) == SORT_DIRECTION;j--){
            move(&temp, &array[j], sizeof(T));
            move(&array[j], &array[j-1], sizeof(T));
            move(&array[j-1], &temp, sizeof(T));
		}
	}
}

template<typename T>
void selection_sort(T *array, int n, int SORT_DIRECTION)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        move(&temp, &array[0], sizeof(T));
        for (int j = i + 1; j < n; j++)
        {
            if (comp(&array[i], &array[j]) == SORT_DIRECTION)
            {
            move(&temp, &array[i], sizeof(T));
            move(&array[i], &array[j], sizeof(T));
            move(&array[j], &temp, sizeof(T));
            }
        }
    }
}

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
/*
template <typename T> void merge_s(T *A, int high, int mid, int SORT_DIRECTION);

template <typename T> void merge_sort(T *a, int high, int SORT_DIRECTION);
*/
template <typename T>
void heap_s(T *array, int len_a, int k, int SORT_DIRECTION){
    int nmax = k, l = 2*k + 1, r = 2*k + 2;
    T temp;
    if(l < len_a && comp(&array[l], &array[nmax]) == SORT_DIRECTION) nmax = l;
    if(r < len_a && comp(&array[r], &array[nmax]) == SORT_DIRECTION) nmax = r;
    if(nmax != k){
        move(&temp, &array[k], sizeof(T));
        move(&array[k], &array[nmax], sizeof(T));
        move(&array[nmax], &temp, sizeof(T));
        heap_s(array, len_a, nmax, SORT_DIRECTION);
    }
}

template <typename T>
void heap_sort(T *array, int len_a, int SORT_DIRECTION){
    int k;
    T temp;
    for(k = len_a/2-1; k >= 0; k--) heap_s(array, len_a, k, SORT_DIRECTION);
    for(k = len_a-1; k >= 0; k--){
        move(&temp, &array[0], sizeof(T));
        move(&array[0], &array[k], sizeof(T));
        move(&array[k], &temp, sizeof(T));
        heap_s(array,k,0, SORT_DIRECTION);
    }
}
template <typename T>
int sort(T *array, int size, int elemsize, /*int(*comp)(T *a1, T *a2)*/ int SORT_DIRECTION, int SORT_METHOD){
    switch (SORT_METHOD){
        case 0:
            bubble_sort(array, size, SORT_DIRECTION);
            break;
        case 1:
            insertion_sort(array, size, SORT_DIRECTION);
            break;
        case 2:
            selection_sort(array, size, SORT_DIRECTION);
            break;
        case 3:
            comb_sort(array, size, SORT_DIRECTION);
            break;
        case 4:
            shell_sort(array, size, SORT_DIRECTION);
            break;
        /*case 5:
            merge_sort(array, size, SORT_DIRECTION);
            break;*/
        case 6:
            quick_sort(array, size, SORT_DIRECTION);
            break;
        case 7:
            heap_sort(array, size, SORT_DIRECTION);
            break;
        default:
            std::cout << "SOMETHING WENT WRONG" << std::endl;
    }
}