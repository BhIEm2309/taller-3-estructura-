Algoritmo de Bellman-Ford para Grafos Ponderados

Resumen de la Implementación:
Este código implementa el algoritmo de Bellman-Ford para encontrar los caminos más cortos desde un nodo fuente a todos los demás nodos en un grafo dirigido y ponderado. El algoritmo maneja arcos con pesos negativos, detecta ciclos de peso negativo y proporciona la distancia más corta entre el nodo fuente y todos los demás nodos.

Componentes:

- Grafo: Representa la estructura del grafo dirigido y ponderado. Contiene funciones para agregar nodos, conexiones y ejecutar el algoritmo de Bellman-Ford.

- Nodo: Define la estructura de un nodo en el grafo, con un identificador único y una lista de conexiones conectadas.

- Arco (Conexiones): Representa una conexión ponderada entre dos nodos. Incluye el nodo de origen, el nodo de destino y el peso de la conexión.

- main.cpp: Implementa la interacción con el usuario, la construcción del grafo y la invocación del algoritmo de Bellman-Ford.

Decisiones de Diseño:

- Estructura de Datos: Se utiliza una representación de lista de adyacencia para almacenar los nodos y conexiones del grafo, permitiendo una fácil manipulación y búsqueda de conexiones.

- Algoritmo de Bellman-Ford: La implementación considera la detección de ciclos de peso negativo y utiliza el concepto de distancias acumuladas en cada iteración para actualizar las distancias más cortas.

- Interacción de Usuario: El programa solicita al usuario la entrada necesaria, como el número de nodos, el número de conexiones y los detalles de cada conexión.

Ejecutar el Programa:

- Compile el programa usando un compilador de C++ (por ejemplo, g++): `g++ -o main main.cpp Conexion.cpp Grafo.cpp Mensajeria.cpp Nodo.cpp`

- Ejecute el ejecutable: `./main`

- Siga las instrucciones en pantalla para construir el grafo y visualizar los resultados del algoritmo de Bellman-Ford.

Nota:
Este código se basa en el algoritmo de Bellman-Ford y no es aplicable si el grafo contiene ciclos de peso negativo inalcanzables desde el nodo fuente. Además, en el caso de grafos grandes o con muchos arcos, se recomienda evaluar la eficiencia del algoritmo y considerar algoritmos más especializados para grafos densos.
