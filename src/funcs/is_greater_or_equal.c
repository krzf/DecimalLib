#include "../decimal.h"

int is_greater_or_equal(decimal value_1, decimal value_2) {
  bool result = false;

  if (is_equal(value_1, value_2)) {
    result = true;
  } else if (is_greater(value_1, value_2)) {
    result = true;
  }

  return result;
}