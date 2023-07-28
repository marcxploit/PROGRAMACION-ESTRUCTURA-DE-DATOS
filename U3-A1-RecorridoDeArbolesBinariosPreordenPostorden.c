/*
- Alumno: Marco Antonio García Bautista
- Número de cuenta: 305027731
- Licenciatura: Informática
- Materia: Programación (Estructura de datos)
- Profesora: María Elizabeth García Vargas
- Descripción del programa: Progrma para recorrer el subárbol izquierdo en preorden y recorrer el subárbol derecho en postorden.
*/

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol binario
struct Nodo {
    int dato;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
};

// Función para crear un nuevo nodo
struct Nodo* CrearNodo(int dato) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

// Función para recorrer el subárbol izquierdo en preorden y el subárbol derecho en postorden
void RecorrerSubarbolIzquierdoPreordenYDerechoPostorden(struct Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    // Paso 1: Visitamos el nodo actual en preorden e imprimimos el dato en pantalla
    printf("%d ", nodo->dato);

    // Paso 2: Recorremos el subárbol izquierdo en preorden
    RecorrerSubarbolIzquierdoPreordenYDerechoPostorden(nodo->izquierdo);

    // Paso 3: Recorremos el subárbol derecho en postorden
    RecorrerSubarbolIzquierdoPreordenYDerechoPostorden(nodo->derecho);


}

int main() {
   // Construcción de un árbol con 10 nodos
    //            1
    //           / \
    //          2   3
    //         / \ / \
    //        4  5 6  7
    //       / \
    //      8   9
    //           \
    //           10

    struct Nodo* raiz = CrearNodo(1);
    raiz->izquierdo = CrearNodo(2);
    raiz->derecho = CrearNodo(3);
    raiz->izquierdo->izquierdo = CrearNodo(4);
    raiz->izquierdo->derecho = CrearNodo(5);
    raiz->derecho->izquierdo = CrearNodo(6);
    raiz->derecho->derecho = CrearNodo(7);
    raiz->izquierdo->izquierdo->izquierdo = CrearNodo(8);
    raiz->izquierdo->izquierdo->derecho = CrearNodo(9);
    raiz->izquierdo->izquierdo->derecho->derecho = CrearNodo(10);

    // Llamadamos a la función para recorrer el subárbol izquierdo en preorden y el subárbol derecho en postorden
    printf("Recorrido del subárbol izquierdo en preorden y subárbol derecho en postorden: ");
    RecorrerSubarbolIzquierdoPreordenYDerechoPostorden(raiz);
    
    // Agregamos una pausa para que el programa no se cierre inmediatamente
    printf("\n\nPresiona Enter para salir...");
    getchar();
    
    return 0;
}


