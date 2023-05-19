#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <iostream>
#include <cassert>

namespace luz {

  template < u32 mod >
  class StaticPrimeModInt {
    using modint = StaticPrimeModInt;

    u32 v;

   public:
    StaticPrimeModInt(): v(0) {}

    template < typename T >
    StaticPrimeModInt(T v_) {
      i64 x = (i64)(v_ % (i64)mod);
      if (x < 0) x += mod;
      v = (u32)x;
    }

    u32 val() const {
      return v;
    }

    modint &operator+=(const modint &rhs) {
      v += rhs.v;
      if (v >= mod) v -= mod;
      return *this;
    }

    modint &operator-=(const modint &rhs) {
      v += mod - rhs.v;
      if (v >= mod) v -= mod;
      return *this;
    }

    modint &operator*=(const modint &rhs) {
      v = (u32)(u64(1) * v * rhs.v % mod);
      return *this;
    }

    modint &operator/=(const modint &rhs) {
      *this *= rhs.inverse();
      return *this;
    }

    modint operator+() const {
      return *this;
    }

    modint operator-() const {
      return modint() - *this;
    }

    friend modint operator+(const modint &lhs, const modint &rhs) {
      return modint(lhs) += rhs;
    }

    friend modint operator-(const modint &lhs, const modint &rhs) {
      return modint(lhs) -= rhs;
    }

    friend modint operator*(const modint &lhs, const modint &rhs) {
      return modint(lhs) *= rhs;
    }

    friend modint operator/(const modint &lhs, const modint &rhs) {
      return modint(lhs) /= rhs;
    }

    friend bool operator==(const modint &lhs, const modint &rhs) {
      return lhs.v == rhs.v;
    }

    friend bool operator!=(const modint &lhs, const modint &rhs) {
      return lhs.v != rhs.v;
    }

    modint pow(i64 n) const {
      assert(0 <= n);
      modint x = *this, r = 1;
      while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
      }
      return r;
    }

    modint inverse() const {
      assert(v != 0);
      return pow(mod - 2);
    }

    static constexpr u32 get_mod() {
      return mod;
    }

    friend std::ostream &operator<<(std::ostream &os,
                                    const modint &m) {
      os << m.val();
      return os;
    }
  };

  using modint998244353  = StaticPrimeModInt< 998244353 >;
  using modint1000000007 = StaticPrimeModInt< 1000000007 >;

} // namespace luz
