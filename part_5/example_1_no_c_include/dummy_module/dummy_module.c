#include <re.h>

#include <baresip.h>

#include "dummy_module.h"

static int counter = 0;

int increment_counter(void) { return ++counter; }

static int module_init(void) { return 0; }

static int module_close(void) { return 0; }

const struct mod_export DECL_EXPORTS(dummy_module) = {
    "dummy_module", "application", module_init, module_close};
