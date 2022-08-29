# Caso 2
**Curso: Estructuras de datos**
*Profesor Rodrigo Núñez*
*Estudiante: Daniel Granados Retana*
*Carné: 2022104692*
*Fecha: 29/08/2022*
*Instituto Tecnológico de Costa Rica*
*Escuela de Computación*

El Caso #2 consiste en modelar una aplicación de domótica por medio de clases y usando listas enlazadas.

Por lo tanto, la estructura de datos fundamental para este caso fue el de listas enlazadas. La implementación que se utilizó se basó en tener una serie de nodos en la lista, donde cada nodo apuntaba a una estructura o clase y al siguiente nodo. Para facilitar este trabajo y permitir una versatilidad en los tipos de datos, se usaron templates en las clases de listas y de nodos. Además de implementar métodos para añadir nodos, obtener el nodo siguiente o establecer el siguiente, se crearon métodos para obtener las estructuras a las que apuntaban los nodos a partir de un string, el cual representaba el nombre de la estructura. De esta forma podíamos buscar estructuras y luego, más específicamente, dispositivos, usando su tipo y su nombre.

Se creó una estructura para los parámetros, la cual básicamente consiste en solo el nombre del parámetro. 

La estructura para las acciones contiene un string para su nombre, y una lista de parámetros, lo que significa que los nodos de la lista apuntan a estructuras de parámetros. Además recibe la lista de parámetros del dispositivo y un vector de strings, los cuales representan los parámetros específicos que esa acción puede modificar. Luego, las estructuras de los parámetros específicos se agregan a la lista de parámetros que va a modificar. Finalmente, esta estructura tiene un método llamado "execute", el cual recibe el parámetro a cambiar y el valor por el cuál será cambiado. Lo que hace es obtener la estructura correspondiente al string y almacenarlo, por si en el futuro se quisiera cambiar el valor en el parámetro propiamente. No obstante, solo se imprime un mensaje de que el parámetro se modificó al valor deseado.

Para modelar los dispositivos, se definió una clase general llamada Device que contiene los atributos esenciales para todos los dispositivos. De esta, se definen subclases que representen cada tipo específico de dispositivo. Estas subclases heredan los atributos generales y pueden hacerlos específicos a la clase y al objeto. El formato para declarar estas subclases para los dispositivos es el siguiente.

```
Estructura para declarar subclases de distintos dispositivos.
class TipoDispositivo : public Device{ // Subclase que hereda las características de Device para objetos del tipo.
    public:
        Bombillo(List<Tparameter> paramsTipo, List<Taction> pActions, string pName){
            this->deviceType = "Tipo";
            this->name = pName;
            this->params = paramsTipo;
            this->actions = pActions;
        }
};
```

También se definió una estructura para los cuartos, la cual contiene un string para el nombre de la habitación y una lista de objetos de tipo Device. Al ser los dispositivos de cada tipo subclases de Device, se pueden agregar a esta lista, por lo que podemos tener dispositivos de diferente tipo en la misma habitación.

Para las tareas, se creó una estructura para las tareas, la cual contiene un string para el nombre, una lista de cuartos (una casa), y un vector de vectores de strings. Este vector de strings es lo que le permite al usuario configurar las tareas. Cada vector de strings dentro del vector grande establece la configuración con la siguiente estructura:

```
    // Estructura de cada dispositivo en el vector de acciones en la tarea.
    // {"Nombre del cuarto", "Nombre del tipo", "Nombre del dispositivo", "Nombre de accion", "Nombre de param", "Valor de param"}
```

Luego, cuando se llama la tarea, por medio del método llamarTarea, se recorre este vector y se ejecuta la acción de cada dispositivo, cambiando el parámetro ingresado por el valor especificado. Para facilitar esto, se almacena cada tarea en una lista, donde luego se puede ejecutar la tarea solo llamándola por su string:
```
    Tareas->findStruct("Buenos días")->llamarTarea(); // Con el string del nombre puedo llamar a la tarea.
```

Para crear un objeto de un tipo, 
1. primero se debe crear la subclase para el tipo del objeto con la estructura mencionada anteriormente.
```
class Bombillo : public Device{ // Subclase que hereda las características de Device para los Bombillos.
    public:
        Bombillo(List<Tparameter> paramsBombillo, List<Taction> pActions, string pName){
            this->deviceType = "Bombillo";
            this->name = pName;
            this->params = paramsBombillo;
            this->actions = pActions;
        }
};
```
2. Se crea una lista de parámetros para el dispositivo, creando cada parámetro y agregándolo a la lista.
3. Se crea una lista de acciones para el dispositivo, creando cada acción con sus parámetros a modificar y agregándola a la lista.
```
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
```
4. Ya se pueden crear objetos de la clase. Se puede crear un cuarto y agregarlos al cuarto.
```
    Bombillo *bombillo1 = new Bombillo(parametersBo, accionesBo, "Cuarto Cama"); // Se crean unos bombillos y otros dispositivos
    Bombillo *bombillo2 = new Bombillo(parametersBo, accionesBo, "Cuarto Techo");

    Room *Cuarto = new Room("Cuarto"); // Se crea un cuarto y se le asignan los dispositivos
    Cuarto->Devices.add(bombillo1);
    Cuarto->Devices.add(bombillo2);
```

Después de crear otros dispositivos y cuartos, podemos crear una lista de Rooms, para crear la casa y crear la lista de tareas.
```
    List<Room> *Casa = new List<Room>(); // Se agrupan los cuartos en una casa.
    Casa->add(Cuarto);
    Casa->add(Cocina);
    Casa->add(Bano);
    Casa->add(Oficina);

    List<Ttarea> *Tareas = new List<Ttarea>(); // se crea una lista para las tareas.
```
Por último, ya podemos crear las tareas usando el formato de la configuración del vector y agregarla a la lista de tareas para poder ejecutarla.

```
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
```

Al fin y al cabo, terminamos teniendo una serie de listas anidadas. Por ejemplo, con la casa, tenemos una lista de cuartos que contienen dispositivos que contienen acciones que contienen parámetros. Se usa mucho los métodos de findStruct y findDevice para navegar estas sublistas y encontrar la estructura que queremos.
