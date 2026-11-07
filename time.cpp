#include "function.hpp"
#include "mysorts.hpp"
#include <chrono>
using namespace std::chrono;
using namespace std;
int main(){
    time(nullptr);
    //размер массива
    size_t size = 100;
    // Переменная для суммирования времени в наносекундах
    cout << "Сортировка простым выбором " << endl << endl << endl;
    // начальная отметка времени
    for (size_t i = 100; i < 10'000; i+=1'000){
        long long total_nanoseconds = 0;
        double total_milliseconds = 0;
        
        int *test_arr1 = new int[size];
        for (size_t i = 0; i < 10000; i++){
            
            test_arr1 = random_int_array(test_arr1, size, -100'000'000, 100'000'000);
            auto t0 = steady_clock::now();
            // код, время выполнения которого нужно измерить
            selectionSort(test_arr1, size);
            auto t1 = steady_clock::now();
            total_nanoseconds += duration_cast<nanoseconds>(t1 - t0).count();
            total_milliseconds = total_nanoseconds / 10'000'000'000.0;
        }
        delete[] test_arr1;
        // конечная отметка времени
        cout << size <<"," << total_milliseconds << endl;
        size += 1'000;
    }
    size = 100;
    cout << "Быстрая сортировка" << endl << endl << endl;
    // начальная отметка времени
    for (size_t i = 100; i < 10'000; i+=1'000){
        long long total_nanoseconds = 0;
        double total_milliseconds = 0;
        int *test_arr1 = new int[size];
        for (size_t i = 0; i < 10'000; i++){
            
            test_arr1 = random_int_array(test_arr1, size, -100'000'000, 100'000'000);
            auto t0 = steady_clock::now();
            // код, время выполнения которого нужно измерить
            quicksort(test_arr1, 0, size-1);
            auto t1 = steady_clock::now();
            total_nanoseconds += duration_cast<nanoseconds>(t1 - t0).count();
            total_milliseconds = total_nanoseconds / 10'000'000'000.0;
        }
        delete[] test_arr1;
        // конечная отметка времени
        cout << size <<"," << total_milliseconds << endl;
        size += 1'000;
    }

    size = 100;
    cout << "Быстрая сортировка" << endl << endl << endl;
    // начальная отметка времени
    for (size_t i = 100; i < 10'000; i+=1'000){
        long long total_nanoseconds = 0;
        double total_milliseconds = 0;
        int *test_arr1 = new int[size];
        for (size_t i = 0; i < 10'000; i++){
            
            test_arr1 = random_int_array(test_arr1, size, -100'000'000, 100'000'000);
            auto t0 = steady_clock::now();
            // код, время выполнения которого нужно измерить
            mergeSort(test_arr1, 0, size);
            auto t1 = steady_clock::now();
            total_nanoseconds += duration_cast<nanoseconds>(t1 - t0).count();
            total_milliseconds = total_nanoseconds / 10'000'000'000.0;
        }
        delete[] test_arr1;
        // конечная отметка времени
        cout << size <<"," << total_milliseconds << endl;
        size += 1'000;
    }

    size = 100;
    cout << "Сортировка Шелла" << endl << endl << endl;
    for (size_t i = 100; i < 100'000; i+=1'000){
        long long total_nanoseconds = 0;
        double total_milliseconds = 0;
        int *test_arr1 = new int[size];
        for (size_t i = 0; i < 10'000; i++){
            
            test_arr1 = random_int_array(test_arr1, size, -100'000'000, 100'000'000);
            auto t0 = steady_clock::now();
            // код, время выполнения которого нужно измерить
            shellSort(test_arr1, size);
            auto t1 = steady_clock::now();
            total_nanoseconds += duration_cast<nanoseconds>(t1 - t0).count();
            total_milliseconds = total_nanoseconds / 10'000'000'000.0;
        }
        delete[] test_arr1;
        // конечная отметка времени
        cout << size <<"," << total_milliseconds << endl;
        size += 1'000;
    }
    
    
    
    return 0;
}