#include <iostream>

#include "sort.hpp"


/**
 * Bubble sort algorithm that sorts an array of integers in ascending order,
 * in place.
 * 
 * @param arr[] array to be sorted.
 * @param size size of the array.
*/
void bubbleSort(int arr[], int size)
{
    
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}


int main()
{
    int arr[] = {6, 3, 2, 5, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
