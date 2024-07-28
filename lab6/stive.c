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

Values pop(Node** top) {
  Values isEmptyVal;
  isEmptyVal.x = INT_MIN;
  isEmptyVal.y = INT_MIN;
  isEmptyVal.z = INT_MIN;

  if (isEmpty(*top))
    return isEmptyVal;
  Node* temp = (*top);
  Values aux = temp->val;
  *top = (*top)->next;
  free(temp);
  return aux;
}

void push(Node** top, Values v) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->val = v;
  newNode->next = *top;
  *top = newNode;
}

Values top(Node* top) {
  Values isEmptyVal;
  isEmptyVal.x = INT_MIN;
  isEmptyVal.y = INT_MIN;
  isEmptyVal.z = INT_MIN;

  if (isEmpty(top))
    return isEmptyVal;
  return top->val;
}

void printStack(Node* stack) {
  while (!isEmpty(stack)) {
    Values aux = pop(&stack);
    printf("%d %d %d\n", aux.x, aux.y, aux.z);
  }
}
