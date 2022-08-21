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
    path: src/graph/offline-query-lowest-common-ancestor.hpp
    title: src/graph/offline-query-lowest-common-ancestor.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_1_a.test.cpp
    title: test/aoj/dsl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_5_c.test.cpp
    title: test/aoj/grl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc177_d.test.cpp
    title: test/atcoder/abc177_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind.test.cpp
    title: test/library-checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 2 \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include <cstdint>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n\
    \  using u64 = std::uint64_t;\n  \n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace\
    \ luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
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
    \ }\n  };\n\n} // namespace luz\n#line 5 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#line 7 \"src/data-structure/disjoint-set-union.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion {\n    usize\
    \ n_;\n\n    // vals_[v] :=\n    //   if v is root node: -1 * component size\n\
    \    //   otherwise: parent node\n    std::vector< isize > vals_;\n\n    void\
    \ bound_check(usize v) const {\n      assert(v < n_);\n    }\n\n    usize impl_leader(usize\
    \ v) {\n      if (vals_[v] < 0) return v;\n      return vals_[v] = leader(vals_[v]);\n\
    \    }\n\n   public:\n    DisjointSetUnion() = default;\n    explicit DisjointSetUnion(usize\
    \ n): n_(n), vals_(n, -1) {}\n\n    usize size() const {\n      return n_;\n \
    \   }\n\n    usize leader(usize v) {\n      bound_check(v);\n      return impl_leader(v);\n\
    \    }\n\n    bool same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n\
    \      return impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize\
    \ u, usize v) {\n      bound_check(u); bound_check(v);\n\n      isize x = impl_leader(u);\n\
    \      isize y = impl_leader(v);\n      if (x == y) return x;\n      if (-vals_[x]\
    \ < -vals_[y]) std::swap(x, y);\n      vals_[x] += vals_[y];\n      vals_[y] =\
    \ x;\n      return x;\n    }\n\n    usize group_size(usize v) {\n      bound_check(v);\n\
    \      return -vals_[impl_leader(v)];\n    }\n\n    std::vector< std::vector<\
    \ usize > > groups() {\n      std::vector< std::vector< usize > > result(n_);\n\
    \n      std::vector< usize > leaders(n_), g_sizes(n_);\n      for (usize v: rep(0,\
    \ n_)) {\n        leaders[v] = impl_leader(v);\n        g_sizes[leaders[v]]++;\n\
    \      }\n      for (usize v: rep(0, n_)) {\n        result[v].reserve(g_sizes[v]);\n\
    \      }\n      for (usize v: rep(0, n_)) {\n        result[leaders[v]].emplace_back(v);\n\
    \      }\n\n      auto empty_check = [](const std::vector< usize > &vs) {\n  \
    \      return vs.empty();\n      };\n      result.erase(\n        std::remove_if(result.begin(),\
    \ result.end(), empty_check),\n        result.end()\n      );\n\n      return\
    \ result;\n    }\n\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n#include\
    \ \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion {\n    usize\
    \ n_;\n\n    // vals_[v] :=\n    //   if v is root node: -1 * component size\n\
    \    //   otherwise: parent node\n    std::vector< isize > vals_;\n\n    void\
    \ bound_check(usize v) const {\n      assert(v < n_);\n    }\n\n    usize impl_leader(usize\
    \ v) {\n      if (vals_[v] < 0) return v;\n      return vals_[v] = leader(vals_[v]);\n\
    \    }\n\n   public:\n    DisjointSetUnion() = default;\n    explicit DisjointSetUnion(usize\
    \ n): n_(n), vals_(n, -1) {}\n\n    usize size() const {\n      return n_;\n \
    \   }\n\n    usize leader(usize v) {\n      bound_check(v);\n      return impl_leader(v);\n\
    \    }\n\n    bool same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n\
    \      return impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize\
    \ u, usize v) {\n      bound_check(u); bound_check(v);\n\n      isize x = impl_leader(u);\n\
    \      isize y = impl_leader(v);\n      if (x == y) return x;\n      if (-vals_[x]\
    \ < -vals_[y]) std::swap(x, y);\n      vals_[x] += vals_[y];\n      vals_[y] =\
    \ x;\n      return x;\n    }\n\n    usize group_size(usize v) {\n      bound_check(v);\n\
    \      return -vals_[impl_leader(v)];\n    }\n\n    std::vector< std::vector<\
    \ usize > > groups() {\n      std::vector< std::vector< usize > > result(n_);\n\
    \n      std::vector< usize > leaders(n_), g_sizes(n_);\n      for (usize v: rep(0,\
    \ n_)) {\n        leaders[v] = impl_leader(v);\n        g_sizes[leaders[v]]++;\n\
    \      }\n      for (usize v: rep(0, n_)) {\n        result[v].reserve(g_sizes[v]);\n\
    \      }\n      for (usize v: rep(0, n_)) {\n        result[leaders[v]].emplace_back(v);\n\
    \      }\n\n      auto empty_check = [](const std::vector< usize > &vs) {\n  \
    \      return vs.empty();\n      };\n      result.erase(\n        std::remove_if(result.begin(),\
    \ result.end(), empty_check),\n        result.end()\n      );\n\n      return\
    \ result;\n    }\n\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: false
  path: src/data-structure/disjoint-set-union.hpp
  requiredBy:
  - src/graph/offline-query-lowest-common-ancestor.hpp
  timestamp: '2022-08-06 17:20:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/unionfind.test.cpp
  - test/aoj/grl_5_c.test.cpp
  - test/aoj/dsl_1_a.test.cpp
  - test/atcoder/abc177_d.test.cpp
documentation_of: src/data-structure/disjoint-set-union.hpp
layout: document
title: Disjoint Set Union (Union Find)
---

## コンストラクタ
```
DisjointSetUnion<T>(usize n)
```

$1$ 要素の集合 $n$ 個で集合を初期化する。

### 制約
- $0 \leq n$

### 計算量
- $O(n)$


## size
```
usize size() const
```

グラフの頂点集合のサイズを返す。

[ac-library の DSU](https://atcoder.github.io/ac-library/document_ja/dsu.html) の `size()` とは仕様が異なるため注意。
こちらと同じ動作をする関数として `group_size()` が用意されている。

### 計算量
- $O(1)$


## leader
```
usize leader(usize v)
```

頂点 `v` が属する連結成分の代表元を返す。

### 制約
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## same
```
bool same(usize u, usize v)
```

頂点 `u`, `v` が連結ならば `true` を、そうでないならば `false` を返す。

### 制約
- $0 \leq u < n$
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## merge
```
usize merge(usize u, usize v)
```

`u`, `v` が属する連結成分を連結し、連結後の代表元を返す。

### 制約
- $0 \leq u < n$
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## group_size
```
usize group_size(usize v)
```

頂点 `v` が属する連結成分の頂点集合のサイズを返す。

### 制約
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## groups
```
std::vector< std::vector< usize > > groups()
```

連結成分の頂点番号の集合のリストを返す。

連結成分の順番は未定義。各連結成分内の頂点番号は昇順になっている。

### 計算量
- $O(n)$
