#include <iostream>
#include <stdexcept>
// @brief узел списка
/// @tparam T тип данных
template <typename T>
struct Node{
    // поле с данными которые хранятся в узле
    T data;
    // указатель на предыдущий элемент
    Node* left;
    // указатель на следующий элемент
    Node* right;
    // конструктор
    Node(T new_data): data(new_data), left(nullptr), right(nullptr){}
};

/// @brief класс двусвязного списка
/// @tparam T тип данных
template <typename T>
class Tree{
    private:
        // поле, которое хранит указатель на начало списка
        Node<T>* root;
    
    public:
        /// @brief конструктор
        Tree(): root(nullptr){    
        };

        /// @brief деструктор 
        ~Tree(){
            clear();
        }
        /// @brief вставка
        /// @param data данные
        void insert(T data){
            Node<T>* newNode = new Node<T>(data);
            if (root == nullptr){
                root = newNode;
                return;
            }
            while (true){
                Node<T>* current = root;
                if (data <  current->data){
                    if (current->left == nullptr){
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else{
                    if (current->right == nullptr){
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }                
            }
                while (current != nullptr){
                }
                current = newNode;
        }
        /// @brief 
        void pop(){

        }
        /// @brief вывод дерева в порядке по возрастанию
        void print(){

        }

        /// левый обход, правый обход, в ширину 
        /// отдельный класс бинарного дерева поиска
        /// конкорданс
};
