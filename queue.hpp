#include "dyn_arr.hpp"
using namespace std;
/// шаблонный класс
template <typename T>
/// класс очереди на основе динамического массива
class Queue{
private:
// переменная, которая отвечает за очередь
    DynamicArray<T> arr;
public:
    /// @brief конструктор класса
    Queue(): arr(){};
    
    /// @brief вставка в конец очереди
    /// @param data данные
    void push(T data){
        arr.push_back(data);
    }

    /// @brief получение последнего элемента
    /// @return элемент
    T get_element(){
        return arr[arr.get_size() - 1];
    }

    /// @brief удаление первого элемента
    void pop(){
        arr.pop_front();
    }

    /// @brief проверка на пустоту
    /// @return 1 - если пуст, 0 - если нет
    bool is_empty() const {
        if(arr.get_size() == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
  
    /// @brief размер очереди
    /// @return размер очереди
    size_t size() const {
        return arr.get_size();
    }
};