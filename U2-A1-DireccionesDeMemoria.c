/*
- Alumno: Marco Antonio García Bautista
- Número de cuenta: 305027731
- Licenciatura: Informática
- Materia: Estructura de datos
- Descripción del programa: Programa que almacena los nombres de 5 animales e imprime la dirección de memoria
                            cuando se elija por el usuario alguno de ellos.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int numeroAnimales = 5;                    // número máximo de animales
    char animales[numeroAnimales][15];         // definimos el arreglo bidimensional animales
    char *apuntadoresAnimales[numeroAnimales]; // definimos el arreglo apuntadoresAnimales que apuntan a las direcciones de memoria de cada nombre de animal del arreglo animales
    int opcionSeleccionada;                    // variable que tendrá el valor de la opción seleccionada por el usuario

    // solicitamos que se capturen los nombres de los 5 animales
    printf("Captura los nombres de 5 animales.\n");
    int i = 0;
    for (i = 0; i < numeroAnimales; i++)
    {
        printf("Animal %d: ", i + 1);
        scanf("%s", animales[i]);             // leemos el dato capturado y lo asignamos al indice correspondiente del arreglo animales
        apuntadoresAnimales[i] = animales[i]; // asignamos el mismo valor al arreglo de apuntadoresAnimales
    }

    while (1)
    {
        // una vez capturados los 5 animales los mostramos en pantalla y solicitamos al usuario seleccionar uno
        printf("\nElije uno de animales (ingresa el número del 1 al %d):\n", numeroAnimales);
        for (i = 0; i < numeroAnimales; i++)
        {
            printf("%d.- %s\n", i + 1, animales[i]);
        }

        // leemos el dato capturado por el usuario
        scanf("%d", &opcionSeleccionada);

        // si se elige una opción mayor al número de animales el programa termina
        if (opcionSeleccionada < 1 || opcionSeleccionada > numeroAnimales)
        {
            printf("Elección inválida.\n");
            return 0;
        }

        // cuando el usuario elige un animal se imprime la opción y la dirección de memoria correspondiente utilizando las notaciones %s y %p en la función printf,
        // la dirección de memoria se obtiene accediendo a la posición correspondiente en el arreglo apuntadoresAnimales
        printf("\nOpción seleccionada: %s, dirección de memoria: %p\n", animales[opcionSeleccionada - 1], (void *)apuntadoresAnimales[opcionSeleccionada - 1]);
        // la función void* se usa para mostrar la dirección en formato hexadecimal
    }

    return 0;
}

