#include "../decimal.h"

int from_decimal_to_int(decimal src, int *dst) {
  int error = 0;
  decimal temp;
  int exp = get_exp(src);
  int sign = get_sign(src);
  truncate(src, &temp);

  if (temp.bits[1] || temp.bits[2])
    error = CONVERT_ERROR;
  else if (temp.bits[0] == INT_MIN && !sign)
    error = CONVERT_ERROR;
  else if (exp < 0 || exp > 28)
    error = CONVERT_ERROR;
  else
    *dst = temp.bits[0] * pow(-1, sign);

  return error;
}
