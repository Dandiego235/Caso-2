#include "List.cpp"
#include "Parameter.cpp"
#include <iostream>

#ifndef ACTION

#define ACTION 1

using namespace std;

typedef struct Taction { // Estructura para representar las acciones de un dispositivo
    string name;
    List<Tparameter> paramModify; // Lista de parámetros que puede modificar.
    Taction (string pName, List<Tparameter> pDeviceParams, vector<string> pParamsMod) {
        this->name = pName;
        Tparameter *structPtr; // Puntero a estructuras de parámetros
        for (int index = 0; index < pParamsMod.size(); index++){ // Itera por el vector de los nombres de los parámetros
            structPtr = pDeviceParams.findStruct(pParamsMod[index]); // Encuentra la estructura con el nombre del string dado.
            if (structPtr != nullptr){ // Si la encontró, el puntero no es nullptr, entonces la agrega.
                paramModify.add(structPtr);
            }
        }
    } 
    void execute(string pParam, string pValue){ // Función para simular la ejecución de acciones.
        Tparameter *structPtr = paramModify.findStruct(pParam);
        // se obtuvo el apuntador a la estructura de parámetros en sí por si en el futuro se quisiera cambiarle un valor dentro del objeto.
        cout << "Se ha alterado el estado del parámetro " << structPtr->name << " a " << pValue << ".\n" << endl;
    }
}*PtrAction;

#endif