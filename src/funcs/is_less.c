#include "../decimal.h"

int is_less(decimal value_1, decimal value_2) {
  bool result = false;

  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0 &&
      value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
    return result;

  unsigned char exp_val_1 = get_exp(value_1);
  unsigned char exp_val_2 = get_exp(value_2);

  if (exp_val_1 != exp_val_2) {
    /**
     * Приводим число с меньшей экспонентой к нужному виду путем умножения
     */
    decimal val_mul = {{10}};

    if (exp_val_1 > exp_val_2) {
      for (int i = 0; i < exp_val_1 - exp_val_2; ++i) {
        int code = mul(value_2, val_mul, &value_2);

        if (code == INF)
          return true;
        else if (code == NEGATIVE_INF)
          return false;
      }
      set_exp(&value_2, exp_val_1);
    } else {
      for (int i = 0; i < exp_val_2 - exp_val_1; ++i) {
        int code = mul(value_1, val_mul, &value_1);

        if (code == INF)
          return false;
        else if (code == NEGATIVE_INF)
          return true;
      }
      set_exp(&value_1, exp_val_2);
    }
  }

  bool sign_bit_val_1 = get_sign(value_1);
  bool sign_bit_val_2 = get_sign(value_2);

  if (sign_bit_val_1 == sign_bit_val_2 && is_equal(value_1, value_2)) {
    result = false;
  } else if (sign_bit_val_1 == sign_bit_val_2) {
    for (int i = 0; i < 3; ++i)
      for (unsigned long bit = 0; bit < (sizeof(int) * 8); ++bit) {
        bool v1 = (1 << bit) & value_1.bits[i];
        bool v2 = (1 << bit) & value_2.bits[i];

        if (v1 && !v2)
          result = false;
        else if (!v1 && v2)
          result = true;
      }

    if (sign_bit_val_1) {
      result = !result;
    }
  } else {
    result = sign_bit_val_1;
  }

  return result;
}
