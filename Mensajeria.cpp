#include "Mensajeria.h"
#include <iostream>
#include <fstream>

using namespace std;

Grafo& Mensajeria::getGrafo() {
    return grafo;
}

int Mensajeria::calcularTiempo(int idCliente, int tamArchivo) {
    auto it = grafo.nodos.find(idCliente);
    if (it == grafo.nodos.end()) {
        cout << "Error: Cliente con ID " << idCliente << " no encontrado en el grafo." << endl;
        return -1;
    }
    
    int tiempoTotal = 0;
    int partes = (tamArchivo + 299) / 300; // Redondear hacia arriba

    for (int i = 0; i < partes; ++i) {
        int tiempoConexion = calcularTiempoConexion(idCliente);
        tiempoTotal += tiempoConexion;
    }

    return tiempoTotal;
}

int Mensajeria::calcularTiempoConexion(int idCliente) {
    auto it = grafo.nodos.find(idCliente);
    if (it == grafo.nodos.end()) {
        cout << "Error: Cliente con ID " << idCliente << " no encontrado en el grafo." << endl;
        return -1;
    }
    int tiempoConexion = 0;

    for (const Conexion& conexion : grafo.conexiones) {
        if (conexion.idCliente == idCliente) {
            tiempoConexion += conexion.distancia;
        }
    }

    return tiempoConexion;
}
