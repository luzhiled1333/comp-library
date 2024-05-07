---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_b/fenwick-tree.test.cpp
    title: test/aoj/dsl_2_b/fenwick-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/data-structure/fenwick-tree.test.cpp
    title: unit-test/data-structure/fenwick-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/fenwick-tree.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/data-structure/fenwick-tree.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ T >\n  class FenwickTree {\n    usize n;\n    std::vector< T > vals;\n\n   \
    \ T sum(usize k) const {\n      T result(0);\n      while (k > 0) {\n        result\
    \ += vals[k];\n        k -= k & -k;\n      }\n      return result;\n    }\n\n\
    \   public:\n    FenwickTree() = default;\n\n    explicit FenwickTree(usize n):\
    \ n(n), vals(n + 1, T()) {}\n\n    explicit FenwickTree(const std::vector< T >\
    \ &as)\n        : n(as.size()),\n          vals(as.size() + 1, T()) {\n      for\
    \ (usize i: rep(1, as.size() + 1)) {\n        vals[i] = as[i - 1];\n      }\n\
    \      for (usize i: rep(1, as.size() + 1)) {\n        usize j = i + (i & -i);\n\
    \        if (j <= as.size()) {\n          vals[j] += vals[i];\n        }\n   \
    \   }\n    }\n\n    void add(usize k, const T &v) {\n      assert(k < n);\n  \
    \    k++;\n      while (k <= n) {\n        vals[k] += v;\n        k += k & -k;\n\
    \      }\n    }\n\n    T sum(usize l, usize r) const {\n      assert(l <= r and\
    \ r <= n);\n      return sum(r) - sum(l);\n    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n\n#include <cassert>\n#include <vector>\n\
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
    \ sum(l);\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/data-structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/data-structure/fenwick-tree.test.cpp
  - test/aoj/dsl_2_b/fenwick-tree.test.cpp
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
