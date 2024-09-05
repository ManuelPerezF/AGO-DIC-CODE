// Manuel Antonio Pérez Fonseca A01741957 
// Creado: 13/08/2024
// Act 1.1 - Funciones Iterativas, Recursivas y su análisis de Complejidad
// Ultima modificacion: 16/08/2024

#include <iostream>
using namespace std;

int sumaIterativa(int n) 
{
    int suma = 0;
    // un FOR que suma los numeros del 1 al n (numero ingresado)
    for (int i = 1; i <= n; i++) 
    {
        suma += i;
    }
    return suma;
}

int sumaRecursiva(int n) 
{
    if (n == 1) //Por si n es 1, la suma sera 1
    {
        return 1;
    }
    return n + sumaRecursiva(n - 1); //se llama la funcion recursiva sumando n y la suma de los números anteriores
    
}

int sumaDirecta(int n) 
{
    return (n * (n + 1)) / 2; //Formula directa para la suma de los numeros del 1 al n
}

int main()
{
    int n;
    // un DOWHILE que hace que ingreses un numero valido
    do 
    {
        cout << "Ingrese un numero entero positivo: ";
        cin >> n;
        if (n <= 0) {
            cout << "Numero invalido. " << endl;
        }
    } 
    while (n <= 0);

    cout << "La suma iterativa de los numeros del 1 al " << n << " es: " << sumaIterativa(n) << endl;
    cout << "La suma recursiva de los numeros del 1 al " << n << " es: " << sumaRecursiva(n) << endl;
    cout << "La suma directa de los numeros del 1 al " << n << " es: " << sumaDirecta(n) << endl;
    
    return 0;
}
