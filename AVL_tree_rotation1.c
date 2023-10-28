#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    int height;
    struct node *left;
    struct node *right;
};

int max(int a,int b){
    return a>b?a:b;
}
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

struct node *createNode(struct node *key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return getheight(n->left) - getheight(n->right);
    }
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
}
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return (createNode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getBalanceFactor(node);

    // left left case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // left right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case
    if (bf > 1 && key > node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct node* root){
    if (root!=NULL)
    {
        printf("%d ",root->key);
        preOrder(root->left);
        preOrder(root->right);

    }
}
int main(){
    struct node* root=NULL;
    root=insert(root, 45);
    root=insert(root, 4);
    root=insert(root, 5);
    root=insert(root, 8);
    root=insert(root, 9);
    preOrder(root);
    return 0;
}