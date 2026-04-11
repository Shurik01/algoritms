#include  "function.hpp"
// Инициализируйте генератор случайных чисел номером вашего варианта * 42. Номер варианта - номер строки в гугл-таблице с отметками о выполнении.
// Определите размер массива от 10-20 элементов с помощью генератора случайных чисел.
// Заполните массив случайными числами от 0 до 30
// Ищите случайное число от 0 до 30
// Опишите все итерации бинарного поиска в отчёте.
using namespace std;
int main(){
    std::random_device rd;
    // Объект - генератор случайных чисел с seed (начальным значением) от random_device
    std::mt19937 gen(13 * 42);
    uniform_int_distribution<> distr(10, 20);
    size_t size = distr(gen);
    cout << "размер массива: " << size << endl;
    // массив заполняется случайными числами от 0 до 30
    int* arr = new int[size];
    arr = random_array_int_increasing(arr, size, 0, 30);
    cout << "массив: ";
    array_int_output(arr, size);
    uniform_int_distribution<> dist(0, 30);
    int num = dist(gen);

    cout << "искомое число: "<< num << endl;
    int count = 0;
    size_t l = 0;
    size_t r = size - 1;
    
    while (l < r) {
        cout << "итерация " << count << endl;  
        size_t mid = l + (r - l) / 2;

        cout << "mid = " << mid << endl;
        cout << "l = " << l << endl;
        cout << "r = " << r << endl;
        cout << "arr[mid] = " << arr[mid] << endl;
        
        if (arr[mid] == num) {
            cout << "индекс искомого числа " << mid;
            break;
        }
        if (arr[mid] < num) {
            l = mid + 1;
        } else {
            r = mid;
        }
        count += 1;
        
        if (l >= r and arr[mid] != num){
            cout << "число не найдено";
        }
    }
    
    delete[] arr;
    return 0;
}
