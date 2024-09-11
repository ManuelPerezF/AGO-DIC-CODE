//Equipo 6
//Autores: Manuel Perez, Herman Pauwells

#include <iostream>
#include <fstream>
#include "Registro.h"
#include <vector>
#include <algorithm>

using namespace std;

void leerArchivo(string, vector<Registro>&);
void escribirArchivo(string, const vector<Registro>&);

int main(int argc, char* argv[]) {
    string nombreArchivo = "bitacora.txt";
    vector<Registro> registros;
    if (argc > 1) {
        nombreArchivo = argv[1];
    }

    leerArchivo(nombreArchivo, registros);
    cout << "Total de lineas: " << registros.size() << endl;


    sort(registros.begin(), registros.end());

    // Escribir los registros ordenados en un nuevo archivo
    escribirArchivo("bitacora_ordenada.txt", registros);

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
    return 0;
}

void leerArchivo(string nombreArchivo, vector<Registro>& registros) {
    ifstream s(nombreArchivo);
    if (!s.is_open()) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    Registro r;
    while (s >> r) {
        registros.push_back(r);
    }
    s.close();
}

void escribirArchivo(string nombreArchivo, const vector<Registro>& registros) {
    ofstream s(nombreArchivo);
    if (!s.is_open()) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    for (const auto& registro : registros) {
        s << registro << endl;
    }
    s.close();
}