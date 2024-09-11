#pragma once
#include <vector>

template <typename T>
class SequentialSearch 
{
public:
    static int search(const std::vector<T>& arr, const T& busq) 
    {
        for (size_t i = 0; i < arr.size(); ++i) 
        {
            if (arr[i] == busq) 
            {
                return i; // Retorna el índice si se encuentra el dato
            }
        }
        return -1; // Retorna -1 si el dato no se encuentra
    }
};