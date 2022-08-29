#include <iostream>
#include <vector>
#include <string>

#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"
#include "Device.cpp"
#include "Tarea.cpp"
#include "Room.cpp"
#include "Alarma.cpp"
#include "Bombillo.cpp"
#include "CoffeeMaker.cpp"
#include "SensorHumo.cpp"
#include "SensorPuertas.cpp"
#include "TomaCorriente.cpp"

using namespace std;

/* Estructura para declarar subclases de distintos dispositivos.
class TipoDispositivo : public Device{ // Subclase que hereda las características de Device para opjetos del tipo.
    public:
        Bombillo(List<Tparameter> paramsTipo, List<Taction> pActions, string pName){
            this->deviceType = "Tipo";
            this->name = pName;
            this->params = paramsTipo;
            this->actions = pActions;
        }
};*/

/* Estructura para crear nuevas tareas. Solo hace falta cambiarle el nombre a la función para crear una nueva tarea.
   Lo que la tarea haga se especifica en el main.
void nombreTarea (List<Room> *House, vector<vector<string>> tasks){ // tasks = {{Room, Type, Name, Action, Parameter, Value},...}
    for (int device = 0; device < tasks.size(); device++){
        Device *roomDevice = House->findStruct(tasks[device][ROOM])->Devices.findDevice(tasks[device][DEVICETYPE], tasks[device][NAME]);
        cout << roomDevice->deviceType << " " << roomDevice->name << endl;
        roomDevice->actions.findStruct(tasks[device][ACTION])->execute(tasks[device][PARAMETER], tasks[device][VALUE]);
    }   
}*/

