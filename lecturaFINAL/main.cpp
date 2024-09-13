#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Registro.hpp"
#include "Fecha.hpp"

using namespace std;

void leerArchivo(string, vector<Registro>&);
void escribirArchivoOrdenado(string, const vector<Registro>&);
void filtrarYOrdenarRegistrosPorFecha(const vector<Registro>&, const Fecha&, const Fecha&);

int main(int argc, char* argv[]) {
    string nombreArchivo = "bitacora.txt";
    vector<Registro> registros;
    if (argc > 1) {
        nombreArchivo = argv[1];
    }

    leerArchivo(nombreArchivo, registros);
    cout << "Total de lineas: " << registros.size() << endl;

    // Solicitar fechas de inicio y fin
    string mesInicio, mesFin;
    int diaInicio, diaFin;
    cout << "Ingrese la fecha de inicio (Mes Día): ";
    cin >> mesInicio >> diaInicio;
    cout << "Ingrese la fecha de fin (Mes Día): ";
    cin >> mesFin >> diaFin;
    cout << "Filtrando registros de " << mesInicio << " " << diaInicio << " a " << mesFin << " " << diaFin << endl;
    cout << "Fechas guardados en datos_solicitados.txt" << endl;

    Fecha fechaInicio(mesInicio, diaInicio, "00:00:00");
    Fecha fechaFin(mesFin, diaFin, "23:59:59");

    // Filtrar, ordenar y guardar registros
    filtrarYOrdenarRegistrosPorFecha(registros, fechaInicio, fechaFin);

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

void filtrarYOrdenarRegistrosPorFecha(const vector<Registro>& registros, const Fecha& inicio, const Fecha& fin) {
    vector<Registro> registrosFiltrados;
    for (const auto& registro : registros) {
        if (registro.getFecha() >= inicio && registro.getFecha() <= fin) {
            registrosFiltrados.push_back(registro);
        }
    }

    // Ordenar los registros filtrados
    sort(registrosFiltrados.begin(), registrosFiltrados.end());

    // Escribir los registros filtrados y ordenados en el archivo
    ofstream s("datos_solicitados.txt");
    for (const auto& registro : registrosFiltrados) {
        s << registro << endl; // Usar el operador << sobrecargado para Registro
    }
    s.close();
}