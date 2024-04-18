#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
} Node;

Node *initNode(Node **prev_ref,  int new_data, Node **next_ref) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Error: Memory allocation error\n");
    exit(1);
  }
  new_node->data = new_data;
  if (next_ref == NULL) {
    new_node->next = NULL;
  } else {
    new_node->next = (*next_ref);
  }
  if (prev_ref == NULL) {
    new_node->prev = NULL;
  } else {
    new_node->prev = (*prev_ref);
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
    fprintf(stderr, "Error: List is empty\n");
    return;
  }
  printf("List items:");
  for (Node *item = (*head_ref); item != NULL; item = item->next) {
    printf(" %d ", item->data);
  }
  printf("\n");
}

void insert(Node **head_ref) {
  Node *new_node = initNode(NULL, getData(), head_ref);
  (*head_ref)->prev = new_node;
  (*head_ref) = new_node;
  printf("%d inserted to end of list\n", new_node->data);
}

void push(Node **tail_ref) {
  Node *new_node = initNode(tail_ref, getData(), NULL);
  if ((*tail_ref) == NULL) {
    (*tail_ref) = new_node;
    printf("%d pushed to end of list\n", new_node->data);
    printList(tail_ref);
    return;
  }
  (*tail_ref)->next = new_node;
  (*tail_ref) = new_node;
  printf("%d pushed\n", new_node->data);
}

void insertAtNthPosition(Node **head_ref) {
  int position;
  printf("Enter position: ");
  scanf("%d", &position);
  if (position <= 0) {
    fprintf(
        stderr,
        "Error: Invalid position, please try again with a positive value\n");
    return;
  }
  if (position == 1 || (*head_ref) == NULL) {
    insert(head_ref);
    return;
  }
  Node *prev_node = *head_ref;
  if (prev_node == NULL) {
    fprintf(stderr, "Error: Invalid position\n");
    return;
  }
  for (int i = 0; i <= position - 1 && prev_node->next != NULL; i++) {
    prev_node = prev_node->next;
  }
    Node *new_node = initNode(&prev_node, getData(), &prev_node->next);
    prev_node->next = new_node;
  }

  void reverseList(Node **head_ref, Node **tail_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
      fprintf(stderr, "Error: List is either empty or has only one item\n");
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
    (*tail_ref) = (*head_ref);
    *head_ref = prev;
  }

  void deleteNthItem(Node **head_ref) {
    if (*head_ref == NULL) {
      fprintf(stderr, "Error: List is empty\n");
      return;
    }
    int position;
    Node *prev_node = *head_ref;
    printf("Enter nth position of item to be deleted: ");
    scanf("%d", &position);
    if (position < 1) {
      fprintf(
          stderr,
          "Error: Invalid position. Try again with a position bigger than 0\n");
      return;
    }
    if (position == 1) {
      printf("Deleting 1st item\n");
      prev_node = *head_ref;
      *head_ref = prev_node->next;
      free(prev_node);
      return;
    }
    for (int i = 0; i <= position - 2 || prev_node->next == NULL; i++) {
      if (prev_node->next == NULL) {
        fprintf(stderr, "Error: Index larger that list lenth. Try again\n");
        return;
      } else {
        prev_node = prev_node->next;
      }
    }
    printf("Prev node: %d\n", prev_node->data);
  printf("Deleting %d\n", prev_node->next->data);
  Node *del_node = prev_node->next;
  if (del_node->next == NULL) {
    prev_node->next = NULL;
  } else {
    prev_node->next = del_node->next;
  }
  free(del_node);
  printf("Deleted successfully\n");
}

int main() {
  struct Node *head = NULL;
  struct Node *tail = NULL;
  printf("List created");
  int operation;
  const int TOTAL_OPERATIONS = 6;
  do {
    printList(&head);
    printf("Enter operation:"
           "\n\t[1] - Print"
           "\n\t[2] - Insert"
           "\n\t[3] - Push"
           "\n\t[4] - Insert at Nth position"
           "\n\t[5] - Reverse list"
           "\n\t[6] - Delete Nth item"
           "\n\t[0] - Exit\n");
    scanf("%d", &operation);
    if (operation < 0 || operation > TOTAL_OPERATIONS) {
      printf("operation: %d\n", operation);
      fprintf(stderr, "Error: Invalid operation. Try again\n");
      continue;
    }
    switch (operation) {
    case 0:
      printf("Goodbye!\n");
      return 0;
      break;
    case 1:
      printList(&head);
      break;
    case 2:
      insert(&head);
      break;
    case 3:
      push(&tail);
      break;
    case 4:
      insertAtNthPosition(&head);
      break;
    case 5:
      reverseList(&head, &tail);
      break;
    case 6:
      deleteNthItem(&head);
      break;
    default:
      fprintf(stderr, "Error: Invalid operation. Try again\n");
      break;
    }
  } while (1);
  return 0;
}
