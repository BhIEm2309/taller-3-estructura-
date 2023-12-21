#ifndef NODO_H
#define NODO_H

#include <string>

using namespace std;

class Nodo {
public:
    int id;
    string nombre;
    string tipo;

    Nodo(int id, string nombre, string tipo);
    
    // Constructor por defecto necesario para std::map
    Nodo() = default;
};

#endif // NODO_H
