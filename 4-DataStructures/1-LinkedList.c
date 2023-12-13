#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *initNode(int new_data, Node **next_ref) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Memory allocation error\n");
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

void printList(Node **head_ref) {
  if ((*head_ref) == NULL) {
    fprintf(stderr, "List is empty\n");
  }
  printf("List items:");
  for (Node *temp = (*head_ref); temp != NULL; temp = temp->next) {
    printf(" %d ", temp->data);
  }
  printf("\n");
}

void insert(Node **head_ref) {
  int new_data = getData();
  Node *new_node = initNode(new_data, head_ref);
  (*head_ref) = new_node;
  printf("%d inserted\n", new_data);
  printList(head_ref);
}

void push(Node **head_ref) {
  int new_data = getData();
  Node *new_node = initNode(new_data, NULL);
  if ((*head_ref) == NULL) {
    (*head_ref) = new_node;
    printf("%d pushed\n", new_data);
    printList(head_ref);
    return;
  }
  Node *temp = *head_ref;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
  printf("%d pushed\n", new_data);
  printList(head_ref);
}

void insertAtNthPosition(Node **head_ref) {
  int new_data = getData();
  Node *new_node = initNode(new_data, head_ref);
  int position;
  printf("Enter position: ");
  scanf("%d", &position);
  if (position < 0) {
    fprintf(stderr,
            "Invalid position, please try again with a positive value\n");
    return;
  }
  if (position == 1 || (*head_ref) == NULL) {
    new_node->next = *head_ref;
    (*head_ref) = new_node;
    printf("%d inserted at position 1\n", new_data);
    return;
  }
  Node *temp = *head_ref;
  if (temp == NULL) {
    fprintf(stderr, "Invalid position\n");
    return;
  }
  for (int i = 0; i < position - 2 && temp->next != NULL; i++) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
  printList(head_ref);
}

void reverseList(Node **head_ref) {
  if (*head_ref == NULL || (*head_ref)->next == NULL) {
    fprintf(stderr, "List is either empty or has only one item\n");
    return;
  }
  Node *current = *head_ref;
  Node *prev = NULL;
  Node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
  printList(head_ref);
}

int main() {
  struct Node *head = NULL;
  printf("List created");
  int op;
  const int TOTAL_OPERATIONS = 5;
  do {
    printf("Enter operation:"
           "\n\t[1] - Print"
           "\n\t[2] - Insert"
           "\n\t[3] - Push"
           "\n\t[4] - Insert at Nth position"
           "\n\t[5] - Reverse list"
           "\n\t[0] - Exit\n");
    scanf("%d", &op);
    if (op < 0 || op > TOTAL_OPERATIONS) {
      fprintf(stderr, "Invalid operation. Try again\n");
      continue;
    }
    switch (op) {
    case 1:
      printList(&head);
      break;
    case 2:
      insert(&head);
      break;
    case 3:
      push(&head);
      break;
    case 4:
      insertAtNthPosition(&head);
      break;
    case 5:
      reverseList(&head);
      break;
    case 0:
      printf("Goodbye!\n");
      break;
    default:
      fprintf(stderr, "Invalid operation. Try again\n");
      break;
    }
  } while (op != 0);
  return 0;
}
