#include <iostream>
#include <stdexcept>
#include <queue>
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

        /// @brief 
        /// @param root 
        /// @param order 1 - прямой, 0 - обратный
        void leftOrderHelper(Node<T>* root, bool order){
            if (order == 1){
                if (node == nullptr) return;
                cout << root->data << " ";
                leftOrderHelper(root->left, 1);
                leftOrderHelper(root->right, 1);
            }

            if (order == 0){
                if (node == nullptr) return;
                leftOrderHelper(root->left, 0);
                leftOrderHelper(root->right, 0);
                cout << root->data << " ";
            }
        }

        /// @brief 
        /// @param root 
        /// @param order 1 - прямой, 0 - обратный
        void rightOrderHelper(Node<T>* root, bool order){
            if (order == 1){
                if (node == nullptr) return;
                cout << root->data;
                rightOrderHelper(root->right, 1);
                rightOrderHelper(root->left, 1);
            }

            if (order == 0){
                if (node == nullptr) return;
                rightOrderHelper(root->right, 0);
                rightOrderHelper(root->left, 0);
                cout << root->data;
            }
        }



    public:
        /// @brief конструктор
        BinaryTree(): root(nullptr){    
        };

        /// @brief деструктор 
        ~BinaryTree(){
            clearHelper(root);
        }

        /// @brief 
        /// @param order 1 - прямой обход, 0 - обратный обход 
        void leftOrder(bool order){
            leftOrderHelper(root, order);
        }
        /// @brief 
        /// @param order 1 - прямой обход, 0 - обратный обход
        void rightOrder(bool order){
            rightOrderHelper(root, order);
        }

        /// @brief функция вставки элемента к нужному родителю
        /// @param data значение элемента
        /// @param parent к какому родителю вставить элемент
        /// @param flag в какую сторону вставить, 0 - влево, 1 - вправо
        /// @return 
        Node<T>* insert(T data, Node<T>* parent, bool flag){
            if (parent != nullptr){
                if (flag == 0){
                    if (parent->left == nullptr){
                        Node<T>* newNode = new Node<T>(data);
                        parent -> left = newNode;
                        return parent -> left;
                    }
                    return;
                }
                else{
                    if (parent->right==nullptr){
                        Node<T>* newNode = new Node<T>(data);
                        parent->right = newNode;
                        return parent -> right;
                    }
                }
            }
            return nullptr;
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

        void bsf_reverse(){
            
        }

        /// левый обход, правый обход, в ширину(прямой, обратный), симметричный обход(необяз)
        /// 1.2 отдельный класс бинарного дерева поиска(структура, добавление, удаление, поиск(кол-во операции)
        /// 1.3 класс бинарное дерево(на массиве) (структура, добавление, удаение, возврат элемента по индексам, сортировка массива(турнирная))
        /// 1.4 класс бинарн пирамидальная сортировка
        /// конкорданс
};