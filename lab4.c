#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define MIN_NUM_NOTES 3

typedef struct Node {
  char nota;
  struct Node* next;
} Node;

// Insert the elements of the array in the list in the same order
void append(struct Node** head, int data) {
  struct Node* auxNode = (struct Node*)malloc(sizeof(struct Node));

  struct Node* last = *head;

  auxNode->nota = data;
  auxNode->next = NULL;
  if (*head == NULL) {
    *head = auxNode;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = auxNode;
  return;
}

void insert(struct Node** head, int data) {
  struct Node* auxNode = (struct Node*)malloc(sizeof(struct Node));

  auxNode->nota = data;
  auxNode->next = *head;
  *head = auxNode;
}

Node* startingSequence(Node* head, char refren[]) {
  Node* current = head;
  Node* startOfSequence = NULL;

  while (current != NULL) {
    Node* aux = current;
    bool isStartingSequence = true;
    for (int i = 0; i < MIN_NUM_NOTES - 1 && aux; i++) {
      if (aux->nota != refren[i]) {
        isStartingSequence = false;
        break;
      }
      aux = aux->next;
    }

    if (isStartingSequence) {
      startOfSequence = current;
      break;
    } else
      current = current->next;
  }

  return startOfSequence;
}

void printList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("%c ", current->nota);
    current = current->next;
  }
}

void repeatSequence(Node* sequence) {
  Node* copy = NULL;
  Node* current = sequence;
  while (current != NULL) {
    append(&copy, current->nota);
    current = current->next;
  }

  current = sequence;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = copy;
}

int main() {
  Node* partitura = NULL;

  char arr[] = {'D', 'D', 'G', 'G', 'A', 'F', 'C', 'D', 'F', 'C'};
  char refren[] = {'G', 'A', 'D'};

  for (int i = 0; i < ARRAY_SIZE; i++) {
    append(&partitura, arr[i]);
  }

  printList(partitura);

  Node* sequence = startingSequence(partitura, refren);
  if (sequence == NULL) {
    printf("No sequence found\n");
    return 0;
  }

  printf("\n");

  repeatSequence(sequence);

  printf("\n");

  printList(partitura);

  return 0;
}