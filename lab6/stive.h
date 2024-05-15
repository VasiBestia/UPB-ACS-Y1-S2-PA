#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Values {
  int x, y, z;
} Values;

typedef struct Node {
  Values val;
  struct Node* next;
} Node;

int isEmpty(Node*);
void deleteStack(Node**);
Values pop(Node**);
void push(Node**, Values);
Values top(Node*);
void printStack(Node*);