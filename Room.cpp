
#include "List.cpp"
#include "Device.cpp"

#ifndef ROOM

#define ROOM 1

using namespace std;

typedef struct Room { // Estructura para los cuartos con una lista de dispositivos dentro de su estructura.
    string name; // nombre del cuarto
    List<Device> Devices; // Lista de dispositivos del cuarto.

    Room (string pName){
        this->name = pName;
    }
}*RoomPtr;

#endif