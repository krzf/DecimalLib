#include "../decimal.h"

int from_int_to_decimal(int src, decimal *dst) {
  clear_decimal(dst);
  int error = OK;
  if (src > INT_MAX || src < INT_MIN)
    error = CONVERT_ERROR;
  else {
    if (src < 0) {
      set_sign(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;
  }
  return error;
}
