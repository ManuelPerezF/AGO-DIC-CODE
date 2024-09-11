#pragma once
#include <string>
#include <iostream>

class Fecha {
  private:
    std::string mes; 
    std::string hhmmss; 
    int m;
    int dia;
    int hh;
    int mm;
    int ss;
  public:
    Fecha(std::string, int, std::string);
    void print() const;
    bool operator<(const Fecha&) const;
    bool operator>=(const Fecha&) const;
    bool operator<=(const Fecha&) const;
    friend std::ostream& operator<<(std::ostream&, const Fecha&);
};