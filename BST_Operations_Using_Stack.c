#include <stdio.h>
#include <stdlib.h>

// Structure for a BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for a stack Node (used for traversal)
struct StackNode {
    struct Node* data;
    struct StackNode* next;
};

// Stack data structure for Node pointers
struct Stack {
    struct StackNode* top;
};

// Create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Push a Node onto the stack
void push(struct Stack* stack, struct Node* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop a Node from the stack
struct Node* pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return NULL; 
    }
    struct Node* data = stack->top->data;
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Insert a Node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a Node in the BST
struct Node* search(struct Node* root, int data) {
    struct Stack* stack = createStack();
    struct Node* current = root;
    while (current || stack->top) {
        while (current) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        if (current->data == data) {
            free(stack); 
            return current;
        }
        current = current->right;
    }
    free(stack); 
    return NULL; 
}


void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Stack* stack = createStack();
    struct Node* current = root;
    while (current || stack->top) {
        while (current) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
    free(stack); }

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    struct Node* searchResult = search(root, 40);
    if (searchResult) {
        printf("Node 40 found in the BST.\n");
    } else {
        printf("Node 40 not found in the BST.\n");
    }

    return 0;
}
