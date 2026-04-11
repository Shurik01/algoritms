#pragma once
#include <algorithm> 
//  Автор: Пархоменко Александра
// модуль для функций сорировки
using namespace std;


/// @brief функция сортировки массива простым выбором(итеративная) по возрастанию
/// @param arr массив
/// @param n количество чисел в массиве
/// @return отсортированный массив
template <typename T>
int* selectionSort(T* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Меняет местами элементы массива
        swap(arr[i], arr[min_idx]);
    }
    return arr;
}

/// @brief функция сортировки массива простым выбором(рекурсивная)
/// @param arr массив
/// @param n количество чисел в массиве
/// @return отсортированный массив
int* selectionSort_rec(int* arr, size_t n, size_t idx = 0) {
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

/// @brief разбиение массива по схеме Ломуто
/// @tparam T шаблон типа массива
/// @param arr массив
/// @param low 
/// @param high 
/// @return индекс опорного элемента
template <typename T>
size_t partition(T* arr, size_t low, size_t high){
    T pivot = arr[high];
    size_t i = low;
    for (size_t j = low; j < high; j++){
        if (arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i += 1;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

template <typename T>
void quicksort(T* arr, size_t low, size_t high){
    if (low < high){
        T p = partition(arr, low, high);
        if (p > low) { 
            quicksort(arr, low, p - 1);
        }
        quicksort(arr, p + 1, high);
    }
}