#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

namespace luz {

  class FastRollingHash {
    static const u64 mod = (1ull << 61ull) - 1;

    const u64 base;
    std::vector< u64 > power;

    static u64 add(u64 a, u64 b) {
      if ((a += b) >= mod) a -= mod;
      return a;
    }

    static u64 mul(u64 a, u64 b) {
      u128 c = u128(a) * b;
      return add(c >> 61, c & mod);
    }

    void expand(usize sz) {
      usize l = power.size(), r = sz + 1;
      if (r <= l) return;

      power.resize(r);
      for (usize i: rep(l, r)) {
        power[i] = mul(power[i - 1], base);
      }
    }

   public:
    using Hs = std::vector< u64 >;

    FastRollingHash(): base(generate_base()), power{1} {}

    explicit FastRollingHash(u64 base): base(base), power{1} {}

    template < class Iter >
    Hs build(Iter first, Iter last) const {
      Hs hs(1);
      hs.reserve(last - first + 1);
      while (first != last) {
        u64 h = add(mul(hs.back(), base), *first);
        hs.emplace_back(h);
        ++first;
      }
      return hs;
    }

    u64 query(const Hs &s, usize first, usize last) {
      expand(last - first);
      return add(s[last], mod - mul(s[first], power[last - first]));
    }

    u64 combine(u64 h1, u64 h2, usize h2len) {
      expand(h2len);
      return add(mul(h1, power[h2len]), h2);
    }

    usize lcp(const Hs &a, usize first1, usize last1, const Hs &b,
              usize first2, usize last2) {
      usize len = std::min(last1 - first1, last2 - first2);
      usize low = 0, high = len + 1;

      while (high - low > 1) {
        usize mid = (low + high) / 2;
        if (query(a, first1, first1 + mid) ==
            query(b, first2, first2 + mid)) {
          low = mid;
        } else {
          high = mid;
        }
      }
      return low;
    }

   private:
    static u64 mod_pow(u64 b, u64 e) {
      u64 res{1};

      while (e) {
        if (e & 1) {
          res = mul(res, b);
        }
        b = mul(b, b);
        e >>= 1;
      }

      return res;
    }

    static bool is_primitive_root(u64 b) {
      constexpr u64 ps[] = {2,  3,  5,  7,   11,  13,
                            31, 41, 61, 151, 331, 1321};
      for (const auto &p: ps) {
        if (mod_pow(b, (mod - 1) / p) == 1) {
          return false;
        }
      }
      return true;
    }

    static u64 generate_base() {
      std::mt19937_64 mt(std::chrono::steady_clock::now()
                             .time_since_epoch()
                             .count());
      std::uniform_int_distribution< u64 > rand(1e9, mod - 1);
      while (true) {
        u64 b = rand(mt);
        if (not is_primitive_root(b)) {
          continue;
        }

        return b;
      }
    }
  };

} // namespace luz
