#include "Node.cpp"
#include <iostream>

#ifndef LIST

#define LIST 1

using namespace std;

template <class T>
class List {
    private:
        Node<T> *first;
        Node<T> *last;
        int quantity;
    public:
        List(){
            first = nullptr;
            last = nullptr;
            quantity = 0;
        }

        void add(T *structure){
            Node<T> *newNode = new Node<T>(structure);
            if (quantity > 0){
                this->last->setNext(newNode);
            } else {
                this->first = newNode;
            }
            this->last = newNode;
            quantity++;
        }

        Node<T>* getFirst() {
            return this->first;
        }

        int size() {
            return quantity;
        }

        void print(){
            Node<T> *search = first;
            while (search != nullptr){
                cout << search->structure->name << endl;
                search = search->getNext();
            }
        }

        T* findStruct(string element){
            Node<T> *search = first;
            while (search != nullptr){
                if (search->structure->name == element){
                    return search->structure;
                }
                search = search->getNext();
            }
            return nullptr;
        }

        T* findDevice(string device, string element){
            Node<T> *search = first;
            while (search != nullptr){
                if (search->structure->name == element && search->structure->deviceType == device){
                    return search->structure;
                }
                search = search->getNext();
            }
            return nullptr;
        }
};

#endif