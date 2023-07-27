/*
- Alumno: Marco Antonio Garc�a Bautista
- N�mero de cuenta: 305027731
- Licenciatura: Inform�tica
- Materia: Estructura de datos
- Descripci�n del programa: Programa que almacena los nombres de 5 animales e imprime la direcci�n de memoria
                            cuando se elija por el usuario alguno de ellos.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int numeroAnimales = 5;                    // n�mero m�ximo de animales
    char animales[numeroAnimales][15];         // definimos el arreglo bidimensional animales
    char *apuntadoresAnimales[numeroAnimales]; // definimos el arreglo apuntadoresAnimales que apuntan a las direcciones de memoria de cada nombre de animal del arreglo animales
    int opcionSeleccionada;                    // variable que tendr� el valor de la opci�n seleccionada por el usuario

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
        printf("\nElije uno de animales (ingresa el n�mero del 1 al %d):\n", numeroAnimales);
        for (i = 0; i < numeroAnimales; i++)
        {
            printf("%d.- %s\n", i + 1, animales[i]);
        }

        // leemos el dato capturado por el usuario
        scanf("%d", &opcionSeleccionada);

        // si se elige una opci�n mayor al n�mero de animales el programa termina
        if (opcionSeleccionada < 1 || opcionSeleccionada > numeroAnimales)
        {
            printf("Elecci�n inv�lida.\n");
            return 0;
        }

        // cuando el usuario elige un animal se imprime la opci�n y la direcci�n de memoria correspondiente utilizando las notaciones %s y %p en la funci�n printf,
        // la direcci�n de memoria se obtiene accediendo a la posici�n correspondiente en el arreglo apuntadoresAnimales
        printf("\nOpci�n seleccionada: %s, direcci�n de memoria: %p\n", animales[opcionSeleccionada - 1], (void *)apuntadoresAnimales[opcionSeleccionada - 1]);
        // la funci�n void* se usa para mostrar la direcci�n en formato hexadecimal
    }

    return 0;
}

