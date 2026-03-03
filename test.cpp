#include "function.hpp"
#include <format>
int main(){
    //размер массивов
    size_t size = 12;

    //объявление массивов для тестов
    float *test_arr1 = new float[size];
    float *test_arr2 = new float[size];
    float *test_arr3 = new float[size];

    //заполнение массивов
    time_ms([&](){test_arr1 = random_array_increasing(test_arr1, size, -10'000, 5'000);});
    test_arr2 = random_array_increasing(test_arr2, size, -10'000, 10'000);
    test_arr3 = random_array_increasing(test_arr3, size, -10'000, 10'000);

    //проверка работы функции
    time_ms([&](){is_arr_sorted(test_arr1, size);
    });
    assert(is_arr_sorted(test_arr1, size) == 1);
    assert(is_arr_sorted(test_arr2, size) == 1);
    assert(is_arr_sorted(test_arr3, size) == 1);

    delete[] test_arr1;
    delete[] test_arr2;
    delete[] test_arr3;

    return 0;
}