#include "stive.h"

int tak(int x, int y, int z) {
  if (y < x) {
    printf(
        "x=%d, y=%d, z=%d, tak(tak(%d, %d, %d), tak(%d, %d, %d), tak(%d, %d, "
        "%d))\n",
        x, y, z, x - 1, y, z, y - 1, z, x, z - 1, x, y);
    return tak(tak(x - 1, y, z), tak(y - 1, z, x), tak(z - 1, x, y));
  } else
    return y;
}

int main() {
  Values input;
  // scanf("%d%d%d", &input.x, &input.y, &input.z);
  input.x = 5, input.y = 1, input.z = 1;

  Node* stack = NULL;
  push(&stack, input);

  int res = INT_MIN;

  while (!isEmpty(stack)) {
    Values current = pop(&stack);

    int a = current.x;
    int b = current.y;
    int c = current.z;

    if (b < a) {
      Values triple1 = {a - 1, b, c};
      Values triple2 = {b - 1, c, a};
      Values triple3 = {c - 1, a, b};

      push(&stack, triple3);
      push(&stack, triple2);
      push(&stack, triple1);
    } else {
      res = b;
    }
  }

  return 0;
}