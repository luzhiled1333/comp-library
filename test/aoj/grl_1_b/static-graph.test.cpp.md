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
    path: src/graph/class/dynamic-graph.hpp
    title: "\u52D5\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/class/static-graph.hpp
    title: "\u9759\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
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
  bundledCode: "#line 1 \"test/aoj/grl_1_b/static-graph.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\n\n#line 2 \"src/graph/class/static-graph.hpp\"\
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
    \ 5 \"src/graph/class/static-graph.hpp\"\n\n#line 7 \"src/graph/class/static-graph.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace luz::internal {\n\n  template\
    \ < typename Iterator >\n  class OutgoingEdges {\n    Iterator f, l;\n\n   public:\n\
    \    OutgoingEdges(Iterator f, Iterator l): f(f), l(l) {}\n\n    Iterator begin()\
    \ const {\n      return f;\n    }\n    Iterator end() const {\n      return l;\n\
    \    }\n    usize size() const {\n      return l - f;\n    }\n\n    auto &operator[](usize\
    \ k) {\n      assert(k < size());\n      return begin()[k];\n    }\n    const\
    \ auto &operator[](usize k) const {\n      assert(k < size());\n      return begin()[k];\n\
    \    }\n  };\n\n} // namespace luz::internal\n\nnamespace luz {\n\n  template\
    \ < typename Edge >\n  class StaticGraph {\n\n    using Edges          = std::vector<\
    \ Edge >;\n    using iterator       = typename Edges::iterator;\n    using const_iterator\
    \ = typename Edges::const_iterator;\n\n    template < typename Iterator >\n  \
    \  using Es = internal::OutgoingEdges< Iterator >;\n\n   protected:\n    bool\
    \ initialized;\n    usize vertex_count;\n    usize edge_count;\n\n    Edges edges;\n\
    \    std::vector< usize > outdegrees;\n\n   public:\n    using cost_type = typename\
    \ Edge::cost_type;\n\n    StaticGraph() = default;\n    explicit StaticGraph(usize\
    \ n)\n        : initialized(false),\n          vertex_count(n),\n          edge_count(0),\n\
    \          outdegrees(vertex_count) {}\n\n    usize size() const {\n      return\
    \ vertex_count;\n    }\n\n    void initialize() {\n      assert(not initialized);\n\
    \n      outdegrees.emplace_back(0);\n      for (usize i: rrep(0, size())) {\n\
    \        outdegrees[i] += outdegrees[i + 1];\n      }\n\n      std::sort(edges.begin(),\
    \ edges.end(),\n                [](const Edge &e1, const Edge &e2) {\n       \
    \ return e1.from != e2.from ? e1.from > e2.from : e1.to < e2.to;\n      });\n\n\
    \      initialized = true;\n    }\n\n    void add_directed_edge(usize from, usize\
    \ to, cost_type cost = 1) {\n      assert(not initialized);\n      assert(from\
    \ < size());\n      assert(to < size());\n      edges.emplace_back(from, to, cost,\
    \ edge_count++);\n      outdegrees[from]++;\n    }\n\n    void add_undirected_edge(usize\
    \ u, usize v, cost_type cost = 1) {\n      assert(not initialized);\n      assert(u\
    \ < size());\n      assert(v < size());\n      assert(u != v);\n      edges.emplace_back(u,\
    \ v, cost, edge_count);\n      outdegrees[u]++;\n      edges.emplace_back(v, u,\
    \ cost, edge_count++);\n      outdegrees[v]++;\n    }\n\n    Es< iterator > operator[](const\
    \ usize &v) {\n      assert(initialized);\n      return Es< iterator >(edges.begin()\
    \ + outdegrees[v + 1],\n                            edges.begin() + outdegrees[v]);\n\
    \    }\n\n    const Es< const_iterator > operator[](const usize &v) const {\n\
    \      assert(initialized);\n      return Es< const_iterator >(edges.cbegin()\
    \ + outdegrees[v + 1],\n                                  edges.cbegin() + outdegrees[v]);\n\
    \    }\n  };\n\n} // namespace luz\n#line 4 \"test/aoj/grl_1_b/static-graph.test.cpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/graph/class/edge/edge.hpp\"\
    \n\n#line 4 \"src/graph/class/edge/edge.hpp\"\n\n#line 6 \"src/graph/class/edge/edge.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T >\n  class Edge {\n   public:\n\
    \    using cost_type = T;\n\n    usize from, to;\n    T cost;\n    usize id;\n\
    \    Edge() = default;\n    Edge(usize from_, usize to_, T cost_, usize id_)\n\
    \        : from(from_),\n          to(to_),\n          cost(cost_),\n        \
    \  id(id_) {}\n  };\n\n  template < typename T >\n  using Edges = std::vector<\
    \ Edge< T > >;\n\n} // namespace luz\n#line 2 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#line 2 \"src/graph/class/dynamic-graph.hpp\"\n\n#line 4 \"src/graph/class/dynamic-graph.hpp\"\
    \n\n#line 7 \"src/graph/class/dynamic-graph.hpp\"\n\nnamespace luz {\n\n  template\
    \ < typename Edge >\n  class DynamicGraph {\n\n    using Edges = std::vector<\
    \ Edge >;\n\n   protected:\n    std::vector< Edges > g;\n    usize edge_count;\n\
    \n   public:\n    using cost_type = typename Edge::cost_type;\n\n    DynamicGraph()\
    \ = default;\n    explicit DynamicGraph(usize n): g(n), edge_count(0) {}\n\n \
    \   usize size() const {\n      return g.size();\n    }\n\n    void add_directed_edge(usize\
    \ from, usize to, cost_type cost = 1) {\n      assert(from < size());\n      assert(to\
    \ < size());\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\
    \n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n     \
    \ assert(u < size());\n      assert(v < size());\n      assert(u != v);\n    \
    \  g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v, u, cost,\
    \ edge_count++);\n    }\n\n    Edges operator[](const usize &v) {\n      return\
    \ g[v];\n    }\n\n    const Edges operator[](const usize &v) const {\n      return\
    \ g[v];\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#include <limits>\n#include <queue>\n#line 9 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\nnamespace luz::sssp {\n\n  template < class G >\n  class InWeightedGraph {\n\
    \    using cost_type = typename G::cost_type;\n    using graph     = G;\n\n  \
    \  static constexpr cost_type inf_ =\n        std::numeric_limits< cost_type >::max();\n\
    \    static constexpr cost_type negative_inf_ =\n        std::numeric_limits<\
    \ cost_type >::min();\n    static constexpr usize undefined_ =\n        std::numeric_limits<\
    \ usize >::max();\n\n    graph g;\n    usize g_size;\n    usize source;\n\n  \
    \  std::vector< cost_type > ds;\n    std::vector< usize > parents, ids;\n\n  \
    \  void spfa(usize s) {\n      std::queue< usize > que;\n      std::vector< usize\
    \ > ds_update_cnt(g_size);\n      std::vector< bool > in_que(g_size);\n\n    \
    \  ds[s]            = 0;\n      in_que[s]        = true;\n      ds_update_cnt[s]\
    \ = 0;\n      que.emplace(s);\n\n      while (not que.empty()) {\n        usize\
    \ v = que.front();\n        que.pop();\n        in_que[v] = false;\n\n       \
    \ for (const auto &e: g[v]) {\n          usize u        = e.to;\n          cost_type\
    \ cost = e.cost;\n          if (ds[v] + cost >= ds[u]) {\n            continue;\n\
    \          }\n\n          ds[u]      = ds[v] + cost;\n          parents[u] = v;\n\
    \          ids[u]     = e.id;\n\n          if (in_que[u]) {\n            continue;\n\
    \          }\n\n          in_que[u] = true;\n          ds_update_cnt[u]++;\n\n\
    \          if (ds_update_cnt[u] < 2 * g_size) {\n            que.emplace(u);\n\
    \          }\n        }\n      }\n\n      for (usize v: rep(0, g_size)) {\n  \
    \      if (ds_update_cnt[v] >= g_size) {\n          ds[v]      = negative_inf();\n\
    \          parents[v] = undefined();\n          ids[v]     = undefined();\n  \
    \      }\n      }\n    }\n\n   public:\n    explicit InWeightedGraph(const graph\
    \ &g_, usize source_)\n        : g(g_),\n          g_size(g.size()),\n       \
    \   source(source_),\n          ds(g_size, inf()),\n          parents(g_size,\
    \ undefined()),\n          ids(g_size, undefined()) {\n      spfa(source);\n \
    \   }\n\n    graph get_original_graph() const {\n      return g;\n    }\n\n  \
    \  static inline cost_type inf() {\n      return inf_;\n    }\n\n    static inline\
    \ cost_type negative_inf() {\n      return negative_inf_;\n    }\n\n    inline\
    \ cost_type distance(const usize v) const {\n      return ds[v];\n    }\n\n  \
    \  inline std::vector< cost_type > get_distances() const {\n      return ds;\n\
    \    }\n\n    static inline usize undefined() {\n      return undefined_;\n  \
    \  }\n\n    inline usize parent(const usize v) const {\n      return parents[v];\n\
    \    }\n\n    inline std::vector< usize > get_parents() const {\n      return\
    \ parents;\n    }\n\n    inline usize edge_label(const usize v) const {\n    \
    \  return ids[v];\n    }\n\n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n} // namespace luz::sssp\n#line 10\
    \ \"test/aoj/grl_1_b/static-graph.test.cpp\"\n\n#include <iostream>\n\nnamespace\
    \ luz {\n\n  void main_() {\n    int v, e, source;\n    std::cin >> v >> e >>\
    \ source;\n\n    using edge  = Edge< i32 >;\n    using graph = StaticGraph< edge\
    \ >;\n\n    graph g(v);\n    for ([[maybe_unused]] usize _: rep(0, e)) {\n   \
    \   usize s, t;\n      i32 d;\n      std::cin >> s >> t >> d;\n      g.add_directed_edge(s,\
    \ t, d);\n    }\n\n    g.initialize();\n\n    sssp::InWeightedGraph< graph > sssp(g,\
    \ source);\n    auto dists = sssp.get_distances();\n    for (const auto& dist:\
    \ dists) {\n      if (dist == sssp.negative_inf()) {\n        std::cout << \"\
    NEGATIVE CYCLE\" << std::endl;\n        return;\n      }\n    }\n    for (const\
    \ auto& dist: dists) {\n      if (dist == sssp.inf()) {\n        std::cout <<\
    \ \"INF\" << std::endl;\n      } else {\n        std::cout << dist << std::endl;\n\
    \      }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\n\
    \n#include \"src/graph/class/static-graph.hpp\"\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/graph/class/edge/edge.hpp\"\n#include \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    int v, e,\
    \ source;\n    std::cin >> v >> e >> source;\n\n    using edge  = Edge< i32 >;\n\
    \    using graph = StaticGraph< edge >;\n\n    graph g(v);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, e)) {\n      usize s, t;\n      i32 d;\n      std::cin >> s\
    \ >> t >> d;\n      g.add_directed_edge(s, t, d);\n    }\n\n    g.initialize();\n\
    \n    sssp::InWeightedGraph< graph > sssp(g, source);\n    auto dists = sssp.get_distances();\n\
    \    for (const auto& dist: dists) {\n      if (dist == sssp.negative_inf()) {\n\
    \        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n        return;\n    \
    \  }\n    }\n    for (const auto& dist: dists) {\n      if (dist == sssp.inf())\
    \ {\n        std::cout << \"INF\" << std::endl;\n      } else {\n        std::cout\
    \ << dist << std::endl;\n      }\n    }\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::main_();\n}\n"
  dependsOn:
  - src/graph/class/static-graph.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/single-source-shortest-path/in-weighted-graph.hpp
  - src/graph/class/dynamic-graph.hpp
  isVerificationFile: true
  path: test/aoj/grl_1_b/static-graph.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_1_b/static-graph.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_1_b/static-graph.test.cpp
- /verify/test/aoj/grl_1_b/static-graph.test.cpp.html
title: test/aoj/grl_1_b/static-graph.test.cpp
---
