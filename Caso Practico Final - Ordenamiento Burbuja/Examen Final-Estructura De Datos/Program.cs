using System;

namespace Caso_Practico_Final
{
    /*
     * CASO PRÁCTICO FINAL
     - Alumno: Marco Antonio García Bautista
     - Número de cuenta: 305027731
     - Licenciatura: Informática
     - Materia: Programación (Estructura de datos)
     - Profesora: María Elizabeth García Vargas
     */

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("CASO PRÁCTICO FINAL: ORDENAMIENTO DE NÚMEROS");
            IniciaPrograma();
        }

        static void IniciaPrograma()
        {
            //PASO 1: El usuario pueda ingresar la cantidad de elementos a ordenar
            int cantidadAOrdenar; //definimos la variable de la cantidad de números que el usuario puede capturar
            do
            {

                Console.WriteLine($"\nCaptura la cantidad de números que deseas ordenar:");
                string datoCapturado = Console.ReadLine(); //leemos el dato capturado por el usuario              
                if (!int.TryParse(datoCapturado, out cantidadAOrdenar)) //validamos si el dato capturado es un número
                {
                    //si el usuario captura algo que no sea un número válido
                    Console.WriteLine($"'{datoCapturado} no es un número válido");
                }

                //PASO 2: Establece e indícale al usuario que puede ingresar un máximo de 8 números
                if (cantidadAOrdenar < 1 || cantidadAOrdenar > 8)
                {
                    Console.WriteLine("La cantidad debe ser entre 1 y 8");

                }
            } while (cantidadAOrdenar < 1 || cantidadAOrdenar > 8); //realizamos esta tarea mientras la cantidad no esté entre 1 y 8


            string[] arregloDatosCapturados; //definimos un arreglo del tipo string donde almacenaremos los caracteres capturados por el usuario
            int longitudArreglo = 0; //longitud del arreglo que el usuario va a capturar 
            do
            {
                //PASO 3: El usuario puede ingresar los numeros de diferentes valores de manera desordenada
                Console.WriteLine($"\nCaptura {cantidadAOrdenar} números (separados por un espacio):");
                arregloDatosCapturados = Console.ReadLine().Trim().Split(' '); //convertimos los datos capturados en un arreglo tomando como delimitador el espacio en blanco
                longitudArreglo = arregloDatosCapturados.Length; //obtenemos el tamaño de elementos que tiene el arreglo arregloDatosCapturados

                if (longitudArreglo != cantidadAOrdenar)
                {
                    Console.WriteLine($"Debes capturar un máximo de {cantidadAOrdenar} números"); //si el usuario captura una cantidad diferente de caracteres al establecido mostramos el mensaje
                }
            }
            while (arregloDatosCapturados.Length != cantidadAOrdenar); //si el usuario captura una cantidad diferente de caracteres al establecido los seguimos solicitando


            int[] arregloNumeros = new int[longitudArreglo]; //definimos un nuevo arreglo del tipo int con la longitud que el usuario ha establecido

            //comenzamos a validar que todos los caracteres sean números
            for (int i = 0; i < longitudArreglo; i++)
            {
                int numero;
                bool esNumero = int.TryParse(arregloDatosCapturados[i], out numero); //validamos si el caracter es número o no
                if (!esNumero)
                {
                    Console.WriteLine($"'{arregloDatosCapturados[i]}' no es un número válido"); //si al menos un caracter no es número iniciamos nuevamente desde el inicio
                    IniciaPrograma();
                    return;
                }
                else
                {
                    //si todos los caracteres son números los asignamos ahora al arreglo arregloNumeros como enteros
                    arregloNumeros[i] = numero;
                }
            }

            //PASO 4: Imprime la lista desordenada
            //mostramos la lista tal como el usuario la capturó
            Console.WriteLine("La lista desordenada que capturaste es: " + string.Join(",", arregloNumeros));

            //PASO 5: Utiliza el método de burbuja y ordena los números de tu usuario
            OrdenarPorMetodoBurbuja(arregloNumeros); // ejecutamos la función OrdenarPorMetodoBurbuja(int[])

            //PASO 6: Imprime la lista ordenada
            Console.WriteLine("La lista ordenada que capturaste es: " + string.Join(",", arregloNumeros));

            //PASO 7: Imprime tu nombre al solicitarle al usuario imprimir cualquier tecla
            Console.WriteLine("Ahora captura cualquier tecla por favor");

            Console.ReadKey(); //esperamos a que el usuario capture una tecla para mostrar al final un mensaje con mi nombre
            Console.WriteLine("¡Gracias! Mi nombre es Marco Antonio García Bautista");
            Console.Read();
        }


        // Función o método para ordenar los números utilizando el ordenamiento de burbuja
        // esta función toma un arreglo del tipo int[] y ordena sus elementos, al finalizar devuelve el mismo arreglo pero con sus elementos ordenados 
        static void OrdenarPorMetodoBurbuja(int[] arregloNumeros)
        {

            int longitudArreglo = arregloNumeros.Length;

            /*
             Realizamos un recorrido del arreglo
             En cada recorrido, comparamos el elemento actual con el siguiente elemento
             Si el elemento actual es mayor que el siguiente, los intercambiamos, por lo tanto el elemento más grande se mueva hacia el final del arreglo y el más pequeño queda al inicio
            */
            for (int i = 0; i < longitudArreglo - 1; i++)
            {

                for (int j = 0; j < longitudArreglo - i - 1; j++)
                {
                    if (arregloNumeros[j] > arregloNumeros[j + 1])
                    {
                        // Intercambio de los elementos usando una variable temporal
                        int temporal = arregloNumeros[j];
                        arregloNumeros[j] = arregloNumeros[j + 1];
                        arregloNumeros[j + 1] = temporal;
                    }
                }
            }
        }

       


    }
}
