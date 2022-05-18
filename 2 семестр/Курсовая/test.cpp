#include "sort.hpp"
#include <limits>
#include <random>
using std::numeric_limits;

template <typename T>
void findError_ascending(T a[], int n){
    int err = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]) err++;
    }
    if(!err) std::cout << n << "\t- массив отсортирован" << std::endl;
    else std::cout << n << "\t- массив не отсортирован" << std::endl; 
}

template <typename T>
void findError_descending(T a[], int n){
    int err = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i] < a[i+1]) err++;
    }
    if(!err) std::cout << n << "\t- массив отсортирован" << std::endl;
    else std::cout << n << "\t- массив не отсортирован" << std::endl; 
}

void test(int types){
    switch(types){
        case _int:
            goto _int_test;
            break;
        case _short_int:
            goto _short_int_test;
            break;
        case _unsigned_short_int:
            goto _unsigned_short_int_test;
            break;
        case _unsigned_int:
            goto _unsigned_int_test;
            break;
        case _float:
            goto _float_test;
            break;
        case _double:
            goto _double_test;
            break;
        default:
            std::cout << "WRONG DATA TYPE FOR TEST" << std::endl;
    }

        _double_test:
            for(int i = 0; i <= 7; i++, SORT_METOD = methods(i)){
            for(int arraySize = 8; arraySize <= 268435456; arraySize *= 2){
                double *array = new double[arraySize];
                std::random_device rd;
                std::default_random_engine eng(rd());
                std::uniform_real_distribution<double> distr(-numeric_limits<double>::max(), numeric_limits<double>::max());
                
                for(int arrElem = 0; arrElem < arraySize; arrElem++) array[arrElem] = distr(rd);
                
                switch(SORT_METOD){
                case bubble:
                    bubble_sort(array, arraySize, ascending);
                    std::cout << "bubble\t";
                    findError_ascending(array, arraySize);
                case insertion:
                    insertion_sort(array, arraySize, descending);
                    std::cout << "insertion\t";
                    findError_descending(array, arraySize);
                case selection:
                    selection_sort(array, arraySize, ascending);
                    std::cout << "selection\t";
                    findError_ascending(array, arraySize);
                case comb:
                    comb_sort(array, arraySize, descending);
                    std::cout << "comb\t";
                    findError_descending(array, arraySize);
                case shell:
                    shell_sort(array, arraySize, ascending);
                    std::cout << "shell\t";
                    findError_ascending(array, arraySize);
                case quick:
                    quick_sort(array, arraySize, descending);
                    std::cout << "quick\t";
                    findError_descending(array, arraySize);
                case heap:
                    heap_sort(array, arraySize, ascending);
                    std::cout << "heap\t";
                    findError_ascending(array, arraySize);
                case merge:
                    merge_sort(array, arraySize, descending);
                    std::cout << "merge\t";
                    findError_descending(array, arraySize);
                }
                delete [] array;
            }
        }

        _float_test:
            for(int i = 0; i <= 7; i++, SORT_METOD = methods(i)){
            for(int arraySize = 8; arraySize <= 268435456; arraySize *= 2){
                float *array = new float[arraySize];
                std::random_device rd;
                std::default_random_engine eng(rd());
                std::uniform_real_distribution<float> distr(-numeric_limits<float>::max(), numeric_limits<float>::max());
                
                for(int arrElem = 0; arrElem < arraySize; arrElem++) array[arrElem] = distr(rd);
                
                switch(SORT_METOD){
                case bubble:
                    bubble_sort(array, arraySize, ascending);
                    std::cout << "bubble\t";
                    findError_ascending(array, arraySize);
                case insertion:
                    insertion_sort(array, arraySize, descending);
                    std::cout << "insertion\t";
                    findError_descending(array, arraySize);
                case selection:
                    selection_sort(array, arraySize, ascending);
                    std::cout << "selection\t";
                    findError_ascending(array, arraySize);
                case comb:
                    comb_sort(array, arraySize, descending);
                    std::cout << "comb\t";
                    findError_descending(array, arraySize);
                case shell:
                    shell_sort(array, arraySize, ascending);
                    std::cout << "shell\t";
                    findError_ascending(array, arraySize);
                case quick:
                    quick_sort(array, arraySize, descending);
                    std::cout << "quick\t";
                    findError_descending(array, arraySize);
                case heap:
                    heap_sort(array, arraySize, ascending);
                    std::cout << "heap\t";
                    findError_ascending(array, arraySize);
                case merge:
                    merge_sort(array, arraySize, descending);
                    std::cout << "merge\t";
                    findError_descending(array, arraySize);
                }
                delete [] array;
            }
        }

        _unsigned_int_test:
            for(int i = 0; i <= 7; i++, SORT_METOD = methods(i)){
            for(int arraySize = 8; arraySize <= 268435456; arraySize *= 2){
                unsigned int *array = new unsigned int[arraySize];
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist6(0, numeric_limits<int>::max());
                
                for(int arrElem = 0; arrElem < arraySize; arrElem++) array[arrElem] = dist6(rng);
                
                switch(SORT_METOD){
                case bubble:
                    bubble_sort(array, arraySize, ascending);
                    std::cout << "bubble\t";
                    findError_ascending(array, arraySize);
                case insertion:
                    insertion_sort(array, arraySize, descending);
                    std::cout << "insertion\t";
                    findError_descending(array, arraySize);
                case selection:
                    selection_sort(array, arraySize, ascending);
                    std::cout << "selection\t";
                    findError_ascending(array, arraySize);
                case comb:
                    comb_sort(array, arraySize, descending);
                    std::cout << "comb\t";
                    findError_descending(array, arraySize);
                case shell:
                    shell_sort(array, arraySize, ascending);
                    std::cout << "shell\t";
                    findError_ascending(array, arraySize);
                case quick:
                    quick_sort(array, arraySize, descending);
                    std::cout << "quick\t";
                    findError_descending(array, arraySize);
                case heap:
                    heap_sort(array, arraySize, ascending);
                    std::cout << "heap\t";
                    findError_ascending(array, arraySize);
                case merge:
                    merge_sort(array, arraySize, descending);
                    std::cout << "merge\t";
                    findError_descending(array, arraySize);
                }
                delete [] array;
            }
        }

        _unsigned_short_int_test:
            for(int i = 0; i <= 7; i++, SORT_METOD = methods(i)){
            for(int arraySize = 8; arraySize <= 268435456; arraySize *= 2){
                unsigned short *array = new unsigned short[arraySize];
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist6(0, numeric_limits<short int>::max());
                
                for(int arrElem = 0; arrElem < arraySize; arrElem++) array[arrElem] = dist6(rng);
                
                switch(SORT_METOD){
                case bubble:
                    bubble_sort(array, arraySize, ascending);
                    std::cout << "bubble\t";
                    findError_ascending(array, arraySize);
                case insertion:
                    insertion_sort(array, arraySize, descending);
                    std::cout << "insertion\t";
                    findError_descending(array, arraySize);
                case selection:
                    selection_sort(array, arraySize, ascending);
                    std::cout << "selection\t";
                    findError_ascending(array, arraySize);
                case comb:
                    comb_sort(array, arraySize, descending);
                    std::cout << "comb\t";
                    findError_descending(array, arraySize);
                case shell:
                    shell_sort(array, arraySize, ascending);
                    std::cout << "shell\t";
                    findError_ascending(array, arraySize);
                case quick:
                    quick_sort(array, arraySize, descending);
                    std::cout << "quick\t";
                    findError_descending(array, arraySize);
                case heap:
                    heap_sort(array, arraySize, ascending);
                    std::cout << "heap\t";
                    findError_ascending(array, arraySize);
                case merge:
                    merge_sort(array, arraySize, descending);
                    std::cout << "merge\t";
                    findError_descending(array, arraySize);
                }
                delete [] array;
            }
        }
        
        _short_int_test:
            for(int i = 0; i <= 7; i++, SORT_METOD = methods(i)){
            for(int arraySize = 8; arraySize <= 268435456; arraySize *= 2){
                short *array = new short[arraySize];
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist6(-numeric_limits<short int>::max(), numeric_limits<short int>::max());
                
                for(int arrElem = 0; arrElem < arraySize; arrElem++) array[arrElem] = dist6(rng);
                
                switch(SORT_METOD){
                case bubble:
                    bubble_sort(array, arraySize, ascending);
                    std::cout << "bubble\t";
                    findError_ascending(array, arraySize);
                case insertion:
                    insertion_sort(array, arraySize, descending);
                    std::cout << "insertion\t";
                    findError_descending(array, arraySize);
                case selection:
                    selection_sort(array, arraySize, ascending);
                    std::cout << "selection\t";
                    findError_ascending(array, arraySize);
                case comb:
                    comb_sort(array, arraySize, descending);
                    std::cout << "comb\t";
                    findError_descending(array, arraySize);
                case shell:
                    shell_sort(array, arraySize, ascending);
                    std::cout << "shell\t";
                    findError_ascending(array, arraySize);
                case quick:
                    quick_sort(array, arraySize, descending);
                    std::cout << "quick\t";
                    findError_descending(array, arraySize);
                case heap:
                    heap_sort(array, arraySize, ascending);
                    std::cout << "heap\t";
                    findError_ascending(array, arraySize);
                case merge:
                    merge_sort(array, arraySize, descending);
                    std::cout << "merge\t";
                    findError_descending(array, arraySize);
                }
                delete [] array;
            }
        }

        _int_test:
            for(int i = 0; i <= 7; i++, SORT_METOD = methods(i)){
            for(int arraySize = 8; arraySize <= 268435456; arraySize *= 2){
                int *array = new int[arraySize];
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist6(-numeric_limits<int>::max(), numeric_limits<int>::max());
                
                for(int arrElem = 0; arrElem < arraySize; arrElem++) array[arrElem] = dist6(rng);
                
                switch(SORT_METOD){
                case bubble:
                    bubble_sort(array, arraySize, ascending);
                    std::cout << "bubble\t";
                    findError_ascending(array, arraySize);
                case insertion:
                    insertion_sort(array, arraySize, descending);
                    std::cout << "insertion\t";
                    findError_descending(array, arraySize);
                case selection:
                    selection_sort(array, arraySize, ascending);
                    std::cout << "selection\t";
                    findError_ascending(array, arraySize);
                case comb:
                    comb_sort(array, arraySize, descending);
                    std::cout << "comb\t";
                    findError_descending(array, arraySize);
                case shell:
                    shell_sort(array, arraySize, ascending);
                    std::cout << "shell\t";
                    findError_ascending(array, arraySize);
                case quick:
                    quick_sort(array, arraySize, descending);
                    std::cout << "quick\t";
                    findError_descending(array, arraySize);
                case heap:
                    heap_sort(array, arraySize, ascending);
                    std::cout << "heap\t";
                    findError_ascending(array, arraySize);
                case merge:
                    merge_sort(array, arraySize, descending);
                    std::cout << "merge\t";
                    findError_descending(array, arraySize);
                }
                delete [] array;
            }
        }
}

int main(){
    test(_int);
    return 0;
}