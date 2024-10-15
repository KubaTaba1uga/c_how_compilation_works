#include "example_1_dep.h"
#include <stdio.h>

#define PI 3.14159

static const char msg[] = "The value of pi is approximately";

void print_pi(void) { printf("%s %f\n", msg, PI); }
