#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"
#include "Device.cpp"

#ifndef ALARMA

#define ALARMA 1

using namespace std;

class Alarma : public Device{ // Subclase que hereda las características de Device para las Alarmas.
    public:
        Alarma(List<Tparameter> paramsAlarma, List<Taction> pActions, string pName){
            this->deviceType = "Alarma";
            this->name = pName;
            this->params = paramsAlarma;
            this->actions = pActions;
        }
};

#endif