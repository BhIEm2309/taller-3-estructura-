#include "Grafo.h"
using namespace std;

void Grafo::agregarNodo(Nodo nodo) {
    nodos[nodo.id] = nodo;
}

void Grafo::agregarConexion(Conexion conexion) {
    conexiones.push_back(conexion);
}
