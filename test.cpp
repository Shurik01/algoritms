#include "function.hpp"
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

    delete[] test_arr1;
    delete[] test_arr2;
    delete[] test_arr3;
    delete[] test_arr4;
    delete[] test_arr5;
    delete[] test_arr6;
    delete[] test_arr7;

    return 0;
}