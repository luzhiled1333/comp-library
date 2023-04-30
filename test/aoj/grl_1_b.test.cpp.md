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
    path: src/graph/single-source-shortest-path/in-weighted-graph.hpp
    title: "\u91CD\u307F\u3042\u308A\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
      \ (Single Source Shortest Path in Unweighted Graph, SPFA)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/grl_1_b.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\n\
    namespace luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       ++i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
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
    \ 2 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\n\n#line 5\
    \ \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\n\n#include\
    \ <limits>\n#include <queue>\n#line 9 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\nnamespace luz::sssp {\n\n  template < typename cost_type >\n  class InWeightedGraph\
    \ {\n    using graph = Graph< cost_type >;\n\n    static constexpr cost_type inf_\
    \ =\n        std::numeric_limits< cost_type >::max();\n    static constexpr cost_type\
    \ negative_inf_ =\n        std::numeric_limits< cost_type >::min();\n    static\
    \ constexpr usize undefined_ =\n        std::numeric_limits< usize >::max();\n\
    \n    graph g;\n    usize g_size;\n    usize source;\n\n    std::vector< cost_type\
    \ > ds;\n    std::vector< usize > parents, ids;\n\n    void spfa(usize s) {\n\
    \      std::queue< usize > que;\n      std::vector< usize > ds_update_cnt(g_size);\n\
    \      std::vector< bool > in_que(g_size);\n\n      ds[s]            = 0;\n  \
    \    in_que[s]        = true;\n      ds_update_cnt[s] = 0;\n      que.emplace(s);\n\
    \n      while (not que.empty()) {\n        usize v = que.front();\n        que.pop();\n\
    \        in_que[v] = false;\n\n        for (const auto &e: g[v]) {\n         \
    \ usize u        = e.to;\n          cost_type cost = e.cost;\n          if (ds[v]\
    \ + cost >= ds[u]) {\n            continue;\n          }\n\n          ds[u]  \
    \    = ds[v] + cost;\n          parents[u] = v;\n          ids[u]     = e.id;\n\
    \n          if (in_que[u]) {\n            continue;\n          }\n\n         \
    \ in_que[u] = true;\n          ds_update_cnt[u]++;\n\n          if (ds_update_cnt[u]\
    \ < 2 * g_size) {\n            que.emplace(u);\n          }\n        }\n     \
    \ }\n\n      for (usize v: rep(0, g_size)) {\n        if (ds_update_cnt[v] >=\
    \ g_size) {\n          ds[v]      = negative_inf();\n          parents[v] = undefined();\n\
    \          ids[v]     = undefined();\n        }\n      }\n    }\n\n   public:\n\
    \    explicit InWeightedGraph(const graph &g_, usize source_)\n        : g(g_),\n\
    \          g_size(g.size()),\n          source(source_),\n          ds(g_size,\
    \ inf()),\n          parents(g_size, undefined()),\n          ids(g_size, undefined())\
    \ {\n      spfa(source);\n    }\n\n    graph get_original_graph() const {\n  \
    \    return g;\n    }\n\n    static inline cost_type inf() {\n      return inf_;\n\
    \    }\n\n    static inline cost_type negative_inf() {\n      return negative_inf_;\n\
    \    }\n\n    inline cost_type distance(const usize v) const {\n      return ds[v];\n\
    \    }\n\n    inline std::vector< cost_type > get_distances() const {\n      return\
    \ ds;\n    }\n\n    static inline usize undefined() {\n      return undefined_;\n\
    \    }\n\n    inline usize parent(const usize v) const {\n      return parents[v];\n\
    \    }\n\n    inline std::vector< usize > get_parents() const {\n      return\
    \ parents;\n    }\n\n    inline usize edge_label(const usize v) const {\n    \
    \  return ids[v];\n    }\n\n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n} // namespace luz::sssp\n#line 7\
    \ \"test/aoj/grl_1_b.test.cpp\"\n\n#include <iostream>\n\nnamespace luz {\n\n\
    \  void main_() {\n    int v, e, source;\n    std::cin >> v >> e >> source;\n\
    \    Graph< i32 > G(v);\n    for ([[maybe_unused]] usize _: rep(0, e)) {\n   \
    \   usize s, t;\n      i32 d;\n      std::cin >> s >> t >> d;\n      G.add_directed_edge(s,\
    \ t, d);\n    }\n\n    sssp::InWeightedGraph sssp(G, source);\n    auto dists\
    \ = sssp.get_distances();\n    for (const auto& dist: dists) {\n      if (dist\
    \ == sssp::InWeightedGraph< i32 >::negative_inf()) {\n        std::cout << \"\
    NEGATIVE CYCLE\" << std::endl;\n        return;\n      }\n    }\n    for (const\
    \ auto& dist: dists) {\n      if (dist == sssp::InWeightedGraph< i32 >::inf())\
    \ {\n        std::cout << \"INF\" << std::endl;\n      } else {\n        std::cout\
    \ << dist << std::endl;\n      }\n    }\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/graph/graph-template.hpp\"\n#include \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    int v, e,\
    \ source;\n    std::cin >> v >> e >> source;\n    Graph< i32 > G(v);\n    for\
    \ ([[maybe_unused]] usize _: rep(0, e)) {\n      usize s, t;\n      i32 d;\n \
    \     std::cin >> s >> t >> d;\n      G.add_directed_edge(s, t, d);\n    }\n\n\
    \    sssp::InWeightedGraph sssp(G, source);\n    auto dists = sssp.get_distances();\n\
    \    for (const auto& dist: dists) {\n      if (dist == sssp::InWeightedGraph<\
    \ i32 >::negative_inf()) {\n        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n\
    \        return;\n      }\n    }\n    for (const auto& dist: dists) {\n      if\
    \ (dist == sssp::InWeightedGraph< i32 >::inf()) {\n        std::cout << \"INF\"\
    \ << std::endl;\n      } else {\n        std::cout << dist << std::endl;\n   \
    \   }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/graph/graph-template.hpp
  - src/graph/single-source-shortest-path/in-weighted-graph.hpp
  isVerificationFile: true
  path: test/aoj/grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2023-04-30 17:48:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_1_b.test.cpp
- /verify/test/aoj/grl_1_b.test.cpp.html
title: test/aoj/grl_1_b.test.cpp
---
