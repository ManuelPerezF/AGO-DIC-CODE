#include "Fecha.hpp"
using namespace std;
#include<string>
#include <iostream>
#include <sstream>
int resto(string mes)
{
    string meses[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dic"};
    for (int i = 0; i < 12; i++)
    {
        if (mes == meses[i])
        {
            return i+1;
        }
    }
    return -1;
}

Fecha::Fecha(std::string mes, int dia, std::string hhmmss)
{
    this->mes = mes;
    this->dia = dia;
    this->hhmmss = hhmmss;
    m = resto(mes);
    istringstream iss (hhmmss);
    string s;
    getline(iss, s, ':');
    hh = stoi(s);
    getline(iss, s, ':');
    mm = stoi(s);
    getline(iss, s, ':');
    ss = stoi(s);

}

void Fecha::print()
{
    cout << mes << " " << dia << " " << hhmmss << endl;
}
