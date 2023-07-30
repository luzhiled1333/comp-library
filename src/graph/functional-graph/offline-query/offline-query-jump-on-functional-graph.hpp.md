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
    path: src/graph/tree/offline-query/offline-query-level-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3 Level Ancestor (Offline Level Ancestor)"
  - icon: ':heavy_check_mark:'
    path: src/utility/pair-hash.hpp
    title: "std::pair \u306E Hash"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/offline-algorithm.test.cpp
    title: test/atcoder/abc258_e/offline-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\
    \n\n#line 2 \"src/utility/pair-hash.hpp\"\n\n#line 4 \"src/utility/pair-hash.hpp\"\
    \n\n#include <functional>\n#include <utility>\n\nnamespace luz {\n\n  class PairHash\
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
    \    }\n  };\n\n} // namespace luz\n#line 8 \"src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp\"\
    \n\n#line 13 \"src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp\"\
    \n\nnamespace luz {\n\n  template < class G >\n  class OfflineJumpOnFunctionalGraphQuery\
    \ {\n    using graph     = G;\n    using cost_type = typename graph::cost_type;\n\
    \n    usize g_size;\n    graph g;\n\n    graph tree;\n    usize tree_root;\n \
    \   std::vector< usize > tree_depth, subtree_roots;\n\n    std::vector< usize\
    \ > loop_id, loop_size, loop_pos;\n    std::vector< std::vector< usize > > loops;\n\
    \n    using query_type = std::pair< usize, u64 >;\n    std::vector< query_type\
    \ > qs;\n    std::unordered_map< query_type, usize, PairHash > result;\n\n   \
    \ void dfs_on_subtree(usize v, usize p) {\n      for (auto &e: tree[v]) {\n  \
    \      usize u = e.to;\n        if (u == p) continue;\n        subtree_roots[u]\
    \ = subtree_roots[v];\n        tree_depth[u]    = tree_depth[v] + 1;\n       \
    \ dfs_on_subtree(u, v);\n      }\n    }\n\n    std::vector< usize > get_indegrees()\
    \ const {\n      std::vector< usize > indegrees(g_size);\n      for (usize v:\
    \ rep(0, g_size)) {\n        for (auto e: g[v]) {\n          indegrees[e.to]++;\n\
    \        }\n      }\n      return indegrees;\n    }\n\n    void construct_tree(std::vector<\
    \ usize > &indegrees) {\n      std::vector< usize > leaves;\n      leaves.reserve(g_size);\n\
    \n      for (usize v: rep(0, g_size)) {\n        if (indegrees[v] > 0) {\n   \
    \       continue;\n        }\n        leaves.emplace_back(v);\n      }\n\n   \
    \   while (not leaves.empty()) {\n        usize child = leaves.back();\n     \
    \   leaves.pop_back();\n\n        usize parent = g[child][0].to;\n        indegrees[parent]--;\n\
    \n        tree.add_undirected_edge(parent, child);\n\n        if (indegrees[parent]\
    \ == 0) {\n          leaves.emplace_back(parent);\n        }\n      }\n\n    \
    \  for (usize v: rep(0, g_size)) {\n        if (indegrees[v] == 0) {\n       \
    \   continue;\n        }\n        tree.add_undirected_edge(tree_root, v);\n  \
    \    }\n\n      tree.initialize();\n\n      for (usize v: rep(0, g_size)) {\n\
    \        if (indegrees[v] == 0) {\n          continue;\n        }\n        subtree_roots[v]\
    \ = v;\n        dfs_on_subtree(v, tree_root);\n      }\n    }\n\n    void construct_loops(std::vector<\
    \ usize > &indegrees) {\n      for (usize v: rep(0, g_size)) {\n        if (indegrees[v]\
    \ == 0) {\n          continue;\n        }\n\n        usize cur = v;\n        std::vector<\
    \ usize > loop;\n        do {\n          loop_id[cur]  = loops.size();\n     \
    \     loop_pos[cur] = loop.size();\n          loop.emplace_back(cur);\n      \
    \    indegrees[cur] = 0;\n          cur            = g[cur][0].to;\n        }\
    \ while (cur != v);\n\n        do {\n          loop_size[cur] = loop.size();\n\
    \          cur            = g[cur][0].to;\n        } while (cur != v);\n\n   \
    \     loops.emplace_back(std::move(loop));\n      }\n    }\n\n   public:\n   \
    \ explicit OfflineJumpOnFunctionalGraphQuery(const graph &g_)\n        : g_size(g_.size()),\n\
    \          g(g_),\n          tree(g_size + 1),\n          tree_root(g_size),\n\
    \          tree_depth(g_size),\n          subtree_roots(g_size),\n          loop_id(g_size),\n\
    \          loop_size(g_size),\n          loop_pos(g_size) {\n      for (usize\
    \ v: rep(0, g_size)) {\n        assert(g[v].size() == 1);\n      }\n\n      std::vector<\
    \ usize > indegrees = get_indegrees();\n      construct_tree(indegrees);\n   \
    \   construct_loops(indegrees);\n    }\n\n    void add_query(usize v, u64 k) {\n\
    \      qs.emplace_back(v, k);\n    }\n\n    void build() {\n      OfflineLAQuery\
    \ la_solver(tree);\n      result.reserve(qs.size());\n      for (auto [v, k]:\
    \ qs) {\n        if (k < tree_depth[v]) {\n          la_solver.add_query(v, tree_depth[v]\
    \ - k + 1);\n        } else {\n          query_type qi(v, k);\n          k -=\
    \ tree_depth[v];\n          usize root       = subtree_roots[v];\n          const\
    \ auto &loop = loops[loop_id[root]];\n          k += loop_pos[root];\n       \
    \   k %= loop_size[root];\n          result[qi] = loop[k];\n        }\n      }\n\
    \      la_solver.build(g_size);\n\n      for (auto [v, k]: qs) {\n        if (tree_depth[v]\
    \ <= k) {\n          continue;\n        }\n        query_type qi(v, k);\n    \
    \    result[qi] = la_solver.la(v, tree_depth[v] - k + 1).value();\n      }\n \
    \   }\n\n    usize jump(usize v, u64 k) const {\n      query_type qi(v, k);\n\
    \      assert(result.count(qi));\n      return result.find(qi)->second;\n    }\n\
    \  };\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n#include\
    \ \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\n\
    #include \"src/utility/pair-hash.hpp\"\n\n#include <cassert>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n\nnamespace luz {\n\n  template < class\
    \ G >\n  class OfflineJumpOnFunctionalGraphQuery {\n    using graph     = G;\n\
    \    using cost_type = typename graph::cost_type;\n\n    usize g_size;\n    graph\
    \ g;\n\n    graph tree;\n    usize tree_root;\n    std::vector< usize > tree_depth,\
    \ subtree_roots;\n\n    std::vector< usize > loop_id, loop_size, loop_pos;\n \
    \   std::vector< std::vector< usize > > loops;\n\n    using query_type = std::pair<\
    \ usize, u64 >;\n    std::vector< query_type > qs;\n    std::unordered_map< query_type,\
    \ usize, PairHash > result;\n\n    void dfs_on_subtree(usize v, usize p) {\n \
    \     for (auto &e: tree[v]) {\n        usize u = e.to;\n        if (u == p) continue;\n\
    \        subtree_roots[u] = subtree_roots[v];\n        tree_depth[u]    = tree_depth[v]\
    \ + 1;\n        dfs_on_subtree(u, v);\n      }\n    }\n\n    std::vector< usize\
    \ > get_indegrees() const {\n      std::vector< usize > indegrees(g_size);\n \
    \     for (usize v: rep(0, g_size)) {\n        for (auto e: g[v]) {\n        \
    \  indegrees[e.to]++;\n        }\n      }\n      return indegrees;\n    }\n\n\
    \    void construct_tree(std::vector< usize > &indegrees) {\n      std::vector<\
    \ usize > leaves;\n      leaves.reserve(g_size);\n\n      for (usize v: rep(0,\
    \ g_size)) {\n        if (indegrees[v] > 0) {\n          continue;\n        }\n\
    \        leaves.emplace_back(v);\n      }\n\n      while (not leaves.empty())\
    \ {\n        usize child = leaves.back();\n        leaves.pop_back();\n\n    \
    \    usize parent = g[child][0].to;\n        indegrees[parent]--;\n\n        tree.add_undirected_edge(parent,\
    \ child);\n\n        if (indegrees[parent] == 0) {\n          leaves.emplace_back(parent);\n\
    \        }\n      }\n\n      for (usize v: rep(0, g_size)) {\n        if (indegrees[v]\
    \ == 0) {\n          continue;\n        }\n        tree.add_undirected_edge(tree_root,\
    \ v);\n      }\n\n      tree.initialize();\n\n      for (usize v: rep(0, g_size))\
    \ {\n        if (indegrees[v] == 0) {\n          continue;\n        }\n      \
    \  subtree_roots[v] = v;\n        dfs_on_subtree(v, tree_root);\n      }\n   \
    \ }\n\n    void construct_loops(std::vector< usize > &indegrees) {\n      for\
    \ (usize v: rep(0, g_size)) {\n        if (indegrees[v] == 0) {\n          continue;\n\
    \        }\n\n        usize cur = v;\n        std::vector< usize > loop;\n   \
    \     do {\n          loop_id[cur]  = loops.size();\n          loop_pos[cur] =\
    \ loop.size();\n          loop.emplace_back(cur);\n          indegrees[cur] =\
    \ 0;\n          cur            = g[cur][0].to;\n        } while (cur != v);\n\n\
    \        do {\n          loop_size[cur] = loop.size();\n          cur        \
    \    = g[cur][0].to;\n        } while (cur != v);\n\n        loops.emplace_back(std::move(loop));\n\
    \      }\n    }\n\n   public:\n    explicit OfflineJumpOnFunctionalGraphQuery(const\
    \ graph &g_)\n        : g_size(g_.size()),\n          g(g_),\n          tree(g_size\
    \ + 1),\n          tree_root(g_size),\n          tree_depth(g_size),\n       \
    \   subtree_roots(g_size),\n          loop_id(g_size),\n          loop_size(g_size),\n\
    \          loop_pos(g_size) {\n      for (usize v: rep(0, g_size)) {\n       \
    \ assert(g[v].size() == 1);\n      }\n\n      std::vector< usize > indegrees =\
    \ get_indegrees();\n      construct_tree(indegrees);\n      construct_loops(indegrees);\n\
    \    }\n\n    void add_query(usize v, u64 k) {\n      qs.emplace_back(v, k);\n\
    \    }\n\n    void build() {\n      OfflineLAQuery la_solver(tree);\n      result.reserve(qs.size());\n\
    \      for (auto [v, k]: qs) {\n        if (k < tree_depth[v]) {\n          la_solver.add_query(v,\
    \ tree_depth[v] - k + 1);\n        } else {\n          query_type qi(v, k);\n\
    \          k -= tree_depth[v];\n          usize root       = subtree_roots[v];\n\
    \          const auto &loop = loops[loop_id[root]];\n          k += loop_pos[root];\n\
    \          k %= loop_size[root];\n          result[qi] = loop[k];\n        }\n\
    \      }\n      la_solver.build(g_size);\n\n      for (auto [v, k]: qs) {\n  \
    \      if (tree_depth[v] <= k) {\n          continue;\n        }\n        query_type\
    \ qi(v, k);\n        result[qi] = la_solver.la(v, tree_depth[v] - k + 1).value();\n\
    \      }\n    }\n\n    usize jump(usize v, u64 k) const {\n      query_type qi(v,\
    \ k);\n      assert(result.count(qi));\n      return result.find(qi)->second;\n\
    \    }\n  };\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/tree/offline-query/offline-query-level-ancestor.hpp
  - src/utility/pair-hash.hpp
  isVerificationFile: false
  path: src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  - test/atcoder/abc258_e/offline-algorithm.test.cpp
documentation_of: src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp
layout: document
title: "(offine) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$ \u56DE\
  \u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Offline Jump On Functional Graph)"
---
 
Functional Graph において、頂点 $v$ からちょうど $k$ 本の辺を辿って到達する頂点を求めるクエリをオフラインで処理する。このようなクエリを $jump(v, k)$ と表記する。

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
OfflineJumpOnFunctionalGraphQuery(const G &g)
```

$jump$ クエリを求めるグラフ $g$ を渡す。

内部では $g$ を loop と tree に分解している。

### 制約
- $g$ は Functional Graph である。
  - $g$ の任意の任意の頂点の出次数は $1$ であるとも言い換えられる。

### 計算量
- $O(\|V\|)$

## add_query
```
void add_query(usize v, u64 k)
```

$jump(v, k)$ を求めるクエリを追加する。

後述する `build` をした後、`jump(v, k)` によってクエリに対する答えを得ることができる。

### 制約
- $0 \leq v < \|V\|$

### 計算量
- $O(1)$

## build
```
void build()
```

$g$ 上での $jump$ クエリを計算する。

### 計算量
- $O(\|V\| + Q)$
  - 追加されたクエリの数を $Q$ とする

## jump
```
usize jump(usize v, u64 k)
```

$jump(v, k)$ を返す。

### 制約
- `add_query(v, k)` が呼ばれており、かつその後に `build()` が呼ばれていること。

### 計算量
- $O(1)$
