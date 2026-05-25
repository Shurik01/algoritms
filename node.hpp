#include <iostream>
template <typename T>
struct Node{
    T data;
    Node* prev;
    Node* next;
    Node(T new_data){ data = new_data; prev = nullptr; next = nullptr;}
};

template <typename T>
class List{
    Node<T>* head;
    Node<T>* tail;
    size_t size;
    public:
        List(){
            
        };
        void push_front(T data);
}