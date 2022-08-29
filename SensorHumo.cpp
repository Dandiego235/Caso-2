
#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"
#include "Device.cpp"

#ifndef SENSORHUMO

#define SENSORHUMO 1

using namespace std;

class SensorHumo : public Device{ // Subclase que hereda las características de Device para los Sensores de humo.
    public:
        SensorHumo(List<Tparameter> paramsSensorHumo, List<Taction> pActions, string pName){
            this->deviceType = "Sensor de Humo";
            this->name = pName;
            this->params = paramsSensorHumo;
            this->actions = pActions;
        }
};

#endif