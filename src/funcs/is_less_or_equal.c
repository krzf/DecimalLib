#include "../decimal.h"

int is_less_or_equal(decimal a, decimal b) {
  int res = 0;
  if (!is_greater(a, b)) {
    res = 1;
  }
  return res;
}