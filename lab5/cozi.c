#include "cozi.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Queue* createQueue() {
  Queue* q;
  q = (Queue*)malloc(sizeof(Queue));
  if (q == NULL)
    return NULL;
  q->front = q->rear = NULL;
  return q;
}

int isEmpty(Queue* q) {
  return (q->front == NULL);
}

int deQueue(Queue* q) {
  Node* aux;
  int d;
  if (isEmpty(q))
    return INT_MIN;

  aux = q->front;
  d = aux->val;
  q->front = (q->front)->next;

  if (q->front == NULL)
    q->rear = NULL;
  else
    q->front->prev = NULL;
  free(aux);
  return d;
}

void enQueue(Queue* q, int v) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->val = v;
  newNode->next = NULL;

  if (q->rear == NULL)
    q->rear = newNode;
  else {
    newNode->prev = q->rear;
    (q->rear)->next = newNode;
    (q->rear) = newNode;
  }

  if (q->front == NULL)
    q->front = q->rear;
}
