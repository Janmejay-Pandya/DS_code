#include<stdio.h>
void printArray(int arr[],int size){
    for (int i = 0; i < size;  i++)
    {
        printf("%d  ",arr[i]);
    }
    
}
void BubbleSort(int arr[],int size){
    int temp;
    for (int i = 0; i < size-1; i++) //////for number of passes
    {
        for (int j = 0; j < size-1-i; j++)  //for comparison in each pass
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}


int main()
{
    int arr[]={3,1,5,8,7,45,32,12,89,32,78,11,22,2323},size;
    size=sizeof(arr)/sizeof(int);
    printf("%d\n",size);
    bbsort(arr,size);
    printArray(arr,size);


}


