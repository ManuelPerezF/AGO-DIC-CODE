#include <iostream>
#include <fstream>
#include "Registro.hpp"
#include <vector>
using namespace std;


void leerArchivo(string filename, vector<Registro>& registros)
{

}


int main(int argc, char* argv[])
{
    string filename = "bitacora.txt";
    vector<Registro> registros;
    if (argc > 1)
    {
        filename = argv[1];
    }

    leerArchivo(filename, registros);
    cout << "Registros leidos: " << registros.size() << endl;
    cout << "Cual registro quiere ver" << endl;
    int n;
    cin >> n;
    registros[n].print();
    return 0;
}

void leerArchivo(string filename, vector<Registro>& registros)
{
    ifstream s;
    s.open(filename);
    string mes, hora, ip, msj;
    int dia;
    while (!s.eof())
    {
        s >> mes >> dia >> hora >> ip >> msj;
        Registro r(mes, dia, hora, ip, msj);
        registros.push_back(r);
    }
    s.close();
    cout << "archivo cerrado" << endl;
}

