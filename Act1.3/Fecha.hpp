#pragma once
#include <string>

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
        void print();

};