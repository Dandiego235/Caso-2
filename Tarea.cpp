#include <iostream>
#include <vector>
#include "List.cpp"
#include "Action.cpp"
#include "Parameter.cpp"
#include "Device.cpp"
#include "Room.cpp"

#ifndef TAREA

#define TAREA 1

#define ROOMINDEX 0
#define DEVICETYPEINDEX 1
#define NAMEINDEX 2
#define ACTIONINDEX 3
#define PARAMETERINDEX 4
#define VALUEINDEX 5

using namespace std;

struct Ttarea { // Estructura para almacenar las tareas
    string name; // nombre de la tarea
    vector<vector<string>> tasks; // Vector configurable de la tarea.
    List<Room> *House; // Lista donde se almacenan los cuartos.

    Ttarea (string pName, List<Room> *pHouse, vector<vector<string>> pTasks) : name(pName), House(pHouse), tasks(pTasks) { } // constructor

    void llamarTarea(){ // tasks = {{Room, Type, Name, Action, Parameter, Value},...}
        cout << this->name << endl;
        for (int device = 0; device < tasks.size(); device++){ 
            // Itera por cada dispositivo de la lista de acciones que se van a agregar en la tarea de buenosDias
            Device *roomDevice = House->findStruct(tasks[device][ROOMINDEX])->Devices.findDevice(tasks[device][DEVICETYPEINDEX], tasks[device][NAMEINDEX]);
            //                  Encuentra el cuarto en la casa    Accede a la lista de dispositivos y encuentra el objeto del dispositivo correcto
            cout << roomDevice->deviceType << " " << roomDevice->name << endl;
            //       imprime el tipo y el nombre

            roomDevice->actions.findStruct(tasks[device][ACTIONINDEX])->execute(tasks[device][PARAMETERINDEX], tasks[device][VALUEINDEX]);
            // ejecuta la acción dada con el parámetro y valor dados.
        }   
    }
};

#endif