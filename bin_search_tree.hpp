#include <iostream>
#include <stdexcept>
// @brief узел списка
/// @tparam T тип данных
template <typename T>
struct Node{
    // поле с данными которые хранятся в узле
    T data;
    // указатель на левого потомка
    Node* left;
    // указатель на правого потомка
    Node* right;
    // конструктор
    Node(T new_data): data(new_data), left(nullptr), right(nullptr){}
};

/// @brief класс двусвязного списка
/// @tparam T тип данных
template <typename T>
class BinarySearchTree{
    private:
        // поле, которое хранит указатель на начало списка
        Node<T>* root;

        void popHelper(Node<T>*& node, T data){
            if (node == nullptr) return;

            if (data < node->data){
                popHelper(node->left, data);
            }
            else if (data > node->data){
                popHelper(node->right, data);
            }
            else {
                // нашли узел
                if (node->left == nullptr && node->right == nullptr){
                    delete node;
                    node = nullptr;
                }
                else if (node->left == nullptr){
                    Node<T>* tmp = node;
                    node = node->right;
                    delete tmp;
                }
                else if (node->right == nullptr){
                    Node<T>* tmp = node;
                    node = node->left;
                    delete tmp;
                }
                else {
                    Node<T>* minParent = node;
                    Node<T>* minNode = node->right;
                    while (minNode->left){
                        minParent = minNode;
                        minNode = minNode->left;
                    }
                    node->data = minNode->data;
                    popHelper(node->right, minNode->data);   
                }
            }
        }

        void clearHelper(Node<T>* node){
            if (node == nullptr) return;
            clearHelper(node->left);
            clearHelper(node->right);
            delete node;
            }
    public:
        /// @brief конструктор
        BinarySearchTree(): root(nullptr){    
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
            Node<T>* current = root;
            while (true){
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
        }

        Node<T>* search(T data){
            Node<T>* current = root;
            while (current != nullptr){
                if (data < current->data){
                current = current->left;
                }
                else if (data > current->data){
                    current = current->right;
                }
                else{
                    return current;
                }
            }
            return nullptr;
        }

        /// @brief 
        void remove(T data){
            popHelper(root, data);
        }

        /// @brief вывод дерева в порядке по возрастанию
        void print(){

        }

        /// левый обход, правый обход, в ширину(прямой, обратный), симметричный обход(необяз)
        /// 1.2 отдельный класс бинарного дерева поиска(структура, добавление, удаление, поиск(кол-во операции)
        /// 1.3 класс бинарное дерево(на массиве) (структура, добавление, удаение, возврат элемента по индексам, сортировка массива(турнирная))
        /// 1.4 класс бинарн пирамидальная сортировка
        /// конкорданс
};
