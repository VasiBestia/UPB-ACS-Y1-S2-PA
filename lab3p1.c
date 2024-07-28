#include <stdio.h>

void f4(int* x) {
  (*x)++;
  printf("F4 OUTPUT: %d at address %p\n", *x, x);
}

void f3(int x) {
  x++;
  f4(&x);
  printf("F3 OUTPUT: %d at address %p\n", x, &x);
}

void f2(int x) {
  x++;
  f3(x);
  printf("F2 OUTPUT: %d at address %p\n", x, &x);
}

void f1(int* x) {
  (*x)++;
  f2(*x);
  printf("F1 OUTPUT: %d at address %p\n", *x, x);
}

int main() {
  int x = 0;  // INIT X = 0
  printf("Before running all functions: %d at adress %p\n", x, &x);
  x++;
  printf("After running x++: %d at address %p\n", x, &x);

  f1(&x);

  printf("After running all functions: %d at address %p\n", x, &x);

  return 0;
}