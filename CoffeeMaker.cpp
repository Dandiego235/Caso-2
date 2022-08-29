
#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"
#include "Device.cpp"

#ifndef COFFEMAKER

#define COFFEEMAKER 1

using namespace std;

class CoffeeMaker : public Device{ // Subclase que hereda las características de Device para los Coffee Makers.
    public:
        CoffeeMaker(List<Tparameter> paramsCoffeeMaker, List<Taction> pActions, string pName){
            this->deviceType = "Coffee Maker";
            this->name = pName;
            this->params = paramsCoffeeMaker;
            this->actions = pActions;
        }
};

#endif