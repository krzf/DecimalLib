#include "../decimal.h"

int MySub(decimal value_1, decimal value_2, decimal *result) {
  int res = OK;
  clear_decimal(result);

  bool sign_bit_val_1 = get_sign(value_1);
  bool sign_bit_val_2 = get_sign(value_2);

  if (!sign_bit_val_1 && sign_bit_val_2) {
    abs_decimal(&value_2);
    res = MyAdd(value_1, value_2, result);
    return res;
  } else if (sign_bit_val_1 && sign_bit_val_2) {
    abs_decimal(&value_1);
    abs_decimal(&value_2);

    if (is_equal(value_1, value_2))
      clear_decimal(result);
    else if (is_greater(value_1, value_2)) {
      res = MySub(value_1, value_2, result);
      set_sign(result, true);
    } else if (is_greater(value_2, value_1)) {
      res = MySub(value_2, value_1, result);
      set_sign(result, false);
    }

    return res;
  }

  unsigned char exp_val_1 = get_exp(value_1);
  unsigned char exp_val_2 = get_exp(value_2);

  if (exp_val_1 != exp_val_2) {
    decimal val_mul = {{10}};

    if (exp_val_1 > exp_val_2) {
      for (int i = 0; i < exp_val_1 - exp_val_2; ++i)
        mul(value_2, val_mul, &value_2);

      set_exp(result, exp_val_1);
      set_exp(&value_2, exp_val_1);
    } else {
      for (int i = 0; i < exp_val_2 - exp_val_1; ++i)
        mul(value_1, val_mul, &value_1);

      set_exp(result, exp_val_2);
      set_exp(&value_1, exp_val_2);
    }
  } else {
    set_exp(result, exp_val_2);
  }

  if (is_equal(value_1, value_2)) {
    clear_decimal(result);
    return res;
  } else if (is_greater(value_2, value_1)) {
    // вычесть из вычитаемого уменьшаемого и вернуть результат отрицательным

    res = MySub(value_2, value_1, result);

    if (res == 1)
      res = 2;
    else
      set_sign(result, true);

    return res;
  }

  bool duty = false;
  for (int i = 0; i < 3; ++i) {
    for (unsigned long bit = 0; bit < (sizeof(int) * 8); ++bit) {
      bool v1 = (1 << bit) & value_1.bits[i];
      bool v2 = (1 << bit) & value_2.bits[i];

      if (duty) {
        if (v1) duty = false;

        v1 = !v1;
      }

      if (v1 && v2) {  /// 1 - 1 = 0
        result->bits[i] &= ~(1 << bit);
      } else if (v1 && !v2) {  /// 1 - 0 = 1
        result->bits[i] |= (1 << bit);
      } else if (!v1 && !v2) {  /// 0 - 0 = 0
        result->bits[i] &= ~(1 << bit);
      } else if (!v1 && v2) {  /// 10 - 1 = 1

        duty = true;
        result->bits[i] |= (1 << bit);
      }
    }
  }

  return res;
}
