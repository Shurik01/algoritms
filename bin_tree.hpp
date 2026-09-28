#include <iostream>
#include <stdexcept>
using namespace std;

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
class BinaryTree{
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
        BinaryTree(): root(nullptr){    
        };

        /// @brief деструктор 
        ~Tree(){
            clear();
        }

        /// @brief функция вставки элемента к нужному родителю
        /// @param data значение элемента
        /// @param parent к какому родителю вставить элемент
        /// @param flag в какую сторону вставить, 0 - влево, 1 - вправо
        /// @return 
        Node<T>* insert(T data, Node<T>* parent, bool flag){
            if (flag == False){
                if (parent->left == nullptr){
                    Node<T>* newNode = new Node<T>(data);
                    parent -> left = newNode;
                }
                return;
            }
            else{
                if (parent->right==nullptr){
                    Node<T>* newNode = new Node<T>(data);
                    parent->right = newNode;
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
        void bsf(){
            Node<T>* current = root;
            
        }

        /// левый обход, правый обход, в ширину(прямой, обратный), симметричный обход(необяз)
        /// 1.2 отдельный класс бинарного дерева поиска(структура, добавление, удаление, поиск(кол-во операции)
        /// 1.3 класс бинарное дерево(на массиве) (структура, добавление, удаение, возврат элемента по индексам, сортировка массива(турнирная))
        /// 1.4 класс бинарн пирамидальная сортировка
        /// конкорданс
};
