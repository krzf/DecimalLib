#include "../decimal.h"

int mul(decimal value_1, decimal value_2, decimal *result) {
  int res = OK;
  clear_decimal(result);
  // if 0 then 0
  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0)
    return res;
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
    return res;

  int sign_bit_val_1 = get_sign(value_1);
  int sign_bit_val_2 = get_sign(value_2);

  //
  if (sign_bit_val_1 != sign_bit_val_2) {
    set_sign(result, true);
    res = NEGATIVE_INF;
  } else {
    set_sign(result, false);
    res = INF;
  }

  set_exp(result, get_exp(value_1) + get_exp(value_2));

  int remainder = 0;  /// остаток

  bool overHead = false;

  for (int sec_i = 0; sec_i < 3; ++sec_i) {
    for (unsigned long bit_i = 0; bit_i < (sizeof(int) * 8); ++bit_i) {
      bool v1 = (1 << bit_i) & value_1.bits[sec_i];

      unsigned long idx_res, sec_res, bit_res;

      for (int sec_j = 0; sec_j < 3; ++sec_j) {
        for (unsigned long bit_j = 0; bit_j < (sizeof(int) * 8); ++bit_j) {
          bool v2 = (1 << bit_j) & value_2.bits[sec_j];

          idx_res = ((sizeof(int) * 8) * sec_j) + ((sizeof(int) * 8) * sec_i) +
                    bit_j + bit_i,
          sec_res = idx_res / (sizeof(int) * 8),
          bit_res = idx_res % (sizeof(int) * 8);

          int newValue = remainder;
          remainder = 0;

          if (v1 && v2) newValue++;

          if (idx_res > ((sizeof(int) * 8 * 3) - 1)) {
            if (newValue > 0) remainder = 1;
            overHead = true;
            break;
          }

          if ((1 << bit_res) & result->bits[sec_res]) newValue++;

          if (newValue == 0) {
            result->bits[sec_res] &= ~(1 << bit_res);  // 0
          } else if (newValue == 1) {
            result->bits[sec_res] |= (1 << bit_res);  // 1
          } else if (newValue == 2) {
            remainder = 1;
            result->bits[sec_res] &= ~(1 << bit_res);  // 0
          } else if (newValue == 3) {
            remainder = 1;
            result->bits[sec_res] |= (1 << bit_res);  // 1
          }
        }
        if (overHead) {
          overHead = false;
          break;
        }
      }

      if (remainder == 1) break;
    }
  }

  if (remainder == 0) {
    res = OK;
  } else {
    clear_decimal(result);
  }

  return res;
}
