
#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"
#include "Device.cpp"

#ifndef SENSORPUERTAS

#define SENSORPUERTAS 1

using namespace std;

class SensorPuertas : public Device{ // Subclase que hereda las características de Device para los Sensores de puertas.
    public:
        SensorPuertas(List<Tparameter> paramsSensorPuertas, List<Taction> pActions, string pName){
            this->deviceType = "Sensor de Puertas";
            this->name = pName;
            this->params = paramsSensorPuertas;
            this->actions = pActions;
        }
};

#endif