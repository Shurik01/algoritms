#include "function.hpp"
#include "mysorts.hpp"
#include <format>
int main(){
    //размер массивов
    size_t size = 19;

    //объявление массивов для тестов
    float *test_arr1 = new float[size];
    float *test_arr2 = new float[size];
    float *test_arr3 = new float[size];
    float *test_arr4 = new float[4]{5, 1, 2, 3};
    float *test_arr5 = new float[5]{0, 1, 5, 8, 1};
    float *test_arr6 = new float[4]{5, 4, 2, 0};
    float *test_arr7 = new float[4]{-5, -4, -2, 0};

    //заполнение массивов
    test_arr1 = random_array_increasing(test_arr1, size, -10'000, 5'000);
    test_arr2 = random_array_increasing(test_arr2, size, -10'000, 10'000);
    test_arr3 = random_array_increasing(test_arr3, size, -10'000, 10'000);
    // тестирование фукнций поиска

    //проверка работы функции is_arr_sorted
    assert(is_arr_sorted(test_arr1, size) == 1);
    assert(is_arr_sorted(test_arr2, size) == 1);
    assert(is_arr_sorted(test_arr3, size) == 1);
    assert(is_arr_sorted(test_arr4, 4) == 0);
    assert(is_arr_sorted(test_arr5, 5) == 0);
    assert(is_arr_sorted(test_arr6, 4) == 0);
    assert(is_arr_sorted(test_arr7, 4) == 1);

    // проверка работы функции find_num
    assert(find_num<float>(test_arr4, 4, 2) == 2);
    assert(find_num<float>(test_arr4, 4, 6) == size_t(-1));
    assert(find_num<float>(test_arr5, 5, 0) == 0);
    assert(find_num<float>(test_arr6, 4, 0)==3);

    // проверка работы функции find_num_bin
    assert(find_num_bin<float>(test_arr4, 4, 6) == size_t(-1));
    assert(find_num_bin<float>(test_arr5, 5, 0) == 0);
    assert(find_num_bin<float>(test_arr7, 4, -2) == 2);

    // проверка работы функции find_num_interpolation
    assert(find_num_interpolation<float>(test_arr4, 4, 6) == size_t(-1));
    assert(find_num_interpolation<float>(test_arr5, 5, 0) == 0);
    assert(find_num_interpolation<float>(test_arr7, 4, -2) == 2);

    size_t n = 100;
    // тестирование функций сортировки

    // выделение памяти под массивы
    int* arr = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    // заполнение массивов случайными числами
    arr = random_int_array(arr, n, -100, 100);
    arr2 = random_int_array(arr, n, -1000, 1000);
    arr3 = random_int_array(arr, n, -10000, 10000);
    int* arr4 = new int[n];
    random_array_int_increasing(arr4, n, -1000, 1000);
    int* arr5 = new int[5]{2, 2, 8, 1, 4};
    int* arr6 = new int[6]{9, 7, 6, 3, 2, 1};
    // добавить с повторами и отсортированные
    
    // тест функции selectionSort
    assert(is_arr_sorted(selectionSort(arr, n), n) == 1);
    assert(is_arr_sorted(selectionSort(arr2, n), n) == 1);
    assert(is_arr_sorted(selectionSort(arr3, n), n) == 1);
    assert(is_arr_sorted(selectionSort(arr4, n), n) == 1);
    assert(is_arr_sorted(selectionSort(arr5, 5), 5) == 1);
    assert(is_arr_sorted(selectionSort(arr6, 6), 6) == 1);

    delete[] arr5;
    delete[] arr6;

    arr = random_int_array(arr, n, -100, 100);
    arr2 = random_int_array(arr, n, -1000, 1000);
    arr3 = random_int_array(arr, n, -10000, 10000);
    random_array_int_increasing(arr4, n, -1000, 1000);
    arr5 = new int[5]{2, 2, 8, 1, 4};
    arr6 = new int[6]{9, 7, 6, 3, 2, 1};

    quicksort(arr, 0, n-1);
    quicksort(arr2, 0, n-1);
    quicksort(arr3, 0, n-1);
    quicksort(arr4, 0, n-1);
    quicksort(arr5, 0, 4);
    quicksort(arr6, 0, 5);

    assert(is_arr_sorted(arr, n) == 1);
    assert(is_arr_sorted(arr2, n) == 1);
    assert(is_arr_sorted(arr3, n) == 1);
    assert(is_arr_sorted(arr4, n) == 1);
    assert(is_arr_sorted(arr5, 5) == 1);
    assert(is_arr_sorted(arr6, 6) == 1);

    delete[] test_arr1;
    delete[] test_arr2;
    delete[] test_arr3;
    delete[] test_arr4;
    delete[] test_arr5;
    delete[] test_arr6;
    delete[] test_arr7;
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    return 0;
}