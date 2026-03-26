#include <iostream>
#include <algorithm> 
using namespace std;
int* selectionSort(int* arr, size_t n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Меняем местами
        swap(arr[i], arr[min_idx]);
    }
    return arr;
}