// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(st1_checkPrime, returns_false_for_zero) {
  EXPECT_FALSE(checkPrime(0));
}

TEST(st1_checkPrime, returns_false_for_one) {
  EXPECT_FALSE(checkPrime(1));
}

TEST(st1_checkPrime, returns_true_for_small_prime) {
  EXPECT_TRUE(checkPrime(2));
}

TEST(st1_checkPrime, returns_true_for_large_prime) {
  EXPECT_TRUE(checkPrime(97));
}

TEST(st1_checkPrime, returns_false_for_composite) {
  EXPECT_FALSE(checkPrime(100));
}

TEST(st1_nPrime, returns_first_prime) {
  EXPECT_EQ(2, nPrime(1));
}

TEST(st1_nPrime, returns_fifth_prime) {
  EXPECT_EQ(11, nPrime(5));
}

TEST(st1_nPrime, returns_tenth_prime) {
  EXPECT_EQ(29, nPrime(10));
}

TEST(st1_nextPrime, returns_two_after_zero) {
  EXPECT_EQ(2, nextPrime(0));
}

TEST(st1_nextPrime, returns_next_prime_after_composite) {
  EXPECT_EQ(5, nextPrime(4));
}

TEST(st1_nextPrime, skips_current_prime_value) {
  EXPECT_EQ(13, nextPrime(11));
}

TEST(st1_sumPrime, returns_zero_for_small_bound) {
  EXPECT_EQ(0, sumPrime(2));
}

TEST(st1_sumPrime, returns_sum_below_ten) {
  EXPECT_EQ(17, sumPrime(10));
}

TEST(st1_sumPrime, returns_sum_below_thirty) {
  EXPECT_EQ(129, sumPrime(30));
}

TEST(st1_sumPrime, returns_large_reference_sum) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
