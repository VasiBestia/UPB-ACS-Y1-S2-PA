#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node* next;
} Node;

int isEmpty(Node*);
void deleteStack(Node**);
int pop(Node**);
void push(Node**, int);
int top(Node*);
void printStack(Node*);