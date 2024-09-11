#include "Fecha.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

int mestoi(string mes) {
    string meses[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; i++) {
        if (mes == meses[i])
            return i + 1;
    }
    return -1;
}

Fecha::Fecha(string mes, int dia, string hhmmss) 
: mes(mes), dia(dia), hhmmss(hhmmss) { 
    m = mestoi(mes);
    stringstream iss(hhmmss);
    string s;
    try {
        getline(iss, s, ':'); // hh
        hh = stoi(s);
        getline(iss, s, ':'); // mm
        mm = stoi(s);
        getline(iss, s, ':'); // ss
        ss = stoi(s);
    } catch (const invalid_argument& e) {
        cerr << "Error: formato de hora inválido en " << hhmmss << endl;
        hh = mm = ss = 0;
    }
}

void Fecha::print() const {
    cout << mes << " " << dia << " " << hhmmss;
}

bool Fecha::operator<(const Fecha& v) const {
    if (m < v.m)
        return true;
    else if (m > v.m)
        return false;

    if (dia < v.dia)
        return true;
    else if (dia > v.dia)
        return false;

    if (hh < v.hh)
        return true;
    else if (hh > v.hh)
        return false;

    if (mm < v.mm)
        return true;
    else if (mm > v.mm)
        return false;

    if (ss < v.ss)
        return true;
    else if (ss > v.ss)
        return false;

    return false;
}

std::ostream& operator<<(std::ostream& os, const Fecha& f) {
    os << f.mes << " " << f.dia << " " << f.hhmmss;
    return os;
}
