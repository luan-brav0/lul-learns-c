#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void printList(struct Node *n) {
  if (n == NULL) {
    fprintf(stderr, "List is empty\n");
  }
  while (n != NULL) {
    printf("%d ", n->data);
    n = n->next;
  }
  printf("\n");
}

int getData() {
  printf("Enter the new number: ");
  int new_data;
  scanf("%d", &new_data);
  return new_data;
}

void insert(Node **head_ref) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Memory error\n");
    exit(1);
  }

  int new_data = getData();

  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
  printf("%d inserted\n", new_data);
  printList(*head_ref);
}

void push(Node *head_ref) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Memory error\n");
    exit(1);
  }

  int new_data = getData();

  new_node->data = new_data;
  new_node->next = NULL;

  Node *last_node;
  Node *temp = head_ref;
  if (temp == NULL) {
    head_ref = new_node;
  }

  do {
    if (temp->next == NULL) {
      last_node = temp;
    } else {
      temp = temp->next;
    }
  } while (temp->next != NULL);

  last_node->next = new_node;
  printList(head_ref);
}

int main() {
  struct Node *head = NULL;
  printf("List created");

  int op;
  do {
    printf("Enter operation:\n\t[1] - Print\n\t[2] - Insert\n\t[0] - Exit\n");
    scanf("%d", &op);
    if (op < 0 || op > 2) {
      fprintf(stderr, "Invalid operation. Try again\n");
      continue;
    }

    switch (op) {
    case 1:
      printList(head);
      break;
    case 2:
      insert(&head);
      break;
    case 0:
      printf("Goodbye!\n");
      break;
    }
  } while (op != 0);
  return 0;
}
