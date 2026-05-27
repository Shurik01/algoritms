#include <iostream>
#include <stdexcept>
/// @brief узел списка
/// @tparam T тип данных
template <typename T>
struct Node{
    // поле с данными которые хранятся в узле
    T data;
    // указатель на предыдущий элемент
    Node* prev;
    // указатель на следующий элемент
    Node* next;
    // конструктор
    Node(T new_data): data(new_data), prev(nullptr), next(nullptr){}
};
/// @brief класс двусвязного списка
/// @tparam T тип данных
template <typename T>
class List{
    private:
        // поле, которое хранит указатель на начало списка
        Node<T>* head;
        // поле, которое хранит указательна конец списка
        Node<T>* tail;
        // поле, которое хранит размер списка
        size_t size;
        /// @brief метод для получения узла списка(O(n))
        /// @param idx индекс узла
        /// @return узел списка
        Node<T>* get_node(size_t idx) const{
            if (idx >= size){
                // бросает исключение, если обращаемся к индексу вне границ списка
                throw::std::out_of_range("Индекс выходит за границы списка");
            }
            Node<T>* current = head;
            for (size_t i = 0; i < idx; i++){
                Node<T>* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            return current;
        }
    public:
        /// @brief конструктор
        List(): head(nullptr), tail(nullptr), size(0){    
        };

        /// @brief деструктор 
        ~List(){
            clear();
        }

        /// @brief конструктор копирования(O(n))
        /// @param other другой список из которого копируем
        List(const List& other) : head(nullptr), tail(nullptr), size(0){
            Node<T>* current = other.head;
            while (current != nullptr){
                push_back(current->data);
                current = current -> next;
            }
        }

        /// @brief операторр присваивания копированием(O(n))
        /// @param other массив который копируем
        /// @return 
        List& operator=(const List& other){
            if (this != &other){
                clear();
                Node<T>* current = other.head;
                while (current != nullptr){
                    push_back(current->data);
                    current = current->next;
                }
            }
            return *this;
        }
        /// @brief конструктор перемещения(O(1))
        /// @param other другой список
        List(List&& other) noexcept : head(other.head), tail(other.tail), size(other.size){
            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }

        /// @brief оператор перемещения(для временных объектов)(O(1))
        /// @param other другой список
        /// @return список
        List& operator=(List&& other) noexcept{
            if (this != &other){
               clear();
               head = other.head;
               tail = other.tail;
               size= other.size;
               other.head = nullptr;
               other.tail = nullptr;
               other.size = 0; 
            }
            return *this;
        }

        /// @brief геттер размера(O(1))
        /// @return размер списка
        size_t get_size(){
            return size;
        }

        /// @brief вставка в начало списка(O(1))
        /// @param data данные
        void push_front(T data){
            Node<T>* newNode = new Node<T>(data);
            if (head == nullptr){
                head = tail = newNode;
            } 
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }

        /// @brief вставка в конец списка(O(1))
        /// @param data данные
        void push_back(T data){
            Node<T>* newNode = new Node<T>(data);
            if (head==nullptr){
                head = tail = newNode;
            } 
            else{
                newNode->prev=tail;
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        /// @brief вставка в произвольное место списка(O(n))
        /// @param idx индекс(куда вставится значения)
        /// @param data данные
        void insert(size_t idx, T data){
            if (idx == 0){
                push_front(data);
                return;
            }
            if (idx == size){
                push_back(data);
                return;
            }
            if (idx < size){
                Node<T>* current = get_node(idx);
                Node<T>* newNode = new Node<T>(data);
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
                size++;
            }
        }

        /// @brief удаление элемента с конца списка(O(1))
        void pop_back(){
            if (tail == nullptr) return;
            Node<T>* temp = tail;
            tail = tail->prev;
            if (tail != nullptr){
                tail->next = nullptr;
            }
            else{
                head = nullptr;
            }
            delete temp;
            size--;
        }

        /// @brief удаление элемента в начале списка(O(1))
        void pop_front(){
            if (head == nullptr) return;
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr){
                head->prev = nullptr;
            }
            else{
                tail = nullptr;
            }
            delete temp;
            size--;
        }

        /// @brief удаление произвольного элемента списка(O(n))
        /// @param idx индекс элемента, который удаляем
        void pop(size_t idx){
            if (idx == 0){
                pop_front();
                return;
            }
            if (idx == size){
                pop_back();
                return;
            }
            if (idx < size){
                Node<T>* current = get_node(idx);
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
            }
        }

        /// @brief получение элемента списка(O(n))
        /// @param idx индекс элемента
        /// @return элемент списка(данные узла)
        T& at(size_t idx){
            return get_node(idx)->data;
        }

        /// @brief получение элемента списка(для константных объектов)(O(n))
        /// @param idx индекс элемента
        /// @return элемент списка(данные узла)
        const T& at(size_t idx) const{
            return get_node(idx)->data;
        }

        /// @brief присоединяет к текущуму списку другой(O(n))
        void association(const List& other){
            Node<T>* current = other.head;
            while (current != nullptr){
                push_back(current->data);
                current = current->next;
            }
        } 

        /// @brief очищает список(O(n))
        void clear(){
            while (head != nullptr){
                pop_front();
            }
        }
};