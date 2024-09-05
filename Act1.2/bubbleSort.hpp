#pragma once
#include <vector>

using namespace std;

template <typename T>
class BubbleSort 
{
public:
    static void sort(vector<T>& data);
};

template <typename T>
void BubbleSort<T>::sort(vector<T>& data) 
{
    for (size_t i = 0; i < data.size() - 1; ++i)
    {
        for (size_t j = 0; j < data.size() - i - 1; ++j) 
        {
            if (data[j] > data[j + 1]) 
            {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}