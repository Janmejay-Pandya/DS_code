#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[low];
//     int i = low + 1;
//     int j = high;
//     int temp;

//     do
//     {
//         while (arr[i] <= pivot)
//         {
//             i++;
//         }

//         while (arr[j] > pivot)
//         {
//             j--;
//         }

//         if (i < j)
//         {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     } while (i < j);

//     temp = arr[low];
//     arr[low] = arr[j];
//     arr[j] = temp;
//     return j;
// }

// void quickSort(int arr[], int low, int high)
// {
//     int partitionIndex; 

//     if (low < high)
//     {
//         partitionIndex = partition(arr, low, high); 
//         quickSort(arr, low, partitionIndex - 1);  
//         quickSort(arr, partitionIndex + 1, high);
//     }
// }

int main()
{
    
    int arr[] = {9, 4, 4, 8, 7, 5, 6};
    int n =sizeof(n)/sizeof(int);
    quickSort(arr, 0, n - 1);
    printarray(arr, n);
    
}



void quicksort(int arr[],int low,int high){
    int partitionIndex;
    if (low < high)
    {
        partitionIndex=partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);   
    }
    
}

void partition(int arr[],int low, int high){
    
}