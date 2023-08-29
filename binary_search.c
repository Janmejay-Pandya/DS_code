//Binary search with menu driven approach by iterative and recursive methods
#include <stdio.h>
// Binary search using iteration
int binarySearchIterative(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    
    return -1; // key not found
}

// Binary search using recursion
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, right, key); 
        } else {
            return binarySearchRecursive(arr, left, mid - 1, key); 
        }
    }

    return -1; // key not found
}

int main() {
    int choice;
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Choose an option:\n");
    printf("1. Binary search with iteration\n");
    printf("2. Binary search with recursion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the key: ");
            scanf("%d", &key);
            int indexIterative = binarySearchIterative(arr, size, key);
            if (indexIterative != -1) {
                printf("key found at index %d\n", indexIterative);
            } else {
                printf("key not found\n");
            }
            break;

        case 2:
            printf("Enter the key: ");
            scanf("%d", &key);
            int indexRecursive = binarySearchRecursive(arr, 0, size - 1, key);
            if (indexRecursive != -1) {
                printf("key found at index %d\n", indexRecursive);
            } else {
                printf("key not found\n");
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}






// //Iterative method
// #include <stdio.h>
// int bin_search_iterative(int arr[], int size, int key)
// {
//     int low, mid, high;
//     low = 0;
//     high = size - 1;
//     while (low <= high)
//     {
        
//         mid = (low + high) / 2;
//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         if (arr[mid] < key)
//         {
//             low = mid + 1;
//         }
//         if (arr[mid] > key)
//         {
//             high = mid - 1;
//         }
//     }
//     return -1;
// }
// //Recursive method 
// #include<stdio.h>
// int bin_search_recursive(int *arr,int key,int size)
// {
//     int low, mid, high;
//     low = 0;
//     high = size - 1;
//     while (low<high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]==key)
//         {
//             printf("Key found");
//         }
//         if (arr[mid]>key){
//             return bin_search_recursive(arr,key,mid-1);
//         }
//         return bin_search_recursive(arr,key,mid+1);

//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//     int size = sizeof(arr) / sizeof(int);
//     int key,x;
//     int result;
//     printf("Enter the element you want to find:-\n");
//     scanf("%d\n", &key);
//     printf("Enter the choice you want to find (1) for Recursive and (2) for Iterative:\n");
//     scanf("%d\n",&x);
//     switch (x)
//     {
//     case 1:
//         bin_search_recursive(arr,key,size);
//         break;
//     case 2:
//         result = bin_search_iterative(arr, size, key);
//         printf("The key %d was found at index %d\n", key, result + 1);
//         break;

    
//     default:
//         break;
//     }
    
    

// }



