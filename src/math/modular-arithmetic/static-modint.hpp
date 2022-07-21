#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>

namespace luz {

  template< u32 mod >
  class StaticPrimeModInt {
    using mint = StaticPrimeModInt;
    u32 v_;

   public:
     StaticPrimeModInt(): v_(0) {}

     template< typename T >
     StaticPrimeModInt(T v) {
       i64 x = (i64)(v % mod);
       if (x < 0) x += mod;
       v_ = (u32)x;
     }

     u32 val() const { return v_; }

     mint &operator+=(const mint &rhs) {
       v_ += rhs.v_;
       if (v_ >= mod) v_ -= mod;
       return *this;
     }
     mint &operator-=(const mint &rhs) {
       v_ += mod - rhs.v_;
       if (v_ >= mod) v_ -= mod;
       return *this;
     }
     mint &operator*=(const mint &rhs) {
       v_ = (u32)(u64(1) * v_ * rhs.v_ % mod);
       return *this;
     }
     mint &operator/=(const mint &rhs) {
       *this *= rhs.inverse();
       return *this;
     }

     mint operator+() const { return *this; }
     mint operator-() const { return mint() - *this; }

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
     friend mint operator/(const mint &lhs, const mint &rhs) {
       return mint(lhs) /= rhs;
     }

     friend mint operator==(const mint &lhs, const mint &rhs) {
       return lhs.v_ == rhs.v_;
     }
     friend mint operator!=(const mint &lhs, const mint &rhs) {
       return lhs.v_ != rhs.v_;
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
       assert(v_ != 0);
       return pow(mod - 2);
     }

  };

  using modint998244353  = StaticPrimeModInt< 998244353 >;
  using modint1000000007 = StaticPrimeModInt< 1000000007 >;

} // namespace luz
