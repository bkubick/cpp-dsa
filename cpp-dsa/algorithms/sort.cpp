#include <iostream>

#include "sort.hpp"


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
    // Helper lambda function to print an array to verify the sorting function.
    auto runAndPrintSort = [](void (*sortingAlgorithm)(int[], int)) 
    { 
        int arr[] = {6, 3, 2, 5, 4, 1};
        int size = sizeof(arr) / sizeof(arr[0]);

        sortingAlgorithm(arr, size);

        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    };


    runAndPrintSort(bubbleSort);

    return 0;
}
