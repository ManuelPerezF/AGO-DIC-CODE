#pragma once
#include <vector>

using namespace std;

template <typename T>
class InsertionSort
{
public:
    static void sort(vector<T>& data);
};

template <typename T>
void InsertionSort<T>::sort(vector<T>& data)
{
    for (size_t i = 1; i < data.size(); ++i)
    {
        T temp = data[i];
        size_t j = i;
        while (j > 0 && temp < data[j - 1])
        {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = temp;
    }
}