#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d \n", root->data);
        inOrder(root->right);
    }
}

struct node* search(struct node*root,int key){
    if(root == NULL){
        return NULL;
    }
    if (root->data==key)    
    {
        return root;
    }
    else if (root->data>key)
    {
        return  search(root->left , key );
    }
    else{
        return   search(root->right , key ) ;
    }
}
struct node*searchIterative(struct node*root ,int key){
    while (root!=NULL)
    {
        if (root->data==key)
        {
            return root;
        }
        else if (key<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
}

int main()
{
    struct node*root;
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(2);
    struct node *p3 = createNode(7);
    struct node *p4 = createNode(6);
    struct node *p5 = createNode(4);
    struct node *p6 = createNode(8);
    p->left = p1;
    p->right = p3;
    p1->right=p5;
    p1->left = p2;
    p3->left = p4;
    p3->right=p6;
    int key,choice,num;
    printf("Tree operations are");
    printf("1. Create Node ");
    printf("2. Search Recursive ");
    printf("3. Search Itreative ");
    printf("4. Display Tree ");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    while (1)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to add:");
            scanf("%d", &num);
            createNode(num);
            break;
        case 2:
            printf("Enter the number you want to search: ");
            scanf("%d",&key);
            struct node*n=search(p,key);
            if (n!=NULL)
            {
                printf("\nElement found :%d\n",n->data);
            }
            else
            {
                printf("\nelement not found\n ");
            }

        
        default:
            break;
        }
    }
    

    
    inOrder(p);
    printf("Enter the number you want to serach: ");
    scanf("%d",&key);
    struct node*n=searchIterative(p,key);
    if (n!=NULL)
    {
        printf("\nElement found :%d\n",n->data);
    }
    else{
        printf("\nelement not found\n ");
    }
    
    
}
/*    5
    /   \
   3     7
  / \   / \ 
 2   4 6   8  
*/