int main(){
    List<Tparameter> parametersBo; // Se crea lista de parámetros de bombillo
    PtrParam param1Bombillo = new Tparameter("Brillo"); // se agregan parámetros a la lista.
    PtrParam param2Bombillo = new Tparameter("Color");
    PtrParam param3Bombillo = new Tparameter("Tamaño");
    parametersBo.add(param1Bombillo);
    parametersBo.add(param2Bombillo);
    parametersBo.add(param3Bombillo);

    List<Taction> accionesBo; // Se crea la lista de acciones del bombillo
    PtrAction accion1Bombillo = new Taction("Encender", parametersBo, {"Brillo", "Color"});
    PtrAction accion2Bombillo = new Taction("Apagar", parametersBo, {"Brillo", "Color"});
    accionesBo.add(accion1Bombillo); // Se agregan acciones a la lista.
    accionesBo.add(accion2Bombillo);
    
    List<Tparameter> parametersSP; // Parámetros y acciones del Sensor de puertas
    PtrParam param1SP = new Tparameter("Actividad");
    PtrParam param2SP = new Tparameter("Estado");
    PtrParam param3SP = new Tparameter("Sonido");
    PtrParam param4SP = new Tparameter("Notificacion");
    parametersSP.add(param1SP);
    parametersSP.add(param2SP);
    parametersSP.add(param3SP);
    parametersSP.add(param4SP);

    List<Taction> accionesSP;
    PtrAction accion1SP = new Taction("Encender", parametersSP, {"Actividad"});
    PtrAction accion2SP = new Taction("Apagar", parametersSP, {"Actividad"});
    PtrAction accion3SP = new Taction("Abrir", parametersSP, {"Estado", "Sonido", "Notificacion"});
    PtrAction accion4SP = new Taction("Cerrar", parametersSP, {"Estado", "Sonido", "Notificacion"});
    accionesSP.add(accion1SP);
    accionesSP.add(accion2SP);
    accionesSP.add(accion3SP);
    accionesSP.add(accion4SP);

    List<Tparameter> parametersSH; // Parámetros y acciones del Sensor de Humo
    PtrParam param1SH = new Tparameter("Actividad");
    PtrParam param2SH = new Tparameter("Sensibilidad");
    PtrParam param3SH = new Tparameter("Sonido");
    parametersSH.add(param1SH);
    parametersSH.add(param2SH);
    parametersSH.add(param3SH);

    List<Taction> accionesSH;
    PtrAction accion1SH = new Taction("Encender", parametersSH, {"Actividad"});
    PtrAction accion2SH = new Taction("Apagar", parametersSH, {"Actividad"});
    PtrAction accion3SH = new Taction("Ajustar", parametersSH, {"Sensibilidad"});
    PtrAction accion4SH = new Taction("Activar", parametersSH, {"Sonido"});
    PtrAction accion5SH = new Taction("Desactivar", parametersSH, {"Sonido"});
    accionesSH.add(accion1SH);
    accionesSH.add(accion2SH);
    accionesSH.add(accion3SH);
    accionesSH.add(accion4SH);
    accionesSH.add(accion5SH);

    List<Tparameter> parametersCM; // Parámetros y acciones del Coffee Maker
    PtrParam param1CM = new Tparameter("Actividad");
    PtrParam param2CM = new Tparameter("Modo");
    PtrParam param3CM = new Tparameter("Intensidad");
    parametersCM.add(param1CM);
    parametersCM.add(param2CM);
    parametersCM.add(param3CM);

    List<Taction> accionesCM;
    PtrAction accion1CM = new Taction("Encender", parametersCM, {"Actividad"});
    PtrAction accion2CM = new Taction("Apagar", parametersCM, {"Actividad"});
    PtrAction accion3CM = new Taction("Ajustar", parametersCM, {"Intensidad"});
    PtrAction accion4CM = new Taction("Preparar", parametersCM, {"Modo"});
    accionesCM.add(accion1CM);
    accionesCM.add(accion2CM);
    accionesCM.add(accion3CM);
    accionesCM.add(accion4CM);

    List<Tparameter> parametersAl; // Parámetros y acciones de la alarma
    PtrParam param1Al = new Tparameter("Actividad");
    PtrParam param2Al = new Tparameter("Sonido");
    PtrParam param3Al = new Tparameter("Hora");
    parametersAl.add(param1Al);
    parametersAl.add(param2Al);
    parametersAl.add(param3Al);

    List<Taction> accionesAl;
    PtrAction accion1Al = new Taction("Encender", parametersAl, {"Actividad", "Sonido"});
    PtrAction accion2Al = new Taction("Apagar", parametersAl, {"Actividad", "Sonido"});
    PtrAction accion3Al = new Taction("Posponer", parametersAl, {"Hora"});
    PtrAction accion4Al = new Taction("Configurar", parametersAl, {"Hora"});
    accionesAl.add(accion1Al);
    accionesAl.add(accion2Al);
    accionesAl.add(accion3Al);
    accionesAl.add(accion4Al);

    List<Tparameter> parametersTC; // Parámetros y acciones del toma corriente
    PtrParam param1TC = new Tparameter("Actividad");
    parametersTC.add(param1TC);

    List<Taction> accionesTC;
    PtrAction accion1TC = new Taction("Encender", parametersTC, {"Actividad"});
    PtrAction accion2TC = new Taction("Apagar", parametersTC, {"Actividad"});
    accionesTC.add(accion1TC);
    accionesTC.add(accion2TC);

    Bombillo *bombillo1 = new Bombillo(parametersBo, accionesBo, "Cuarto Cama"); // Se crean unos bombillos y otros dispositivos
    Bombillo *bombillo2 = new Bombillo(parametersBo, accionesBo, "Cuarto Techo");
    Alarma *alarma1 = new Alarma(parametersAl, accionesAl, "Despertador");
    SensorPuertas *sensorPuertas1 = new SensorPuertas(parametersSP, accionesSP, "Cuarto");
    TomaCorriente *tomaCorriente1 = new TomaCorriente(parametersTC, accionesTC, "Cuarto");

    Room *Cuarto = new Room("Cuarto"); // Se crea un cuarto y se le asignan los dispositivos
    Cuarto->Devices.add(bombillo1);
    Cuarto->Devices.add(bombillo2);
    Cuarto->Devices.add(alarma1);
    Cuarto->Devices.add(sensorPuertas1);
    Cuarto->Devices.add(tomaCorriente1);
    

    RoomPtr Cocina = new Room("Cocina"); // se crea un cuarto para la cocina y se crean dispositivos para la cocina
    Bombillo *bombillo3 = new Bombillo(parametersBo, accionesBo, "Cocina 1");
    Bombillo *bombillo4 = new Bombillo(parametersBo, accionesBo, "Cocina 2");
    SensorHumo *sensorHumo1 = new SensorHumo(parametersSH, accionesSH, "Cocina");
    CoffeeMaker *coffeeMaker = new CoffeeMaker(parametersCM, accionesCM, "Cocina");
    TomaCorriente *tomaCorriente2 = new TomaCorriente(parametersTC, accionesTC, "Cocina");
    SensorPuertas *sensorPuertas2 = new SensorPuertas(parametersSP, accionesSP, "Cocina");
    Cocina->Devices.add(bombillo3); // se agregan los dispositivos a la cocina
    Cocina->Devices.add(bombillo4);
    Cocina->Devices.add(alarma1);
    Cocina->Devices.add(sensorHumo1);
    Cocina->Devices.add(coffeeMaker);
    Cocina->Devices.add(tomaCorriente2);
    Cocina->Devices.add(sensorPuertas2);

    RoomPtr Bano = new Room("Baño");
    Bombillo *bombillo5 = new Bombillo(parametersBo, accionesBo, "Baño");
    TomaCorriente *tomaCorriente3 = new TomaCorriente(parametersTC, accionesTC, "Baño");
    Bano->Devices.add(bombillo5);
    Bano->Devices.add(tomaCorriente3);

    RoomPtr Oficina = new Room("Oficina");
    Bombillo *bombillo6 = new Bombillo(parametersBo, accionesBo, "Oficina");
    TomaCorriente *tomaCorriente4 = new TomaCorriente(parametersTC, accionesTC, "Computadora");
    TomaCorriente *tomaCorriente5 = new TomaCorriente(parametersTC, accionesTC, "Monitor");
    Oficina->Devices.add(bombillo6);
    Oficina->Devices.add(tomaCorriente4);
    Oficina->Devices.add(tomaCorriente5);
    
    List<Room> *Casa = new List<Room>(); // Se agrupan los cuartos en una casa.
    Casa->add(Cuarto);
    Casa->add(Cocina);
    Casa->add(Bano);
    Casa->add(Oficina);

    List<Ttarea> *Tareas = new List<Ttarea>(); // se crea una lista para las tareas.

    // Estructura de cada dispositivo en el vector de acciones en la tarea.
    // {"Nombre del cuarto", "Nombre del tipo", "Nombre del disp", "Nombre de accion", "Nombre de param", "Valor de param"}
    vector<vector<string>> buenosDiasVec = {{"Cuarto", "Bombillo", "Cuarto Cama", "Apagar", "Brillo", "Apagado"}, 
    {"Cuarto", "Bombillo", "Cuarto Cama", "Apagar", "Color", "Ninguno"},
    {"Cocina", "Coffee Maker", "Cocina", "Encender", "Actividad", "Encendido"},
    {"Cocina", "Coffee Maker", "Cocina", "Preparar", "Modo", "Haciendo café"},
    {"Baño", "Bombillo", "Baño", "Encender", "Brillo", "Alto"},
    {"Baño", "Bombillo", "Baño", "Encender", "Color", "Blanco"},
    {"Cuarto", "Alarma", "Despertador", "Apagar", "Sonido", "Apagado"},
    {"Cuarto", "Toma Corriente", "Cuarto", "Encender", "Actividad", "Encendido"}};

    Ttarea *buenosDias = new Ttarea("Buenos días", Casa, buenosDiasVec);

    Tareas->add(buenosDias);

    Tareas->findStruct("Buenos días")->llamarTarea(); // Con el string del nombre puedo llamar a la tarea.
    

    vector<vector<string>> trabajarVec = {
        {"Oficina", "Bombillo", "Oficina", "Encender", "Brillo",  "Alto"},
        {"Oficina", "Toma Corriente", "Computadora", "Encender", "Actividad", "Encendido"},
        {"Oficina", "Toma Corriente", "Monitor", "Encender", "Actividad", "Encendido"}};

    Ttarea *trabajar = new Ttarea("Trabajar", Casa, trabajarVec); // creamos la tarea de trabajar

    Tareas->add(trabajar); // la añadimos a la Lista de tareas.

    Tareas->findStruct("Trabajar")->llamarTarea(); // Llamamos a la tarea con su string.

    //bombillo1->getParams(); // instrucciones para obtener los parámetros y acciones de un dispositivo
    //bombillo1->getActions();
}

//Cuarto->Devices.findDevice("Bombillo", "Cuarto")->actions.findStruct("Encender")->execute("Brillo", "Alto");
//bombillo1->actions.findStruct("Encender")->execute("Brillo", "Alto");
//accion1Bombillo->execute("Color", "Rojo");
//accion1Bombillo->execute("Color", "Azul");
//cout << param2Bombillo->value << endl;
//Cuarto->Devices.findDevice("Bombillo", "Cuarto")->actions.findStruct("Encender")->execute("Brillo", "Alto");