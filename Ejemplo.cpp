enum {
	bombillo = 0,
	sensorHumo = 0,
	sensorPuertas = 2,
	camara = 3,
};

struct AccionesPorTipo{
    TipoDisp type;
    list<string> acciones;
}

AccionesPorTipo config_acciones[4];

list<string> accionesToLoad = new list<string>;
accionesToLoad.add("encender", "apagar", "cambiarColor");

config_acciones[(int)TipoDisp.bombillo].type = TipoDisp.bombillo;

)