#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

// Estructura para almacenar los registros
struct Registro {
    string mes;
    int dia;
    string hora;
    string resto;
    string original;

    time_t to_time() const {
        struct tm tm = {};
        stringstream ss;
        ss << mes << " " << dia << " " << hora;
        strptime(ss.str().c_str(), "%b %d %H:%M:%S", &tm);
        return mktime(&tm);
    }
};

// Función para leer el archivo y almacenar los datos en un vector
vector<Registro> leerArchivo(const string &nombreArchivo) {
    vector<Registro> registros;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return registros;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string mes, hora, resto;
        int dia;
        iss >> mes >> dia >> hora;
        getline(iss, resto);
        registros.push_back({mes, dia, hora, resto, linea});
    }

    archivo.close();
    return registros;
}

// Función para ordenar los registros por fecha
void ordenarRegistros(vector<Registro> &registros) {
    sort(registros.begin(), registros.end(), [](const Registro &a, const Registro &b) {
        return a.to_time() < b.to_time();
    });
}

// Función para buscar los registros entre dos fechas
vector<Registro> buscarRegistros(const vector<Registro> &registros, time_t inicio, time_t fin) {
    vector<Registro> resultado;
    for (const auto &registro : registros) {
        time_t fechaRegistro = registro.to_time();
        if (fechaRegistro >= inicio && fechaRegistro <= fin) {
            resultado.push_back(registro);
        }
    }
    return resultado;
}

// Función para convertir una fecha de string a time_t
time_t convertirFecha(const string &fecha) {
    struct tm tm = {};
    stringstream ss(fecha);
    strptime(ss.str().c_str(), "%Y-%m-%d %H:%M:%S", &tm);
    return mktime(&tm);
}

// Función para guardar los registros ordenados en un archivo
void guardarRegistrosOrdenados(const vector<Registro> &registros, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (const auto &registro : registros) {
        archivo << registro.original << endl;
    }

    archivo.close();
}

int main() {
    string nombreArchivo = "bitacora.txt";
    vector<Registro> registros = leerArchivo(nombreArchivo);

    // Ordenar los registros por fecha
    ordenarRegistros(registros);

    // Pedir las fechas de inicio y fin al usuario
    string fechaInicio, fechaFin;
    cout << "Ingrese la fecha de inicio (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fechaInicio);
    cout << "Ingrese la fecha de fin (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fechaFin);

    // Convertir las fechas a time_t
    time_t inicio = convertirFecha(fechaInicio);
    time_t fin = convertirFecha(fechaFin);

    // Buscar y mostrar los registros entre las fechas dadas
    vector<Registro> encontrados = buscarRegistros(registros, inicio, fin);

    cout << "Registros encontrados entre " << fechaInicio << " y " << fechaFin << ":" << endl;
    for (const auto &registro : encontrados) {
        cout << registro.original << endl;
    }

    // Guardar los registros ordenados en un archivo
    guardarRegistrosOrdenados(registros, "bitacora_ordenada.txt");

    return 0;
}
