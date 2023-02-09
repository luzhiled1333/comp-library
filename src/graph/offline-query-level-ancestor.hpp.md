---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/utility/pair-hash.hpp
    title: "std::pair \u306E Hash"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-jump-on-functional-graph.hpp
    title: "(offine) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$\
      \ \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Offline Jump On Functional\
      \ Graph)"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-jump-on-tree.hpp
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
  bundledCode: "#line 2 \"src/graph/offline-query-level-ancestor.hpp\"\n\n#line 2\
    \ \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\
    \n\n#line 4 \"src/graph/graph-template.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz {\n\n  template < typename cost_type >\n  class Edge {\n   public:\n\
    \    usize from, to;\n    cost_type cost;\n    usize id;\n    Edge() = default;\n\
    \    Edge(usize from_, usize to_, cost_type cost_, usize id_)\n        : from(from_),\n\
    \          to(to_),\n          cost(cost_),\n          id(id_) {}\n  };\n\n  template\
    \ < typename cost_type >\n  using Edges = std::vector< Edge< cost_type > >;\n\n\
    \  template < typename cost_type >\n  class Graph {\n   protected:\n    std::vector<\
    \ std::vector< Edge< cost_type > > > g;\n    usize edge_count;\n\n   public:\n\
    \    Graph() = default;\n    explicit Graph(usize n): g(n), edge_count(0) {}\n\
    \n    usize size() const {\n      return g.size();\n    }\n\n    void add_directed_edge(usize\
    \ from, usize to, cost_type cost = 1) {\n      assert(from < size());\n      assert(to\
    \ < size());\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\
    \n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n     \
    \ assert(u < size());\n      assert(v < size());\n      g[u].emplace_back(u, v,\
    \ cost, edge_count);\n      g[v].emplace_back(v, u, cost, edge_count++);\n   \
    \ }\n\n    inline Edges< cost_type > &operator[](const usize &v) {\n      return\
    \ g[v];\n    }\n\n    inline const Edges< cost_type > &operator[](\n        const\
    \ usize &v) const {\n      return g[v];\n    }\n  };\n\n} // namespace luz\n#line\
    \ 2 \"src/utility/pair-hash.hpp\"\n\n#line 4 \"src/utility/pair-hash.hpp\"\n\n\
    #include <functional>\n#include <utility>\n\nnamespace luz {\n\n  class PairHash\
    \ {\n    template < typename T >\n    usize hash_combine(usize hr, const T &x)\
    \ const {\n      usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr <<\
    \ 11) + (hr >> 13));\n    }\n\n   public:\n    template < typename F, typename\
    \ S >\n    usize operator()(const std::pair< F, S > &p) const {\n      return\
    \ hash_combine(hash_combine(0, p.first), p.second);\n    }\n  };\n\n} // namespace\
    \ luz\n#line 7 \"src/graph/offline-query-level-ancestor.hpp\"\n\n#line 9 \"src/graph/offline-query-level-ancestor.hpp\"\
    \n#include <optional>\n#include <unordered_map>\n#line 13 \"src/graph/offline-query-level-ancestor.hpp\"\
    \n\nnamespace luz {\n\n  template < typename cost_type >\n  class OfflineLAQuery\
    \ {\n    usize g_size_;\n    Graph< cost_type > g_;\n\n    usize query_count_;\n\
    \    std::vector< std::vector< usize > > qs_;\n\n    std::vector< bool > visited_;\n\
    \    std::vector< usize > path_;\n\n    using query_type = std::pair< usize, usize\
    \ >;\n    std::unordered_map< query_type, std::optional< usize >, PairHash >\n\
    \        results_;\n\n    void bound_check(usize v) const {\n      assert(v <\
    \ g_size_);\n    }\n\n    void dfs(usize v) {\n      visited_[v] = true;\n   \
    \   path_.emplace_back(v);\n\n      for (const auto &level: qs_[v]) {\n      \
    \  if (level < path_.size()) {\n          results_[query_type(v, level)] = path_[level];\n\
    \        }\n      }\n\n      for (const auto &e: g_[v]) {\n        if (visited_[e.to])\
    \ continue;\n        dfs(e.to);\n      }\n\n      path_.pop_back();\n    }\n\n\
    \   public:\n    explicit OfflineLAQuery() = default;\n\n    explicit OfflineLAQuery(Graph<\
    \ cost_type > &g)\n        : g_size_(g.size()),\n          g_(g),\n          query_count_(0),\n\
    \          qs_(g_size_),\n          visited_(g_size_, false) {}\n\n    void add_query(usize\
    \ v, usize level) {\n      bound_check(v);\n      qs_[v].emplace_back(level);\n\
    \      query_count_++;\n    }\n\n    void build(usize root) {\n      bound_check(root);\n\
    \      results_.reserve(query_count_);\n      path_.reserve(g_size_);\n      dfs(root);\n\
    \    }\n\n    std::optional< usize > la(usize v, usize level) const {\n      bound_check(v);\n\
    \      query_type qi(v, level);\n      assert(results_.count(qi));\n      return\
    \ (*results_.find(qi)).second;\n    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n#include \"src/graph/graph-template.hpp\"\
    \n#include \"src/utility/pair-hash.hpp\"\n\n#include <cassert>\n#include <optional>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  template < typename cost_type >\n  class OfflineLAQuery {\n    usize\
    \ g_size_;\n    Graph< cost_type > g_;\n\n    usize query_count_;\n    std::vector<\
    \ std::vector< usize > > qs_;\n\n    std::vector< bool > visited_;\n    std::vector<\
    \ usize > path_;\n\n    using query_type = std::pair< usize, usize >;\n    std::unordered_map<\
    \ query_type, std::optional< usize >, PairHash >\n        results_;\n\n    void\
    \ bound_check(usize v) const {\n      assert(v < g_size_);\n    }\n\n    void\
    \ dfs(usize v) {\n      visited_[v] = true;\n      path_.emplace_back(v);\n\n\
    \      for (const auto &level: qs_[v]) {\n        if (level < path_.size()) {\n\
    \          results_[query_type(v, level)] = path_[level];\n        }\n      }\n\
    \n      for (const auto &e: g_[v]) {\n        if (visited_[e.to]) continue;\n\
    \        dfs(e.to);\n      }\n\n      path_.pop_back();\n    }\n\n   public:\n\
    \    explicit OfflineLAQuery() = default;\n\n    explicit OfflineLAQuery(Graph<\
    \ cost_type > &g)\n        : g_size_(g.size()),\n          g_(g),\n          query_count_(0),\n\
    \          qs_(g_size_),\n          visited_(g_size_, false) {}\n\n    void add_query(usize\
    \ v, usize level) {\n      bound_check(v);\n      qs_[v].emplace_back(level);\n\
    \      query_count_++;\n    }\n\n    void build(usize root) {\n      bound_check(root);\n\
    \      results_.reserve(query_count_);\n      path_.reserve(g_size_);\n      dfs(root);\n\
    \    }\n\n    std::optional< usize > la(usize v, usize level) const {\n      bound_check(v);\n\
    \      query_type qi(v, level);\n      assert(results_.count(qi));\n      return\
    \ (*results_.find(qi)).second;\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/graph/graph-template.hpp
  - src/utility/pair-hash.hpp
  isVerificationFile: false
  path: src/graph/offline-query-level-ancestor.hpp
  requiredBy:
  - src/graph/offline-query-jump-on-tree.hpp
  - src/graph/offline-query-jump-on-functional-graph.hpp
  timestamp: '2023-02-10 00:06:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/jump_on_tree.test.cpp
  - test/atcoder/abc258_e/offline-algorithm.test.cpp
  - unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
documentation_of: src/graph/offline-query-level-ancestor.hpp
layout: document
title: "\u30AA\u30D5\u30E9\u30A4\u30F3 Level Ancestor (Offline Level Ancestor)"
---

## コンストラクタ
```
OfflineLAQuery(const Graph<cost_type> &g)
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
