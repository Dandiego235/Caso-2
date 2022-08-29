#include "Node.cpp"
#include <iostream>

#ifndef LIST

#define LIST 1

using namespace std;

template <class T>
class List {
    private:
        Node<T> *first; // primer nodo
        Node<T> *last; // ultimo nodo
        int quantity; // cantidad de nodes
    public:
        List(){
            first = nullptr; // inicializamos los atributos.
            last = nullptr;
            quantity = 0;
        }

        void add(T *structure){ // función que agrega nodos que apuntan a un struct o clase.
            Node<T> *newNode = new Node<T>(structure); // Se crea un nodo para la estructura

            if (quantity > 0){ // si la lista no está vacía, 
                this->last->setNext(newNode); // el siguiente del último es el nuevo nodo
            } else {
                this->first = newNode; // Si está vacía, el primero es este nodo.
            }
            this->last = newNode; // El último es el nodo agregado
            quantity++;
        }

        Node<T>* getFirst() { // Retorna el primer nodo de la lista.
            return this->first;
        }

        int size() { // Retorna el tamaño de la lista.
            return quantity;
        }

        void print(){ // Imprime los nombres de las estructuras a las que apuntan los nodos.
            Node<T> *search = first;
            while (search != nullptr){
                cout << search->structure->name << endl;
                search = search->getNext();
            }
        }

        T* findStruct(string element){ // Encuentra la estructura en un nodo a partir de su nombre.
            Node<T> *search = first;
            while (search != nullptr){
                if (search->structure->name == element){ // Si el nombre de la estructura del nodo que se está revisando es igual al string ingresado.
                    return search->structure; // retorna el puntero a la estructura.
                }
                search = search->getNext(); // Si no, continúa por el siguiente de la lista.
            }
            return nullptr; // Si no lo encuentra, retorna nullptr.
        }

        T* findDevice(string device, string element){ // Encuentra un dispositivo, a partir del nombre del tipo del dispositivo y el nombre del dispositivo.
            Node<T> *search = first;
            while (search != nullptr){
                if (search->structure->name == element && search->structure->deviceType == device){
                    // Si el nombre de la estructura del nodo que se está revisando y el nombre del tipo es igual a los strings ingresados.
                    return search->structure; // retorna el puntero al dispositivo.
                }
                search = search->getNext(); // Si no, continúa por el siguiente de la lista.
            }
            return nullptr; // Si no lo encuentra, retorna nullptr.
        }
};

#endif