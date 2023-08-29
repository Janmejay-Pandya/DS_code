#include <stdio.h>
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void SelectionSort(int arr[], int size)
{
    int indexOfMin, temp;

    for (int i = 0; i < size - 1; i++) // Number of passes

    {
        indexOfMin = i;

        for (int j = i + 1; j < size; j++)
        {

            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
            temp = arr[i];
            arr[i] = arr[indexOfMin];
            arr[indexOfMin] = temp;
        }
    }
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5};
    int size;
    size = sizeof(arr) / sizeof(int);
    SelectionSort(arr, size);
    printArray(arr, size);
}


