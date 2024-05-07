---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/utility/pair-hash.hpp
    title: "std::pair \u306E Hash"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp
    title: "(offine) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$\
      \ \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Offline Jump On Functional\
      \ Graph)"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/offline-query/offline-query-jump-on-tree.hpp
    title: "(offine) \u6728\u306E\u30D1\u30B9 $u-v$ \u4E0A\u306E $k$ \u756A\u76EE\u306E\
      \u9802\u70B9 (Offline Jump On Tree)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/offline-algorithm.test.cpp
    title: test/atcoder/abc258_e/offline-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\
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
    \ 2 \"src/utility/pair-hash.hpp\"\n\n#line 4 \"src/utility/pair-hash.hpp\"\n\n\
    #include <functional>\n#include <utility>\n\nnamespace luz {\n\n  class PairHash\
    \ {\n    template < typename T >\n    usize hash_combine(usize hr, const T &x)\
    \ const {\n      usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr <<\
    \ 11) + (hr >> 13));\n    }\n\n   public:\n    template < typename F, typename\
    \ S >\n    usize operator()(const std::pair< F, S > &p) const {\n      return\
    \ hash_combine(hash_combine(0, p.first), p.second);\n    }\n  };\n\n} // namespace\
    \ luz\n#line 6 \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\
    \n\n#include <cassert>\n#include <optional>\n#include <unordered_map>\n#line 11\
    \ \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < class G >\n  class OfflineLAQuery\
    \ {\n    using graph     = G;\n    using cost_type = typename graph::cost_type;\n\
    \n    usize g_size;\n    graph g;\n\n    usize query_count;\n    std::vector<\
    \ std::vector< usize > > qs;\n\n    std::vector< bool > visited;\n    std::vector<\
    \ usize > path;\n\n    using query_type = std::pair< usize, usize >;\n    std::unordered_map<\
    \ query_type, std::optional< usize >, PairHash >\n        results;\n\n    void\
    \ bound_check(usize v) const {\n      assert(v < g_size);\n    }\n\n    void dfs(usize\
    \ v) {\n      visited[v] = true;\n      path.emplace_back(v);\n\n      for (const\
    \ auto &level: qs[v]) {\n        if (level < path.size()) {\n          results[query_type(v,\
    \ level)] = path[level];\n        }\n      }\n\n      for (const auto &e: g[v])\
    \ {\n        if (visited[e.to]) continue;\n        dfs(e.to);\n      }\n\n   \
    \   path.pop_back();\n    }\n\n   public:\n    explicit OfflineLAQuery() = default;\n\
    \n    explicit OfflineLAQuery(graph &g)\n        : g_size(g.size()),\n       \
    \   g(g),\n          query_count(0),\n          qs(g_size),\n          visited(g_size,\
    \ false) {}\n\n    void add_query(usize v, usize level) {\n      bound_check(v);\n\
    \      qs[v].emplace_back(level);\n      query_count++;\n    }\n\n    void build(usize\
    \ root) {\n      bound_check(root);\n      results.reserve(query_count);\n   \
    \   path.reserve(g_size);\n      dfs(root);\n    }\n\n    std::optional< usize\
    \ > la(usize v, usize level) const {\n      bound_check(v);\n      query_type\
    \ qi(v, level);\n      assert(results.count(qi));\n      return (*results.find(qi)).second;\n\
    \    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n#include \"src/utility/pair-hash.hpp\"\
    \n\n#include <cassert>\n#include <optional>\n#include <unordered_map>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace luz {\n\n  template < class G >\n\
    \  class OfflineLAQuery {\n    using graph     = G;\n    using cost_type = typename\
    \ graph::cost_type;\n\n    usize g_size;\n    graph g;\n\n    usize query_count;\n\
    \    std::vector< std::vector< usize > > qs;\n\n    std::vector< bool > visited;\n\
    \    std::vector< usize > path;\n\n    using query_type = std::pair< usize, usize\
    \ >;\n    std::unordered_map< query_type, std::optional< usize >, PairHash >\n\
    \        results;\n\n    void bound_check(usize v) const {\n      assert(v < g_size);\n\
    \    }\n\n    void dfs(usize v) {\n      visited[v] = true;\n      path.emplace_back(v);\n\
    \n      for (const auto &level: qs[v]) {\n        if (level < path.size()) {\n\
    \          results[query_type(v, level)] = path[level];\n        }\n      }\n\n\
    \      for (const auto &e: g[v]) {\n        if (visited[e.to]) continue;\n   \
    \     dfs(e.to);\n      }\n\n      path.pop_back();\n    }\n\n   public:\n   \
    \ explicit OfflineLAQuery() = default;\n\n    explicit OfflineLAQuery(graph &g)\n\
    \        : g_size(g.size()),\n          g(g),\n          query_count(0),\n   \
    \       qs(g_size),\n          visited(g_size, false) {}\n\n    void add_query(usize\
    \ v, usize level) {\n      bound_check(v);\n      qs[v].emplace_back(level);\n\
    \      query_count++;\n    }\n\n    void build(usize root) {\n      bound_check(root);\n\
    \      results.reserve(query_count);\n      path.reserve(g_size);\n      dfs(root);\n\
    \    }\n\n    std::optional< usize > la(usize v, usize level) const {\n      bound_check(v);\n\
    \      query_type qi(v, level);\n      assert(results.count(qi));\n      return\
    \ (*results.find(qi)).second;\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/utility/pair-hash.hpp
  isVerificationFile: false
  path: src/graph/tree/offline-query/offline-query-level-ancestor.hpp
  requiredBy:
  - src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp
  - src/graph/tree/offline-query/offline-query-jump-on-tree.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
  - test/atcoder/abc258_e/offline-algorithm.test.cpp
documentation_of: src/graph/tree/offline-query/offline-query-level-ancestor.hpp
layout: document
title: "\u30AA\u30D5\u30E9\u30A4\u30F3 Level Ancestor (Offline Level Ancestor)"
---

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
OfflineLAQuery(const G &g)
```

Level ancestor を求める木 `g` を渡す。

## add_query
```
void add_query(usize v, usize level)
```

頂点 $v$ の祖先であって深さが $level$ であるような頂点 $la(v, level)$ を求めるクエリを追加する。

後述する `build` をした後、`la(v, level)` によって $la(v, level)$ を得ることができる。

### 制約
- $0 \leq v < \|V\|$

### 計算量
- $O(1)$

## build
```
void build(usize root)
```

頂点 `root` を根とする根付き木上での Level ancestor を計算する。

### 制約
- $0 \leq root < \|V\|$

### 計算量
- $O(\|V\| + Q)$
  - 追加されたクエリの数を $Q$ とする

## la
```
std::optional< usize > la(usize v, usize level)
```

$la(v, level)$ を `std::optional` でラップして返す。根は直近で呼ばれた `build(root)` に依存する。

頂点 $v$ の祖先であって深さが $level$ であるような頂点が存在しないとき `std::nullopt` が返る。

### `la()` の使用例
$la(v, level)$ が存在するときは $la(v, level)$ となる頂点の番号を、そうでない場合 `-1` を出力するサンプル

```
OfflineLAQuery la_query(g);

...

auto la = la_query.la(v, level);

if (la) {
  std::cout << la.value() << std::endl;
} else {
  std::cout << -1 << std::endl;
}
```

### 制約
- `add_query(v, level)` が呼ばれており、かつその後に `build(root)` が呼ばれていること。

### 計算量
- $O(1)$
