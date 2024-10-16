#include "dummy_module.h"

static int counter = 0;

int increment_counter(void) { return ++counter; }
