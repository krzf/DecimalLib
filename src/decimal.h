#ifndef DECIMAL
#define DECIMAL

#include <float.h>
#include <limits.h>
#include <stdint.h>

#include "stdbool.h"
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
#define OK 0
#define INF 1
#define NEGATIVE_INF 2
#define DivisionByZero 3
#define TOO_LARGE_OR_INF 1
#define CONVERT_ERROR 1

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')

#define is_gef_valid(ch) \
  (is_digit(ch) || (ch) == '.' || (ch) == 'e' || (ch) == '+' || (ch) == '-')

// maxmin
#define MAX_VAL pow(2, 96)
#define MIN_VAL 1e-28

//
#define POSITIVE_INFINITY ((decimal){{0, 255, 0, 0}})
#define NEGATIVE_INFINITY ((decimal){{1, 255, 0, 0}})
// #define NAN ((decimal){{0, 0, 0xFF, 0x800000}})
#define DIV_BY_ZERO 3

typedef struct {
  int bits[4];  // unsigned int???
} decimal;

typedef struct {
  int exponent;
  int sign;
} info;

// arithmetic
int MyAdd(decimal value_1, decimal value_2, decimal *result);
int MySub(decimal value_1, decimal value_2, decimal *result);
int mul(decimal value_1, decimal value_2, decimal *result);
int MyDiv(decimal value_1, decimal value_2, decimal *result);
// help
void clear_decimal(decimal *dec);  // очищает bits decimal
bool get_sign(decimal dst);
void set_sign(decimal *dec, bool isNeg);
void abs_decimal(decimal *dec);
void set_exp(decimal *dec, unsigned char exp);
unsigned char get_exp(decimal dec);
int copy_to_buffer(decimal value, decimal *dest);
int left_shift(decimal *value);
int decimal_pow(decimal *value, int n);
// int is_zero(decimal a,decimal b );
int int_get_bit(decimal value, int n, int byteNum); 
int int_set_bit(decimal *value, int n, int byteNum); 

//
int MyRemainder(decimal value_1, decimal value_2);
decimal machine_div_rem(decimal value_1, decimal value_2,
                            decimal *result);
int get_active_bits_count(decimal value);

// ed sravn
int is_equal(decimal a, decimal b);
int is_greater(decimal a, decimal b);
int is_less(decimal a, decimal b);
int is_greater_or_equal(decimal a, decimal b);
int is_less_or_equal(decimal a, decimal b);
int is_not_equal(decimal a, decimal b);

// mangorra convert
int from_float_to_decimal(float src, decimal *dst);
int from_int_to_decimal(int src, decimal *dst);
int from_decimal_to_float(decimal src, float *dst);
int from_decimal_to_int(decimal src, int *dst);
void zero_trunc(decimal *dst);
void float_to_dec_parse(float src, decimal *dst);

// void get_exp(info *bits, decimal *src);
// int is_less_abs(decimal value_1, decimal value_2);
int get_bit(decimal num, int pos);
void set_bit(decimal *val, int bit, int pos);
int get_bit_nums(unsigned int num, int pos);
void set_bit_nums(unsigned int *val, int bit, int pos);

// enum {low, mid, top, scale};
// int equal_exp(unsigned exp1, unsigned exp2, decimal *value_1, decimal
// *value_2); void set_exp(decimal *result, int exp); int mul10(decimal*
// value_1, int exp); int mod(decimal value_1, decimal value_2,
// decimal *result); void set_info(decimal *result, int sign, int exp);
// bool has_trailing_zeros(decimal value);

// additional Yeg
int MyRound(decimal value, decimal *result);
int truncate(decimal value, decimal *result);
int negate(decimal value, decimal *result);
int MyFloor(decimal value, decimal *result);
#endif  // DECIMAL