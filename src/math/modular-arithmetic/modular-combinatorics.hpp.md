---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/small-mod-combination.hpp
    title: "mod \u304C\u5C0F\u3055\u3044\u5834\u5408\u306E combination (Lucas's theorem)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc132_d.test.cpp
    title: test/atcoder/abc132_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc117_c.test.cpp
    title: test/atcoder/arc117_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\n\
    \n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr {\n      usize\
    \ i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n      void operator++()\
    \ noexcept {\n        ++i;\n      }\n      constexpr usize operator*() const noexcept\
    \ {\n        return i;\n      }\n      constexpr bool operator!=(const itr x)\
    \ const noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f,\
    \ l;\n    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
    \ l)),\n          l(l) {}\n    constexpr auto begin() const noexcept {\n     \
    \ return f;\n    }\n    constexpr auto end() const noexcept {\n      return l;\n\
    \    }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       --i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rrep(const usize f, const usize l) noexcept\n        : f(l - 1),\n\
    \          l(std::min(f, l) - 1) {}\n    constexpr auto begin() const noexcept\
    \ {\n      return f;\n    }\n    constexpr auto end() const noexcept {\n     \
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\n  template < typename mint >\n  class\
    \ Combinatorics {\n    static usize bound;\n    static std::vector< mint > fact,\
    \ finv, inv;\n\n    static void expand(usize n) {\n      n += 1;\n      if (fact.size()\
    \ >= n) return;\n\n      if (bound == 0) bound = 1;\n\n      fact.resize(n, mint(1));\n\
    \      finv.resize(n, mint(1));\n      inv.resize(n, mint(1));\n\n      for (usize\
    \ i: rep(bound, n)) {\n        fact[i] = fact[i - 1] * i;\n      }\n\n      finv.back()\
    \ = mint(1) / fact.back();\n      for (usize i: rrep(bound, n)) {\n        finv[i\
    \ - 1] = finv[i] * i;\n      }\n\n      for (usize i: rep(bound, n)) {\n     \
    \   inv[i] = finv[i] * fact[i - 1];\n      }\n\n      bound = n;\n    }\n\n  \
    \ public:\n    explicit Combinatorics(usize n = 0) {\n      expand(n);\n    }\n\
    \n    static mint factorial(usize n) {\n      expand(n);\n      return fact[n];\n\
    \    }\n\n    static mint factorial_inverse(usize n) {\n      expand(n);\n   \
    \   return finv[n];\n    }\n\n    static mint inverse(usize n) {\n      expand(n);\n\
    \      return inv[n];\n    }\n\n    static mint permutation(isize n, isize r)\
    \ {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n      return fact[n]\
    \ * finv[n - r];\n    }\n\n    static mint combination(isize n, isize r) {\n \
    \     if (r < 0 or n < r) return 0;\n\n      expand(n);\n      return fact[n]\
    \ * finv[r] * finv[n - r];\n    }\n\n    static mint combination_with_repetitions(isize\
    \ n, isize r) {\n      if (n < 0 or r < 0) return 0;\n      return (r ? combination(n\
    \ + r - 1, r) : 1);\n    }\n\n    static mint P(isize n, isize r) {\n      return\
    \ permutation(n, r);\n    }\n\n    static mint C(isize n, isize r) {\n      return\
    \ combination(n, r);\n    }\n\n    static mint H(isize n, isize r) {\n      return\
    \ combination_with_repetitions(n, r);\n    }\n  };\n\n  template < typename mint\
    \ >\n  usize Combinatorics< mint >::bound = 0;\n\n  template < typename mint >\n\
    \  std::vector< mint > Combinatorics< mint >::fact =\n      std::vector< mint\
    \ >();\n\n  template < typename mint >\n  std::vector< mint > Combinatorics< mint\
    \ >::finv =\n      std::vector< mint >();\n\n  template < typename mint >\n  std::vector<\
    \ mint > Combinatorics< mint >::inv =\n      std::vector< mint >();\n\n} // namespace\
    \ luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <vector>\n\nnamespace luz\
    \ {\n\n  template < typename mint >\n  class Combinatorics {\n    static usize\
    \ bound;\n    static std::vector< mint > fact, finv, inv;\n\n    static void expand(usize\
    \ n) {\n      n += 1;\n      if (fact.size() >= n) return;\n\n      if (bound\
    \ == 0) bound = 1;\n\n      fact.resize(n, mint(1));\n      finv.resize(n, mint(1));\n\
    \      inv.resize(n, mint(1));\n\n      for (usize i: rep(bound, n)) {\n     \
    \   fact[i] = fact[i - 1] * i;\n      }\n\n      finv.back() = mint(1) / fact.back();\n\
    \      for (usize i: rrep(bound, n)) {\n        finv[i - 1] = finv[i] * i;\n \
    \     }\n\n      for (usize i: rep(bound, n)) {\n        inv[i] = finv[i] * fact[i\
    \ - 1];\n      }\n\n      bound = n;\n    }\n\n   public:\n    explicit Combinatorics(usize\
    \ n = 0) {\n      expand(n);\n    }\n\n    static mint factorial(usize n) {\n\
    \      expand(n);\n      return fact[n];\n    }\n\n    static mint factorial_inverse(usize\
    \ n) {\n      expand(n);\n      return finv[n];\n    }\n\n    static mint inverse(usize\
    \ n) {\n      expand(n);\n      return inv[n];\n    }\n\n    static mint permutation(isize\
    \ n, isize r) {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n   \
    \   return fact[n] * finv[n - r];\n    }\n\n    static mint combination(isize\
    \ n, isize r) {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n   \
    \   return fact[n] * finv[r] * finv[n - r];\n    }\n\n    static mint combination_with_repetitions(isize\
    \ n, isize r) {\n      if (n < 0 or r < 0) return 0;\n      return (r ? combination(n\
    \ + r - 1, r) : 1);\n    }\n\n    static mint P(isize n, isize r) {\n      return\
    \ permutation(n, r);\n    }\n\n    static mint C(isize n, isize r) {\n      return\
    \ combination(n, r);\n    }\n\n    static mint H(isize n, isize r) {\n      return\
    \ combination_with_repetitions(n, r);\n    }\n  };\n\n  template < typename mint\
    \ >\n  usize Combinatorics< mint >::bound = 0;\n\n  template < typename mint >\n\
    \  std::vector< mint > Combinatorics< mint >::fact =\n      std::vector< mint\
    \ >();\n\n  template < typename mint >\n  std::vector< mint > Combinatorics< mint\
    \ >::finv =\n      std::vector< mint >();\n\n  template < typename mint >\n  std::vector<\
    \ mint > Combinatorics< mint >::inv =\n      std::vector< mint >();\n\n} // namespace\
    \ luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/math/modular-arithmetic/modular-combinatorics.hpp
  requiredBy:
  - src/math/modular-arithmetic/small-mod-combination.hpp
  timestamp: '2023-04-25 13:12:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/arc117_c.test.cpp
  - test/atcoder/abc132_d.test.cpp
