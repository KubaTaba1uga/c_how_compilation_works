#include <stdio.h>

static void print_message(void);

static int counter = 0;

void print_counter(void) {
  print_message();

  counter++;

  printf("counter = %d\n", counter);
}

void print_message(void) { printf("Hello from example 1 dep: "); };
