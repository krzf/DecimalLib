#include "../decimal.h"

bool get_sign(decimal dec) { return (1 << 31) & dec.bits[3]; }

void clear_decimal(decimal *dec) {
  dec->bits[0] = 0;
  dec->bits[1] = 0;
  dec->bits[2] = 0;
  dec->bits[3] = 0;
}

void set_sign(decimal *dec, bool isNeg) {
  if (isNeg)
    dec->bits[3] |= (1 << 31);
  else
    dec->bits[3] &= ~(1 << 31);
}

unsigned char get_exp(decimal dec) {
  unsigned char result = 0;
  int cBit = 0;
  for (int bit = 16; bit < 16 + 8; ++bit) {
    bool b = (1 << bit) & dec.bits[3];

    if (b)
      result |= (1 << cBit);
    else
      result &= ~(1 << cBit);

    cBit++;
  }
  return result;
}
void set_exp(decimal *dec, unsigned char exp) {
  int cBit = 0;
  for (int bit = 16; bit < 16 + 8; ++bit) {
    bool b = (1 << cBit) & exp;
    cBit++;

    if (b)
      dec->bits[3] |= (1 << bit);
    else
      dec->bits[3] &= ~(1 << bit);
  }
}
//
void abs_decimal(decimal *dec) { set_sign(dec, false); }

//

int copy_to_buffer(decimal value, decimal *dest) {
  dest->bits[0] = value.bits[0];
  dest->bits[1] = value.bits[1];
  dest->bits[2] = value.bits[2];
  dest->bits[3] = value.bits[3];
  return 0;
}

int left_shift(decimal *value) {
  decimal result;
  clear_decimal(&result);
  int lastBit = 0;
  int bit;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      bit = int_get_bit(*value, i, j);
      if (lastBit == 1) {
        int_set_bit(&result, i, j);
      }
      lastBit = bit;
    }
  }
  value->bits[0] = result.bits[0];
  value->bits[1] = result.bits[1];
  value->bits[2] = result.bits[2];
  return lastBit;
}

int decimal_pow(decimal *value, int n) {
  decimal result;
  decimal ten;
  from_float_to_decimal(10, &ten);
  clear_decimal(&result);
  for (int i = 0; i < n; i++) {
    mul(*value, ten, &result);
    copy_to_buffer(result, value);
  }

  return 0;
}

int int_set_bit(decimal *value, int n, int byteNum) {
  value->bits[byteNum] |= 1UL << n;
  return 0;
}

int int_get_bit(decimal value, int n, int byteNum) {
  int mask = 1 << n;
  return abs((value.bits[byteNum] & mask) >> n);
}

int get_bit(decimal num, int pos) {
  int result = (num.bits[pos / 32] >> (pos % 32)) & 1;
  return result;
}

////okok?

decimal machine_div_rem(decimal value_1, decimal value_2,
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

    /**
     * Вдвигаем старший бит делимого в остаток
     */
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
      /**
       * В результат пишем только единицы т.к там только нули
       */
      result->bits[sec_res] |= (1 << bit_res);
    }
  }

  return remainder;
}

int MyRemainder(decimal value_1, decimal value_2) {
  decimal res = {{0}};

  return machine_div_rem(value_1, value_2, &res).bits[0];
}

int get_active_bits_count(decimal value) {
  unsigned long result = 0;

  for (int sec_i = 0; sec_i < 3; ++sec_i) {
    for (unsigned long bit_i = 0; bit_i < (sizeof(int) * 8); ++bit_i) {
      bool v1 = (1 << bit_i) & value.bits[sec_i];

      if (v1) result = sec_i * (sizeof(int) * 8) + bit_i;
    }
  }

  return (int)result;
}

//
