#ifndef GRAFO_H
#define GRAFO_H

#include <map>
#include <vector>
#include "Nodo.h"
#include "Conexion.h"

class Grafo {
public:
    map<int, Nodo> nodos;
    vector<Conexion> conexiones;

    void agregarNodo(Nodo nodo);
    void agregarConexion(Conexion conexion);
};

#endif // GRAFO_H
