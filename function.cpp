#include "function.hpp"

//Автор: Пархоменко Александра
//модуль для функций

/// @details время работы O(n)
/// @brief функция, которая заполняет массив рандомными монотонно возрастающими значениями
/// @param arr массив
/// @param size размер массива
/// @param min_rand минимальное генерируемое значение 
/// @param max_rand максимальное генерируемое значение
/// @return массив arr
float* random_array_increasing(float *arr, size_t size, int min_rand, int max_rand){
    float diff = (max_rand - min_rand)/size;
    // Объект для доступа к аппаратному или программному источнику случайности
    // нужен для инициализации генератора случайных чисел
    std::random_device rd;

    // Объект - генератор случайных чисел с seed (начальным значением) от random_device
    std::mt19937 gen(rd());

    for (size_t n = 0; n < size; ++n){
        // Объект, отвечающий за конкретные парамеры (вид распределения, его параметры)
        // выдаваемых случайных значений
        std::uniform_real_distribution<> distr(min_rand, max_rand);
        arr[n] = distr(gen);
        min_rand = arr[n];
        max_rand += diff;
    }
    return arr;
}

/// @details время работы O(n)
/// @brief функция, которая заполняет массив рандомными монотонно возрастающими значениями
/// @param arr массив
/// @param size размер массива
/// @param min_rand минимальное генерируемое значение 
/// @param max_rand максимальное генерируемое значение
/// @return массив arr
int* random_array_int_increasing(int *arr, size_t size, int min_rand, int max_rand){
    // Объект для доступа к аппаратному или программному источнику случайности
    // нужен для инициализации генератора случайных чисел
    std::random_device rd;
    // Объект - генератор случайных чисел с seed (начальным значением) от random_device
    std::mt19937 gen(rd());
    int diff = (max_rand - min_rand) / size + 1;
    int me = max_rand;
    max_rand = min_rand;
    for (size_t n = 0; n < size; ++n){
        // Объект, отвечающий за конкретные парамеры (вид распределения, его параметры)
        // выдаваемых случайных значений
        max_rand += diff;
        if (max_rand >= me){
            max_rand = me;
        }
        std::uniform_int_distribution<> distr(min_rand, max_rand);
        arr[n] = distr(gen);
        min_rand = arr[n];
        
    }
    return arr;
}

/// @brief вывод массива
/// @param arr массив
/// @param size размер массива
void array_output(float *arr, size_t size){
    for (size_t i = 0; i < size; ++i){
        std::cout << std::format("{:.3f}\n", arr[i]);
    }
}

/// @brief вывод массива
/// @param arr массив
/// @param size размер массива
void array_int_output(int *arr, size_t size){
    for (size_t i = 0; i < size; ++i){
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}


/// @details время работы O(n)
/// @brief функция, которая заполняет массив рандомными значениями
/// @param arr массив
/// @param size размер массива
/// @param min_rand минимальное генерируемое значение 
/// @param max_rand максимальное генерируемое значение
/// @return массив arr
float* random_array(float *arr, size_t size, int min_rand, int max_rand){

    // Объект для доступа к аппаратному или программному источнику случайности
    // нужен для инициализации генератора случайных чисел
    std::random_device rd;

    // Объект - генератор случайных чисел с seed (начальным значением) от random_device
    std::mt19937 gen(rd());

    for (size_t n = 0; n < size; ++n){
        // Объект, отвечающий за конкретные парамеры (вид распределения, его параметры)
        // выдаваемых случайных значений
        std::uniform_real_distribution<> distr(min_rand, max_rand);
        arr[n] = distr(gen);
    }
    return arr;
}

/// @details время работы O(n)
/// @brief создает текстовый файл с массивом, в названии файла не нужно указывать расширение
/// @param arr массив
/// @param size размер массива
void create_txt_file(float *arr, size_t size, std::string filename)
{
    // создать объект f для записи в файл, открыть файл
    // если файл не существует, то будет создан, если существует, то будет перезаписан
    std::ofstream f(filename + ".txt");
    if (!f.is_open()) {
        //бросает исключение runtime_error, если не удалось открыть файл 
        throw std::runtime_error("failed to open file: " + filename);
    }
    if ( f.is_open() ) { // проверка, удалось ли открыть файл
        // запись в файл
        for (size_t i = 0; i < size; i++)
        {
            f << arr[i];
            f << "\n";
        }
        f.close(); // закрытие файла, в т.ч. запись файлового буфера на экран
    }
}

/// @brief функция, которая проверяет отсортирован ли массив по возрастанию
/// @param arr массив
/// @param size размер массива
/// @return 1, если массив отсортирован, 0 в другом случае
bool is_arr_sorted(float *arr, size_t size){
    for (size_t i = 1; i < size; i++){
        if (arr[i-1] > arr[i]){
            return 0;
        }
    }
    return 1;
}
