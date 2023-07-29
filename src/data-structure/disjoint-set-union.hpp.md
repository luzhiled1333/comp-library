---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/graph/tree/offline-query/offline-query-jump-on-tree.hpp
    title: "(offine) \u6728\u306E\u30D1\u30B9 $u-v$ \u4E0A\u306E $k$ \u756A\u76EE\u306E\
      \u9802\u70B9 (Offline Jump On Tree)"
  - icon: ':question:'
    path: src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\u7956\u5148 (Offline\
      \ Lowest Common Ancestor)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_1_a.test.cpp
    title: test/aoj/dsl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_5_c/grl_5_c.test.cpp
    title: test/aoj/grl_5_c/grl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc177_d.test.cpp
    title: test/atcoder/abc177_d.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc259_d.test.cpp
    title: test/atcoder/abc259_d.test.cpp
  - icon: ':x:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':x:'
    path: test/library-checker/unionfind.test.cpp
    title: test/library-checker/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 2 \"\
    src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 5 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 7 \"src/data-structure/disjoint-set-union.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion\
    \ {\n    usize n;\n\n    // vals[v] :=\n    //   if v is root node: -1 * component\
    \ size\n    //   otherwise: parent node\n    std::vector< isize > vals;\n\n  \
    \  void bound_check(usize v) const {\n      assert(v < n);\n    }\n\n    usize\
    \ impl_leader(usize v) {\n      if (vals[v] < 0) return v;\n      return vals[v]\
    \ = leader(vals[v]);\n    }\n\n   public:\n    DisjointSetUnion() = default;\n\
    \    explicit DisjointSetUnion(usize n): n(n), vals(n, -1) {}\n\n    usize size()\
    \ const {\n      return n;\n    }\n\n    usize leader(usize v) {\n      bound_check(v);\n\
    \      return impl_leader(v);\n    }\n\n    bool same(usize u, usize v) {\n  \
    \    bound_check(u), bound_check(v);\n      return impl_leader(u) == impl_leader(v);\n\
    \    }\n\n    usize merge(usize u, usize v) {\n      bound_check(u);\n      bound_check(v);\n\
    \n      isize x = impl_leader(u);\n      isize y = impl_leader(v);\n      if (x\
    \ == y) return x;\n      if (-vals[x] < -vals[y]) std::swap(x, y);\n      vals[x]\
    \ += vals[y];\n      vals[y] = x;\n      return x;\n    }\n\n    usize group_size(usize\
    \ v) {\n      bound_check(v);\n      return -vals[impl_leader(v)];\n    }\n\n\
    \    std::vector< std::vector< usize > > groups() {\n      std::vector< std::vector<\
    \ usize > > result(n);\n\n      std::vector< usize > leaders(n), g_sizes(n);\n\
    \      for (usize v: rep(0, n)) {\n        leaders[v] = impl_leader(v);\n    \
    \    g_sizes[leaders[v]]++;\n      }\n      for (usize v: rep(0, n)) {\n     \
    \   result[v].reserve(g_sizes[v]);\n      }\n      for (usize v: rep(0, n)) {\n\
    \        result[leaders[v]].emplace_back(v);\n      }\n\n      auto empty_check\
    \ = [](const std::vector< usize > &vs) {\n        return vs.empty();\n      };\n\
    \      result.erase(\n          std::remove_if(result.begin(), result.end(), empty_check),\n\
    \          result.end());\n\n      return result;\n    }\n  };\n\n} // namespace\
    \ luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion {\n    usize\
    \ n;\n\n    // vals[v] :=\n    //   if v is root node: -1 * component size\n \
    \   //   otherwise: parent node\n    std::vector< isize > vals;\n\n    void bound_check(usize\
    \ v) const {\n      assert(v < n);\n    }\n\n    usize impl_leader(usize v) {\n\
    \      if (vals[v] < 0) return v;\n      return vals[v] = leader(vals[v]);\n \
    \   }\n\n   public:\n    DisjointSetUnion() = default;\n    explicit DisjointSetUnion(usize\
    \ n): n(n), vals(n, -1) {}\n\n    usize size() const {\n      return n;\n    }\n\
    \n    usize leader(usize v) {\n      bound_check(v);\n      return impl_leader(v);\n\
    \    }\n\n    bool same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n\
    \      return impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize\
    \ u, usize v) {\n      bound_check(u);\n      bound_check(v);\n\n      isize x\
    \ = impl_leader(u);\n      isize y = impl_leader(v);\n      if (x == y) return\
    \ x;\n      if (-vals[x] < -vals[y]) std::swap(x, y);\n      vals[x] += vals[y];\n\
    \      vals[y] = x;\n      return x;\n    }\n\n    usize group_size(usize v) {\n\
    \      bound_check(v);\n      return -vals[impl_leader(v)];\n    }\n\n    std::vector<\
    \ std::vector< usize > > groups() {\n      std::vector< std::vector< usize > >\
    \ result(n);\n\n      std::vector< usize > leaders(n), g_sizes(n);\n      for\
    \ (usize v: rep(0, n)) {\n        leaders[v] = impl_leader(v);\n        g_sizes[leaders[v]]++;\n\
    \      }\n      for (usize v: rep(0, n)) {\n        result[v].reserve(g_sizes[v]);\n\
    \      }\n      for (usize v: rep(0, n)) {\n        result[leaders[v]].emplace_back(v);\n\
    \      }\n\n      auto empty_check = [](const std::vector< usize > &vs) {\n  \
    \      return vs.empty();\n      };\n      result.erase(\n          std::remove_if(result.begin(),\
    \ result.end(), empty_check),\n          result.end());\n\n      return result;\n\
    \    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/data-structure/disjoint-set-union.hpp
  requiredBy:
  - src/graph/tree/offline-query/offline-query-jump-on-tree.hpp
  - src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc177_d.test.cpp
  - test/atcoder/abc259_d.test.cpp
  - test/aoj/dsl_1_a.test.cpp
  - test/aoj/grl_5_c/grl_5_c.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
  - test/library-checker/unionfind.test.cpp
documentation_of: src/data-structure/disjoint-set-union.hpp
layout: document
title: Disjoint Set Union (Union Find)
---

## コンストラクタ
```
DisjointSetUnion(usize n)
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
