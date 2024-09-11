#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Registro.h"

using namespace std;

void leerArchivo(string, vector<Registro>&);
void escribirArchivoOrdenado(string, const vector<Registro>&);

int main(int argc, char* argv[]) {
    string nombreArchivo = "bitacora.txt";
    vector<Registro> registros;
    if (argc > 1) {
        nombreArchivo = argv[1];
    }

    leerArchivo(nombreArchivo, registros);
    cout << "Total de lineas: " << registros.size() << endl;

    // Comparar antes de ordenar
    cout << "Cual registro quieres ver? : ";
    int n;
    cin >> n;
    registros[n].print();
    cout << endl;
    cout << "Contra cual quieres comparar? : ";
    int m;
    cin >> m;
    registros[m].print();
    cout << endl;
    cout << "El registro " << (registros[n] < registros[m] ? n : m) << " es menor" << endl;

    // Ordenar y escribir en archivo
    sort(registros.begin(), registros.end());
    escribirArchivoOrdenado("bitacora_ordenada.txt", registros);

    return 0;
}

void leerArchivo(string nombreArchivo, vector<Registro>& registros) {
    ifstream s;
    s.open(nombreArchivo);
    Registro r;
    while (s >> r) { // Usar el operador >> sobrecargado para Registro
        registros.push_back(r);
    }
    s.close();
}

void escribirArchivoOrdenado(string nombreArchivo, const vector<Registro>& registros) {
    ofstream s;
    s.open(nombreArchivo);
    for (const auto& r : registros) {
        s << r << endl; // Usar el operador << sobrecargado para Registro
    }
    s.close();
}