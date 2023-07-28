/*
- Alumno: Marco Antonio Garc�a Bautista
- N�mero de cuenta: 305027731
- Licenciatura: Inform�tica
- Materia: Programaci�n (Estructura de datos)
- Profesora: Mar�a Elizabeth Garc�a Vargas
- Descripci�n del programa: Programa de un grafo que almacena los 6 primeros meses del a�o y los d�as que lo integran,
                            imprime el nombre de cada mes y una lista de sus d�as.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIAS 30 // agregamos 30 d�as a cada mes
#define NUM_MESES 6 // n�mero de meses deseados

// Estructura para representar un nodo de mes en el grafo
struct NodoMes
{
    char nombre[20];
    int dias[MAX_DIAS];
    int numDias;
    struct NodoMes *siguiente;
};

// Estructura para representar el grafo
struct Grafo
{
    struct NodoMes *listaMeses;
};

// Funci�n para crear un nuevo nodo de mes
struct NodoMes *CrearNodoMes(char nombreMes[])
{
    struct NodoMes *nuevoNodo = (struct NodoMes *)malloc(sizeof(struct NodoMes));
    strcpy(nuevoNodo->nombre, nombreMes);
    nuevoNodo->numDias = 0;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Funci�n para agregar un d�a al mes
void AgregarDiasAlMes(struct NodoMes *mes, int dia)
{
    if (mes->numDias < MAX_DIAS)
    {
        mes->dias[mes->numDias] = dia;
        mes->numDias++;
    }
}

// Funci�n para agregar una conexi�n entre dos meses en el grafo
void CreaConexion(struct Grafo *grafo, char nombreMesOrigen[], char nombreMesDestino[])
{
    struct NodoMes *nodoOrigen = grafo->listaMeses;
    struct NodoMes *nodoDestino = grafo->listaMeses;

    // Buscamos los nodos de los meses de origen y destino
    while (nodoOrigen != NULL && strcmp(nodoOrigen->nombre, nombreMesOrigen) != 0)
    {
        nodoOrigen = nodoOrigen->siguiente;
    }

    while (nodoDestino != NULL && strcmp(nodoDestino->nombre, nombreMesDestino) != 0)
    {
        nodoDestino = nodoDestino->siguiente;
    }

    // Si se encontraron ambos nodos, agregar conexi�n
    int i = 0;
    if (nodoOrigen != NULL && nodoDestino != NULL)
    {
        for (i = 0; i < nodoDestino->numDias; i++)
        {
            AgregarDiasAlMes(nodoOrigen, nodoDestino->dias[i]);
        }
        for (i = 0; i < nodoOrigen->numDias; i++)
        {
            AgregarDiasAlMes(nodoDestino, nodoOrigen->dias[i]);
        }
    }
}

// Funci�n para imprimir en pantalla el grafo con los meses y sus d�as
void MuestraGrafo(struct Grafo *grafo)
{
    struct NodoMes *nodoMes = grafo->listaMeses;
    while (nodoMes != NULL && nodoMes != "")
    {
        if (nodoMes->nombre[0] != '\0')
        {
            printf("%s: ", nodoMes->nombre);
            int i = 0;
            for (i = 0; i < nodoMes->numDias; i++)
            {
                printf("%d ", nodoMes->dias[i]);
            }
        }
        printf("\n");
        nodoMes = nodoMes->siguiente;
    }
}

int main()
{
    // Creamos el grafo y los nodos de los meses
    struct Grafo grafo;
    grafo.listaMeses = CrearNodoMes("Enero");

    // Agregar d�as a cada mes utilizando un bucle for
    char nombresMeses[NUM_MESES][20] = {"Febrero", "Marzo", "Abril", "Mayo", "Junio"};
    int i = 0;
    for (i = 0; i < NUM_MESES; i++)
    {
        struct NodoMes *nuevoMes = CrearNodoMes(nombresMeses[i]);
        int dia = 1;
        for (dia = 1; dia <= MAX_DIAS; dia++)
        {
            AgregarDiasAlMes(nuevoMes, dia);
        }
        nuevoMes->siguiente = grafo.listaMeses;
        grafo.listaMeses = nuevoMes;
    }

    // Establecemos las conexiones en el grafo
    CreaConexion(&grafo, "Enero", "Febrero");
    CreaConexion(&grafo, "Febrero", "Marzo");
    CreaConexion(&grafo, "Marzo", "Abril");
    CreaConexion(&grafo, "Abril", "Mayo");
    CreaConexion(&grafo, "Mayo", "Junio");

    // Mostramos el grafo en pantalla
    MuestraGrafo(&grafo);

    // Agregamos una pausa para que el programa no se cierre inmediatamente
    printf("\n\nPresiona Enter para salir...");
    getchar();
    return 0;
}

