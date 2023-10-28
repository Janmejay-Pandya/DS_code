//Queue program push or delete
#include<stdio.h>
#include<stdlib.h>

struct queue
{   int size;    
    int f;    
    int r;    
    int* arr;
};

int isfull(struct queue *q){
    if (q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;
}

int enqueue(struct queue *q,int val){
    if (isfull(q))
    {
        printf("This queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
    }
    
}
int dequeue(struct queue *q){
    int a=-1;
    if (isEmpty(q))
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size=400;
    q.f=0,q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));

    // enqueue(&q,2);
    // enqueue(&q,1);
    // enqueue(&q,11);
    // printf("The deleted element is %d\n", dequeue(&q));
    // printf("The deleted element is %d\n", dequeue(&q));
    // if (isEmpty(&q))
    // {
    //     printf("Queue is empty");
    // }

    //BFS IMPLEMENTATION
    int node;
    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,1,0,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0}
    };
    printf("%d",i);
    visited[i]=1;
    enqueue(&q,i);
    while (!isEmpty(&q))
    {
        node=dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j]==1 && visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
        
    }
    


}

       /*     0---1
              | \ |    graph used for BFS
              3---2
               \ /
                4
               / \
              5   6     */



//QUEUE WITH LINKED LIST
// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node* next;
// };

// struct node*front=NULL;
// struct node*rear=NULL;
// int enqueue(int value){
//     struct node*ptr;
//     ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=value;
//     ptr->next=NULL;
//     if ((front==NULL)&&(rear==NULL))
//     {
//         front=rear=ptr;
//     }
//     else{
//         rear->next=ptr;
//         rear = ptr;
//     }
//     printf("node is inserted\n");
// }

// int dequeue(int value){
//     struct node *temp=front;
//     if(front==NULL)
//     {
//        printf("UnderFlow\n");
//     }
//     else
//     {
//         int temp_data=front->data;
//         front=front->next;
//         free(temp);
//         return temp_data;
//     }
    
// }

// void dispaly(){
//     if (front == NULL && rear == NULL )
//     {
//         printf("\nQueue Underflow\n");

//     }
//     else{
//         while((front!=NULL)){
//             printf("%d ",front->data );
//             front=front->next ;
//         }

//     }
// }

// int main(){
//         int choice,value;
//         printf("Implementation of Queue usinf LInked list\n");
//         while (choice!=4)
//         {
//             printf("1.Enqueue,\n 2.Dequeue,\n 3. dispaly,\n 4. exit\n");
//             printf("Enter your choice\n");
//             scanf("%d",&choice);
//             switch (choice)
//             {
//             case 1:
//                 printf("Enter the value to Insert:\n ");
//                 scanf("%d",&value);
//                 enqueue(value);
//                 break;
//             case 2:
//                 printf("Popped element is :%d\n",dequeue(value));
//                 break;
//             case 3:
//                 dispaly();
//                 break;
//             case 4:
//                 exit(0);
//                 break;
//             default:
//                 break;
//             }

//         }
        
// }
    
        


