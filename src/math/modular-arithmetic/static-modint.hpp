#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>

namespace luz {

  template < u32 mod >
  class StaticPrimeModInt {
    using mint = StaticPrimeModInt;

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

    mint &operator+=(const mint &rhs) {
      v += rhs.v;
      if (v >= mod) v -= mod;
      return *this;
    }

    mint &operator-=(const mint &rhs) {
      v += mod - rhs.v;
      if (v >= mod) v -= mod;
      return *this;
    }

    mint &operator*=(const mint &rhs) {
      v = (u32)(u64(1) * v * rhs.v % mod);
      return *this;
    }

    mint &operator/=(const mint &rhs) {
      *this *= rhs.inverse();
      return *this;
    }

    mint operator+() const {
      return *this;
    }

    mint operator-() const {
      return mint() - *this;
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
      return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
      return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
      return mint(lhs) *= rhs;
    }

    friend mint operator/(const mint &lhs, const mint &rhs) {
      return mint(lhs) /= rhs;
    }

    friend bool operator==(const mint &lhs, const mint &rhs) {
      return lhs.v == rhs.v;
    }

    friend bool operator!=(const mint &lhs, const mint &rhs) {
      return lhs.v != rhs.v;
    }

    mint pow(i64 n) const {
      assert(0 <= n);
      mint x = *this, r = 1;
      while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
      }
      return r;
    }

    mint inverse() const {
      assert(v != 0);
      return pow(mod - 2);
    }

    static u32 get_mod() {
      return mod;
    }
  };

  using modint998244353  = StaticPrimeModInt< 998244353 >;
  using modint1000000007 = StaticPrimeModInt< 1000000007 >;

} // namespace luz
