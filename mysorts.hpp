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
/// @details время работы в среднем случае - O(nlogn), в худшем случае - O(n^2)(когда массив уже отсортирован или содержит много одинаковых элементов)
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

/// @brief быстрая сортировка по опорному элементу
/// @tparam T тип элементов массива
/// @param arr массив
/// @param low минимальный индекс(при вызове 0) 
/// @param high максимальный индекс(при вызове -1 от размера массива)
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

/// @brief функция, которая объединяет массивы
/// @param arr массив
/// @param left начало левого массива
/// @param mid конец левого(не включительно), начало правого массива
/// @param right конец правого массива
template <typename T>
void merge(T* arr, size_t left, size_t mid, size_t right)
{
    // текущий индекc в левом массиве
    size_t idx_left = 0;
    // текущий индекс в правом массиве
    size_t idx_right = 0;
    // временный массив, где хранится результат слияния массивов
    T* result = new T[right - left];
    // пока в обоих массивах есть элементы
    while (left + idx_left < mid && mid + idx_right < right)
    {
        // если элемент в левом массиве меньше элемента в правом
        if (arr[left + idx_left] < arr[mid + idx_right])
        {
            // записываем в result, idx_left + idx_right - то, сколько элементов уже находится в result
            result[idx_left + idx_right] = arr[left + idx_left];
            idx_left += 1;
        }
        // если элемент в правом массиве больше
        else
        {
            // записываем в result, idx_left + idx_right - то, сколько элементов уже находится в result
            result[idx_left + idx_right] = arr[mid + idx_right];
            idx_right += 1;
        }
    }

    // пока в левом массиве есть элементы(в правом закончились)
    while (left + idx_left < mid)
    {
        // копируем их в конец
        result[idx_left + idx_right] = arr[left + idx_left];
        idx_left += 1;
    }

    // пока в правом массиве есть элементы
    while (mid + idx_right < right)
    {
        result[idx_left + idx_right] = arr[mid + idx_right];
        idx_right += 1;
    }

    for (size_t i = 0; i < idx_left + idx_right; i++)
    {
        arr[left + i] = result[i];
    }
    delete[] result;
}

/// @brief функция сортировки слиянием
/// @tparam T тип элементов массива
/// @param arr массив
/// @param left левая граница массива(при вызове функции 0)
/// @param right правая граница массива(при вызове функции - размер)
/// @details сложность сортировки - O(nlogn), требует O(n) доп памяти
template <typename T>
void mergeSort(T* arr, size_t left, size_t right)
{
    if (left + 1 >= right)
    {
        return;
    }
    // делим массив на подмассивы, пока в них не останется по одному элементу
    size_t mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}

/// @brief сортировка Шелла
/// @tparam T тип элементов массива
/// @param arr массив
/// @param size размер массива
/// @details в среднем O(n(log^2n)), в худшем - O(n^2), в лучшем - O(nlogn)
template <typename T>
void shellSort(T* arr, size_t size){
    // размер шага, каждый раз уменьшается в два раза, пока не дойдет до единицы
    for (size_t s = size / 2; s > 0; s/= 2){
        // текущий элемент
        for (size_t i = s; i < size; i++){
            // j - место, куда вставляем элемент, который находится на расстоянии s шагов, если он больше
            for (size_t j = i; j >= s && arr[j - s] > arr[j]; j -= s){
                swap(arr[j - s], arr[j]);
            }
        }
    }
}