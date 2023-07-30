#pragma once

#include "src/cpp-template/header/int-alias.hpp"

#include <initializer_list>

namespace luz::internal_primality_test {

  template < typename T1, typename T2 >
  T1 mod_pow(T1 b, T1 e, T1 mod) {
    if (mod == 1) return 0;

    T1 ans{1};
    while (e) {
      if (e & 1) {
        ans = T2(ans) * b % mod;
      }

      b = T2(b) * b % mod;
      e >>= 1;
    }

    return ans;
  }

  template < typename T1, typename T2 >
  bool is_prime(T1 n, std::initializer_list< T1 > ws) {
    if (n == 2) return true;
    if (n == 1 or n % 2 == 0) return false;

    T1 k = (n - 1) & -(n - 1);
    T1 d = (n - 1) / k;

    for (T1 a: ws) {
      if (n <= a) break;

      T1 t = d;
      T1 y = mod_pow< T1, T2 >(a, t, n);
      while (t != n - 1 and y != 1 and y != n - 1) {
        y = T2(y) * y % n;
        t = T2(t) * 2 % n;
      }

      if (y != n - 1 and t % 2 == 0) {
        return false;
      }
    }

    return true;
  }

  bool is_prime_u32(u32 n) {
    return is_prime< u32, u64 >(n, {2, 7, 61});
  }

  bool is_prime_u64(u64 n) {
    return is_prime< u64, u128 >(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
  }

} // namespace luz::internal_primality_test

namespace luz {

  bool is_prime(u64 n) {
    if (n == 2) return true;
    if (n == 1 or n % 2 == 0) return false;

    if (n < u64(1) << 32) {
      return internal_primality_test::is_prime_u32(n);
    } else {
      return internal_primality_test::is_prime_u64(n);
    }
  }

} // namespace luz
