---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/data-structure/fenwick-tree.hpp
    title: Fenwick Tree (Binary Indexed Tree, BIT)
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/data-structure/fenwick-tree.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/data-structure/fenwick-tree.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        ++i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rep(const usize f, const usize l)\
    \ noexcept\n        : f(std::min(f, l)),\n          l(l) {}\n    constexpr auto\
    \ begin() const noexcept {\n      return f;\n    }\n    constexpr auto end() const\
    \ noexcept {\n      return l;\n    }\n  };\n\n  struct rrep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        --i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rrep(const usize f, const usize l)\
    \ noexcept\n        : f(l - 1),\n          l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept {\n      return f;\n    }\n    constexpr auto end()\
    \ const noexcept {\n      return l;\n    }\n  };\n\n} // namespace luz\n#line\
    \ 5 \"src/data-structure/fenwick-tree.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz {\n\n  template < typename T >\n  class FenwickTree {\n    usize\
    \ n;\n    std::vector< T > vals;\n\n    T sum(usize k) const {\n      T result(0);\n\
    \      while (k > 0) {\n        result += vals[k];\n        k -= k & -k;\n   \
    \   }\n      return result;\n    }\n\n   public:\n    FenwickTree() = default;\n\
    \n    explicit FenwickTree(usize n): n(n), vals(n + 1, T()) {}\n\n    explicit\
    \ FenwickTree(const std::vector< T > &as)\n        : n(as.size()),\n         \
    \ vals(as.size() + 1, T()) {\n      for (usize i: rep(1, as.size() + 1)) {\n \
    \       vals[i] = as[i - 1];\n      }\n      for (usize i: rep(1, as.size() +\
    \ 1)) {\n        usize j = i + (i & -i);\n        if (j <= as.size()) {\n    \
    \      vals[j] += vals[i];\n        }\n      }\n    }\n\n    void add(usize k,\
    \ const T &v) {\n      assert(k < n);\n      k++;\n      while (k <= n) {\n  \
    \      vals[k] += v;\n        k += k & -k;\n      }\n    }\n\n    T sum(usize\
    \ l, usize r) const {\n      assert(l <= r and r <= n);\n      return sum(r) -\
    \ sum(l);\n    }\n  };\n\n} // namespace luz\n#line 4 \"unit-test/data-structure/fenwick-tree.test.cpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#line 6 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n#include <iostream>\n\nnamespace luz {\n\n  template < u32 mod >\n  class StaticPrimeModInt\
    \ {\n    using modint = StaticPrimeModInt;\n\n    u32 v;\n\n   public:\n    StaticPrimeModInt():\
    \ v(0) {}\n\n    template < typename T >\n    StaticPrimeModInt(T v_) {\n    \
    \  i64 x = (i64)(v_ % (i64)mod);\n      if (x < 0) x += mod;\n      v = (u32)x;\n\
    \    }\n\n    u32 val() const {\n      return v;\n    }\n\n    modint &operator+=(const\
    \ modint &rhs) {\n      v += rhs.v;\n      if (v >= mod) v -= mod;\n      return\
    \ *this;\n    }\n\n    modint &operator-=(const modint &rhs) {\n      v += mod\
    \ - rhs.v;\n      if (v >= mod) v -= mod;\n      return *this;\n    }\n\n    modint\
    \ &operator*=(const modint &rhs) {\n      v = (u32)(u64(1) * v * rhs.v % mod);\n\
    \      return *this;\n    }\n\n    modint &operator/=(const modint &rhs) {\n \
    \     *this *= rhs.inverse();\n      return *this;\n    }\n\n    modint operator+()\
    \ const {\n      return *this;\n    }\n\n    modint operator-() const {\n    \
    \  return modint() - *this;\n    }\n\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\n      return modint(lhs) += rhs;\n    }\n\n    friend\
    \ modint operator-(const modint &lhs, const modint &rhs) {\n      return modint(lhs)\
    \ -= rhs;\n    }\n\n    friend modint operator*(const modint &lhs, const modint\
    \ &rhs) {\n      return modint(lhs) *= rhs;\n    }\n\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\n      return modint(lhs) /= rhs;\n    }\n\
    \n    friend bool operator==(const modint &lhs, const modint &rhs) {\n      return\
    \ lhs.v == rhs.v;\n    }\n\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\n      return lhs.v != rhs.v;\n    }\n\n    modint pow(i64 n)\
    \ const {\n      assert(0 <= n);\n      modint x = *this, r = 1;\n      while\
    \ (n) {\n        if (n & 1) r *= x;\n        x *= x;\n        n >>= 1;\n     \
    \ }\n      return r;\n    }\n\n    modint inverse() const {\n      assert(v !=\
    \ 0);\n      return pow(mod - 2);\n    }\n\n    static constexpr u32 get_mod()\
    \ {\n      return mod;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os,\n                                    const modint &m) {\n      os << m.val();\n\
    \      return os;\n    }\n  };\n\n  using modint998244353  = StaticPrimeModInt<\
    \ 998244353 >;\n  using modint1000000007 = StaticPrimeModInt< 1000000007 >;\n\n\
    } // namespace luz\n#line 7 \"unit-test/data-structure/fenwick-tree.test.cpp\"\
    \n\n#line 10 \"unit-test/data-structure/fenwick-tree.test.cpp\"\n\nnamespace luz\
    \ {\n\n  void main_() {\n    { // T as i32\n      FenwickTree< i32 > ft(3);\n\n\
    \      ft.add(0, 3);\n      ft.add(1, 6);\n      ft.add(2, -4);\n\n      assert(ft.sum(0,\
    \ 0) == 0);\n      assert(ft.sum(0, 0 + 1) == 3);\n      assert(ft.sum(0, 1 +\
    \ 1) == 9);\n      assert(ft.sum(0, 2 + 1) == 5);\n    }\n\n    { // T as u32\n\
    \      FenwickTree< u32 > ft(3);\n\n      ft.add(0, 5);\n      ft.add(1, 2);\n\
    \      ft.add(2, 1);\n\n      assert(ft.sum(0, 0) == 0);\n      assert(ft.sum(0,\
    \ 0 + 1) == 5);\n      assert(ft.sum(0, 1 + 1) == 7);\n      assert(ft.sum(0,\
    \ 2 + 1) == 8);\n    }\n\n    { // T as i64\n      FenwickTree< i64 > ft(3);\n\
    \n      ft.add(0, 1000000000000ll);\n      ft.add(1, 1000000000000ll);\n     \
    \ ft.add(2, -2000000000000ll);\n\n      assert(ft.sum(0, 0) == 0);\n      assert(ft.sum(0,\
    \ 0 + 1) == 1000000000000ll);\n      assert(ft.sum(0, 1 + 1) == 2000000000000ll);\n\
    \      assert(ft.sum(0, 2 + 1) == 0);\n    }\n\n    { // T as u64\n      FenwickTree<\
    \ u64 > ft(3);\n\n      ft.add(0, 10000000000ull);\n      ft.add(1, 10000000000ull);\n\
    \      ft.add(2, 10000000000ull);\n\n      assert(ft.sum(0, 0) == 0);\n      assert(ft.sum(0,\
    \ 0 + 1) == 10000000000ull);\n      assert(ft.sum(0, 1 + 1) == 20000000000ull);\n\
    \      assert(ft.sum(0, 2 + 1) == 30000000000ull);\n    }\n\n    { // T as ModInt\n\
    \      using mint = modint998244353;\n      FenwickTree< mint > ft(3);\n\n   \
    \   ft.add(1, 5);\n      ft.add(2, 998244352);\n\n      assert(ft.sum(0, 0) ==\
    \ 0);\n      assert(ft.sum(0, 0 + 1) == 0);\n      assert(ft.sum(0, 1 + 1) ==\
    \ 5);\n      assert(ft.sum(0, 2 + 1) == 4);\n    }\n\n    { // T as i32\n    \
    \  FenwickTree< i32 > ft({1, -10, 100, -1000});\n\n      assert(ft.sum(0, 0) ==\
    \ 0);\n      assert(ft.sum(0, 0 + 1) == 1);\n      assert(ft.sum(0, 1 + 1) ==\
    \ -9);\n      assert(ft.sum(0, 2 + 1) == 91);\n      assert(ft.sum(0, 3 + 1) ==\
    \ -909);\n    }\n\n    { // T as u32\n      FenwickTree< u32 > ft({1, 10, 100,\
    \ 1000});\n\n      assert(ft.sum(0, 0) == 0);\n      assert(ft.sum(0, 0 + 1) ==\
    \ 1);\n      assert(ft.sum(0, 1 + 1) == 11);\n      assert(ft.sum(0, 2 + 1) ==\
    \ 111);\n      assert(ft.sum(0, 3 + 1) == 1111);\n    }\n\n    std::cout << \"\
    Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/data-structure/fenwick-tree.hpp\"\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    { // T as i32\n\
    \      FenwickTree< i32 > ft(3);\n\n      ft.add(0, 3);\n      ft.add(1, 6);\n\
    \      ft.add(2, -4);\n\n      assert(ft.sum(0, 0) == 0);\n      assert(ft.sum(0,\
    \ 0 + 1) == 3);\n      assert(ft.sum(0, 1 + 1) == 9);\n      assert(ft.sum(0,\
    \ 2 + 1) == 5);\n    }\n\n    { // T as u32\n      FenwickTree< u32 > ft(3);\n\
    \n      ft.add(0, 5);\n      ft.add(1, 2);\n      ft.add(2, 1);\n\n      assert(ft.sum(0,\
    \ 0) == 0);\n      assert(ft.sum(0, 0 + 1) == 5);\n      assert(ft.sum(0, 1 +\
    \ 1) == 7);\n      assert(ft.sum(0, 2 + 1) == 8);\n    }\n\n    { // T as i64\n\
    \      FenwickTree< i64 > ft(3);\n\n      ft.add(0, 1000000000000ll);\n      ft.add(1,\
    \ 1000000000000ll);\n      ft.add(2, -2000000000000ll);\n\n      assert(ft.sum(0,\
    \ 0) == 0);\n      assert(ft.sum(0, 0 + 1) == 1000000000000ll);\n      assert(ft.sum(0,\
    \ 1 + 1) == 2000000000000ll);\n      assert(ft.sum(0, 2 + 1) == 0);\n    }\n\n\
    \    { // T as u64\n      FenwickTree< u64 > ft(3);\n\n      ft.add(0, 10000000000ull);\n\
    \      ft.add(1, 10000000000ull);\n      ft.add(2, 10000000000ull);\n\n      assert(ft.sum(0,\
    \ 0) == 0);\n      assert(ft.sum(0, 0 + 1) == 10000000000ull);\n      assert(ft.sum(0,\
    \ 1 + 1) == 20000000000ull);\n      assert(ft.sum(0, 2 + 1) == 30000000000ull);\n\
    \    }\n\n    { // T as ModInt\n      using mint = modint998244353;\n      FenwickTree<\
    \ mint > ft(3);\n\n      ft.add(1, 5);\n      ft.add(2, 998244352);\n\n      assert(ft.sum(0,\
    \ 0) == 0);\n      assert(ft.sum(0, 0 + 1) == 0);\n      assert(ft.sum(0, 1 +\
    \ 1) == 5);\n      assert(ft.sum(0, 2 + 1) == 4);\n    }\n\n    { // T as i32\n\
    \      FenwickTree< i32 > ft({1, -10, 100, -1000});\n\n      assert(ft.sum(0,\
    \ 0) == 0);\n      assert(ft.sum(0, 0 + 1) == 1);\n      assert(ft.sum(0, 1 +\
    \ 1) == -9);\n      assert(ft.sum(0, 2 + 1) == 91);\n      assert(ft.sum(0, 3\
    \ + 1) == -909);\n    }\n\n    { // T as u32\n      FenwickTree< u32 > ft({1,\
    \ 10, 100, 1000});\n\n      assert(ft.sum(0, 0) == 0);\n      assert(ft.sum(0,\
    \ 0 + 1) == 1);\n      assert(ft.sum(0, 1 + 1) == 11);\n      assert(ft.sum(0,\
    \ 2 + 1) == 111);\n      assert(ft.sum(0, 3 + 1) == 1111);\n    }\n\n    std::cout\
    \ << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n\
    \  luz::main_();\n}\n"
  dependsOn:
  - src/data-structure/fenwick-tree.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  isVerificationFile: true
  path: unit-test/data-structure/fenwick-tree.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/data-structure/fenwick-tree.test.cpp
layout: document
redirect_from:
- /verify/unit-test/data-structure/fenwick-tree.test.cpp
- /verify/unit-test/data-structure/fenwick-tree.test.cpp.html
title: unit-test/data-structure/fenwick-tree.test.cpp
---
