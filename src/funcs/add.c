#include "../decimal.h"

int MyAdd(decimal value_1, decimal value_2, decimal *result) {
  int res = OK;
  clear_decimal(result);

  bool sign_bit_val_1 = get_sign(value_1);
  bool sign_bit_val_2 = get_sign(value_2);

  if (sign_bit_val_1 != sign_bit_val_2) {
    abs_decimal(&value_1);
    abs_decimal(&value_2);

    if (is_equal(value_1, value_2))
      clear_decimal(result);
    else if (is_greater(value_1, value_2)) {
      res = MySub(value_1, value_2, result);
      set_sign(result, sign_bit_val_1);
    } else if (is_greater(value_2, value_1)) {
      res = MySub(value_2, value_1, result);
      set_sign(result, sign_bit_val_2);
    }
    return res;
  } else {
    set_sign(result, sign_bit_val_2);

    if (sign_bit_val_2)
      res = NEGATIVE_INF;
    else
      res = INF;
  }

  unsigned char exp_val_1 = get_exp(value_1);
  unsigned char exp_val_2 = get_exp(value_2);

  if (exp_val_1 != exp_val_2) {
    // view

    decimal val_mul = {{10}};

    if (exp_val_1 > exp_val_2) {
      set_exp(result, exp_val_1);

      for (int i = 0; i < exp_val_1 - exp_val_2; ++i)
        if (mul(value_2, val_mul, &value_2) != 0) {
          clear_decimal(result);
          return res;
        }

      set_exp(&value_2, exp_val_1);
    } else {
      set_exp(result, exp_val_2);

      for (int i = 0; i < exp_val_2 - exp_val_1; ++i)
        if (mul(value_1, val_mul, &value_1)) {
          clear_decimal(result);
          return res;
        }

      set_exp(&value_1, exp_val_2);
    }
  } else {
    set_exp(result, exp_val_2);
  }

  int remainder = 0;  /// divis

  for (int i = 0; i < 3; ++i) {
    for (unsigned long bit = 0; bit < (sizeof(int) * 8); ++bit) {
      bool v1 = (1 << bit) & value_1.bits[i];
      bool v2 = (1 << bit) & value_2.bits[i];

      int newValue = remainder;
      remainder = 0;

      if (v1) newValue++;

      if (v2) newValue++;

      if (newValue == 0) {
        result->bits[i] &= ~(1 << bit);

      } else if (newValue == 1) {
        result->bits[i] |= (1 << bit);
      } else if (newValue == 2) {
        remainder = 1;
        result->bits[i] &= ~(1 << bit);
      } else if (newValue == 3) {
        remainder = 1;
        result->bits[i] |= (1 << bit);
      }
    }
  }

  if (remainder == 0) {
    res = OK;
  } else {
    clear_decimal(result);
  }

  return res;
}