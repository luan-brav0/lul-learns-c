#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node
typedef struct BSTNode {
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
} BSTNode;

BSTNode *newBSTNode(int data, BSTNode *left, BSTNode *right) {
  printf("creating new node %d\n", data);
  BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
  if (new_node == NULL) {
    fprintf(stderr, "ERROR: Failed to allocate new node to memory\n%s\n",
            stderr);
    exit(1);
  }
  new_node->data = data;
  new_node->left = left;
  new_node->right = right;
  return new_node;
}

void insert(BSTNode **root, int data) {
  printf("inserting %d\n", data);
  BSTNode *new_node = newBSTNode(data, NULL, NULL);
  if (!(*root)) {
    printf("root was NULL, setting to %d\n", data);
    *root = new_node;
    return;
  }
  BSTNode *node = *root;
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

int main() {
  BSTNode *root = NULL;
  insert(&root, 10);
  insert(&root, 7);
  insert(&root, 69);
  insert(&root, 420);
  insert(&root, 9);
  printf("data: %d\n", root->data);
  printf("left: %d\n", root->left->data);
  printf("right: %d\n", root->right->data);
  printf("right of right: %d\n", root->right->right->data);
  printf("right of left: %d\n", root->left->right->data);
  /*
  insert(&root, 420);
  insert(&root, 3);
  insert(&root, 3);

  printInOrder(&root);
  */
  return 0;
}
