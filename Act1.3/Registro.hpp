#pragma once
#include "Fecha.hpp"
#include <string>

class Registro {
    private:
        Fecha fecha;
        std::string ip;
        std::string msj;
    public:
        Registro();
        Registro(Fecha, std::string, std::string);
        Registro(std::string, int, std::string, std::string, std::string);
        void print();
};