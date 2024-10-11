#include <iostream>
#include "LinkedList.h"

using namespace std;

void printMenu() {
    cout << "1. Agregar al inicio" << endl;
    cout << "2. Agregar al final" << endl;
    cout << "3. Eliminar" << endl;
    cout << "4. Actualizar" << endl;
    cout << "5. Imprimir lista" << endl;
    cout << "6. Obtener elemento" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    lista l, m;

    for (int i = 0; i < 10; i++) 
    {
        int valor = rand() % 100;
        l.addFirst(valor);

    }
    l.print();
    
    int opcion, valor, posicion;

    while (true) {
        printMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor a agregar al inicio: ";
                cin >> valor;
                l.addFirst(valor);
                break;
            case 2:
                cout << "Ingrese el valor a agregar al final: ";
                cin >> valor;
                l.addLast(valor);
                break;
            case 3:
                cout << "Ingrese la posición del elemento a eliminar: ";
                cin >> posicion;
                l.remove(posicion);
                break;
            case 4:
                cout << "Ingrese la posición del elemento a actualizar: ";
                cin >> posicion;
                cout << "Ingrese el nuevo valor: ";
                cin >> valor;
                l.update(posicion, valor);
                break;
            case 5:
                l.print();
                break;
            case 6:
                cout << "Ingrese la posición del elemento a obtener: ";
                cin >> posicion;
                cout << "Elemento en la posición " << posicion << ": " << l.get(posicion) << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }

    return 0;
}