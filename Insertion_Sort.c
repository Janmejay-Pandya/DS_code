#include<stdio.h>
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[],int size){
    for (int i =1; i < size; i++)
    {
        int key,j;
        j=i-1;
        key=arr[i];
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;

    }

}

int main()

{
    int arr[]={9,23,54,76,86,45,3,2,6};
    int size,result;
    size=sizeof(arr)/sizeof(int);
    insertionSort(arr,size);
    printArray(arr,size);

}
