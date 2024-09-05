#pragma once
#include <vector>

using namespace std;

template <typename T>
class ExchangeSort 
{
public:
    static void sort(vector<T>& data);
};


template <typename T>
void ExchangeSort<T>::sort(vector<T>& data) 
{
    for (size_t i = 0; i < data.size() - 1; ++i)
     {
        for (size_t j = i + 1; j < data.size(); ++j) 
        {
            if (data[i] > data[j]) 
            {
                T temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
