#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Stack {
    TreeNode* nodes[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, TreeNode* node) {
    if (stack->top < STACK_SIZE - 1) {
        stack->nodes[++(stack->top)] = node;
    }
}

TreeNode* pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->nodes[(stack->top)--];
    }
    return NULL;
}

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void PlaceNode(TreeNode* node, int direction, int data) {
    TreeNode* newNode = createNode(data);
    if (direction == 0) {
        node->left = newNode;
    }
    else {
        node->right = newNode;
    }
}

void GenerateLinkTree(TreeNode* root) {
    PlaceNode(root, 0, 2);
    PlaceNode(root, 1, 9);

    PlaceNode(root->left, 0, 3);
    PlaceNode(root->left, 1, 5);
    PlaceNode(root->left->left, 0, 4);
    PlaceNode(root->left->left, 1, 6);
    PlaceNode(root->left->right, 0, 7);
    PlaceNode(root->left->right, 1, 8);

    PlaceNode(root->right, 0, 10);
    PlaceNode(root->right, 1, 13);
    PlaceNode(root->right->left, 0, 11);
    PlaceNode(root->right->left, 1, 12);
    PlaceNode(root->right->right, 0, 14);
    PlaceNode(root->right->right, 1, 15);
}

void GetSumOfNodes(TreeNode* root) {
    Stack stack;
    initStack(&stack);
    push(&stack, root);
    int sum = 0;

    while (!isEmpty(&stack)) {
        TreeNode* node = pop(&stack);
        if (node != NULL) {
            sum += node->data;
            if (node->right) push(&stack, node->right);
            if (node->left) push(&stack, node->left);
        }
    }

    printf("Sum of nodes: %d\n", sum);
}

void GetNumberOfNodes(TreeNode* root) {
    Stack stack;
    initStack(&stack);
    push(&stack, root);
    int count = 0;

    while (!isEmpty(&stack)) {
        TreeNode* node = pop(&stack);
        if (node != NULL) {
            count++;
            if (node->right) push(&stack, node->right);
            if (node->left) push(&stack, node->left);
        }
    }

    printf("Number of nodes: %d\n", count);
}

void GetHeightOfTree(TreeNode* root) {
    if (root == NULL) {
        printf("Height of tree: 0\n");
        return;
    }

    Stack stack;
    initStack(&stack);
    push(&stack, root);
    int maxDepth = 0;

    while (!isEmpty(&stack)) {
        TreeNode* node = pop(&stack);
        int depth = 1;
        TreeNode* temp = node;

        while (temp) {
            depth++;
            temp = temp->left ? temp->left : temp->right;
        }

        if (depth > maxDepth) maxDepth = depth;
    }

    printf("Height of tree: %d\n", maxDepth);
}


void GetNumberOfLeafNodes(TreeNode* root) {
    Stack stack;
    initStack(&stack);
    push(&stack, root);
    int leafCount = 0;

    while (!isEmpty(&stack)) {
        TreeNode* node = pop(&stack);
        if (node != NULL) {
            if (node->left == NULL && node->right == NULL) {
                leafCount++;
            }
            if (node->right) push(&stack, node->right);
            if (node->left) push(&stack, node->left);
        }
    }

    printf("Number of leaf nodes: %d\n", leafCount);
}

// main ÇÔ¼ö
int main() {
    TreeNode* root = NULL;
    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;

    GenerateLinkTree(root);

    GetSumOfNodes(root);
    GetNumberOfNodes(root);
    GetHeightOfTree(root);
    GetNumberOfLeafNodes(root);

    return 0;
}
