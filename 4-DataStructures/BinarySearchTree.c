#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define STACK_MAX 128

// Binary Search Tree Node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newBSTNode(int data, Node *left, Node *right) {
    printf("creating new node %d\n", data);
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate new node to memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

void insertNode(Node **root, int data) {
    printf("inserting %d\n", data);
    Node *new_node = newBSTNode(data, NULL, NULL);
    if (!(*root)) {
        printf("root was NULL, setting to %d\n", data);
        // root could not be node* because of reasignment of it's referencing node is done here
        *root = new_node;
        return;
    }
    Node *node = *root;
    while (node) {
        printf("data %d at %p\n", node->data, node);
        if (data <= node->data) {
            if (!node->left) {
                printf("%d is smaller than %d\n", data, node->data);
                node->left = new_node;
                return;
            } else {
                node = node->left;
                continue;
            }
        } else if (data >= node->data) {
            if (!node->right) {
                printf("%d is bigger than %d\n", data, node->data);
                node->right = new_node;
                return;
            } else {
                node = node->right;
                continue;
            }
        }
    }
    return;
}

void printInOrderNoRecursion(Node* node) {
    Node* stack[STACK_MAX] = {NULL};
    size_t i = 0;
    uint8_t count = 1;

    if (!node) {
        fprintf(stderr, "ERROR: Could not print tree as root pointer is NULL\n");
        return;
    }
    while (i > 0 || node) {
        for (;(node = node->left); stack[i++] = node)
            ;
        node = stack[--i];
        printf(" -> %d: %d\n", count++, node->data);
        node = node->right;
    }
    printf("Done printing tree, total of %d nodes\n", count - 1);
    return;
}

void printReversedNoRecursion(Node* node) {
    Node* stack[STACK_MAX] = {NULL};
    size_t i = 0;
    uint8_t count = 1;

    if (!node) {
        fprintf(stderr, "ERROR: Could not print tree as given root pointer is NULL\n");
        return;
    }
    while (i > 0 || node) {
        while (node) {
            stack[i++] = node;
            node = node->right;
        }
        node = stack[--i];
        printf(" -> %d: %d\n", count++, node->data);
        node = node->left;
    }
    printf("Done printing tree, total of %d nodes\n", count - 1);
    return;
}

void freeTreeNodes(Node* node) {
    Node* stack[STACK_MAX] = {NULL};
    size_t i = 0;
    uint8_t count = 1;
    if (!node) {
        fprintf(stderr, "ERROR: Could not print tree as root pointer is NULL\n");
        return;
    }
    while (i > 0 || node) {
        while (node) {
            stack[i++] = node;
            node = node->left;
        }
        node = stack[--i];
        printf(" -> FREEING %d: %d\n", count++, node->data);
        free(node);
    }
    printf("Done freeing tree, total of %d nodes\n", count - 1);
    return;
}

void deleteNode(Node* node, int target) {
    // should become parent of to be deleted node so to link with it's children
    Node* parent = node;
    //find node in tree, error if not
    while (node && node->data != target) {
        printf("finding node to delete\n");
        parent = node;
        if (target < node->data)
            node = node->left;
        else if (target > node->data)
            node = node->right;
        else
            break;
    }
    if (node->data != target || !node ) {
        fprintf(stderr, "ERROR: could not deleteNode node with data: %d because it doesn't exist in the tree @ %p", target, node);
        return;
    }
    printf("found node @ %p w/ parent %d @ %p\n data: %d\n left: %d\n right: %d\n", node, parent->data, parent, node->data, node->left->data, node->right->data);
    // rearenge left & right
    /*
    if (parent == node) {
        printf("chroot\n");
        parent = node->right;

    } else
    */
    if (parent->data >= node->data) {
        parent->right = node->left;
        parent->right->right = node->right;
    } else {
        parent->left = node->right;
        parent->left->left = node->left;
    }
    printf("deleting node %d @ %p\n", node->data, node);
    free(node);
    return;
}

void readNth(Node* node, size_t nth);
void update(Node* root, int target);

int main() {
    Node *root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 7);
    insertNode(&root, 69);
    insertNode(&root, 420);
    insertNode(&root, 9);
    insertNode(&root, 1);
    insertNode(&root, 42);
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 100);
    insertNode(&root, 1000);
    printf("data: %d\n", root->data);
    printf("left: %d\n", root->left->data);
    printf("right: %d\n", root->right->data);
    printf("right of right: %d\n", root->right->right->data);
    printf("left of right: %d\n", root->right->left->data);
    printf("right of left: %d\n", root->left->right->data);
    printf("left of left: %d\n", root->left->left->data);
    printf("banana\n");
    /*
    insertNode(&root, 420);
    insertNode(&root, 3);
    insertNode(&root, 3);
    */
    printInOrderNoRecursion(root);
    printReversedNoRecursion(root);
    deleteNode(root, 69);
    printInOrderNoRecursion(root);

    //freeTreeNodes(root);
    return 0;
}
