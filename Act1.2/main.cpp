#include <iostream>
#include "exchangeSort.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "insertionSort.hpp"
#include "mergeSort.hpp"
#include "quickSort.hpp"
#include "busqSequencial.hpp"
#include "busqBinaria.hpp"
#include <vector>

using namespace std;

// Manuel Antonio Pérez Fonseca A01741957
// Act 1.2 - Algoritmos de Búsqueda y Ordenamiento

int main() 
{
    vector<int> data = {5, 2, 9, 1, 5, 6};

    cout << "Datos antes del ordenamiento: ";
    for (const auto& num : data) 
    {
        cout << num << " ";
    }
    cout << endl;

    ExchangeSort<int>::sort(data);
    cout << "Ordenamiento con ExchangeSort: ";
    for (const auto& num : data)
    {
        cout << num << " ";
    }
    cout << endl;

    BubbleSort<int>::sort(data);
    cout << "Ordenamiento con BubbleSort: ";
    for (const auto& num : data) 
    {
        cout << num << " ";
    }
    cout << endl;

    SelectionSort<int>::sort(data);
    cout << "Ordenamiento con SelectionSort: ";
    for (const auto& num : data) 
    {
        cout << num << " ";
    }
    cout << endl;

    InsertionSort<int>::sort(data);
    cout << "Ordenamiento con InsertionSort: ";
    for (const auto& num : data) 
    {
        cout << num << " ";
    }
    cout << endl;

    MergeSort<int>::sort(data);
    cout << "Ordenamiento con MergeSort: ";
    for (const auto& num : data) 
    {
        cout << num << " ";
    }
    cout << endl;

    QuickSort<int>::sort(data);
    cout << "Ordenamiento con QuickSort: ";
    for (const auto& num : data) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Solicitar al usuario el elemento a buscar
    int busq;
    cout << "Ingrese el elemento a buscar: ";
    cin >> busq;

    int index = SequentialSearch<int>::search(data, busq);
    cout << "Busqueda secuencial: " << busq << (index != -1 ? " se encuentra en el indice " + to_string(index) : " no se encuentra en el vector.") << "." << endl;

    int indexBin = BinarySearch<int>::search(data, busq);
    cout << "Busqueda binaria: " << busq << (indexBin != -1 ? " se encuentra en el indice " + to_string(indexBin) : " no se encuentra en el vector.") << "." << endl;

    return 0;
}


