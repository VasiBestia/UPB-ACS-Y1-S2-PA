#include <stdio.h>
#include <stdlib.h>
#include "cozi.h"

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue *q) {
    return (q->front == NULL);
}

void enQueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = q->rear;
    
    if (q->rear == NULL) { // Queue was empty
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void enQueuefront(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = q->front;
    newNode->prev = NULL;
    
    if (isEmpty(q)) {
        q->rear = newNode;
    } else {
        q->front->prev = newNode;
    }
    
    q->front = newNode;
}

int deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Or any other value that indicates an error
    }

    Node *temp = q->front;
    int value = temp->val;
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // Queue is now empty
    } else {
        q->front->prev = NULL;
    }

    free(temp);
    return value;
}

int deQueuerear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Or any other value that indicates an error
    }

    Node *temp = q->rear;
    int value = temp->val;
    
    q->rear = q->rear->prev;
    if (q->rear == NULL) {
        q->front = NULL; // Queue is now empty
    } else {
        q->rear->next = NULL;
    }

    free(temp);
    return value;
}
void printQueue(Queue *q){
     Node *current=q->front;
	 printf("coada este:");
	 while(current!=NULL){
		printf("%d ",current->val);
		current=current->next;
	 }
	 printf("\n");
}