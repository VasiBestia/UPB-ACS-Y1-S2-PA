#ifndef COZI_H
#define COZI_H

typedef struct Node {
    int val;
    struct Node *next,*prev;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue* createQueue();
int isEmpty(Queue *q);
void enQueue(Queue *q, int value);
void enQueuefront(Queue *q, int value);
int deQueue(Queue *q);
#endif
