#include "../decimal.h"

int MyRound(decimal value, decimal *result) {
  decimal zero = {{0}};

  if (is_equal(value, zero)) {
    clear_decimal(result);
    return OK;
  }

  int value_exp = get_exp(value);
  if (value_exp == 0) {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[3];
    return OK;
  }
  clear_decimal(result);
  if (value_exp > 28) {
    return 1;
  }

  set_exp(&value, 0);
  bool isNegaitve = get_sign(value);
  set_sign(&value, false);

  decimal val_div = {{10}};
  int numbers[100] = {};
  int count_numbers = 0;

  while (is_not_equal(value, zero)) {
    numbers[count_numbers] = MyRemainder(value, val_div);

    if (numbers[count_numbers] == 0) {
      MyDiv(value, val_div, &value);
    } else {
      decimal val_sub = {{numbers[count_numbers]}};
      MySub(value, val_sub, &value);
      MyDiv(value, val_div, &value);
    }

    count_numbers++;
  }

  if (count_numbers > value_exp) {
    decimal val_mul = {{10}};

    for (int i = count_numbers - 1; i > value_exp - 1; i--) {
      if (i < count_numbers - 1) mul(*result, val_mul, result);
      decimal val_add = {{numbers[i]}};
      MyAdd(*result, val_add, result);
    }
  }

  int round_res = 0;

  for (int i = 0; i < value_exp; i++) {
    numbers[i] += round_res;

    round_res = 0;
    if (numbers[i] > 4) round_res = 1;
  }

  decimal val_add = {{round_res}};
  MyAdd(*result, val_add, result);

  set_sign(result, isNegaitve);

  return OK;
}