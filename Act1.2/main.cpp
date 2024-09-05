#include <iostream>
#include "exchangeSort.hpp"
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

    return 0;
}
