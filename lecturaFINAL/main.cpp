// Manuel Perez A01741957
// Hermann Pauwells A01741456

#include <vector>
#include <fstream>
#include <iostream>  
#include <algorithm> //esta libreria es para usar la funcion sort
#include "Registro.hpp"
#include "Fecha.hpp"

using namespace std;

void leerArchivo(string, vector<Registro>&);
void escribirArchivoOrdenado(string, const vector<Registro>&);
bool filtrarYOrdenarRegistrosPorFecha(const vector<Registro>&, const Fecha&, const Fecha&);

int main(int argc, char* argv[]) 
{
    string nombreArchivo = "bitacora.txt";
    vector<Registro> registros;
    if (argc > 1) 
    {
        nombreArchivo = argv[1];
    }

    leerArchivo(nombreArchivo, registros);
    cout << "Total de lineas: " << registros.size() << endl;

    // Solicitar fechas de inicio y fin
    string mesInicio, mesFin;
    int diaInicio, diaFin;
    cout << "Ingrese la fecha de inicio (Mes Dia): ";
    cin >> mesInicio >> diaInicio;
    cout << "Ingrese la fecha de fin (Mes Dia): ";
    cin >> mesFin >> diaFin;
    cout << "Filtrando registros de " << mesInicio << " " << diaInicio << " a " << mesFin << " " << diaFin << endl;

    Fecha fechaInicio(mesInicio, diaInicio, "00:00:00");
    Fecha fechaFin(mesFin, diaFin, "23:59:59");

    // Filtrar, ordenar y guardar registros
    bool registrosEncontrados = filtrarYOrdenarRegistrosPorFecha(registros, fechaInicio, fechaFin);

    if (!registrosEncontrados) {
        cout << "No se encontraron registros en el rango de fechas especificado." << endl;
    } else {
        cout << "Fechas guardadas en datos_solicitados.txt" << endl;
    }

    // Ordenar y escribir en archivo
    sort(registros.begin(), registros.end());
    escribirArchivoOrdenado("bitacora_ordenada.txt", registros);
    
    return 0;
}

void leerArchivo(string nombreArchivo, vector<Registro>& registros) {
    ifstream s;
    s.open(nombreArchivo);
    Registro r;
    while (s >> r) { 
        registros.push_back(r);
    }
    s.close();
}

void escribirArchivoOrdenado(string nombreArchivo, const vector<Registro>& registros) {
    ofstream s;
    s.open(nombreArchivo);
    for (const auto& r : registros) {
        s << r << endl; 
    }
    s.close();
}

bool filtrarYOrdenarRegistrosPorFecha(const vector<Registro>& registros, const Fecha& inicio, const Fecha& fin) {
    vector<Registro> registrosFiltrados;
    for (const auto& registro : registros) 
    {
        if (registro.getFecha() >= inicio && registro.getFecha() <= fin) 
        {
            registrosFiltrados.push_back(registro);
        }

    }
    if (registrosFiltrados.empty()) 
    {
        return false;
    }

    // Ordenar los registros filtrados
    sort(registrosFiltrados.begin(), registrosFiltrados.end());

    //Guardar los registros
    ofstream s("datos_solicitados.txt");
    for (const auto& registro : registrosFiltrados) 
    {
        s << registro << endl; 
    }
    s.close();

    return true;
}