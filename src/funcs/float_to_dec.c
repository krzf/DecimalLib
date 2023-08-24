#include "../decimal.h"

int from_float_to_decimal(float src, decimal *dst) {
  int error = OK;
  clear_decimal(dst);
  if (fabs(src) < MIN_VAL)
    error = CONVERT_ERROR;
  else if (src == 0)
    error = OK;
  else if (src > MAX_VAL || src == +INFINITY || src == -INFINITY || isnan(src))
    error = CONVERT_ERROR;
  else {
    float_to_dec_parse(src, dst);
    zero_trunc(dst);
    set_sign(dst, (src < 0) ? 1 : 0);
  }
  return error;
}

void zero_trunc(decimal *dst) {
  int exp = get_exp(*dst);
  for (; exp > 0 && dst->bits[0] % 10 == 0; exp--) dst->bits[0] /= 10;
  set_exp(dst, exp);
}

void float_to_dec_parse(float src, decimal *dst) {
  char str[25];
  sprintf(str, "%e", src);

  int interger_result = 0, fraction_result = 0, i = 0, dot_check = 0,
      exp_check = 0, exp = 0;
  int exp_sign = 1;

  if (str[i] == '-') {
    set_sign(dst, 1);
    i++;
  } else if (str[i] == '+')
    i++;

  if (is_digit(str[i]) || str[i] == '.') {
    while (is_gef_valid(str[i])) {
      if (str[i] == '.' && !dot_check) {
        dot_check++;
        i++;
      }
      if ((str[i] == 'e') && !exp_check) {
        exp_check++;
        i++;
        if (str[i] == '-') {
          exp_sign = -1;
          i++;
        } else if (str[i] == '+')
          i++;
      }
      if (!dot_check && !exp_check)
        interger_result = interger_result * 10 + (str[i] - '0');
      else if (dot_check && !exp_check)
        fraction_result = fraction_result * 10 + (str[i] - '0');
      else if (exp_check && (fraction_result || interger_result))
        exp = exp * 10 + (str[i] - '0');
      i++;
    }
  }
  interger_result = (interger_result * 1000000 + fraction_result);
  exp = 6 + -exp * exp_sign;
  for (; exp < 0; exp++) interger_result *= 10;

  dst->bits[0] = interger_result;
  set_exp(dst, exp);
}
