#include <iostream>

#ifndef NODE

#define NODE 1

using namespace std;

template <class T>
class Node{
    private:
        Node<T> *next;
    public:
        T *structure; // El nodo apunta a una estructura, un struct o clase.
        Node(){
            next = nullptr;
            structure = nullptr;
        }
        Node(T *pointer){
            next = nullptr;
            structure = pointer; // Se establece el puntero de la estructura como el puntero ingresado.
        }

        Node<T>* getNext(){
            return next;
        };

        void setNext(Node<T> *pointer){
            this->next = pointer;
        };
};

#endif