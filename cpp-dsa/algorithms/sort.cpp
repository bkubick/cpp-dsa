#include <algorithm>
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


void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}


void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1])
        {
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
}


int main()
{
    // Helper lambda function to print an array to verify the sorting function.
    auto runAndPrintSort = [](void (*sortingAlgorithm)(int[], int)) 
    { 
        int arr[] = {6, 6, 3, 2, 5, 4, 1};
        int size = sizeof(arr) / sizeof(arr[0]);

        sortingAlgorithm(arr, size);

        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    };


    runAndPrintSort(bubbleSort);
    runAndPrintSort(selectionSort);
    runAndPrintSort(insertionSort);

    return 0;
}
