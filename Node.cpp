#include <iostream>

#ifndef NODE

#define NODE 1

using namespace std;

template <class T>
class Node{
    private:
        Node<T> *next;
    public:
        T *structure;
        Node(){
            next = nullptr;
            structure = nullptr;
        }
        Node(T *pointer){
            next = nullptr;
            structure = pointer;
        }

        Node<T>* getNext(){
            return next;
        };

        void setNext(Node<T> *pointer){
            this->next = pointer;
        };
};

#endif