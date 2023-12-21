#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Mensajeria.h"  // Asegúrate de que Mensajeria.h incluya Grafo.h

using namespace std;

int main() {
    srand(time(NULL));

    Mensajeria mensajeria;
    Grafo& grafo = mensajeria.getGrafo();
//generar archivos
    ofstream archivo;
    ofstream archivo2;
    archivo2.open("conexiones.csv");
    archivo.open("servidores.csv");
    archivo << "id,nombre,tipo" << endl;
    archivo2 << "idCliente,idServidor,velocidad,distancia" << endl;

    vector<string> cliente;
    vector<string> servidor;
//generar datos , rellenar grafo
    for (int i = 0; i < 300; i++) {
        int num = i;
        string nombre = "Servidor" + to_string(i);
        int random = rand() % 5 + 1;
        string tipoServidor = (random == 5) ? "router" : "cliente";
        cout << "Tipo de servidor generado: " << tipoServidor << " (" << random << ")" << endl;

        string tipo;
        if (random == 5) {
            tipo = "router";
            servidor.push_back(to_string(i));
            for (string client : cliente) {
                int random2 = rand() % 10 + 1;
                int velocidadrand = (rand() % 3 + 1) * 300;
                // agregar conexiones grafo
                grafo.agregarConexion(Conexion(stoi(client), i, velocidadrand, random2));

            }
            cliente.clear();
        } else {
            tipo = "cliente";
            cliente.push_back(to_string(i));
        }
        archivo << num << "," << nombre << "," << tipo << endl;
        //agregar nodos grafo
        grafo.agregarNodo(Nodo(num, nombre, tipo));
    }
    archivo.close();
//generar conexiones adicionales y completar grafo
    for (int i = 0; i < servidor.size(); i++) {
        for (int j = i + 1; j < servidor.size(); j++) {
            if (i != j) {
                int moneda = rand() % 4 + 1;
                if (moneda == 1) {
                    int random = rand() % 1000 + 1;
                    int velocidad = (rand() % 3 + 1) * 1000;
                    archivo2 << servidor[i] << "," << servidor[j] << "," << velocidad << "," << random << endl;
                    grafo.agregarConexion(Conexion(stoi(servidor[i]), stoi(servidor[j]), velocidad, random));
                }
            }
        }
    }
    archivo2.close();

int opcion;
while (true) {
    cout << "----- Menu -----" << endl;
    cout << "1. Calcular tiempo de entrega" << endl;
    cout << "2. Calcular tiempo de conexion" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese la opcion deseada: ";
    cin >> opcion;

    if (opcion == 1 || opcion == 2) {
        // Imprimir todos los IDs de clientes disponibles solo cuando sea necesario
        cout << "IDs de clientes disponibles: ";
        for (const auto& nodo : grafo.nodos) {
            if (nodo.second.tipo == "cliente") {
                cout << nodo.second.id << " ";
            }
        }
        cout << endl;
    }

    if (opcion == 1) {
        int idCliente, tamArchivo;
        cout << "Ingrese el ID del cliente: ";
        cin >> idCliente;

        cout << "Ingrese el tamano del archivo (en MB): ";
        cin >> tamArchivo;

        int tiempoTotal = mensajeria.calcularTiempo(idCliente, tamArchivo);

        cout << "Tiempo total de entrega: " << tiempoTotal << " segundos." << endl;
    } else if (opcion == 2) {
        int idCliente;
        cout << "Ingrese el ID del cliente: ";
        cin >> idCliente;

        int tiempoConexion = mensajeria.calcularTiempoConexion(idCliente);

        cout << "Tiempo de conexion: " << tiempoConexion << " segundos." << endl;
    } else if (opcion == 3) {
        cout << "Saliendo del programa." << endl;
        break;
    } else {
        cout << "Opcion no valida. Intentelo de nuevo." << endl;
    }
}

return 0;
}
