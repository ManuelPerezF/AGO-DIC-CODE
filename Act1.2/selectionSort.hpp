#pragma once
#include <vector>

using namespace std;

template <typename T>
class SelectionSort
{
public:
    static void sort(vector<int>& data);
};

template <typename T>
void SelectionSort<T>::sort(vector<int>& data)
{
    for (size_t i = 0; i < data.size() - 1; ++i)
    {
        size_t min = i;
        for (size_t j = i + 1; j < data.size(); ++j)
        {
            if (data[j] < data[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            T temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
}