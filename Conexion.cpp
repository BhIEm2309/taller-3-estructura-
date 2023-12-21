#include "Conexion.h"
using namespace std;

Conexion::Conexion(int idCliente, int idServidor, int velocidad, int distancia)
    : idCliente(idCliente), idServidor(idServidor), velocidad(velocidad), distancia(distancia) {}
