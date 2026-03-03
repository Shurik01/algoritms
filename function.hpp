#pragma once
#include <random> 
#include <iostream>
#include <cmath>
#include <format>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <ctime>
#include <chrono>
using namespace std::chrono;

//Автор: Пархоменко Александра
//модуль для функций

/// @brief функция, которая заполняет массив рандомными монотонно возрастающими значениями
/// @param arr массив
/// @param size размер массива
/// @param min_rand минимальное генерируемое значение 
/// @param max_rand максимальное генерируемое значение
/// @return массив arr
float* random_array_increasing(float *arr, size_t size, int min_rand, int max_rand);

/// @brief функция, которая заполняет массив рандомными значениями
/// @param arr массив
/// @param min_rand минимальное генерируемое значение 
/// @param max_rand максимальное генерируемое значение
/// @return массив arr
float* random_array(float *arr, size_t size, int min_rand, int max_rand);

/// @brief функция, которая проверяет отсортирован ли массив
/// @param arr массив
/// @param size размер массива
/// @return 1, если массив отсортирован, 0 в другом случае
bool is_arr_sorted(float *arr, size_t size);

/// @brief функция, которая измеряет время выполнения в секундах
/// @tparam F шаблон функции 
/// @param func функция
template <typename F>
void time_sec(F func){
    size_t N = 10e8;
    // запоминание начала отсчёта
    time_t t0 = time(nullptr);
    //измеряет время выполнения функции
    func();
    time_t t1 = time(nullptr);
    std::cout << "time delta (seconds) " << time(nullptr) - t0;
}

/// @brief функция, которая измеряет время выполнения в миллисекундах
/// @tparam F шаблон функции 
/// @param func функция
template <typename F>
void time_ms(F func){
    size_t N = 10e8;
    // начальная отметка времени
    auto t0 = steady_clock::now();
    //измеряет время выполнения функции
    func();
    // конечная отметка времени
    auto t1 = steady_clock::now();
    // преобразование времени (обычно наносекунды) в миллисекунды
    // delta - объект, хранящий время.
    auto delta = duration_cast< milliseconds >(t1 - t0);
    std::cout << "time delta (milliseconds) " << delta.count();
}

/// @brief возвращает 1, когда значение найдено, 0, если не найдено
/// @param arr массив
/// @param size размер массива
/// @param num искомое значение
/// @return индекс первого вхождения искомого значения
size_t find_num(float *arr, size_t size, float num);