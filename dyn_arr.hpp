// https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2025/2025_part_1.md#%D0%B7%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5-%D0%B4%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%B9-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2
#include <iostream>
#include <stdexcept>
#include <algorithm>
template <typename T>
class DynamicArray{
    T* arr = nullptr;   //указатель на область памяти
    size_t size = 0;    //размер массива
    size_t capacity = 1;    //емкость массива
    
    public:

    /// @brief конструктор класса, capacity по умолчанию равно 1 
    DynamicArray(){
        arr = new T[capacity];
    }

    /// @brief при создании задает необходимую емкость
    /// @param new_capacity 
    DynamicArray(size_t new_capacity){
        if (new_capacity > 0){
            capacity = new_capacity;
            arr = new T[capacity];
        }
        else{
            arr = new T[capacity];
        }
    }

    /// @brief конструктор копирования
    /// @param other массив, из которого копируются данные
    DynamicArray(const DynamicArray<T>& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new T[this->capacity];
        std::copy(other.arr, other.arr + other.size, arr);
    }

    /// @brief деструктор
    ~DynamicArray(){
        if (arr != nullptr) delete[] arr;
    }

    /// @brief геттер размера
    /// @return возвращает размер массива
    size_t get_size(){
        return size; 
    }

    /// @brief емкость массива
    /// @return возвращает емкость массива
    size_t get_capacity(){
        return capacity;
    }

    /// @brief перегрузка оператора, нужен для получения элементов массива и присваивания им значений
    /// @param i индекс массива
    /// @return ссылку
    T& operator[](size_t i){
        if(i < size) return arr[i];
        else throw std::out_of_range("Индекс выходит за границы массива");
    }

    /// @brief для работы с константными объектами
    /// @param i индекс массива
    /// @return ссылку
    const T& operator[](size_t i) const{
        if(i < size) return arr[i];
        else throw std::out_of_range("Индекс выходит за границы массива");
    }

    /// @brief изменение емкости
    /// @param new_size желаемая емкость
    void resize(size_t new_size){
        if (new_size > size){
            capacity = new_size;
            T* new_arr = new T[capacity];
            std::copy(arr, arr + new_size, new_arr);
            delete[] arr;
            arr = new_arr;  
        }
        else{
            throw std::invalid_argument("Слишком маленький размер");
        }
    }

    /// @brief вставляет элемент в конец массива
    /// @param data элемент
    void push_back(T data){
        if ( size == capacity ){
            resize(capacity*2);}
        arr[size] = data;
        size++;
    }

    /// @brief вставляет элемент в idx, элементы, окторые идут после idx сдвигаются вправо
    /// @param idx место,  в которое вставляется элемент
    /// @param data элемент
    void push(size_t idx, T data){
        if (idx < size){
            if (size == capacity){
                resize(capacity*2);
            }
            for (size_t i = size; i > idx; i--){
                arr[i] = arr[i-1];
            }
            arr[idx] = data;
            size++;

        }
        else{ throw std::out_of_range("Индекс выходит за границы массива");}
    }

    /// @brief вставка элемента в начало
    /// @param data данные
    void push_front(T data){
        push(0, data);
    }

    /// @brief вставка в конец
    void pop_back(){
        if (size > 0){
            size--;
            if (size > 0 && (capacity - size) > (size * 4) && capacity > 1) {
                resize(capacity / 2);
            }
        }
        else{
            throw std::out_of_range("Массив пуст!");
        }
    }

    /// @brief удаление элемента с конца
    /// @param idx индекс элемента, который нужно удалить
    void pop(size_t idx){
        if (size == 0){
            throw std::out_of_range("Массив пуст!");
        }
        if (idx < size){
            for (size_t i = idx+1; i < size; i++){
                arr[i-1] = arr[i];
            }
            size--;
            if (size > 0 && (capacity - size) > (size * 4) && capacity > 1) {
                resize(capacity / 2);
            }
        }
        else{
            throw std::out_of_range("Индекс выходит за границы массива");
        }
    }

    /// @brief удаление элемента из начала
    void pop_front(){
        pop(0);
    }


};
