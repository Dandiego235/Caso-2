
#include "List.cpp"
#include "Parameter.cpp"
#include "Action.cpp"
#include "Device.cpp"

#ifndef BOMBILLO

#define BOMBILLO 1

using namespace std;

class Bombillo : public Device{ // Subclase que hereda las características de Device para los Bombillos.
    public:
        Bombillo(List<Tparameter> paramsBombillo, List<Taction> pActions, string pName){
            this->deviceType = "Bombillo";
            this->name = pName;
            this->params = paramsBombillo;
            this->actions = pActions;
        }
};

#endif