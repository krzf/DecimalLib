#include "../decimal.h"

int negate(decimal value, decimal *result) {
  decimal zero = {{0}};
  clear_decimal(result);

  if (is_equal(value, zero)) return OK;

  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  result->bits[3] = value.bits[3];

  set_sign(result, !get_sign(value));

  return OK;
}