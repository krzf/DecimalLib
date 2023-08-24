#include "../decimal.h"

decimal machine_div(decimal value_1, decimal value_2,
                        decimal *result);

int handle_exp(decimal *value_1, decimal *value_2);

bool handle_sign(decimal *value_1, decimal *value_2);

void perform_division(decimal value_1, decimal value_2,
                      decimal *result, int *exp_result);

int MyDiv(decimal value_1, decimal value_2, decimal *result) {
  int stateCode = OK;
  clear_decimal(result);

  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0)
    return stateCode;
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
    return DivisionByZero;

  bool isNegative = handle_sign(&value_1, &value_2);
  int exp_result = handle_exp(&value_1, &value_2);
  perform_division(value_1, value_2, result, &exp_result);

  set_sign(result, isNegative);
  set_exp(result, exp_result);

  return stateCode;
}

void perform_division(decimal value_1, decimal value_2,
                      decimal *result, int *exp_result) {
  decimal zero = {{0}};
  decimal new_result = {{0}};
  decimal div_result = {{0}};
  decimal remainder;
  decimal val_mul = {{10}};
  bool isRemainder = true;

  while (isRemainder) {
    clear_decimal(&div_result);
    remainder = machine_div(value_1, value_2, &div_result);

    if (MyAdd(*result, div_result, &new_result) != OK) break;
    result->bits[0] = new_result.bits[0];
    result->bits[1] = new_result.bits[1];
    result->bits[2] = new_result.bits[2];

    if (is_equal(remainder, zero)) {
      isRemainder = false;
    } else {
      mul(*result, val_mul, result);

      value_1 = remainder;
      mul(value_1, val_mul, &value_1);
      (*exp_result)++;
    }
  }
}

int handle_exp(decimal *value_1, decimal *value_2) {
  unsigned char exp_val_1 = get_exp(*value_1);
  unsigned char exp_val_2 = get_exp(*value_2);
  decimal val_mul = {{10}};
  unsigned char exp_result = 0;

  if (exp_val_1 > exp_val_2) {
    if (exp_val_2 == 0)
      exp_result = exp_val_1;
    else
      exp_result = exp_val_1 - exp_val_2;

    for (int i = 0; i < exp_val_1; ++i) mul(*value_1, val_mul, value_1);
    set_exp(value_1, 0);

    for (int i = 0; i < exp_val_1; ++i) mul(*value_2, val_mul, value_2);
    set_exp(value_2, 0);
  } else if (exp_val_2 > exp_val_1) {
    exp_result = 0;

    for (int i = 0; i < exp_val_2; ++i) mul(*value_1, val_mul, value_1);
    set_exp(value_1, 0);

    for (int i = 0; i < exp_val_1; ++i) mul(*value_2, val_mul, value_2);
    set_exp(value_2, 0);
  }

  return exp_result;
}

bool handle_sign(decimal *value_1, decimal *value_2) {
  bool isNegative = false;

  if (get_sign(*value_1) != get_sign(*value_2)) isNegative = true;

  set_sign(value_1, false);
  set_sign(value_2, false);

  return isNegative;
}

decimal machine_div(decimal value_1, decimal value_2,
                        decimal *result) {
  decimal zero = {{0}};

  decimal remainder = {{0}};
  decimal next_remainder = {{0}};

  int activeBits = get_active_bits_count(value_1);

  for (int i = activeBits, j = 0; i > -1; i--, j++) {
    unsigned long sec_res = i / (sizeof(int) * 8),
                  bit_res = i % (sizeof(int) * 8);

    unsigned long sec_div = i / (sizeof(int) * 8),
                  bit_div = i % (sizeof(int) * 8);

    bool v_div = (1 << bit_div) & value_1.bits[sec_div];

    // старший бит делимого в остаток

    bool r1 = (1 << 31) & remainder.bits[0];
    bool r2 = (1 << 31) & remainder.bits[1];

    remainder.bits[0] = remainder.bits[0] << 1;
    if (v_div)
      remainder.bits[0] |= (1 << 0);  // 1
    else
      remainder.bits[0] &= ~(1 << 0);  // 0

    remainder.bits[1] = remainder.bits[1] << 1;
    if (r1)
      remainder.bits[1] |= (1 << 0);  // 1
    else
      remainder.bits[1] &= ~(1 << 0);  // 0

    remainder.bits[2] = remainder.bits[2] << 1;
    if (r2)
      remainder.bits[2] |= (1 << 0);  // 1
    else
      remainder.bits[2] &= ~(1 << 0);  // 0

    MySub(remainder, value_2, &next_remainder);

    if (is_greater_or_equal(next_remainder, zero)) {
      remainder = next_remainder;

      result->bits[sec_res] |= (1 << bit_res);
    }
  }

  return remainder;
}
