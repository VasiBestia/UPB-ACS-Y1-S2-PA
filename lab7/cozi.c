#include "cozi.h"

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

char deQueue(Queue* q) {
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

char deQueueRear(Queue* q) {
  Node* aux;
  int d;
  if (isEmpty(q))
    return INT_MIN;

  aux = q->rear;
  d = aux->val;
  q->rear = (q->rear)->prev;

  if (q->rear == NULL)
    q->front = NULL;
  else
    q->rear->next = NULL;
  free(aux);
  return d;
}

void enQueue(Queue* q, char v) {
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

void enQueueFront(Queue* q, char v) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->val = v;
  newNode->next = NULL;

  if (q->front == NULL)
    q->front = newNode;
  else {
    newNode->next = q->front;
    (q->front)->prev = newNode;
    (q->front) = newNode;
  }

  if (q->rear == NULL)
    q->rear = q->front;
}