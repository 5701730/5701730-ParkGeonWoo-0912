#include<stdio.h>
#include<stdlib.h>

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

void GenerateArrayTree(int* tree) {
    int list[] = { 1, 2, 9, 3, 5, 10, 13, 4, 6, 7, 8, 11, 12, 14, 15 };
    for (int i = 0; i < 15; i++) {
        tree[i] = list[i];
    }
}

void GenerateLinkTree(TreeNode** root) {
    *root = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->data = 1;
    (*root)->left = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->right = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->left->data = 2;
    (*root)->right->data = 9;

    
    (*root)->left->left = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->left->right = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->right->right = (TreeNode*)malloc(sizeof(TreeNode));

    (*root)->left->left->data = 3;
    (*root)->left->right->data = 5;
    (*root)->right->left->data = 10;
    (*root)->right->right->data = 13;

    (*root)->left->left->left = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->left->left->right = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->left->left->left->data = 4;
    (*root)->left->left->right->data = 6;
    (*root)->left->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->left->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->left->right->left->data = 7;
    (*root)->left->right->right->data = 8;

    (*root)->right->left->left = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->right->left->right = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->right->left->left->data = 11;
    (*root)->right->left->right->data = 12;
    (*root)->right->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->right->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->right->right->left->data = 14;
    (*root)->right->right->right->data = 15;
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

int main() {
    TreeNode* root = NULL;

    GenerateLinkTree(&root);

    printf("중위 순회:\n");
    LinkInOrder(root);
    printf("\n");

    return 0;
}
