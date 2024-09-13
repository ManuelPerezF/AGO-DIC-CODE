#pragma once
#include <string>
#include "Fecha.hpp"
#include <fstream>

class Registro {
  protected:
    Fecha fecha;
    std::string ip;
    std::string mensaje;
  public:
    Registro();
    Registro(std::string, int, std::string, std::string, std::string);
    Registro(Fecha, std::string, std::string);
    void print() const;
    bool operator<(const Registro&) const;
    friend std::ifstream& operator>>(std::ifstream&, Registro&);
    friend std::ostream& operator<<(std::ostream&, const Registro&);
    Fecha getFecha() const;
};