#ifndef CONEXION_H
#define CONEXION_H

class Conexion {
public:
    int idCliente;
    int idServidor;
    int velocidad;
    int distancia;

    Conexion(int idCliente, int idServidor, int velocidad, int distancia);
};

#endif // CONEXION_H
