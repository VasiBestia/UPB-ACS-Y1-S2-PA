#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next, *prev;
} Node;

typedef struct Queue {
  Node *front, *rear;
} Queue;

Queue* createQueue();
int isEmpty(Queue*);
int deQueue(Queue*);
void enQueue(Queue*, int);