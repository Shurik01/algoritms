#include "mysorts.hpp"
//  Автор: Пархоменко Александра
// модуль для функций сорировки
// время итеративной функции: 
// время рекурсивной функции: 
using namespace std;
/// @brief функция сортировки массива простым выбором(рекурсивная)
/// @param arr массив
/// @param n количество чисел в массиве
/// @return отсортированный массив
int* selectionSort_rec(int* arr, size_t n, size_t idx) {
    if (idx == n-1){
        return arr;
    }
    size_t min_idx = idx;
    for (size_t i = idx + 1; i < n; i++){
        if (arr[i] < arr[min_idx]){
            min_idx = i;
        }
    }
    swap(arr[idx], arr[min_idx]);
    return selectionSort_rec(arr, n, idx + 1);
}


