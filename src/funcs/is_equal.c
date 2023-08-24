#include "../decimal.h"

int is_equal(decimal value_1, decimal value_2) {
  bool result = true;

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
      for (int i = 0; i < exp_val_1 - exp_val_2; ++i)
        mul(value_2, val_mul, &value_2);
      set_exp(&value_2, exp_val_1);
    } else {
      for (int i = 0; i < exp_val_2 - exp_val_1; ++i)
        mul(value_1, val_mul, &value_1);
      set_exp(&value_1, exp_val_2);
    }
  }

  bool sign_bit_val_1 = get_sign(value_1);
  bool sign_bit_val_2 = get_sign(value_2);

  if (sign_bit_val_1 == sign_bit_val_2) {
    for (int i = 0; i < 3; ++i)
      for (unsigned long bit = 0; bit < (sizeof(int) * 8); ++bit) {
        bool v1 = (1 << bit) & value_1.bits[i];
        bool v2 = (1 << bit) & value_2.bits[i];

        if (v1 != v2) result = false;
      }
  } else {
    result = false;
  }

  return result;
}
