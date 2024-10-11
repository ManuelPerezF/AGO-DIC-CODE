#pragma once

class vector{
private:
    int *v; //referencia al arreglo
    int size; //tamaño del vector

public:
    vector();  //constructor
    ~vector(); //destructor
    void add(int); //añadir un elemento al vector
    void remove(int); //borrar un elemento del vector
    int get(int); //obtener un elemento del vector
    void setsize(int); //establecer el tamaño del vector
    int getsize(); //obtener el tamaño del vector
    
};