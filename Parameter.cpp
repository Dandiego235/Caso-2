
#ifndef PARAMETER

#define PARAMETER 1

using namespace std;

typedef struct Tparameter { // Estructura para representar los parámetros de un dispositivo.
    string name;
    Tparameter(string pName){
        this->name = pName;
    }
}*PtrParam;

#endif