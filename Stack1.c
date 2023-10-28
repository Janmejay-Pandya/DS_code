#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int count = 0;
// Creating a stack
struct stack
{
    int items[MAX];
    int top;
};
typedef struct stack st;
void createEmptyStack(st *s)
{
    s->top = -1;
}
int isfull(st *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(st *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(st*s,int newitem){
    
    if (isfull(s))
    {
        printf("Stack Full");
    }
    else{
        s->top++;
        s->items[s->top]=newitem;
    }
    count++;
}
void printStack(st*s){
    printf("Stack:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\n",s->items[i]);
    }
    printf("\n");
}
void pop(st*s){
    if (isempty(s))
    {
        printf("\n STACK EMPTY");
    }
    else
    {
        printf ("Item poped=%d",s->items[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}

void lin_search(st*s,int key){
    for (int i = 0; i < count; i++)
    {
        if ((key==s->items[i]))
        {
            count++;
            printf("Element found at position %d \n",i);
            
        }
        else{
            printf("not found\n");

        }

    }
    
}
int main()
{
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    int key=5;
    lin_search(s,key);
    printStack(s);
}

/*find the number 5 is present in the stack or not
enter 12 elements in the stack and check the overflow condition
use for loop for pop and push operation*/


// void lin_Search(int arr[], int size, int key)
// {
//     int count = 0;

//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == key)
//         {
//             count++;
//             printf("Found %d at index %d\n", key, i);
//         }
//     }

//     if (count == 0)
//     {
//         printf("%d not found in the array.\n", key);
//     }
//     else
//     {
//         printf("Total count of %d: %d\n", key, count);
//     }
// }

