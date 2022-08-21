---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_b.test.cpp
    title: test/aoj/dsl_2_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/data-structure/fenwick-tree.test.cpp
    title: unit-test/data-structure/fenwick-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/fenwick-tree.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line\
    \ 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace luz\
    \ {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { ++i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rep(const usize f, const usize l) noexcept\n\
    \      : f(std::min(f, l)), l(l) {}\n    constexpr auto begin() const noexcept\
    \ { return f; }\n    constexpr auto end() const noexcept { return l; }\n  };\n\
    \n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { --i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rrep(const usize f, const usize l) noexcept\n\
    \      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr auto begin() const\
    \ noexcept { return f; }\n    constexpr auto end() const noexcept { return l;\
    \ }\n  };\n\n} // namespace luz\n#line 5 \"src/data-structure/fenwick-tree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\nnamespace luz {\n \n  template< typename\
    \ T >\n  class FenwickTree {\n    usize n_;\n    std::vector< T > vals_;\n \n\
    \    T sum(usize k) const {\n      T result(0);\n      while (k > 0) {\n     \
    \   result += vals_[k];\n        k -= k & -k;\n      }\n      return result;\n\
    \    }\n \n   public:\n    FenwickTree() = default;\n\n    explicit FenwickTree(usize\
    \ n): n_(n), vals_(n + 1, T()) {}\n\n    explicit FenwickTree(const std::vector<\
    \ T > &as) :\n        n_(as.size()), vals_(as.size() + 1, T()) {\n      for (usize\
    \ i : rep(1, as.size() + 1)) {\n        vals_[i] = as[i - 1];\n      }\n     \
    \ for (usize i : rep(1, as.size() + 1)) {\n        usize j = i + (i & -i);\n \
    \       if (j <= as.size()) {\n          vals_[j] += vals_[i];\n        }\n  \
    \    }\n    }\n    \n    void add(usize k, const T &v) {\n      assert(0 <= k\
    \ and k < n_);\n      k++;\n      while (k <= n_) {\n        vals_[k] += v;\n\
    \        k += k & -k;\n      }\n    }\n \n    T sum(usize l, usize r) const {\n\
    \      assert(0 <= l and l <= r and r <= n_);\n      return sum(r) - sum(l);\n\
    \    }\n \n  };\n \n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n#include\
    \ \"src/cpp-template/header/rep.hpp\"\n\n#include <vector>\n#include <cassert>\n\
    \nnamespace luz {\n \n  template< typename T >\n  class FenwickTree {\n    usize\
    \ n_;\n    std::vector< T > vals_;\n \n    T sum(usize k) const {\n      T result(0);\n\
    \      while (k > 0) {\n        result += vals_[k];\n        k -= k & -k;\n  \
    \    }\n      return result;\n    }\n \n   public:\n    FenwickTree() = default;\n\
    \n    explicit FenwickTree(usize n): n_(n), vals_(n + 1, T()) {}\n\n    explicit\
    \ FenwickTree(const std::vector< T > &as) :\n        n_(as.size()), vals_(as.size()\
    \ + 1, T()) {\n      for (usize i : rep(1, as.size() + 1)) {\n        vals_[i]\
    \ = as[i - 1];\n      }\n      for (usize i : rep(1, as.size() + 1)) {\n     \
    \   usize j = i + (i & -i);\n        if (j <= as.size()) {\n          vals_[j]\
    \ += vals_[i];\n        }\n      }\n    }\n    \n    void add(usize k, const T\
    \ &v) {\n      assert(0 <= k and k < n_);\n      k++;\n      while (k <= n_) {\n\
    \        vals_[k] += v;\n        k += k & -k;\n      }\n    }\n \n    T sum(usize\
    \ l, usize r) const {\n      assert(0 <= l and l <= r and r <= n_);\n      return\
    \ sum(r) - sum(l);\n    }\n \n  };\n \n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: false
  path: src/data-structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2022-08-04 00:52:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_b.test.cpp
  - unit-test/data-structure/fenwick-tree.test.cpp
documentation_of: src/data-structure/fenwick-tree.hpp
layout: document
title: Fenwick Tree (Binary Indexed Tree, BIT)
---

長さ $n$ の列 $(a_0, a_1, \cdots, a_{n-1})$ に対し

- $a_k$ への加算
- $a_l, a_{l+1}, \cdots, a_{r-1}$ の総和

を $O(\log n)$ で求めることが可能なデータ構造

## コンストラクタ
```
(1) FenwickTree<T>(usize n)
(2) FenwickTree<T>(const std::vector<T> &as)
```

1. 列 $(a_0, a_1, \cdots a_{n-1})$ の全要素を `T()` で初期化する。
2. 列 $(a_0, a_1, \cdots a_{n-1})$ を $a_i = $ `as[i]` として初期化する。

### 制約
- $0 \leq n$

### 計算量
- $O(n)$


## add
```
void add(usize k, const T &v)
```

$a_{k} \leftarrow a_{k} + v$ で更新を行う。

### 制約
- $0 \leq k < n$

### 計算量
- $O(\log n)$


## sum
```
T sum(usize l, usize r) const
```

$a_{l} + a_{l+1} + \cdots + a_{r-1}$ を返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$
