#include "stive.h"

int main() {
  Node* Stack;
  push(&Stack, 1);
  push(&Stack, 2);
  push(&Stack, 3);

  printStack(Stack);

  printf("%d", pop(&Stack));
  return 0;
}