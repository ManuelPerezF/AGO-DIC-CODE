#include "vector.h"

vector::vector() 
{
    v = nullptr;
    
    size = 0;
}


vector::~vector() 
{
    delete[] v;
}

void vector::add(int x)
{
    int *q = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        q[i] = v[i];
    }

    delete [] v; //borramos el arreglo anterior
    v = q; //asignamos el nuevo arreglo
    v[size] = x; //añadimos el nuevo elemento
    size++;
}

void vector::remove(int i)
{
    if (i < 0 || i >= size)
        return;
    int *q = new int[size - 1];
    //copiar elementos anterior a i
    for (int j = 0 ; j  < i ; j++)
    {
        q[j] = v[j];
    }
    
    for (int j = i + 1; j < size; j++)
    {
        q[j - 1] = v[j];
    }

    delete [] v;
    v = q;
    size--;
}

int vector::get(int i)
{
    if (i >= 0 && i < size)
        return v[i];
    return 0;
}

void vector::setsize(int m)
{
    if (m < 0)
        return;
    if (m < size)
    {
        int *q = new int[m];
        for (int i = 0; i < m; i++)
        {
            q[i] = v[i];
        }
        delete [] v;
        v = q;
    }
    else if (m > size)
    {
        int *q = new int[m];
        for (int i = 0; i < size; i++)
        {
            q[i] = v[i];
        }
        delete [] v;
        v = q;
    }
    size = m;
    
}

int vector::getsize()
{
    return size;
}