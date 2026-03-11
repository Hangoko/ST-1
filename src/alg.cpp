// Copyright 2025 UNN-CS
#include <cstdint>
#include <limits>
#include <vector>

#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }

  if (value == 2 || value == 3) {
    return true;
  }

  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }

  for (uint64_t divisor = 5; divisor <= value / divisor; divisor += 6) {
    if (value % divisor == 0 || value % (divisor + 2) == 0) {
      return false;
    }
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 2;
  }

  uint64_t count = 1;
  uint64_t candidate = 1;

  while (count < n) {
    candidate += 2;
    if (checkPrime(candidate)) {
      ++count;
    }
  }

  return candidate;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) {
    return 2;
  }

  if (value >= std::numeric_limits<uint64_t>::max() - 1) {
    return 0;
  }

  uint64_t candidate = value + 1;
    if (candidate % 2 == 0) {
    ++candidate;
  }

  while (candidate != 0) {
    if (checkPrime(candidate)) {
      return candidate;
    }

    if (candidate >= std::numeric_limits<uint64_t>::max() - 2) {
      break;
    }

    candidate += 2;
  }

  return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) {
    return 0;
  }

  std::vector<bool> is_prime(hbound, true);
  is_prime[0] = false;
  is_prime[1] = false;

  for (uint64_t value = 2; value <= (hbound - 1) / value; ++value) {
    if (!is_prime[value]) {
      continue;
    }

      // Split long line for cpplint compliance
      for (uint64_t composite = value * value;
           composite < hbound;
           composite += value) {
      is_prime[composite] = false;
    }
  }

  uint64_t sum = 0;
  for (uint64_t value = 2; value < hbound; ++value) {
    if (is_prime[value]) {
      sum += value;
    }
  }

  return sum;
}
