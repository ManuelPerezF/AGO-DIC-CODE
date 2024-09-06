#include <iostream>
#include "exchangeSort.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include <vector>

using namespace std;

int main() {
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

    
    return 0;
}
