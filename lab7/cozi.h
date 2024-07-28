#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char val;
  struct Node *next, *prev;
} Node;

typedef struct Queue {
  Node *front, *rear;
} Queue;

Queue* createQueue();
int isEmpty(Queue*);
char deQueue(Queue*);
void enQueue(Queue*, char);

int deQueueRear(Queue*);
void enQueueFront(Queue*, char);