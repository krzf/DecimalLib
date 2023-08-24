#include "../decimal.h"

int from_decimal_to_float(decimal src, float *dst) {
  int error = 0;
  double value = 0;
  int scale = get_exp(src);
  for (int i = 0; i < 96; i++) {
    value += get_bit(src, i) * pow(2, i);
  }
  if (scale >= 0 && scale <= 28) {
    value /= pow(10, scale);
    if (value < MIN_VAL) {
      error = CONVERT_ERROR;
      *dst = 0;
    } else if (value > FLT_MAX)
      error = CONVERT_ERROR;
    else {
      *dst = value;
      if (get_sign(src)) *dst *= -1;
    }
  } else {
    error = CONVERT_ERROR;
    *dst = 0;
  }
  return error;
}