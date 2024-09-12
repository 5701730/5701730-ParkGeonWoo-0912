#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Stack {
    TreeNode* data[100];
    int top;
} Stack;


void initStack(Stack* stack) {
    stack->top = -1;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}


void push(Stack* stack, TreeNode* node) {
    stack->data[++(stack->top)] = node;
    printf("push(%d) ", node->data);
}


TreeNode* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    TreeNode* node = stack->data[(stack->top)--];
    printf("pop(%d) ", node->data);
    return node;
}


void visit(TreeNode* node) {
    printf("visit(%d) ", node->data);
}


void PlaceNode(TreeNode* node, int direction, int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (direction == 0) { 
        node->left = newNode;
    }
    else if (direction == 1) { 
        node->right = newNode;
    }
}

void GenerateLinkTree(TreeNode* root) {
    PlaceNode(root, 0, 2);    
    PlaceNode(root, 1, 9);    

    PlaceNode(root->left, 0, 3);   
    PlaceNode(root->left, 1, 5);   
    PlaceNode(root->right, 0, 10); 
    PlaceNode(root->right, 1, 13); 

    PlaceNode(root->left->left, 0, 4); 
    PlaceNode(root->left->left, 1, 6); 
    PlaceNode(root->left->right, 0, 7); 
    PlaceNode(root->left->right, 1, 8); 

    PlaceNode(root->right->left, 0, 11); 
    PlaceNode(root->right->left, 1, 12); 
    PlaceNode(root->right->right, 0, 14); 
    PlaceNode(root->right->right, 1, 15); 
}


void LinkPreOrder(TreeNode* node) {
    if (node == NULL) return;
    Stack stack;
    initStack(&stack);
    push(&stack, node);

    while (!isEmpty(&stack)) {
        TreeNode* current = pop(&stack);
        visit(current);

        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}


void LinkInOrder(TreeNode* node) {
    Stack stack;
    initStack(&stack);
    TreeNode* current = node;

    while (current != NULL || !isEmpty(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        visit(current);
        current = current->right;
    }
}


void LinkPostOrder(TreeNode* node) {
    if (node == NULL) return;

    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    push(&stack1, node);

    while (!isEmpty(&stack1)) {
        TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    while (!isEmpty(&stack2)) {
        visit(pop(&stack2));
    }
}


void LinkOrders(TreeNode* root) {
    printf("전위 순회:\n");
    LinkPreOrder(root);
    printf("\n\n");

    printf("중위 순회:\n");
    LinkInOrder(root);
    printf("\n\n");

    printf("후위 순회:\n");
    LinkPostOrder(root);
    printf("\n");
}

int main() {
    
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    
    GenerateLinkTree(root);

    
    LinkOrders(root);

    return 0;
}
