#include "caller_module.h"
#include "../dummy_module/dummy_module.h"

// Funkcja wywołująca inkrementację licznika w dummy_module
int call_increment(void) { return increment_counter(); }
