#include <iostream>
#include <algorithm> 
#include "function.hpp"
#include <cassert>
#include <chrono>
// https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/tasks/task_recursion.md
// время итеративной функции: 
// время рекурсивной функции: 
using namespace std;
/// @brief функция сортировки массива простым выбором(итеративная)
/// @param arr массив
/// @param n количество чисел в массиве
/// @return отсортированный массив
int* selectionSort(int* arr, size_t n) {
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


int main(){
    // размер массива
    size_t n = 10'000;

    // выделение памяти под массивы
    int* arr = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    // заполнение массивов случайными числами
    arr = random_int_array(arr, n, -200'000, 200'000);
    arr2 = random_int_array(arr, n, -200'000, 200'000);
    arr3 = random_int_array(arr, n, -200'000, 200'000);
    
    // тест функции selectionSort
    assert(is_arr_sorted(selectionSort(arr, n), n) == 1);
    assert(is_arr_sorted(selectionSort(arr2, n), n) == 1);
    assert(is_arr_sorted(selectionSort(arr3, n), n) == 1);
    arr = random_int_array(arr, n, -200'000, 200'000);
    arr2 = random_int_array(arr, n, -200'000, 200'000);
    arr3 = random_int_array(arr, n, -200'000, 200'000);
    // тест функции selectionSort_rec
    assert(is_arr_sorted(selectionSort_rec(arr, n), n) == 1);
    assert(is_arr_sorted(selectionSort_rec(arr2, n), n) == 1);
    assert(is_arr_sorted(selectionSort_rec(arr3, n), n) == 1);
    // Переменная для суммирования времени в наносекундах
    long long total_nanoseconds = 0;
    // начальная отметка времени
    auto t0 = steady_clock::now();
    // код, время выполнения которого нужно измерить
    for (size_t i = 0; i < 10'000; i++){
        arr = random_int_array(arr, n, -200'000, 200'000);
        selectionSort(arr, n);
        
    }
    // конечная отметка времени
    auto t1 = steady_clock::now();
    total_nanoseconds += duration_cast<nanoseconds>(t1 - t0).count();
    double total_milliseconds = total_nanoseconds / 1'000'000.0;
    
    cout << "Время выполнения функции selectionSort: " << total_milliseconds << " ms" << endl;
    total_nanoseconds = 0;
    // начальная отметка времени
    t0 = steady_clock::now();
    // код, время выполнения которого нужно измерить
    for (size_t i = 0; i < 10'000; i++){
        arr = random_int_array(arr, n, -200'000, 200'000);
        selectionSort_rec(arr, n);
        
    }
    // конечная отметка времени
    t1 = steady_clock::now();
    total_nanoseconds += duration_cast<nanoseconds>(t1 - t0).count();
    total_milliseconds = total_nanoseconds / 1'000'000.0;
    
    cout << "Время выполнения функции selectionSort_rec: " << total_milliseconds << " ms" << endl;

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    return 0;
}