#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define WHITE "\x1B[0m"
#include "decimal.h"

#define EXPONENT_PLUS_28 1835008
#define EXPONENT_PLUS_1 65536
#define EXPONENT_PLUS_2 196608

START_TEST(mul_0) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res;
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  decimal val1 = {{8, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(1, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(2, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_10) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(1, mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{0, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, mul(val1, val2, &res));
}
END_TEST

Suite *test_mul(void) {
  Suite *s = suite_create("mul");
  TCase *tc = tcase_create("mul");

  tcase_add_test(tc, mul_0);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);
  tcase_add_test(tc, mul_11);

  suite_add_tcase(s, tc);
  return s;
}
// SUB
START_TEST(sub_0) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res;
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  decimal val1 = {{8, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_5) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_6) {
  decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_7) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_8) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_9) {
  decimal val1 = {{8, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_10) {
  decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_11) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{4, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(2, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_12) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal val2 = {{4, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_13) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_14) {
  decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(2, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_15) {
  decimal val1 = {{4, 0, 0, 0}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_16) {
  decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_17) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(1, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_18) {
  decimal val1 = {{4, 0, 0, 0}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(1, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_19) {
  decimal val1 = {{4, 0, 0, 0}};
  decimal val2 = {{4, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MySub(val1, val2, &res));
}
END_TEST

START_TEST(sub_22) {
  decimal value_1 = {{13, 0, 0, 0}};
  set_exp(&value_1, 1);
  set_sign(&value_1, 1);

  decimal value_2 = {{286, 0, 0, 0}};
  set_exp(&value_2, 2);
  set_sign(&value_2, 1);

  decimal result = {0};
  decimal check = {{156, 0, 0, 0}};
  set_exp(&check, 2);

  int return_value = MySub(value_1, value_2, &result);

  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// START_TEST(sub_23) {
//   decimal value_1 = {{13, 0, 0, 0}};
//   set_exp(&value_1, 1);
//   set_sign(&value_1, 1);
//   decimal value_2 = {{286, 0, 0, 0}};
//   set_exp(&value_2, 2);
//   decimal result = {0};
//   decimal check = {{416, 0, 0, 0}};
//   set_exp(&check, 2);
//   set_sign(&check, 1);
//   int return_value = MySub(value_1, value_2, &result);
//   ck_assert_int_eq(is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

START_TEST(sub_24) {
  decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  decimal value_2 = {{2, 0, 0, 0}};
  decimal result = {0};
  decimal check = {{0, 0, 0, 0}};
  int return_value = MySub(value_1, value_2, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sub_25) {
  decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  decimal value_2 = {{2, 0, 0, 0}};
  set_sign(&value_2, 1);
  decimal result = {0};
  decimal check = {{0, 0, 0, 0}};
  int return_value = MyAdd(value_1, value_2, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

// START_TEST(sub_26) {
//   decimal value_1 = {{64071, 0, 0, 0}};
//   set_exp(&value_1, 4);
//   decimal value_2 = {{5919, 0, 0, 0}};
//   set_exp(&value_2, 1);
//   decimal result = {0};
//   decimal check = {{5854929, 0, 0, 0}};
//   set_exp(&check, 4);
//   set_sign(&check, 1);
//   int return_value = MySub(value_1, value_2, &result);
//   ck_assert_int_eq(is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

START_TEST(sub_28) {
  decimal src1 = {0}, src2 = {0};
  src1.bits[3] = 0b00000000000000010000000000000000;
  src1.bits[2] = 0;
  src1.bits[1] = 0;
  src1.bits[0] = 0b00000000000000000110011011110000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[2] = 0;
  src2.bits[1] = 0;
  src2.bits[0] = 0b00000000000001000101000111010110;
  decimal result_origin = {0};
  result_origin.bits[3] = 0b00000000000000110000000000000000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b00000000001000111110001111101010;
  decimal result_our = {0};
  MySub(src1, src2, &result_our);
  ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
}
END_TEST

START_TEST(MySubTest1) {
  // 863
  decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest2) {
  // 889
  decimal src1, src2, origin;
  // src1 = 3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest3) {
  // 915
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest4) {
  // 941
  decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest5) {
  // 967
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest6) {
  // 993
  decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest7) {
  // 1019
  decimal src1, src2, origin;
  // src1 = 6521;
  // src2 = 74121;

  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000010000100000010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest8) {
  // 1045
  decimal src1, src2, origin;
  // src1 = 4;
  // src2 = 97623323;

  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000101110100011001110100010111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest9) {
  // 1071
  decimal src1, src2, origin;
  // src1 = 65658654;
  // src2 = 5;

  src1.bits[0] = 100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 95;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 5;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest10) {
  // 1097
  decimal src1, src2, origin;
  // src1 = -364748;
  // src2 = 1;

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest11) {
  // 1123
  decimal src1, src2, origin;
  // src1 = 1;
  // src2 = 98745654321;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b11111101101100110001110000110000;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest12) {
  // 1149
  decimal src1, src2, origin;
  // src1 = -9878798789;
  // src2 = -3;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b01001100110100101000000111000010;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest13) {
  // 1175
  decimal src1, src2, origin;
  // src1 = 9999999999999999999;
  // src2 = 1;

  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b10001001111001111111111111111110;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest14) {
  // 1201
  decimal src1, src2, origin;
  // src1 = 18446744073709551615;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest15) {
  // 1227
  decimal src1, src2, origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b11000000100010111000101000100010;
  origin.bits[1] = 0b11111111111111111111111111111101;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest16) {
  // 1253
  decimal src1, src2, origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;

  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b10010100100110011101101011101101;
  origin.bits[1] = 0b11000101100100110110100101100010;
  origin.bits[2] = 0b10110000001111101111000110111100;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest18) {
  // 1305
  decimal src1, src2, origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest23) {
  // 1435
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest24) {
  // 1461
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest25) {
  // 1487
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest26) {
  // 1513
  decimal src1, src2, origin;
  // src1 = 792281625142643375935439503;
  // src2 = -1;

  src1.bits[0] = 0b00101000111101011100001010001111;
  src1.bits[1] = 0b11110101110000101000111101011100;
  src1.bits[2] = 0b00000010100011110101110000101000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b00101000111101011100001010010000;
  origin.bits[1] = 0b11110101110000101000111101011100;
  origin.bits[2] = 0b00000010100011110101110000101000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest27) {
  // 1539
  decimal src1, src2, origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;

  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest28) {
  // 1565
  decimal src1, src2, origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b11101000101010001011011101111000;
  origin.bits[1] = 0b00000000000111110100000111110001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest30) {
  // 1617
  decimal src1, src2, origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;

  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b11010010100100100111101010001100;
  origin.bits[1] = 0b10011110100111100111000100000100;
  origin.bits[2] = 0b00011111101010011000000100111000;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MySubTest33) {
  // 1695
  decimal src1, src2, origin;
  // src1 = -7922816251426433759354395033;
  // src2 = 1;

  src1.bits[0] = 0b10011001100110011001100110011001;
  src1.bits[1] = 0b10011001100110011001100110011001;
  src1.bits[2] = 0b00011001100110011001100110011001;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MySub(src1, src2, &result);

  origin.bits[0] = 0b10011001100110011001100110011010;
  origin.bits[1] = 0b10011001100110011001100110011001;
  origin.bits[2] = 0b00011001100110011001100110011001;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_test_decimal_sub_simple_0) {  // 10 -5 =5
  decimal c = {{10, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{5, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);  // Возвращаемое значение: 0 - 0 1 - 1
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_sub_simple_1) {  // 100 -5 !=5
  decimal c = {{100, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{5, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);  // Возвращаемое значение: 0 - 0 1 - 1
  ck_assert_int_eq(equal, 0);  // *
}
END_TEST

START_TEST(my_test_decimal_sub_simple_2) {  // INT_MAX -5 = 2147483642
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{2147483642, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);  // Возвращаемое значение: 0 - 0 1 - 1
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_sub_simple_3) {  // роботает только с ппервым
  // массивом - ложный результат
  decimal c = {{INT_MAX, INT_MAX, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{INT_MAX - 5, INT_MAX, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);  // Возвращаемое значение: 0 - 0 1 - 1
  ck_assert_int_eq(equal, 1);
}

START_TEST(my_test_decimal_sub_simple_7) {  // 1-(-1)=2
  decimal c = {{1, 0, 0, 0}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);  // Возвращаемое значение: 0 - 0 1 - 1
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_sub_simple_8) {  // -1-(-1)=0
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);  // Возвращаемое значение: 0 - 0 1 - 1
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_sub_simple_10) {  // 1-(-1)=2
  decimal c = {{100, 0, 0, 0}};
  decimal d = {{100, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{200, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);  // Возвращаемое значение: 0 - 0 1 - 1
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_sub_simple_11) {  // -1-(-1)=0
  decimal c = {{100, 0, 0, ~(INT_MAX)}};
  decimal d = {{100, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MySub(c, d, p_res);
  ck_assert_int_eq(add, 0);
}
END_TEST

START_TEST(MySub_max_32) {
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  MySub(src1, src2, &res);
  ck_assert_int_eq(MySub(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(MySub_max_35) {
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  ck_assert_int_eq(MySub(src1, src2, &res), 2);
}
END_TEST

Suite *test_sub(void) {
  Suite *s = suite_create("MySub");
  TCase *tc = tcase_create("sub");

  tcase_add_test(tc, sub_0);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);
  tcase_add_test(tc, sub_16);
  tcase_add_test(tc, sub_17);
  tcase_add_test(tc, sub_18);
  tcase_add_test(tc, sub_19);

  tcase_add_test(tc, sub_22);

  tcase_add_test(tc, sub_24);
  tcase_add_test(tc, sub_25);

  tcase_add_test(tc, sub_28);

  tcase_add_test(tc, MySubTest1);
  tcase_add_test(tc, MySubTest2);
  tcase_add_test(tc, MySubTest3);
  tcase_add_test(tc, MySubTest4);
  tcase_add_test(tc, MySubTest5);
  tcase_add_test(tc, MySubTest6);
  tcase_add_test(tc, MySubTest7);
  tcase_add_test(tc, MySubTest8);
  tcase_add_test(tc, MySubTest9);
  tcase_add_test(tc, MySubTest10);
  tcase_add_test(tc, MySubTest11);
  tcase_add_test(tc, MySubTest12);
  tcase_add_test(tc, MySubTest13);
  tcase_add_test(tc, MySubTest14);
  tcase_add_test(tc, MySubTest15);
  tcase_add_test(tc, MySubTest16);
  tcase_add_test(tc, MySubTest18);
  tcase_add_test(tc, MySubTest23);
  tcase_add_test(tc, MySubTest24);
  tcase_add_test(tc, MySubTest25);
  tcase_add_test(tc, MySubTest26);
  tcase_add_test(tc, MySubTest27);
  tcase_add_test(tc, MySubTest28);

  tcase_add_test(tc, MySubTest30);

  tcase_add_test(tc, MySubTest33);

  tcase_add_test(tc, my_test_decimal_sub_simple_0);
  tcase_add_test(tc, my_test_decimal_sub_simple_1);
  tcase_add_test(tc, my_test_decimal_sub_simple_2);
  tcase_add_test(tc, my_test_decimal_sub_simple_3);

  tcase_add_test(tc, my_test_decimal_sub_simple_7);
  tcase_add_test(tc, my_test_decimal_sub_simple_8);
  tcase_add_test(tc, my_test_decimal_sub_simple_10);
  tcase_add_test(tc, my_test_decimal_sub_simple_11);

  tcase_add_test(tc, MySub_max_32);
  tcase_add_test(tc, MySub_max_35);

  suite_add_tcase(s, tc);
  return s;
}

// add

START_TEST(add_0) {
  decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  decimal val1 = {{15, 0, 0, 0}};
  decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal val2 = {{1, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(1, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(2, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
  decimal val1 = {{8, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res;
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
  decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
  decimal val1 = {{4, 0, 0, 0}};
  decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {0};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
  decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{4, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_12) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(2, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
  decimal val1 = {{4, 0, 0, 0}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
  decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_16) {
  decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(2, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_17) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  set_exp(&val1, 5);
  set_exp(&val2, 3);
  decimal res = {{0}};
  ck_assert_int_eq(1, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(add_18) {
  decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  set_exp(&val1, 5);
  set_exp(&val2, 3);
  decimal res = {{0}};
  ck_assert_int_eq(2, MyAdd(val1, val2, &res));
}
END_TEST

START_TEST(my_test_decimal_add_0) {
  decimal c = {{5, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{10, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};

  // 0 - OK 1 - число слишком велико или равно бесконечности
  // 2 - число слишком мало или равно отрицательной бесконечности
  // 3 - деление на 0
  int add = MyAdd(c, d, &res);
  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_1) {
  decimal c = {{100, 0, 0, 0}};
  decimal d = {{100, 0, 0, 0}};
  decimal etalon = {{100, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;
  // 0 - OK 1 - число слишком велико или равно бесконечности
  // 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(my_test_decimal_add_3) {
  decimal c = {{1000, 0, 0, 0}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{2000, 0, 0, 0}};
  decimal result = {{0, 0, 0, 0}};
  decimal *p_result = &result;
  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_result);
  ck_assert_int_eq(add, 0);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = is_equal(result, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_4) {
  decimal c = {{1000, 0, 0, ~(INT_MAX)}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};
  decimal result = {{0, 0, 0, 0}};
  decimal *p_result = &result;
  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_result);
  ck_assert_int_eq(add, 0);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = is_equal(result, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_5) {
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, ~(INT_MAX)}};
  decimal result = {{0, 0, 0, 0}};
  decimal *p_result = &result;
  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_result);
  ck_assert_int_eq(add, 0);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = is_equal(*p_result, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_6) {
  decimal c = {{0, 0, 0, 0}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_7) {
  decimal c = {{1, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{2, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_8) {
  decimal c = {{1000, 0, 0, 0}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{2000, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_9) {
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{INT_MAX, 0, 0, 0}};
  decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_10) {
  decimal c = {{UINT32_MAX, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 1, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_11) {
  decimal c = {{0, UINT_MAX - 1, 0, 0}};
  decimal d = {{0, 1, 0, 0}};
  decimal etalon = {{0, UINT_MAX, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_12) {
  decimal c = {{0, 0, UINT_MAX - 1, 0}};
  decimal d = {{0, 0, 1, 0}};
  decimal etalon = {{0, 0, UINT_MAX, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_13) {
  decimal c = {{0, 0, 0, ~(INT_MAX)}};
  decimal d = {{0, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_14) {
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_15) {  // -1 + (-1) = -2
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_16) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_17) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, &res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_18) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_19) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_20) {
  decimal c = {0};
  c.bits[0] = 0b11111111111111111111111111111110;
  c.bits[1] = 0b00000000000000000000000000000000;
  c.bits[2] = 0b00000000000000000000000000000000;
  c.bits[3] = 0b00000000000000000000000000000000;
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {0};
  etalon.bits[0] = 0b11111111111111111111111111111111;
  etalon.bits[1] = 0b00000000000000000000000000000000;
  etalon.bits[2] = 0b00000000000000000000000000000000;
  etalon.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_21) {
  decimal c = {{UINT32_MAX - 1, UINT32_MAX, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{UINT32_MAX, UINT32_MAX, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_25) {
  decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_26) {
  decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_27) {
  decimal c = {{UINT_MAX, UINT_MAX, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0, 0, 1, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_28) {
  decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};

  decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};

  decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};
  // decimal etalon = {
  //     {0b10000110001000101111001000011011,
  //     0b11111001111010000010010110101101,
  //      0b10110000001111101111000010010100,
  //      0b10000000000011100000000000000000}};
  decimal res = {{0, 0, 0, 0}};

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, &res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_30) {
  decimal src1, src2, origin;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;

  decimal result = {{0, 0, 0, 0}};
  decimal *p_res = &result;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(src1, src2, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);

  int equal = is_equal(
      result, origin);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_0) {
  decimal c = {{0, 0, 0, 0}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_1) {
  decimal c = {{1, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{2, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_2) {
  decimal c = {{1000, 0, 0, 0}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{2000, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_4) {
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{INT_MAX, 0, 0, 0}};
  decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_5) {
  decimal c = {{UINT_MAX, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 1, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_6) {
  decimal c = {{0, UINT_MAX - 1, 0, 0}};
  decimal d = {{0, 1, 0, 0}};
  decimal etalon = {{0, UINT_MAX, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_7) {
  decimal c = {{0, 0, UINT_MAX - 1, 0}};
  decimal d = {{0, 0, 1, 0}};
  decimal etalon = {{0, 0, UINT_MAX, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_8) {
  decimal c = {{0, 0, 0, ~(INT_MAX)}};
  decimal d = {{0, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_9) {
  decimal c = {{1, 0, 0, 0b10000000000000000000000000000000}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_10) {  // -1 + (-1) = -2
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_11) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_12) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_13) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_14) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_20) {
  decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_21) {
  decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_22) {
  decimal c = {{UINT_MAX, UINT_MAX, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0, 0, 1, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(my_test_decimal_add_simple_23) {
  decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};

  decimal res = {{0, 0, 0, 0}};
  decimal *p_res = &res;

  int add = MyAdd(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int equal =
      is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(add_max_33) {
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  ck_assert_int_eq(MyAdd(src1, src2, &res), 1);
}
END_TEST

START_TEST(add_max_36) {
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  decimal res = {0};
  MyAdd(src1, src2, &res);
  ck_assert_int_eq(MyAdd(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_test_37) {
  decimal src1 = {0};
  src1.bits[0] = 0b00000000000000000000001111111111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000001111111111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b00000000000000000010101111110101;
  original_res.bits[1] = 0b00000000000000000000000000000000;
  original_res.bits[2] = 0b00000000000000000000000000000000;
  original_res.bits[3] = 0b00000000000000100000000000000000;
  decimal res = {0};
  MyAdd(src1, src2, &res);
  ck_assert_int_eq(MyAdd(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

Suite *test_add(void) {
  Suite *s = suite_create("MyAdd");
  TCase *tc = tcase_create("add");

  tcase_add_test(tc, add_0);
  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);
  tcase_add_test(tc, add_17);
  tcase_add_test(tc, add_18);

  tcase_add_test(tc, my_test_decimal_add_0);
  tcase_add_test(tc, my_test_decimal_add_1);
  tcase_add_test(tc, my_test_decimal_add_3);
  tcase_add_test(tc, my_test_decimal_add_4);
  tcase_add_test(tc, my_test_decimal_add_5);
  tcase_add_test(tc, my_test_decimal_add_6);
  tcase_add_test(tc, my_test_decimal_add_7);
  tcase_add_test(tc, my_test_decimal_add_8);
  tcase_add_test(tc, my_test_decimal_add_9);
  tcase_add_test(tc, my_test_decimal_add_10);
  tcase_add_test(tc, my_test_decimal_add_11);
  tcase_add_test(tc, my_test_decimal_add_12);
  tcase_add_test(tc, my_test_decimal_add_13);
  tcase_add_test(tc, my_test_decimal_add_14);
  tcase_add_test(tc, my_test_decimal_add_15);
  tcase_add_test(tc, my_test_decimal_add_16);
  tcase_add_test(tc, my_test_decimal_add_17);
  tcase_add_test(tc, my_test_decimal_add_18);
  tcase_add_test(tc, my_test_decimal_add_19);
  tcase_add_test(tc, my_test_decimal_add_20);
  tcase_add_test(tc, my_test_decimal_add_21);
  tcase_add_test(tc, my_test_decimal_add_25);
  tcase_add_test(tc, my_test_decimal_add_26);
  tcase_add_test(tc, my_test_decimal_add_27);
  tcase_add_test(tc, my_test_decimal_add_28);
  tcase_add_test(tc, my_test_decimal_add_30);

  tcase_add_test(tc, my_test_decimal_add_simple_0);
  tcase_add_test(tc, my_test_decimal_add_simple_1);
  tcase_add_test(tc, my_test_decimal_add_simple_2);
  tcase_add_test(tc, my_test_decimal_add_simple_4);
  tcase_add_test(tc, my_test_decimal_add_simple_5);
  tcase_add_test(tc, my_test_decimal_add_simple_6);
  tcase_add_test(tc, my_test_decimal_add_simple_7);
  tcase_add_test(tc, my_test_decimal_add_simple_8);
  tcase_add_test(tc, my_test_decimal_add_simple_9);
  tcase_add_test(tc, my_test_decimal_add_simple_10);
  tcase_add_test(tc, my_test_decimal_add_simple_11);
  tcase_add_test(tc, my_test_decimal_add_simple_12);
  tcase_add_test(tc, my_test_decimal_add_simple_13);
  tcase_add_test(tc, my_test_decimal_add_simple_14);
  tcase_add_test(tc, my_test_decimal_add_simple_20);
  tcase_add_test(tc, my_test_decimal_add_simple_21);
  tcase_add_test(tc, my_test_decimal_add_simple_22);
  tcase_add_test(tc, my_test_decimal_add_simple_23);

  tcase_add_test(tc, add_max_33);
  tcase_add_test(tc, add_max_36);
  tcase_add_test(tc, add_test_37);

  suite_add_tcase(s, tc);
  return s;
}

// div

START_TEST(div_0) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyDiv(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res;
  ck_assert_int_eq(0, MyDiv(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  ck_assert_int_eq(0, MyDiv(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal val2 = {{0, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(3, MyDiv(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{0, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(3, MyDiv(val1, val2, &res));
}
END_TEST

START_TEST(div_5) {
  decimal value_1 = {{35, 0, 0, 0}};
  decimal value_2 = {{5, 0, 0, 0}};
  decimal result = {{0, 0, 0, 0}};
  decimal check = {{70, 0, 0, 0}};
  set_exp(&value_1, 1);
  set_exp(&value_2, 2);
  int return_value = MyDiv(value_1, value_2, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_6) {
  decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
  decimal value_2 = {{0x2, 0, 0, 0}};
  set_sign(&value_2, 1);
  decimal result = {{0, 0, 0, 0}};
  decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
  set_sign(&check, 1);
  int return_value = MyDiv(value_1, value_2, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_8) {
  decimal value_1 = {{15, 0, 0, 0}};
  set_sign(&value_1, 1);
  decimal value_2 = {{0, 0, 0, 0}};
  decimal result = {{0, 0, 0, 0}};
  decimal check = {{0, 0, 0, 0}};
  int return_value = MyDiv(value_1, value_2, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(div_9) {
  decimal value_1 = {{10, 0, 0, 0}};
  decimal value_2 = {{1, 0, 0, 0}};
  set_exp(&value_2, 2);
  decimal result = {{0, 0, 0, 0}};
  decimal check = {{1000u, 0, 0, 0}};
  int return_value = MyDiv(value_1, value_2, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("MyDiv");
  TCase *tc = tcase_create("div");

  tcase_add_test(tc, div_0);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);

  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);

  suite_add_tcase(s, tc);
  return s;
}
// is equal
START_TEST(is_equal_0) {
  decimal val1 = {{0, 0, 0, 0}};
  decimal val2 = {{0, 0, 0, 0}};
  set_sign(&val2, 1);
  ck_assert_int_eq(1, is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_5) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  set_exp(&val1, 3);
  set_exp(&val2, 3);
  ck_assert_int_eq(1, is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_7) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  set_exp(&val1, 3);
  set_exp(&val2, 2);
  ck_assert_int_eq(1, is_equal(val1, val2));
}
END_TEST

START_TEST(equal_11) {
  decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //
  ck_assert_int_eq(is_equal(dec1, dec2), 0);

  decimal dec3 = {
      {120000, 0, 0, 0b00000000000001000000000000000000}};  //  12.0000
  decimal dec4 = {{12, 0, 0, 0b00000000000000000000000000000000}};  // 12
  ck_assert_int_eq(is_equal(dec3, dec4), 1);

  decimal dec5 = {{0, 0, 0, 0b00000000000000000000000000000000}};   //  0
  decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //
  ck_assert_int_eq(is_equal(dec5, dec6), 1);

  decimal dec7 = {{0, 0, 0, 0b00000000000000000000000000000000}};  //   0
  decimal dec8 = {{0, 0, 0, 0b10000000000000000000000000000000}};  // -0;
  ck_assert_int_eq(is_equal(dec7, dec8), 1);
}
END_TEST

START_TEST(is_equalTest1) {
  // 5116
  decimal src1, src2;
  // src1 = 2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest2) {
  // 5134
  decimal src1, src2;
  // src1 = 3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest3) {
  // 5152
  decimal src1, src2;
  // src1 = 3;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest4) {
  // 5170
  decimal src1, src2;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest5) {
  // 5188
  decimal src1, src2;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest6) {
  // 5206
  decimal src1, src2;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest7) {
  // 5224
  decimal src1, src2;
  // src1 = 6521;
  // src2 = 74121;

  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest8) {
  // 5242
  decimal src1, src2;
  // src1 = 4;
  // src2 = 97623323;

  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest9) {
  // 5260
  decimal src1, src2;
  // src1 = 65658654;
  // src2 = 5;

  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest10) {
  // 5278
  decimal src1, src2;
  // src1 = -364748;
  // src2 = 1;

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest11) {
  // 5296
  decimal src1, src2;
  // src1 = 1;
  // src2 = 98745654321;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest12) {
  // 5314
  decimal src1, src2;
  // src1 = -9878798789;
  // src2 = -3;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest13) {
  // 5332
  decimal src1, src2;
  // src1 = 9999999999999999999;
  // src2 = 1;

  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest14) {
  // 5350
  decimal src1, src2;
  // src1 = 18446744073709551615;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest15) {
  // 5368
  decimal src1, src2;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest16) {
  // 5386
  decimal src1, src2;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;

  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest17) {
  // 5404
  decimal src1, src2;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;

  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest18) {
  // 5422
  decimal src1, src2;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest19) {
  // 5440
  decimal src1, src2;
  // src1 = 12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest20) {
  // 5458
  decimal src1, src2;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest21) {
  // 5476
  decimal src1, src2;
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest22) {
  // 5494
  decimal src1, src2;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest23) {
  // 5512
  decimal src1, src2;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest24) {
  // 5530
  decimal src1, src2;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest25) {
  // 5548
  decimal src1, src2;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest26) {
  // 5566
  decimal src1, src2;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest27) {
  // 5584
  decimal src1, src2;
  // src1 = 7922816251427554395;
  // src2 = 65645646;

  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest28) {
  // 5602
  decimal src1, src2;
  // src1 = 665464545;
  // src2 = 8798232189789785;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest29) {
  // 5620
  decimal src1, src2;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;

  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest30) {
  // 5638
  decimal src1, src2;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;

  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest31) {
  // 5656
  decimal src1, src2;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;

  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest32) {
  // 5674
  decimal src1, src2;
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;

  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest33) {
  // 5692
  decimal src1, src2;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest34) {
  // 5710
  decimal src1, src2;
  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;

  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest35) {
  // 5728
  decimal src1, src2;
  // src1 = -784515454.7989898652154545652;
  // src2 = -579895323215489956.67897455465;

  src1.bits[0] = 0b10110001001110110100010111110100;
  src1.bits[1] = 0b00111000100000111010110010000001;
  src1.bits[2] = 0b00011001010110010101110000011000;
  src1.bits[3] = 0b10000000000100110000000000000000;

  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_equalTest36) {
  // 5746
  decimal src1, src2;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  int result = is_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

Suite *test_is_equal(void) {
  Suite *s = suite_create("is_equal");
  TCase *tc = tcase_create("is_equal");

  tcase_add_test(tc, is_equal_0);
  tcase_add_test(tc, is_equal_5);
  tcase_add_test(tc, is_equal_7);

  tcase_add_test(tc, equal_11);

  tcase_add_test(tc, is_equalTest1);
  tcase_add_test(tc, is_equalTest2);
  tcase_add_test(tc, is_equalTest3);
  tcase_add_test(tc, is_equalTest4);
  tcase_add_test(tc, is_equalTest5);
  tcase_add_test(tc, is_equalTest6);
  tcase_add_test(tc, is_equalTest7);
  tcase_add_test(tc, is_equalTest8);
  tcase_add_test(tc, is_equalTest9);
  tcase_add_test(tc, is_equalTest10);
  tcase_add_test(tc, is_equalTest11);
  tcase_add_test(tc, is_equalTest12);
  tcase_add_test(tc, is_equalTest13);
  tcase_add_test(tc, is_equalTest14);
  tcase_add_test(tc, is_equalTest15);
  tcase_add_test(tc, is_equalTest16);
  tcase_add_test(tc, is_equalTest17);
  tcase_add_test(tc, is_equalTest18);
  tcase_add_test(tc, is_equalTest19);
  tcase_add_test(tc, is_equalTest20);
  tcase_add_test(tc, is_equalTest21);
  tcase_add_test(tc, is_equalTest22);
  tcase_add_test(tc, is_equalTest23);
  tcase_add_test(tc, is_equalTest24);
  tcase_add_test(tc, is_equalTest25);
  tcase_add_test(tc, is_equalTest26);
  tcase_add_test(tc, is_equalTest27);
  tcase_add_test(tc, is_equalTest28);
  tcase_add_test(tc, is_equalTest29);
  tcase_add_test(tc, is_equalTest30);
  tcase_add_test(tc, is_equalTest31);
  tcase_add_test(tc, is_equalTest32);
  tcase_add_test(tc, is_equalTest33);
  tcase_add_test(tc, is_equalTest34);
  tcase_add_test(tc, is_equalTest35);
  tcase_add_test(tc, is_equalTest36);

  suite_add_tcase(s, tc);
  return s;
}
// greatorequal

START_TEST(is_greater_or_equal_0) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  ck_assert_int_eq(1, is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_1) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);
  ck_assert_int_eq(0, is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_6) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 10);
  set_exp(&val2, 11);
  ck_assert_int_eq(1, is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_11) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_or_equal_12) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  int return_value = is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_greater_or_equal_13) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, 1);
  int return_value = is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_or_equal_14) {
  decimal value_1 = {{0, 0, 0, 0}};
  decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, 1);
  int return_value = is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_or_equal_15) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  int return_value = is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_or_equal_17) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(greater_or_equal_13) {
  decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //
  ck_assert_int_eq(is_greater_or_equal(dec5, dec6), 1);
  ck_assert_int_eq(is_greater_or_equal(dec6, dec5), 0);

  decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};
  ck_assert_int_eq(is_greater_or_equal(dec7, dec8), 0);
  ck_assert_int_eq(is_greater_or_equal(dec8, dec7), 1);

  decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};
  ck_assert_int_eq(is_greater_or_equal(dec1, dec2), 1);
  ck_assert_int_eq(is_greater_or_equal(dec2, dec1), 0);

  decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec4 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //

  ck_assert_int_eq(is_greater_or_equal(dec3, dec4), 0);
  ck_assert_int_eq(is_greater_or_equal(dec4, dec3), 1);

  decimal dec9 = {{12345, 0, 0, 0}};
  decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(is_greater_or_equal(dec9, dec10), 1);
  ck_assert_int_eq(is_greater_or_equal(dec10, dec9), 1);

  decimal dec11 = {{0, 0, 0, 0}};
  decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_greater_or_equal(dec11, dec12), 1);
  ck_assert_int_eq(is_greater_or_equal(dec12, dec11), 1);
}
END_TEST

Suite *test_is_greater_or_equal(void) {
  Suite *s = suite_create("is_greater_or_equal");
  TCase *tc = tcase_create("is_greater_or_equal");

  tcase_add_test(tc, is_greater_or_equal_0);
  tcase_add_test(tc, is_greater_or_equal_1);
  tcase_add_test(tc, is_greater_or_equal_2);
  tcase_add_test(tc, is_greater_or_equal_3);
  tcase_add_test(tc, is_greater_or_equal_5);
  tcase_add_test(tc, is_greater_or_equal_6);
  tcase_add_test(tc, is_greater_or_equal_11);
  tcase_add_test(tc, is_greater_or_equal_12);
  tcase_add_test(tc, is_greater_or_equal_13);
  tcase_add_test(tc, is_greater_or_equal_14);
  tcase_add_test(tc, is_greater_or_equal_15);
  tcase_add_test(tc, is_greater_or_equal_17);

  tcase_add_test(tc, greater_or_equal_13);

  suite_add_tcase(s, tc);
  return s;
}
// isgreat
START_TEST(is_greater_0) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  ck_assert_int_eq(0, is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_1) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_2) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_3) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_5) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);
  ck_assert_int_eq(0, is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_6) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val1.bits[2] = 256;

  val2.bits[0] = 257;
  val2.bits[2] = 257;
  set_exp(&val1, 10);
  set_exp(&val2, 11);
  ck_assert_int_eq(1, is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_11) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_12) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  int return_value = is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_greater_13) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, 1);
  int return_value = is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_14) {
  decimal value_1 = {{0, 0, 0, 0}};
  decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, 1);
  int return_value = is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_greater_15) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  int return_value = is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_16) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_exp(&value_2, 10);
  int return_value = is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_17) {
  decimal value_1 = {{234, 0, 0, 0}};
  decimal value_2 = {{2, 0, 0, 0}};
  set_exp(&value_1, 2);
  int return_value = is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(greater_11) {
  decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec6 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
  ck_assert_int_eq(is_greater(dec5, dec6), 1);
  ck_assert_int_eq(is_greater(dec6, dec5), 0);

  decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(is_greater(dec7, dec8), 0);
  ck_assert_int_eq(is_greater(dec8, dec7), 1);

  decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2
  ck_assert_int_eq(is_greater(dec1, dec2), 1);
  ck_assert_int_eq(is_greater(dec2, dec1), 0);

  decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec4 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //   -1.2
  ck_assert_int_eq(is_greater(dec3, dec4), 0);
  ck_assert_int_eq(is_greater(dec4, dec3), 1);
}
END_TEST

START_TEST(my_test_is_greater_1) {
  decimal a = {{2, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
  // Возвращаемое значение : 0 - 0   1 - TRUE
}
END_TEST

START_TEST(my_test_is_greater_2) {
  decimal a = {{UINT_MAX, 0, 0, 0}};
  decimal b = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_2i) {
  decimal a = {{UINT_MAX, 0, 0, 0}};
  decimal b = {{UINT_MAX - 1, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_3) {
  decimal a = {{UINT_MAX, 0, 0, 0}};
  decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(my_test_is_greater_4) {
  decimal a = {{UINT_MAX, 0, 0, 0}};
  decimal b = {{UINT_MAX, 1, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(my_test_is_greater_41) {
  decimal a = {{UINT_MAX, 1, 0, 0}};
  decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_5) {
  decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  decimal b = {{UINT_MAX, UINT_MAX - 1, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_51) {
  decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(my_test_is_greater_6) {
  decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal b = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_7) {
  decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_8) {
  decimal a = {{0, UINT_MAX, UINT_MAX, 0}};
  decimal b = {{0, UINT_MAX, UINT_MAX - 1, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_9) {
  decimal a = {{0, 0, UINT_MAX, 0}};
  decimal b = {{0, 0, UINT_MAX - 1, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(my_test_is_greater_10) {
  decimal a = {{0, 0, 0, 0}};
  decimal b = {{0, 0, UINT_MAX, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(is_greaterTest1) {
  // 3820
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest2) {
  // 3838
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest3) {
  // 3856
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 3;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest4) {
  // 3874
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest5) {
  // 3892
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest6) {
  // 3910
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest7) {
  // 3928
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 6521;
  // src2 = 74121;

  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest8) {
  // 3946
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 4;
  // src2 = 97623323;

  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest9) {
  // 3964
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 65658654;
  // src2 = 5;

  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest10) {
  // 3982
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -364748;
  // src2 = 1;

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest11) {
  // 4000
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 1;
  // src2 = 98745654321;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest12) {
  // 4018
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -9878798789;
  // src2 = -3;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest13) {
  // 4036
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 9999999999999999999;
  // src2 = 1;

  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest14) {
  // 4054
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 18446744073709551615;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest15) {
  // 4072
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest16) {
  // 4090
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest18) {
  // 4126
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest19) {
  // 4144
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest20) {
  // 4162
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest21) {
  // 4180
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest22) {
  // 4198
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest23) {
  // 4216
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest24) {
  // 4234
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest25) {
  // 4252
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest26) {
  // 4270
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 79228162514264337593543950335;
  // src2 = -1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest27) {
  // 4288
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 7922816251427554395;
  // src2 = 65645646;

  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest28) {
  // 4306
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 665464545;
  // src2 = 8798232189789785;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest29) {
  // 4324
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest30) {
  // 4342
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest31) {
  // 4360
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest32) {
  // 4378
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;
  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest33) {
  // 4396
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -79228162514264337593543950335;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest34) {
  // 4414
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;

  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_greaterTest36) {
  // 4450
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  int result = is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

Suite *test_is_greater(void) {
  Suite *s = suite_create("is_greater");
  TCase *tc = tcase_create("is_greater");

  tcase_add_test(tc, is_greater_0);
  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_5);
  tcase_add_test(tc, is_greater_6);
  tcase_add_test(tc, is_greater_11);
  tcase_add_test(tc, is_greater_12);
  tcase_add_test(tc, is_greater_13);
  tcase_add_test(tc, is_greater_14);
  tcase_add_test(tc, is_greater_15);
  tcase_add_test(tc, is_greater_16);
  tcase_add_test(tc, is_greater_17);

  tcase_add_test(tc, greater_11);

  tcase_add_test(tc, is_greaterTest1);
  tcase_add_test(tc, is_greaterTest2);
  tcase_add_test(tc, is_greaterTest3);
  tcase_add_test(tc, is_greaterTest4);
  tcase_add_test(tc, is_greaterTest5);
  tcase_add_test(tc, is_greaterTest6);
  tcase_add_test(tc, is_greaterTest7);
  tcase_add_test(tc, is_greaterTest8);
  tcase_add_test(tc, is_greaterTest8);
  tcase_add_test(tc, is_greaterTest9);
  tcase_add_test(tc, is_greaterTest10);
  tcase_add_test(tc, is_greaterTest11);
  tcase_add_test(tc, is_greaterTest12);
  tcase_add_test(tc, is_greaterTest13);
  tcase_add_test(tc, is_greaterTest14);
  tcase_add_test(tc, is_greaterTest15);
  tcase_add_test(tc, is_greaterTest16);
  tcase_add_test(tc, is_greaterTest18);
  tcase_add_test(tc, is_greaterTest19);
  tcase_add_test(tc, is_greaterTest20);
  tcase_add_test(tc, is_greaterTest21);
  tcase_add_test(tc, is_greaterTest22);
  tcase_add_test(tc, is_greaterTest23);
  tcase_add_test(tc, is_greaterTest24);
  tcase_add_test(tc, is_greaterTest25);
  tcase_add_test(tc, is_greaterTest26);
  tcase_add_test(tc, is_greaterTest27);
  tcase_add_test(tc, is_greaterTest28);
  tcase_add_test(tc, is_greaterTest29);
  tcase_add_test(tc, is_greaterTest30);
  tcase_add_test(tc, is_greaterTest31);
  tcase_add_test(tc, is_greaterTest32);
  tcase_add_test(tc, is_greaterTest33);
  tcase_add_test(tc, is_greaterTest34);
  tcase_add_test(tc, is_greaterTest36);

  tcase_add_test(tc, my_test_is_greater_1);
  tcase_add_test(tc, my_test_is_greater_2);
  tcase_add_test(tc, my_test_is_greater_3);
  tcase_add_test(tc, my_test_is_greater_4);
  tcase_add_test(tc, my_test_is_greater_5);
  tcase_add_test(tc, my_test_is_greater_6);
  tcase_add_test(tc, my_test_is_greater_7);
  tcase_add_test(tc, my_test_is_greater_8);
  tcase_add_test(tc, my_test_is_greater_9);
  tcase_add_test(tc, my_test_is_greater_10);
  tcase_add_test(tc, my_test_is_greater_51);
  tcase_add_test(tc, my_test_is_greater_41);
  tcase_add_test(tc, my_test_is_greater_2i);

  suite_add_tcase(s, tc);
  return s;
}

// float to dec
START_TEST(float_to_decimal_56) {
  decimal val;
  float num = -21474836;
  from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 21474840);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], -2147483648);
}
END_TEST

START_TEST(float_to_decimal_58) {
  decimal val = {0};
  from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_60) {
  decimal val = {0};
  float a = 1.0 / 0.0;
  from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_61) {
  decimal val = {0};
  float a = -1.0 / 0.0;
  from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_62) {
  decimal val = {0};
  float a = 1e-30;
  from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_69) {
  decimal dec = {0};
  float a = 1.0 / 0.0;
  int ret = from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(float_to_decimal_70) {
  decimal dec = {0};
  float a = -1.0 / 0.0;
  from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_71) {
  float f = 0.04;
  decimal result = {0};
  decimal check = {{4, 0, 0, 0}};
  set_exp(&check, 2);
  int return_value = from_float_to_decimal(f, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(float_to_decimal_72) {
  float f = -128.023;
  decimal result = {0};
  decimal check = {{128023, 0, 0, 0}};
  set_exp(&check, 3);
  set_sign(&check, 1);
  int return_value = from_float_to_decimal(f, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(float_to_decimal_73) {
  float f = 1.0 / 0.0;
  decimal result = {0};
  decimal check = {{0, 0, 0, 0}};
  int return_value = from_float_to_decimal(f, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("from_float_to_decimal");
  TCase *tc = tcase_create("from_float_to_decimal");

  tcase_add_test(tc, float_to_decimal_56);
  tcase_add_test(tc, float_to_decimal_58);
  tcase_add_test(tc, float_to_decimal_60);
  tcase_add_test(tc, float_to_decimal_61);
  tcase_add_test(tc, float_to_decimal_62);
  tcase_add_test(tc, float_to_decimal_69);
  tcase_add_test(tc, float_to_decimal_70);
  tcase_add_test(tc, float_to_decimal_71);
  tcase_add_test(tc, float_to_decimal_72);
  tcase_add_test(tc, float_to_decimal_73);

  suite_add_tcase(s, tc);
  return s;
}
// is les
START_TEST(is_less_0) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  ck_assert_int_eq(0, is_less(val1, val2));
}
END_TEST

START_TEST(is_less_1) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, is_less(val1, val2));
}
END_TEST

START_TEST(is_less_2) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, is_less(val1, val2));
}
END_TEST

START_TEST(is_less_3) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, is_less(val1, val2));
}
END_TEST

START_TEST(is_less_5) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);

  ck_assert_int_eq(1, is_less(val1, val2));
}
END_TEST

START_TEST(is_less_6) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 10);
  set_exp(&val2, 11);
  ck_assert_int_eq(0, is_less(val1, val2));
}
END_TEST

START_TEST(is_less_7) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val2.bits[2] = 257;
  set_exp(&val1, 127);
  set_exp(&val2, 127);
  ck_assert_int_eq(1, is_less(val1, val2));
}
END_TEST

START_TEST(is_less_17) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_18) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  int return_value = is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_19) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, 1);
  int return_value = is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_20) {
  decimal value_1 = {{0, 0, 0, 0}};
  decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, 1);
  int return_value = is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_21) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  int return_value = is_less(value_1, value_2);
  printf("Return value: %d\n", return_value);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_30) {
  decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2
  ck_assert_int_eq(is_less(dec5, dec6), 0);
  ck_assert_int_eq(is_less(dec6, dec5), 1);

  decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(is_less(dec7, dec8), 1);
  ck_assert_int_eq(is_less(dec8, dec7), 0);

  decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(is_less(dec1, dec2), 0);
  ck_assert_int_eq(is_less(dec2, dec1), 1);

  decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec4 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
  ck_assert_int_eq(is_less(dec3, dec4), 1);
  ck_assert_int_eq(is_less(dec4, dec3), 0);

  decimal dec9 = {{12345, 0, 0, 0}};
  decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(is_less(dec9, dec10), 0);
  ck_assert_int_eq(is_less(dec10, dec9), 0);

  decimal dec11 = {{0, 0, 0, 0}};
  decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_less(dec11, dec12), 0);
  ck_assert_int_eq(is_less(dec12, dec11), 0);
}
END_TEST

Suite *test_is_less(void) {
  Suite *s = suite_create("is_less");
  TCase *tc = tcase_create("is_less");
  tcase_add_test(tc, is_less_0);
  tcase_add_test(tc, is_less_1);
  tcase_add_test(tc, is_less_2);
  tcase_add_test(tc, is_less_3);
  tcase_add_test(tc, is_less_5);
  tcase_add_test(tc, is_less_6);
  tcase_add_test(tc, is_less_7);
  tcase_add_test(tc, is_less_17);
  tcase_add_test(tc, is_less_18);
  tcase_add_test(tc, is_less_19);
  tcase_add_test(tc, is_less_20);
  tcase_add_test(tc, is_less_21);

  tcase_add_test(tc, is_less_30);

  suite_add_tcase(s, tc);
  return s;
}

// dectoflaot
START_TEST(from_decimal_to_float_0) {
  decimal val = {{123456789, 0, 0, 0}};
  set_exp(&val, 5);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  decimal var = {{0, 0, 0, 0}};
  float value = 0;
  from_float_to_decimal(5.0, &var);
  from_decimal_to_float(var, &value);
  ck_assert_float_eq_tol(5.0, value, 10e-5);
}
END_TEST

START_TEST(from_decimal_to_float_1) {
  decimal var = {0};
  float value = 0;
  from_float_to_decimal(5.0, &var);
  from_decimal_to_float(var, &value);
  ck_assert_float_eq_tol(5.0, value, 10e-5);
}
END_TEST

START_TEST(from_decimal_to_float_4) {
  decimal value = {{1812, 0, 0, 0}};
  set_sign(&value, 1);
  float result = 0;
  float check = -1812;
  int return_value = from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(from_decimal_to_float_5) {
  decimal value = {{18122, 0, 0, 0}};
  set_exp(&value, 3);
  set_sign(&value, 1);
  float result = 0;
  float check = -18.122;
  int return_value = from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(from_decimal_to_float_6) {
  decimal value = {{0xFFFFFF, 0, 0, 0}};
  float result = 0;
  float check = 16777215;
  int return_value = from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST
//я поняо

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create("from_decimal_to_float");
  TCase *tc = tcase_create("from_decimal_to_float");

  tcase_add_test(tc, from_decimal_to_float_0);
  tcase_add_test(tc, from_decimal_to_float_2);
  tcase_add_test(tc, from_decimal_to_float_1);
  tcase_add_test(tc, from_decimal_to_float_4);
  tcase_add_test(tc, from_decimal_to_float_5);
  tcase_add_test(tc, from_decimal_to_float_6);

  suite_add_tcase(s, tc);
  return s;
}

// dectoint
START_TEST(from_decimal_to_int_0) {
  decimal val = {{123456789, 0, 0, 0}};
  set_exp(&val, 5);
  int res = 1234;
  int tmp = 0;
  int *dst = &tmp;
  from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_1) {
  decimal val = {{123456789, 0, 0, 0}};
  set_sign(&val, 1);
  set_exp(&val, 5);
  int res = -1234;
  int tmp = 0;
  int *dst = &tmp;
  from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  decimal var = {{0, 0, 0, 0}};
  int value = 0;
  from_int_to_decimal(5, &var);
  from_decimal_to_int(var, &value);
  ck_assert_int_eq(5, value);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  int n = 666;
  decimal var = {{0, 1, 0, 0}};
  int value = 0;
  from_int_to_decimal(n, &var);
  from_decimal_to_int(var, &value);
  ck_assert_float_eq_tol(n, value, 10);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = from_decimal_to_int(src, &number);
  ck_assert_float_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = 133141;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 133141);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = 2147483647;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  set_sign(&src, 1);
  result = from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_7) {
  decimal src = {{0}};
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 123451234;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -123451234);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_8) {
  decimal src = {{0}};
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 18;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;  // 2147483648
  result = from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -18);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_9) {
  decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = UINT_MAX;
  src.bits[1] = UINT_MAX;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

int check, result, code;

START_TEST(from_decimal_to_int_10) {
  decimal a = {{100, 0, 0, 0}};
  check = 100;
  int result = 0;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_11) {
  decimal a = {{INT_MAX, 0, 0, 0}};
  check = INT_MAX;
  int result = 0;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_12) {
  decimal a = {{INT_MAX, INT_MAX, 0, 0}};
  set_sign(&a, 1);
  check = 0;
  int code = from_decimal_to_int(a, &result);
  //   ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_13) {
  decimal a = {{INT_MAX, INT_MAX, INT_MAX, 0}};
  check = 0;
  int result = 0;
  int code = from_decimal_to_int(a, &result);
  //   ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_14) {
  int result = 0;
  decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  check = 0;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_15) {
  decimal a = {{INT_MAX, 0, 0, INT_MIN}};
  int result = 0;
  check = -INT_MAX;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_16) {
  decimal a = {{INT_MAX, 0, 0, INT_MIN}};
  int result = 0;
  check = -INT_MAX;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_17) {
  decimal a = {{INT_MAX, 0, 0, EXPONENT_PLUS_1}};
  int result = 0;
  check = 214748364;  // (int)(INT_MAX / 10^1)
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_18) {
  decimal a = {{INT_MAX, 0, 0, EXPONENT_PLUS_28}};
  int result = 0;
  check = 0;  // (int)(INT_MAX / 10^28)
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_19) {
  decimal a;
  int result = 0;
  a.bits[0] = 0b10000000000000000000000000000000;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000001;
  check = 0;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_20) {
  decimal a;
  int result = 0;
  a.bits[0] = 0b00000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = 1;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_21) {
  decimal a;
  int result = 0;
  a.bits[0] = 0b10000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = -2147483647;
  int code = from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_22) {
  // 6556
  decimal src1;
  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(from_decimal_to_int_23) {
  // 6570
  decimal src1;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_24) {
  // 6584
  decimal src1;
  // src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 3);
}
END_TEST


Suite *test_from_decimal_to_int(void) {
  Suite *s = suite_create("from_decimal_to_int");
  TCase *tc = tcase_create("from_decimal_to_int");

  tcase_add_test(tc, from_decimal_to_int_0);
  tcase_add_test(tc, from_decimal_to_int_1);
  tcase_add_test(tc, from_decimal_to_int_2);
  tcase_add_test(tc, from_decimal_to_int_3);
  tcase_add_test(tc, from_decimal_to_int_4);
  tcase_add_test(tc, from_decimal_to_int_5);
 tcase_add_test(tc, from_decimal_to_int_6);
 tcase_add_test(tc, from_decimal_to_int_7);
tcase_add_test(tc, from_decimal_to_int_8);
tcase_add_test(tc, from_decimal_to_int_9);
tcase_add_test(tc, from_decimal_to_int_10);
tcase_add_test(tc, from_decimal_to_int_11);
tcase_add_test(tc, from_decimal_to_int_12);
tcase_add_test(tc, from_decimal_to_int_13);
tcase_add_test(tc, from_decimal_to_int_14);
tcase_add_test(tc, from_decimal_to_int_15);
tcase_add_test(tc, from_decimal_to_int_16);
tcase_add_test(tc, from_decimal_to_int_17);
tcase_add_test(tc, from_decimal_to_int_18);
tcase_add_test(tc, from_decimal_to_int_19);
tcase_add_test(tc, from_decimal_to_int_20);
tcase_add_test(tc, from_decimal_to_int_21);
tcase_add_test(tc, from_decimal_to_int_22);
tcase_add_test(tc, from_decimal_to_int_23);
tcase_add_test(tc, from_decimal_to_int_24);

  suite_add_tcase(s, tc);
  return s;
}

// int to dec

int a, add, equal;
START_TEST(from_int_to_decimal_0) {
  decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -2147483648;
  from_int_to_decimal(tmp, &val);
  from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_1) {
  decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  from_int_to_decimal(tmp, &val);
  from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 2147483647;
  from_int_to_decimal(tmp, &val);
  from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  decimal val = {0};

  from_int_to_decimal(0, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  clear_decimal(&val);
  from_int_to_decimal(-128, &val);
  ck_assert_int_eq(val.bits[0], 128);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], -2147483648);

  clear_decimal(&val);
  from_int_to_decimal(127, &val);
  ck_assert_int_eq(val.bits[0], 127);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  clear_decimal(&val);
  from_int_to_decimal(-2147483648, &val);
  ck_assert_int_eq(val.bits[0], -2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], -2147483648);

  clear_decimal(&val);
  from_int_to_decimal(2147483647, &val);
  ck_assert_int_eq(val.bits[0], 2147483647);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_int_to_decimal_4) {
  a = 100;
  decimal b = {{0, 0, 0, 0}};
  decimal *ptr_b = &b;

  add = from_int_to_decimal(a, ptr_b);  // a записываем в b
  decimal etalon = {{100, 0, 0, 0}};
  ck_assert_int_eq(add, 0);
  // выходное значение from_int_to_decimal - 0 TRUE и 1 FALSE
  // is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(from_int_to_decimal_5) {
  a = 100;
  decimal b = {{0, 0, 0, 0}};
  decimal *ptr_b = &b;

  add = from_int_to_decimal(a, ptr_b);  // a записываем в b
  decimal etalon = {{1000, 0, 0, 0}};
  ck_assert_int_eq(add, 0);
  // выходное значение from_int_to_decimal -
  // 0 TRUE и 1 FALSE
  // is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(from_int_to_decimal_6) {
  a = INT_MAX;
  decimal b = {{0, 0, 0, 0}};
  decimal *ptr_b = &b;

  add = from_int_to_decimal(a, ptr_b);  // a записываем в b
  decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(add, 0);  // выходное значение from_int_to_decimal -
  // 0 TRUE и 1 FALSE
  // is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(from_int_to_decimal_7) {
  a = -INT_MAX;
  decimal b = {{0, 0, 0, 0}};
  decimal *ptr_b = &b;

  add = from_int_to_decimal(a, ptr_b);  // a записываем в b
  decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(add, 0);  // выходное значение from_int_to_decimal -
  // 0 TRUE и 1 FALSE
  // is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(from_int_to_decimal_8) {
  a = -INT_MAX;
  decimal b = {{0, 0, 0, 0}};
  decimal *ptr_b = &b;

  add = from_int_to_decimal(a, ptr_b);  // a записываем в b
  decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(add, 0);  // выходное значение from_int_to_decimal -
  // 0 TRUE и 1 FALSE
  // is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(from_int_to_decimal_9) {
  a = 0;  // ERROR of NAN
  decimal b = {{0, 0, 0, 0}};
  decimal *ptr_b = &b;

  add = from_int_to_decimal(a, ptr_b);  // a записываем в b
  decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(add, 0);  // выходное значение from_int_to_decimal -
  // 0 TRUE и 1 FALSE
  // is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(from_int_to_decimal_10) {
  // 6412
  int src1 = 1;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_11) {
  // 6428
  int src1 = -1;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_12) {
  // 6444
  int src1 = 0;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_13) {
  // 6460
  int src1 = 0;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_14) {
  // 6476
  int src1 = -987879878;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00111010111000011101100111000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_15) {
  // 6492
  int src1 = -2147483646;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_16) {
  // 6508
  int src1 = 2147483646;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_17) {
  // 6524
  int src1 = 796132784;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00101111011101000000010110110000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_18) {
  // 6540
  int src1 = -12345677;
  decimal origin = {0}, result = {0};
  decimal *res = &result;
  from_int_to_decimal(src1, res);
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s = suite_create("from_int_to_decimal");
  TCase *tc = tcase_create("from_int_to_decimal");

 

  tcase_add_test(tc, from_int_to_decimal_0);
  tcase_add_test(tc, from_int_to_decimal_1);
  tcase_add_test(tc, from_int_to_decimal_2);
  tcase_add_test(tc, from_int_to_decimal_3);
  tcase_add_test(tc, from_int_to_decimal_4);
  tcase_add_test(tc, from_int_to_decimal_5);
   tcase_add_test(tc, from_int_to_decimal_6);
    tcase_add_test(tc, from_int_to_decimal_7);
     tcase_add_test(tc, from_int_to_decimal_8);
      tcase_add_test(tc, from_int_to_decimal_9);
       tcase_add_test(tc, from_int_to_decimal_10);
        tcase_add_test(tc, from_int_to_decimal_11);
         tcase_add_test(tc, from_int_to_decimal_12);
          tcase_add_test(tc, from_int_to_decimal_13);
           tcase_add_test(tc, from_int_to_decimal_14);
            tcase_add_test(tc, from_int_to_decimal_15);
             tcase_add_test(tc, from_int_to_decimal_16);
              tcase_add_test(tc, from_int_to_decimal_17);
  tcase_add_test(tc, from_int_to_decimal_18);
  
  suite_add_tcase(s, tc);
  return s;
}

// isnotequal

START_TEST(is_not_equal_5) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  set_exp(&val1, 3);
  set_exp(&val2, 3);
  ck_assert_int_eq(0, is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_7) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  set_exp(&val1, 3);
  set_exp(&val2, 2);
  ck_assert_int_eq(0, is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_8) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  ck_assert_int_eq(0, is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_12) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_not_equal_13) {
  decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_not_equal_14) {
  decimal value_1 = {{0, 0, 0, 80000000}};
  decimal value_2 = {{0, 0, 0, 0}};
  int return_value = is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(not_equal_7) {
  decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2;
  ck_assert_int_eq(is_not_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(not_equal_8) {
  decimal dec3 = {
      {120000, 0, 0, 0b00000000000001000000000000000000}};  //  12.0000
  decimal dec4 = {{12, 0, 0, 0b00000000000000000000000000000000}};  //
  ck_assert_int_eq(is_not_equal(dec3, dec4), 0);
}
END_TEST
START_TEST(not_equal_9) {
  decimal dec5 = {{0, 0, 0, 0b00000000000000000000000000000000}};   //  0
  decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //
  ck_assert_int_eq(is_not_equal(dec5, dec6), 0);
}
END_TEST
START_TEST(not_equal_10) {
  decimal dec7 = {{0, 0, 0, 0b00000000000000000000000000000000}};  //   0
  decimal dec8 = {{0, 0, 0, 0b10000000000000000000000000000000}};  //  -0;
  ck_assert_int_eq(is_not_equal(dec7, dec8), 0);
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *s = suite_create("is_not_equal");
  TCase *tc = tcase_create("is_not_equal");

  tcase_add_test(tc, is_not_equal_5);
  tcase_add_test(tc, is_not_equal_7);
  tcase_add_test(tc, is_not_equal_8);
  tcase_add_test(tc, is_not_equal_12);
  tcase_add_test(tc, is_not_equal_13);
  tcase_add_test(tc, is_not_equal_14);

  tcase_add_test(tc, not_equal_7);
  tcase_add_test(tc, not_equal_8);
  tcase_add_test(tc, not_equal_9);
  tcase_add_test(tc, not_equal_10);

  suite_add_tcase(s, tc);
  return s;
}

// less or equal

START_TEST(is_less_or_equal_0) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  ck_assert_int_eq(1, is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_1) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_2) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_3) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_5) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);
  ck_assert_int_eq(1, is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_6) {
  decimal val1 = {{0}};
  decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 10);
  set_exp(&val2, 11);
  ck_assert_int_eq(0, is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_12) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_13) {
  decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  int return_value = is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_14) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, 1);
  int return_value = is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_15) {
  decimal value_1 = {{0, 0, 0, 0}};
  decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, 1);
  int return_value = is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_16) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  int return_value = is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_17) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_exp(&value_2, 2);
  int return_value = is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_18) {
  decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(less_or_equal_23) {
  decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2;
  ck_assert_int_eq(is_less_or_equal(dec5, dec6), 0);
  ck_assert_int_eq(is_less_or_equal(dec6, dec5), 1);

  decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(is_less_or_equal(dec7, dec8), 1);
  ck_assert_int_eq(is_less_or_equal(dec8, dec7), 0);

  decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(is_less_or_equal(dec1, dec2), 0);
  ck_assert_int_eq(is_less_or_equal(dec2, dec1), 1);

  decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec4 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
  ck_assert_int_eq(is_less_or_equal(dec3, dec4), 1);
  ck_assert_int_eq(is_less_or_equal(dec4, dec3), 0);

  decimal dec9 = {{12345, 0, 0, 0}};
  decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(dec9, dec10), 1);
  ck_assert_int_eq(is_less_or_equal(dec10, dec9), 1);

  decimal dec11 = {{0, 0, 0, 0}};
  decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(dec11, dec12), 1);
  ck_assert_int_eq(is_less_or_equal(dec12, dec11), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_1) {
  decimal a = {{1, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_2) {
  decimal a = {{1, 0, 0, 0}};
  decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_2i) {
  decimal a = {{UINT_MAX, 0, 0, 0}};
  decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_3) {
  decimal a = {{UINT_MAX - 1, 0, 0, 0}};
  decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_4) {
  decimal a = {{UINT_MAX, 0, 0, 0}};
  decimal b = {{UINT_MAX, 1, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_41) {
  decimal a = {{UINT_MAX, 1, 0, 0}};
  decimal b = {{UINT_MAX, 1, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_5) {
  decimal a = {{UINT_MAX, UINT_MAX - 1, 0, 0}};
  decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_6) {
  decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal b = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_7) {
  decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  decimal b = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_8) {
  decimal a = {{0, UINT_MAX, UINT_MAX, 0}};
  decimal b = {{0, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_9) {
  decimal a = {{0, 0, UINT_MAX, 0}};
  decimal b = {{0, 0, UINT_MAX, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(my_test_is_less_or_equal_10) {
  decimal a = {{0, 0, 0, 0}};
  decimal b = {{0, 0, UINT_MAX, 0}};
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(is_less_or_equalTest01) {
  // 2596
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest1) {
  // 3172
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest2) {
  // 3190
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest3) {
  // 3208
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 3;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest4) {
  // 3226
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest5) {
  // 3244
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest6) {
  // 3262
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest7) {
  // 3280
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 6521;
  // src2 = 74121;

  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest8) {
  // 3298
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 4;
  // src2 = 97623323;

  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest9) {
  // 3316
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 65658654;
  // src2 = 5;

  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest10) {
  // 3334
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -364748;
  // src2 = 1;

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest11) {
  // 3352
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 1;
  // src2 = 98745654321;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest12) {
  // 3370
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -9878798789;
  // src2 = -3;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest13) {
  // 3388
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 9999999999999999999;
  // src2 = 1;

  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest14) {
  // 3406
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 18446744073709551615;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest15) {
  // 3424
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest16) {
  // 3442
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest18) {
  // 3478
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest19) {
  // 3496
  decimal src1 = {{0}};
  decimal src2 = {{0}};

  // 44888571,679810019404305144576
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  // 551006440570,2897413741940543
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest20) {
  // 3514
  decimal src1 = {{0}};
  decimal src2 = {{0}};

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest21) {
  // 3532
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest22) {
  // 3550
  decimal src1 = {0}, src2 = {0};

  // 44888571,679810019404305144576
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  // 551006440570,2897413741940543
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest23) {
  // 3568
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest24) {
  // 3586
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest25) {
  // 3604
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest26) {
  // 3622
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 79228162514264337593543950335;
  // src2 = -1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest27) {
  // 3640
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 7922816251427554395;
  // src2 = 65645646;

  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest28) {
  // 3658
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 665464545;
  // src2 = 8798232189789785;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest29) {
  // 3676
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest30) {
  // 3694
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest31) {
  // 3712
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest32) {
  // 3730
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;
  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest33) {
  // 3748
  decimal src1 = {{0}};
  decimal src2 = {{0}};
  // src1 = -79228162514264337593543950335;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest34) {
  // 3766
  decimal src1 = {0}, src2 = {0};
  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;

  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  // src2.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest35) {
  // 3784
  decimal src1 = {{0}};
  decimal src2 = {{0}};

  src1.bits[0] = 0b10110001001110110100010111110100;
  src1.bits[1] = 0b00111000100000111010110010000001;
  src1.bits[2] = 0b00011001010110010101110000011000;
  // src1.bits[3] = 0b10000000000100110000000000000000;
  src1.bits[3] = 0b10000000000010110000000000000000;

  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(is_less_or_equalTest36) {
  // 3802
  decimal src1 = {{0}};
  decimal src2 = {{0}};

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  int result = is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

Suite *test_is_less_or_equal(void) {
  Suite *s = suite_create("is_less_or_equal");
  TCase *tc = tcase_create("is_less_or_equal");
  tcase_add_test(tc, is_less_or_equal_0);
  tcase_add_test(tc, is_less_or_equal_1);
  tcase_add_test(tc, is_less_or_equal_2);
  tcase_add_test(tc, is_less_or_equal_3);
  tcase_add_test(tc, is_less_or_equal_5);
  tcase_add_test(tc, is_less_or_equal_6);
  tcase_add_test(tc, is_less_or_equal_12);
  tcase_add_test(tc, is_less_or_equal_13);
  tcase_add_test(tc, is_less_or_equal_14);
  tcase_add_test(tc, is_less_or_equal_15);
  tcase_add_test(tc, is_less_or_equal_16);
  tcase_add_test(tc, is_less_or_equal_17);
  tcase_add_test(tc, is_less_or_equal_18);

  tcase_add_test(tc, less_or_equal_23);

  tcase_add_test(tc, my_test_is_less_or_equal_1);
  tcase_add_test(tc, my_test_is_less_or_equal_2);
  tcase_add_test(tc, my_test_is_less_or_equal_2i);
  tcase_add_test(tc, my_test_is_less_or_equal_3);
  tcase_add_test(tc, my_test_is_less_or_equal_4);
  tcase_add_test(tc, my_test_is_less_or_equal_41);
  tcase_add_test(tc, my_test_is_less_or_equal_5);
  tcase_add_test(tc, my_test_is_less_or_equal_6);
  tcase_add_test(tc, my_test_is_less_or_equal_7);
  tcase_add_test(tc, my_test_is_less_or_equal_8);
  tcase_add_test(tc, my_test_is_less_or_equal_8);
  tcase_add_test(tc, my_test_is_less_or_equal_9);
  tcase_add_test(tc, my_test_is_less_or_equal_10);
  tcase_add_test(tc, is_less_or_equalTest01);
  tcase_add_test(tc, is_less_or_equalTest1);
  tcase_add_test(tc, is_less_or_equalTest2);
  tcase_add_test(tc, is_less_or_equalTest3);
  tcase_add_test(tc, is_less_or_equalTest4);
  tcase_add_test(tc, is_less_or_equalTest5);
  tcase_add_test(tc, is_less_or_equalTest6);
  tcase_add_test(tc, is_less_or_equalTest7);
  tcase_add_test(tc, is_less_or_equalTest8);
  tcase_add_test(tc, is_less_or_equalTest9);
  tcase_add_test(tc, is_less_or_equalTest10);
  tcase_add_test(tc, is_less_or_equalTest11);
  tcase_add_test(tc, is_less_or_equalTest12);
  tcase_add_test(tc, is_less_or_equalTest13);
  tcase_add_test(tc, is_less_or_equalTest14);
  tcase_add_test(tc, is_less_or_equalTest15);
  tcase_add_test(tc, is_less_or_equalTest16);
  tcase_add_test(tc, is_less_or_equalTest18);
  tcase_add_test(tc, is_less_or_equalTest19);
  tcase_add_test(tc, is_less_or_equalTest20);
  tcase_add_test(tc, is_less_or_equalTest21);
  tcase_add_test(tc, is_less_or_equalTest22);
  tcase_add_test(tc, is_less_or_equalTest23);
  tcase_add_test(tc, is_less_or_equalTest24);
  tcase_add_test(tc, is_less_or_equalTest25);
  tcase_add_test(tc, is_less_or_equalTest26);
  tcase_add_test(tc, is_less_or_equalTest27);
  tcase_add_test(tc, is_less_or_equalTest28);
  tcase_add_test(tc, is_less_or_equalTest29);
  tcase_add_test(tc, is_less_or_equalTest30);
  tcase_add_test(tc, is_less_or_equalTest31);
  tcase_add_test(tc, is_less_or_equalTest32);
  tcase_add_test(tc, is_less_or_equalTest33);
  tcase_add_test(tc, is_less_or_equalTest34);
  tcase_add_test(tc, is_less_or_equalTest35);
  tcase_add_test(tc, is_less_or_equalTest36);

  suite_add_tcase(s, tc);
  return s;
}
// floor
START_TEST(floor_0) {
  decimal val = {{2, 0, 0, 0}};
  decimal res;
  ck_assert_int_eq(0, MyFloor(val, &res));
}
END_TEST

START_TEST(floor_1) {
  decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  MyFloor(val, &res);
  float fres = 0;
  from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-2, fres);
}
END_TEST

START_TEST(floor_2) {
  decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  set_exp(&val, 5);
  decimal res = {{0}};
  MyFloor(val, &res);

  float fres = 0;
  from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(floor_3) {
  decimal val = {{2, 0, 0, 0}};
  decimal res = {{0}};
  set_exp(&val, 5);
  MyFloor(val, &res);
  float fres = 0;
  from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

START_TEST(floor_5) {
  decimal value_1 = {{7444923, 0, 0, 0}};
  set_exp(&value_1, 5);
  decimal check = {{74, 0, 0, 0}};
  decimal result = {0};
  int return_value = MyFloor(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(floor_6) {
  decimal value_1 = {{7444923, 0, 0, 0}};
  set_exp(&value_1, 5);
  set_sign(&value_1, 1);
  decimal check = {{75, 0, 0, 0}};
  set_sign(&check, 1);
  decimal result = {0};
  int return_value = MyFloor(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(floor_7) {
  decimal src1;
  src1.bits[0] = 0b00001111111111111111111111111111;
  src1.bits[1] = 0b00111110001001010000001001100001;
  src1.bits[2] = 0b00100000010011111100111001011110;
  src1.bits[3] = 0b10000000000010100000000000000000;
  decimal res_od = {0};
  MyFloor(src1, &res_od);
  decimal result = {0};
  result.bits[0] = 0b10100111011001000000000000000000;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

Suite *test_floor(void) {
  Suite *s = suite_create("MyFloor");
  TCase *tc = tcase_create("floor");

  tcase_add_test(tc, floor_0);
  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  tcase_add_test(tc, floor_7);

  suite_add_tcase(s, tc);
  return s;
}
// round

START_TEST(MyRound_1) {
  decimal dec1;
  dec1.bits[0] = 0b10010011111100000001110001010010;
  dec1.bits[1] = 0b00000000000000000000000100100000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000010100000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000001111100;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_2) {
  decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000010100101;  // -16.5
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000000010000000000000000;
  decimal result;
  result.bits[0] = 17;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_3) {
  decimal dec1;
  dec1.bits[0] = 0b11111111111111111111111111111111;  // 18014398509481.983
  dec1.bits[1] = 0b00000000001111111111111111111111;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000110000000000000000;
  decimal result;

  result.bits[0] = 0b01001101110100101111000110101001;  // 18014398509481
  result.bits[1] = 0b00000000000000000001000001100010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_4) {
  decimal dec1;
  dec1.bits[0] = 0b00000000000011110111001001110100;  // -10123.40
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000000110000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000001111110100;  // -1012
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_5) {
  decimal dec1;
  dec1.bits[0] = 0b10000000000000000000001111110100;  // 112590205.4327284
  dec1.bits[1] = 0b00000000000001000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000001110000000000000000;
  decimal result;
  result.bits[0] = 0b00000110101101011111110101111101;  // 112590205
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_6) {
  decimal dec1;
  dec1.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  decimal result;
  result.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_7) {
  decimal dec1;

  dec1.bits[0] = 0b01100011000011111111111111111111;
  dec1.bits[1] = 0b01101011110001110101111000101101;
  dec1.bits[2] = 0b00000000000000000000000000000101;
  dec1.bits[3] = 0b10000000000010100000000000000000;
  decimal result;
  result.bits[0] = 0b01010100000010111110010000000000;
  result.bits[1] = 0b00000000000000000000000000000010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_8) {
  decimal dec1;

  dec1.bits[0] = 0b01010101001110101110101110110001;
  dec1.bits[1] = 0b00001101101101001101101001011111;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000100100000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_9) {
  decimal dec1;

  dec1.bits[0] = 0b10010011111100000001110001010010;
  dec1.bits[1] = 0b00000000000000000000000100100000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000010100000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000001111100;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_11) {
  decimal dec1;

  dec1.bits[0] = 0b10100000111111100100111000000100;
  dec1.bits[1] = 0b00011011110011101100110011101101;
  dec1.bits[2] = 0b00000000000000001101001111000010;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  decimal result;
  result.bits[0] = 0b10100000111111100100111000000100;
  result.bits[1] = 0b00011011110011101100110011101101;
  result.bits[2] = 0b00000000000000001101001111000010;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_12) {
  decimal dec1;

  dec1.bits[0] = 0b10010111011100111001111111111111;
  dec1.bits[1] = 0b00111100000010000011000110001101;
  dec1.bits[2] = 0b00000000000000000000000000000001;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  decimal result;
  result.bits[0] = 0b00110110101101101000110001000000;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRound_13) {
  decimal dec1;

  dec1.bits[0] = 0b10010111011100111001111111111111;
  dec1.bits[1] = 0b00111100000010000011000110001101;
  dec1.bits[2] = 0b00000000000000000000000000000001;
  dec1.bits[3] = 0b10000000000001110000000000000000;
  decimal res1;
  MyRound(dec1, &res1);
  decimal result;
  result.bits[0] = 0b00110110101101101000110001000000;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(MyRoundTest1) {
  // 8053
  decimal src1, origin;
  // src1 = 2;

  src1.bits[0] = 2;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 2;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest2) {
  // 8074
  decimal src1, origin;
  // src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest3) {
  // 8095
  decimal src1, origin;
  // src1 = -3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest4) {
  // 8116
  decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest5) {
  // 8137
  decimal src1, origin;
  // src1 = -9878798789;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b01001100110100101000000111000101;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest6) {
  // 8158
  decimal src1, origin;
  // src1 = -545454512454545.35265;

  src1.bits[0] = 0b11011110101101001010101001100001;
  src1.bits[1] = 0b11110100111110000101111011101001;
  src1.bits[2] = 0b00000000000000000000000000000010;
  src1.bits[3] = 0b10000000000001010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest7) {
  // 8179
  decimal src1, origin;
  // src1 = -5.492654545456454545645464;

  src1.bits[0] = 0b00000111100110110001111110011000;
  src1.bits[1] = 0b01100110010010001001000110100011;
  src1.bits[2] = 0b00000000000001001000101100011101;
  src1.bits[3] = 0b10000000000110000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest8) {
  // 8200
  decimal src1, origin;
  // src1 = 7961327845421.879754123131254;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b10100100000111100100000000101110;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest9) {
  // 8221
  decimal src1, origin;
  // src1 = -12345677.187654345678987654346;

  src1.bits[0] = 0b01111000100010101111010011001010;
  src1.bits[1] = 0b01100010000010101110010010000111;
  src1.bits[2] = 0b00100111111001000001101011010101;
  src1.bits[3] = 0b10000000000101010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest10) {
  // 8242
  decimal src1, origin;
  // src1 = 2.5986531268974139743;

  src1.bits[0] = 0b10101111110010001101100101011111;
  src1.bits[1] = 0b01101000101000101011010010000001;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest11) {
  // 8263
  decimal src1, origin;
  // src1 = 1;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest12) {
  // 8284
  decimal src1, origin;
  // src1 = 1.1;

  src1.bits[0] = 0b00000000000000000000000000001011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest13) {
  // 8305
  decimal src1, origin;
  // src1 = -1.1;

  src1.bits[0] = 0b00000000000000000000000000001011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest14) {
  // 8326
  decimal src1, origin;
  // src1 = 24.56;

  src1.bits[0] = 0b00000000000000000000100110011000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000011001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(MyRoundTest15) {
  // 8347
  decimal src1, origin;
  // src1 = -2.124;

  src1.bits[0] = 0b00000000000000000000100001001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  MyRound(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_1) {
  decimal value_1 = {{7464923, 0, 0, 0}};
  set_exp(&value_1, 5);
  decimal check = {{75, 0, 0, 0}};
  decimal result;
  int return_value = MyRound(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(round_2) {
  decimal value_1 = {{7444923, 0, 0, 0}};
  set_exp(&value_1, 5);
  decimal check = {{75, 0, 0, 0}};
  decimal result;
  int return_value = MyRound(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(round_3) {
  decimal value_1 = {{7464923, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_exp(&value_1, 5);
  decimal check = {{75, 0, 0, 0}};
  set_sign(&check, 1);
  decimal result;
  int return_value = MyRound(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(round_4) {
  decimal value_1 = {{7444923, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_exp(&value_1, 5);
  decimal check = {{75, 0, 0, 0}};
  set_sign(&check, 1);
  decimal result;
  int return_value = MyRound(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *test_round(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("MyRound");
  tc = tcase_create("round");
  tcase_add_test(tc, MyRound_1);
  tcase_add_test(tc, MyRound_2);
  tcase_add_test(tc, MyRound_3);
  tcase_add_test(tc, MyRound_4);
  tcase_add_test(tc, MyRound_5);
  tcase_add_test(tc, MyRound_6);
  tcase_add_test(tc, MyRound_7);
  tcase_add_test(tc, MyRound_8);
  tcase_add_test(tc, MyRound_9);
  tcase_add_test(tc, MyRound_11);
  tcase_add_test(tc, MyRound_12);
  tcase_add_test(tc, MyRound_13);

  tcase_add_test(tc, MyRoundTest1);
  tcase_add_test(tc, MyRoundTest2);
  tcase_add_test(tc, MyRoundTest3);
  tcase_add_test(tc, MyRoundTest4);
  tcase_add_test(tc, MyRoundTest5);
  tcase_add_test(tc, MyRoundTest6);
  tcase_add_test(tc, MyRoundTest7);
  tcase_add_test(tc, MyRoundTest8);
  tcase_add_test(tc, MyRoundTest9);
  tcase_add_test(tc, MyRoundTest10);
  tcase_add_test(tc, MyRoundTest11);
  tcase_add_test(tc, MyRoundTest12);
  tcase_add_test(tc, MyRoundTest13);
  tcase_add_test(tc, MyRoundTest14);
  tcase_add_test(tc, MyRoundTest15);

  tcase_add_test(tc, round_1);
  tcase_add_test(tc, round_2);
  tcase_add_test(tc, round_3);
  tcase_add_test(tc, round_4);

  suite_add_tcase(s, tc);
  return s;
}
// truncate

START_TEST(trun_1) {
  decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000011010011;  // 21.1
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000000010101;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(trun_2) {
  decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000010100101;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000000010000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(trun_4) {
  decimal dec1;
  dec1.bits[0] = 0b10000000000000000000000010100101;  // 214.7483813
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  float num = 0.0;
  from_decimal_to_float(dec1, &num);
  decimal result;
  result.bits[0] = 0b00000000000000000000000011010110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_1) {
  decimal dec1;

  dec1.bits[3] = 0x000A0000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  decimal result;
  result.bits[3] = 0x0;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x6DF37F67;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_2) {
  decimal dec1;

  dec1.bits[3] = 0b10000000000011000000000000000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  decimal result;
  result.bits[3] = 0b10000000000000000000000000000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x1197998;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_4) {
  decimal dec1;

  dec1.bits[0] = 0b00000000000000000000000001101101;
  dec1.bits[1] = 0b00000000000011000110010101011011;
  dec1.bits[2] = 0b00000000000000000011000000111001;
  dec1.bits[3] = 0b00000000000011100000000000000000;
  decimal result;
  result.bits[0] = 0b10000111101111000001011000011110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_6) {
  decimal dec1;

  dec1.bits[3] = 0x80090000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xFFFFEA34;
  dec1.bits[0] = 0xFF837E4F;
  decimal result;
  truncate(dec1, &result);
  decimal res1;

  res1.bits[3] = 0x80000000;
  res1.bits[2] = 0;
  res1.bits[1] = 0x4;
  res1.bits[0] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncate_7) {
  decimal dec1;

  dec1.bits[0] = 0b11010000101000110011000001101101;
  dec1.bits[1] = 0b00011111100110100110101101011000;
  dec1.bits[2] = 0;
  dec1.bits[3] = 0b00000000000010010000000000000000;
  decimal result;
  truncate(dec1, &result);
  decimal result_origin;
  result_origin.bits[3] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b10000111101111000001011000011110;
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncate_8) {
  decimal dec1;

  dec1.bits[0] = 0b01111000101001111011110011000110;
  dec1.bits[1] = 0b10011111111111001111101010000100;
  dec1.bits[2] = 0b00011111111010011010111101101101;
  dec1.bits[3] = 0b00000000000111000000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncateTest2) {
  // 6787
  decimal src1, origin;
  // src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest3) {
  // 6808
  decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest4) {
  // 6829
  decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest6) {
  // 6871
  decimal src1, origin;
  // src1 = -545454512454545.35265454545645;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest7) {
  // 6892
  decimal src1, origin;
  // src1 = -5.492654545456454545645464;

  src1.bits[0] = 0b00000111100110110001111110011000;
  src1.bits[1] = 0b01100110010010001001000110100011;
  src1.bits[2] = 0b00000000000001001000101100011101;
  src1.bits[3] = 0b10000000000110000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest8) {
  // 6913
  decimal src1, origin;
  // src1 = 7961327845421.879754123131254;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest9) {
  // 6934
  decimal src1, origin;
  // src1 = -12345677.187654345678987654346;

  src1.bits[0] = 0b01111000100010101111010011001010;
  src1.bits[1] = 0b01100010000010101110010010000111;
  src1.bits[2] = 0b00100111111001000001101011010101;
  src1.bits[3] = 0b10000000000101010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest10) {
  // 6955
  decimal src1, origin;
  // src1 = 2.5086531268974139743;

  src1.bits[0] = 0b01100101111011101101100101011111;
  src1.bits[1] = 0b01011100001001010100001101000110;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

Suite *test_truncate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("truncate");
  tc = tcase_create("case_truncate");
  tcase_add_test(tc, trun_1);
  tcase_add_test(tc, trun_2);
  tcase_add_test(tc, trun_4);
  tcase_add_test(tc, truncate_1);
  tcase_add_test(tc, truncate_2);

  tcase_add_test(tc, truncate_4);
  tcase_add_test(tc, truncate_6);
  tcase_add_test(tc, truncate_7);
  tcase_add_test(tc, truncate_8);

  tcase_add_test(tc, truncateTest2);
  tcase_add_test(tc, truncateTest3);
  tcase_add_test(tc, truncateTest4);

  tcase_add_test(tc, truncateTest6);
  tcase_add_test(tc, truncateTest7);
  tcase_add_test(tc, truncateTest8);
  tcase_add_test(tc, truncateTest9);
  tcase_add_test(tc, truncateTest10);

  suite_add_tcase(s, tc);
  return s;
}
// negate
START_TEST(negate_0) {
  decimal val = {{2, 0, 0, 0}};
  decimal res = {{0}};
  int sign_before = get_sign(val);
  negate(val, &res);
  int sign_after = get_sign(res);

  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_1) {
  decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  decimal res;
  int sign_before = get_sign(val);
  negate(val, &res);
  int sign_after = get_sign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_2) {
  decimal val = {{0, 0, 0, ~(UINT_MAX / 2)}};
  decimal res = {{0}};
  int sign_before = get_sign(val);
  negate(val, &res);
  int sign_after = get_sign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_5) {
  decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
  set_sign(&value_1, 1);
  decimal check = {{5, 0xFFFFFFFF, 0, 0}};
  decimal result = {0};
  int return_value = negate(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(negate_6) {
  decimal value_1 = {{1, 1, 1, 0}};
  decimal check = {{1, 1, 1, 0x80000000}};
  decimal result = {0};
  int return_value = negate(value_1, &result);
  ck_assert_int_eq(is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(negate_7) {
  float a = 10.1234e5;
  float res_a = 0;
  decimal src = {0};
  from_float_to_decimal(a, &src);
  decimal res = {0};
  negate(src, &res);
  from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

Suite *test_negate(void) {
  Suite *s = suite_create("negate");
  TCase *tc = tcase_create("negate");

  tcase_add_test(tc, negate_0);
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_5);
  tcase_add_test(tc, negate_6);
  tcase_add_test(tc, negate_7);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int failed = 0;
  Suite *decimal_test[] = {
      // additional
      test_floor(), test_truncate(), test_negate(),

      // wrd
      test_from_decimal_to_float(), test_round(),

      // arith
      test_mul(), test_sub(), test_add(), test_div(),
      // sravn
      test_is_equal(), test_is_not_equal(), test_is_greater_or_equal(),
      test_is_greater(), test_is_less(), test_is_less_or_equal(),
      // convert
      test_from_float_to_decimal(),

      test_from_decimal_to_int(), test_from_int_to_decimal(),

      NULL};

  for (int i = 0; decimal_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(decimal_test[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);

    if (failed == 0)
      printf(GREEN "Success\n" WHITE);
    else
      printf(RED "Failed\n" WHITE);

    failed = 0;
  }

  return 0;
}