documentation_of: src/math/modular-arithmetic/modular-combinatorics.hpp
layout: document
title: "mod \u7D44\u5408\u305B (mod combinatorics)"
---

## コンストラクタ
```
Combinatorics<mint>(usize n = 0)
```

### 制約
- $0 \leq n$

### 計算量
- $n + f(p)$
  - $f(p)$ を `mint` の除算にかかる計算量とする。
  - `mint` が扱う $mod$ を $P$ として $O(\log P)$ であることが多い。

## factorial
```
mint factorial(usize n)
```

$n!$ を計算する。

### 制約
- $0 \leq n$

### 計算量
- $O(1)$

## factorial_inverse 
```
mint factorial_inverse(usize n)
```

$(n!)^{-1}$ を計算する。

### 制約
- $0 \leq n$

### 計算量
- $O(1)$

## inverse 
```
mint inverse(usize n)
```

$n^{-1}$ を計算する。

### 制約
- $0 \leq n$

### 計算量
- $O(1)$

## permutation
```
mint permutation(isize n, isize r)
mint P(isize n, isize r)
```

$_n\mathrm{P}_r$ を計算する。

$r < 0$ または $n < r$ のときは $0$ が返る。

### 計算量
- $O(1)$

## combination
```
mint combination(isize n, isize r)
mint C(isize n, isize r)
```

$_n\mathrm{C}_r$ を計算する。

$r < 0$ または $n < r$ のときは $0$ が返る。

### 計算量
- $O(1)$

## combination_with_repetitions
```
mint combination_with_repetitions(isize n, isize r)
mint H(isize n, isize r)
```

$_n\mathrm{H}_r$ を計算する。

$r < 0$ または $n < 0$ のときは $0$ が返る。

ボール $n$ 個、箱$k$ 個の場合は $_k\mathrm{H}_n$ であることに注意。

### 計算量
- $O(1)$
