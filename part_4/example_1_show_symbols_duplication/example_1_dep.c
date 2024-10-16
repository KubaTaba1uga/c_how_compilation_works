#include <stdio.h>

void print_message(void);

int counter = 0;

void print_counter(void) {
  print_message();

  counter++;

  printf("counter = %d\n", counter);
}

void print_message(void) { printf("Hello from example_1_dep.c: "); };
