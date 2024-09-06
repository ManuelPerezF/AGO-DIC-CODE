#include "Registro.hpp"
#include <iostream>
using namespace std;

Registro::Registro()
: fecha("Jul", 1, "00:00:00")
{
    ip = "333.333.333.333";
    msj = "";
}

Registro::Registro(std::string mes, int dia, std::string hhmmss, std::string ip, std::string msj) : fecha(mes, dia, hhmmss) 
{
    this->ip = ip;
    this->msj = msj;
}

Registro::Registro(Fecha fecha, std::string ip, std::string msj) : fecha(fecha)
{
    this->ip = ip;
    this->msj = msj;
}

void Registro::print()
{
    fecha.print();
    cout << ip << " " << msj << endl;
}