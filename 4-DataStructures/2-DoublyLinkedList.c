
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
} Node;

Node *initNode(int new_data, Node **next_ref) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Error: Memory allocation error\n");
    exit(1);
  }
  new_node->data = new_data;
  if (next_ref != NULL) {
    new_node->next = (*next_ref);
  } else {
    new_node->next = NULL;
  }
  return new_node;
}

int getData() {
  printf("Enter the new number: ");
  int new_data;
  scanf("%d", &new_data);
  return new_data;
}

void main {
  
  return 0;
}
