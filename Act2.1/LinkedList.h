#pragma once
#include "Nodo.h"

class lista 
{
  private:
    nodo *head;
    int size;
  public:
    lista();
    ~lista();
    int getSize();
    void addFirst(int);
    void addLast(int);
    void print();
    int get(int);
    void remove(int);
    void update(int, int);
};

#include <iostream>
using namespace std;

lista::lista()
{
    head = nullptr;
    size = 0;
}

lista::~lista() 
{
    nodo *p, *q;
    p = head;
    while (p != nullptr) 
    {
        q = p->getNext();
        cout << "~lista(): delete " << p << endl;
        delete p;
        p = q;
    }
}

int lista::getSize()
{
    return size;
}

void lista::addFirst(int a) 
{
    nodo *nuevo = new nodo(a);
    cout << "addFirst(" << a << "): " << nuevo << endl;
    nuevo->setNext(head);
    head = nuevo;
    size++;
}

void lista::addLast(int a) 
{
    nodo *nuevo = new nodo(a);
    cout << "addLast(" << a << "): " << nuevo << endl;
    nodo *ultimo_nodo = head;
    while (ultimo_nodo->getNext() != nullptr) 
    {
        ultimo_nodo = ultimo_nodo->getNext();
    }
    ultimo_nodo->setNext(nuevo);
    size++;
}

void lista::print() 
{
    nodo *p;
    p = head;
    while (p != nullptr) 
    {
        cout << p->getData() << " ";
        p = p->getNext();
    }
    cout << endl;
}

int lista::get(int position) 
{
    if (position < 0 || position >= size)
        return -1; 
    nodo *p = head;
    for(int i = 0; i < position; i++)
    {
        p = p->getNext();
    }
    return p->getData();
}

void lista::remove(int position) 
{
    if (position < 0 || position >= size)
        cout << "remove(" << position << "): posición inválida" << endl;
        return;
    nodo *p = head;
    if (position == 0) 
    {
        head = p->getNext();
        delete p;
        size--;
        return;
    }
    for(int i = 0; i < position - 1; i++) 
    {
        p = p->getNext();
    }
    nodo *q = p->getNext();
    p->setNext(q->getNext());
    delete q;
    size--;
}


void lista::update(int position, int value) 
{
    if (position < 0 || position >= size)
        cout << "update(" << position << "): posición inválida" << endl;
        return;
    nodo *p = head;
    for(int i = 0; i < position; i++)
    {
        p = p->getNext();
    }
    p->setData(value);
}