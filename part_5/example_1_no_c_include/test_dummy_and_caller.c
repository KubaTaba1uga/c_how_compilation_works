#include <string.h>

#include <re.h>

#include <baresip.h>

#include "../modules/dummy_module/dummy_module.h"

#include "test.h"

int test_dummy_and_caller(void) {
  int result;
  int err = 0;

  err = module_preload("dummy_module");

  TEST_ERR(err);

  result = increment_counter();

  ASSERT_EQ(result, 1);

out:
  return err;
}
