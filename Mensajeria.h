#ifndef MENSAJERIA_H
#define MENSAJERIA_H

#include "Grafo.h"

class Mensajeria {
private:
    Grafo grafo;

public:
    Grafo& getGrafo();
    int calcularTiempo(int idCliente, int tamArchivo);
    int calcularTiempoConexion(int idCliente);
};

#endif // MENSAJERIA_H
