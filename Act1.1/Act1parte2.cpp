// Manuel Antonio Pérez Fonseca A01741957 
// Creado: 13/08/2024
// Act 1.1 - Funciones Iterativas, Recursivas y su análisis de Complejidad
// Ultima modificacion: 16/08/2024

#include <iostream>
using namespace std;

int CollatzRecursiva(int n) 
{
    if (n == 1) // Si es 1 no se hace nada
    {
        return 0;
    }
    else if (n % 2 == 0)  // Si es par se divide entre 2
    {
        return 1 + CollatzRecursiva(n / 2);
    }
    return 1 + CollatzRecursiva((n * 3) + 1); // Si es impar se multiplica por 3 y se suma 1
}

int CollatzIterativa(int n) 
{
    int pasos = 0;
    while (n != 1) //Mientras n no sea 1 se hace lo siguiente
    {
        if (n % 2 == 0) // Si es par se divide entre 2
        {
            n = n / 2;
        }
        else 
        {
            n = (n * 3) + 1; // Si es impar se multiplica por 3 y se suma 1
        }
        pasos++; // Se aumenta el contador de pasos
    }
    return pasos; // Se regresa el numero de pasos
}

int main()
{
    for (int i = 1; i <= 100; ++i)  // Se hace un FOR para los primeros 100 numeros
    {
        cout << "Numero: " << i << " - Pasos (Recursiva): " << CollatzRecursiva(i) << " - Pasos (Iterativa): " << CollatzIterativa(i) << endl;
    }
    return 0;
}