#include "dyn_arr.hpp"
#include <cassert>
int main(){
    // конструктор по умолчанию
    DynamicArray<int> arr;

    arr.push_back(5);
    assert(arr.get_size() == 1);    // проверка - изменился ли размер
    assert(arr[0] == 5);    // проверка правильно ли вставилось число

    arr[0] = 1;     // изменяем первый элемент arr(1)
    assert(arr[0] = 1);  // изменился ли
    arr.resize(10);     // изменяем емкость массива
    assert(arr.get_capacity() == 10);   // тест изменилась ли

    arr.push_front(2);  // в начало вставляем 2, arr(2, 1)
    assert(arr[0] == 2);

    arr.push(1, 6);     //arr(2, 6, 1)
    assert(arr[1] == 6);
    assert(arr[0] == 2);
    assert(arr[2] == 1);

    arr.pop_back();
    assert(arr.get_size() == 2);

    // arr(2, 6, 8, 9)
    arr.push_back(8);
    arr.push_back(9);
    arr.pop_front();
    assert(arr[0] == 6);
    assert(arr[1] == 8);
    assert(arr[2] == 9);

    arr.pop(1);
    assert(arr[0] == 6);
    assert(arr[1] == 9);
    return 0;
}