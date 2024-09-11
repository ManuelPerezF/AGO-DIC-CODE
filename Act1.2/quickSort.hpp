#pragma once
#include <vector>

template <typename T>
class QuickSort 
{
public:
    static void sort(std::vector<T>& arr) 
    {
        quickSort(arr, 0, arr.size() - 1);
    }

private:
    static int part(std::vector<T>& arr, int bajo, int alto) 
    {
        T pivote = arr[alto]; 
        int i = (bajo - 1); 

        for (int j = bajo; j <= alto - 1; j++) 
        {
            // Si el elemento actual es menor o igual al pivote
            if (arr[j] <= pivote) 
            {
                i++; 
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[alto]);
        return (i + 1);
    }

    static void quickSort(std::vector<T>& arr, int bajo, int alto) 
    {
        if (bajo < alto) 
        {
            // pi es el índice de partición, arr[pi] está en el lugar correcto
            int pi = part(arr, bajo, alto);

            // Ordenar los elementos separadamente antes y depues de hacer la particioon
            quickSort(arr, bajo, pi - 1);
            quickSort(arr, pi + 1, alto);
        }
    }
};