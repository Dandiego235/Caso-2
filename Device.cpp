#include <iostream>
#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"


#ifndef DEVICE

#define DEVICE 1

using namespace std;

class Device { // Clase general de la cual las subclases para cada dispositivo va a heredar sus atributos.
    public:
        string name; // nombre del dispositivo
        string deviceType; // nombre del tipo del dispositivo
        List<Tparameter> params; // parámetros del tipo de dispositivo
        List<Taction> actions; // Acciones del tipo de dispositivo-
        void getParams(){ // Función para obtener los parámetros del disposito.
            cout<< "Parámetros de " << name << ":" << endl;
            params.print();
        }
        void getActions(){ // Función para obtener las acciones del disposito.
            cout<< "Acciones de " << name << ":" << endl;
            actions.print();
        }
};

#endif