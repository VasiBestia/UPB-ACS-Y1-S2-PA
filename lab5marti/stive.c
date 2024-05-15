#include "stive.h"

int isEmpty(Node* top) {
  return top == NULL;
}

void deleteStack(Node** top) {
  Node* temp;
  while ((*top) != NULL) {  // !isEmpty(*top)
    temp = *top;
    *top = (*top)->next;
    free(temp);
  }
}

int pop(Node** top) {
  if (isEmpty(*top))
    return INT_MIN;
  Node* temp = (*top);
  int aux = temp->val;
  *top = (*top)->next;
  free(temp);
  return aux;
}

void push(Node** top, int v) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->val = v;
  newNode->next = *top;
  *top = newNode;
}

int top(Node* top) {
  if (isEmpty(top))
    return INT_MIN;
  return top->val;
}

void printStack(Node* stack) {
  while (!isEmpty(stack))
    printf("%d ", pop(&stack));
}
