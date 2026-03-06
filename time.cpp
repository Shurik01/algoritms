#include "function.hpp"
#include <chrono>
using namespace std::chrono;
using namespace std;
int main(){
    time(nullptr);
    std::random_device rd;

    // Объект - генератор случайных чисел с seed (начальным значением) от random_device
    std::mt19937 gen(rd());

    //размер массива
    size_t size = 100'000;
    // Переменная для суммирования времени в наносекундах
    long long total_nanoseconds = 0;
    int *test_arr1 = new int[size];
    test_arr1 = random_array_int_increasing(test_arr1, size, -100'000, 100'000);
    // выдаваемых случайных значений
    std::uniform_int_distribution<> distr(-100'000, 100'000);
    //float random_num = test_arr1[distr(gen)];
    // начальная отметка времени
    auto t0 = steady_clock::now();
    // код, время выполнения которого нужно измерить
    for (size_t i = 0; i < 100'000; i++){
        int num = distr(gen);
        
        find_num<int>(test_arr1, size, num);
        
    }
    // конечная отметка времени
    auto t1 = steady_clock::now();
    total_nanoseconds += duration_cast<nanoseconds>(t1 - t0).count();
    double total_milliseconds = total_nanoseconds / 1'000'000.0;
    
    cout << "Total time: " << total_milliseconds << " ms" << endl;
    delete[] test_arr1;
}