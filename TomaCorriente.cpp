#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"
#include "Device.cpp"

#ifndef TOMACORRIENTE

#define TOMACORRIENTE

using namespace std;

class TomaCorriente : public Device{ // Subclase que hereda las características de Device para los Toma Corrientes.
    public:
        TomaCorriente(List<Tparameter> paramsTomaCorriente, List<Taction> pActions, string pName){
            this->deviceType = "Toma Corriente";
            this->name = pName;
            this->params = paramsTomaCorriente;
            this->actions = pActions;
        }
};

#endif