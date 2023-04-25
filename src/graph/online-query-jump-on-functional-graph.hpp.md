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
    path: src/utility/bit/bit-width.hpp
    title: "\u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
      \u6700\u5C0F\u306Ebit\u5E45 (bit_width)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/online-algorithm.test.cpp
    title: test/atcoder/abc258_e/online-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/online-query-jump-on-functional-graph.hpp\"\n\n\
    #line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
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
    \ 2 \"src/utility/bit/bit-width.hpp\"\n\n#line 2 \"src/utility/bit/popcount.hpp\"\
    \n\n#line 4 \"src/utility/bit/popcount.hpp\"\n\n#line 6 \"src/utility/bit/popcount.hpp\"\
    \n\nnamespace luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus <= 201703L);\n\
    \n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\n    x -= (x\
    \ >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) + ((x >> 2) &\
    \ 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n    return x\
    \ * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n#line 4 \"src/utility/bit/bit-width.hpp\"\
    \n\n#line 6 \"src/utility/bit/bit-width.hpp\"\n\nnamespace luz {\n\n  usize bit_width(u64\
    \ x) {\n    assert(__cplusplus <= 201703L);\n\n    if (x == 0) {\n      return\
    \ 0;\n    }\n\n#ifdef __GNUC__\n    return 64 - __builtin_clzll(x);\n#endif\n\n\
    \    x |= x >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >> 8;\n    x\
    \ |= x >> 16;\n    x |= x >> 32;\n    return popcount(x);\n  }\n\n} // namespace\
    \ luz\n#line 7 \"src/graph/online-query-jump-on-functional-graph.hpp\"\n\n#line\
    \ 9 \"src/graph/online-query-jump-on-functional-graph.hpp\"\n#include <utility>\n\
    #line 11 \"src/graph/online-query-jump-on-functional-graph.hpp\"\n\nnamespace\
    \ luz {\n\n  template < typename cost_type >\n  class OnlineJumpOnFunctionalGraphQuery\
    \ {\n    usize g_size;\n    Graph< cost_type > g;\n\n    usize LOG;\n    std::vector<\
    \ std::vector< usize > > doubling_table;\n\n    std::vector< usize > loop_id,\
    \ loop_size, loop_pos;\n    std::vector< std::vector< usize > > loops;\n\n   \
    \ void check_functional_graph() const {\n      for (usize v: rep(0, g_size)) {\n\
    \        assert(g[v].size() == 1);\n      }\n    }\n\n    void build_doubling_table()\
    \ {\n      for (usize k: rep(0, LOG)) {\n        for (usize v: rep(0, g_size))\
    \ {\n          doubling_table[k][v] =\n              (k ? doubling_table[k - 1][doubling_table[k\
    \ - 1][v]]\n                 : g[v][0].to);\n        }\n      }\n    }\n\n   \
    \ std::vector< usize > get_indegrees() const {\n      std::vector< usize > indegrees(g_size);\n\
    \      for (usize v: rep(0, g_size)) {\n        indegrees[g[v][0].to]++;\n   \
    \   }\n      return indegrees;\n    }\n\n    void delete_leaves(std::vector< usize\
    \ > &indegrees) {\n      std::vector< usize > leaves;\n      leaves.reserve(g_size);\n\
    \n      for (usize v: rep(0, g_size)) {\n        if (indegrees[v] > 0) {\n   \
    \       continue;\n        }\n        leaves.emplace_back(v);\n      }\n\n   \
    \   while (not leaves.empty()) {\n        usize v = leaves.back();\n        leaves.pop_back();\n\
    \n        usize u = g[v][0].to;\n        indegrees[u]--;\n\n        if (indegrees[u]\
    \ == 0) {\n          leaves.emplace_back(u);\n        }\n      }\n    }\n\n  \
    \  void construct_loops() {\n      std::vector< usize > indegrees = get_indegrees();\n\
    \      delete_leaves(indegrees);\n\n      for (usize v: rep(0, g_size)) {\n  \
    \      if (indegrees[v] == 0) {\n          continue;\n        }\n\n        usize\
    \ cur = v;\n        std::vector< usize > loop;\n\n        do {\n          loop_id[cur]\
    \  = loops.size();\n          loop_pos[cur] = loop.size();\n          loop.emplace_back(cur);\n\
    \          indegrees[cur] = 0;\n          cur            = g[cur][0].to;\n   \
    \     } while (cur != v);\n\n        do {\n          loop_size[cur] = loop.size();\n\
    \          cur            = g[cur][0].to;\n        } while (cur != v);\n\n   \
    \     loops.emplace_back(std::move(loop));\n      }\n    }\n\n    usize jump_small(usize\
    \ v, usize k) const {\n      assert(k < g_size);\n\n      for (usize i: rep(0,\
    \ LOG)) {\n        if ((k & 1) == 1) {\n          v = doubling_table[i][v];\n\
    \        }\n        k >>= 1;\n      }\n      return v;\n    }\n\n   public:\n\
    \    OnlineJumpOnFunctionalGraphQuery(const Graph< cost_type > &g_)\n        :\
    \ g_size(g_.size()),\n          g(g_),\n          LOG(bit_width(g_size - 1)),\n\
    \          doubling_table(LOG, std::vector< usize >(g_size)),\n          loop_id(g_size,\
    \ -1),\n          loop_size(g_size),\n          loop_pos(g_size, -1) {\n     \
    \ check_functional_graph();\n      assert(g_size != 0);\n\n      build_doubling_table();\n\
    \      construct_loops();\n    }\n\n    usize jump(usize v, u64 k) const {\n \
    \     assert(v < g_size);\n\n      if (k == 0) {\n        return v;\n      }\n\
    \n      if (k < g_size) {\n        return jump_small(v, k);\n      }\n\n     \
    \ v = jump_small(v, g_size - 1);\n      k -= (g_size - 1);\n\n      const auto\
    \ &loop = loops[loop_id[v]];\n      k += loop_pos[v];\n      k %= loop_size[v];\n\
    \      return loop[k];\n    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n#include \"src/graph/graph-template.hpp\"\
    \n#include \"src/utility/bit/bit-width.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename cost_type >\n  class\
    \ OnlineJumpOnFunctionalGraphQuery {\n    usize g_size;\n    Graph< cost_type\
    \ > g;\n\n    usize LOG;\n    std::vector< std::vector< usize > > doubling_table;\n\
    \n    std::vector< usize > loop_id, loop_size, loop_pos;\n    std::vector< std::vector<\
    \ usize > > loops;\n\n    void check_functional_graph() const {\n      for (usize\
    \ v: rep(0, g_size)) {\n        assert(g[v].size() == 1);\n      }\n    }\n\n\
    \    void build_doubling_table() {\n      for (usize k: rep(0, LOG)) {\n     \
    \   for (usize v: rep(0, g_size)) {\n          doubling_table[k][v] =\n      \
    \        (k ? doubling_table[k - 1][doubling_table[k - 1][v]]\n              \
    \   : g[v][0].to);\n        }\n      }\n    }\n\n    std::vector< usize > get_indegrees()\
    \ const {\n      std::vector< usize > indegrees(g_size);\n      for (usize v:\
    \ rep(0, g_size)) {\n        indegrees[g[v][0].to]++;\n      }\n      return indegrees;\n\
    \    }\n\n    void delete_leaves(std::vector< usize > &indegrees) {\n      std::vector<\
    \ usize > leaves;\n      leaves.reserve(g_size);\n\n      for (usize v: rep(0,\
    \ g_size)) {\n        if (indegrees[v] > 0) {\n          continue;\n        }\n\
    \        leaves.emplace_back(v);\n      }\n\n      while (not leaves.empty())\
    \ {\n        usize v = leaves.back();\n        leaves.pop_back();\n\n        usize\
    \ u = g[v][0].to;\n        indegrees[u]--;\n\n        if (indegrees[u] == 0) {\n\
    \          leaves.emplace_back(u);\n        }\n      }\n    }\n\n    void construct_loops()\
    \ {\n      std::vector< usize > indegrees = get_indegrees();\n      delete_leaves(indegrees);\n\
    \n      for (usize v: rep(0, g_size)) {\n        if (indegrees[v] == 0) {\n  \
    \        continue;\n        }\n\n        usize cur = v;\n        std::vector<\
    \ usize > loop;\n\n        do {\n          loop_id[cur]  = loops.size();\n   \
    \       loop_pos[cur] = loop.size();\n          loop.emplace_back(cur);\n    \
    \      indegrees[cur] = 0;\n          cur            = g[cur][0].to;\n       \
    \ } while (cur != v);\n\n        do {\n          loop_size[cur] = loop.size();\n\
    \          cur            = g[cur][0].to;\n        } while (cur != v);\n\n   \
    \     loops.emplace_back(std::move(loop));\n      }\n    }\n\n    usize jump_small(usize\
    \ v, usize k) const {\n      assert(k < g_size);\n\n      for (usize i: rep(0,\
    \ LOG)) {\n        if ((k & 1) == 1) {\n          v = doubling_table[i][v];\n\
    \        }\n        k >>= 1;\n      }\n      return v;\n    }\n\n   public:\n\
    \    OnlineJumpOnFunctionalGraphQuery(const Graph< cost_type > &g_)\n        :\
    \ g_size(g_.size()),\n          g(g_),\n          LOG(bit_width(g_size - 1)),\n\
    \          doubling_table(LOG, std::vector< usize >(g_size)),\n          loop_id(g_size,\
    \ -1),\n          loop_size(g_size),\n          loop_pos(g_size, -1) {\n     \
    \ check_functional_graph();\n      assert(g_size != 0);\n\n      build_doubling_table();\n\
    \      construct_loops();\n    }\n\n    usize jump(usize v, u64 k) const {\n \
    \     assert(v < g_size);\n\n      if (k == 0) {\n        return v;\n      }\n\
    \n      if (k < g_size) {\n        return jump_small(v, k);\n      }\n\n     \
    \ v = jump_small(v, g_size - 1);\n      k -= (g_size - 1);\n\n      const auto\
    \ &loop = loops[loop_id[v]];\n      k += loop_pos[v];\n      k %= loop_size[v];\n\
    \      return loop[k];\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/graph/graph-template.hpp
  - src/utility/bit/bit-width.hpp
  - src/utility/bit/popcount.hpp
  isVerificationFile: false
  path: src/graph/online-query-jump-on-functional-graph.hpp
  requiredBy: []
  timestamp: '2023-02-11 04:43:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  - test/atcoder/abc258_e/online-algorithm.test.cpp
documentation_of: src/graph/online-query-jump-on-functional-graph.hpp
layout: document
title: "(online) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$ \u56DE\
  \u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Online Jump On Functional Graph)"
---

Functional Graph において、頂点 $v$ からちょうど $k$ 本の辺を辿って到達する頂点を求めるクエリをオンラインで処理する。このようなクエリを $jump(v, k)$ と表記する。

## コンストラクタ
```
OnlineJumpOnFunctionalGraphQuery(
  const Graph<cost_type> &g
)
```

$jump$ クエリを求めるグラフ $g$ を渡す。

内部では $g$ を loop と tree に分解し、ダブリングテーブルを構築している。

### 制約
- $g$ は Functional Graph である。
  - $g$ の任意の任意の頂点の出次数は $1$ であるとも言い換えられる。
- $1 \leq \|V\|$

### 計算量
- $O(\|V\| \log \|V\|)$

## jump
```
usize jump(usize v, u64 k)
```

$jump(v, k)$ を返す。

### 制約
- $0 \leq v < \|V\|$

### 計算量
- $O(\log \|V\|)$
