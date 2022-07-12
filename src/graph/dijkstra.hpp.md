---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: src/cpp-template/header/type-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: src/graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-1-a.test.cpp
    title: test/aoj/grl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/dijkstra.hpp\"\n#include <limits>\n#include <utility>\n\
    #include <queue>\n\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\n\n\
    namespace luz {\n\n  template <typename T1, typename T2>\n  inline bool chmax(T1\
    \ &a, T2 b) {\n    return a < b and (a = b, true);\n  }\n\n  template <typename\
    \ T1, typename T2>\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a\
    \ = b, true);\n  }\n\n} // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\
    \n\n#include <vector>\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n\
    namespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n\
    \  using u64 = std::uint64_t;\n  \n} // namespace luz\n#line 6 \"src/graph/graph-template.hpp\"\
    \n\nnamespace luz {\n\n  template< typename cost_type >\n  class Edge {\n   public:\n\
    \    usize from, to;\n    cost_type cost;\n    usize id;\n    Edge() = default;\n\
    \    Edge(usize from_, usize to_, cost_type cost_, usize id_):\n      from(from_),\
    \ to(to_), cost(cost_), id(id_) {}\n  };\n\n  template< typename cost_type >\n\
    \  using Edges = std::vector< Edge<cost_type> >;\n\n  template< typename cost_type\
    \ >\n  class Graph {\n    std::vector< std::vector<Edge<cost_type>> > g;\n   \
    \ usize edge_count;\n\n   public:\n    Graph() = default;\n    explicit Graph(usize\
    \ n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return g.size();\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void\
    \ add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n      g[u].emplace_back(u,\
    \ v, cost, edge_count);\n      g[v].emplace_back(v, u, cost, edge_count++);\n\
    \    }\n\n    inline std::vector< Edge<cost_type> > &operator[](const usize &v)\
    \ {\n      return g[v];\n    }\n\n    inline const std::vector< Edge<cost_type>\
    \ > &operator[](const usize &v) const {\n      return g[v];\n    }\n  };\n\n}\n\
    #line 7 \"src/graph/dijkstra.hpp\"\n\nnamespace luz {\n\n  template< typename\
    \ cost_type >\n  class Dijkstra {\n    static constexpr usize undefined_ = std::numeric_limits<usize>::max();\n\
    \    static constexpr cost_type inf_ = std::numeric_limits<cost_type>::max();\n\
    \  \n    Graph< cost_type > g;\n    usize g_size;\n    std::vector< cost_type\
    \ > ds;\n    std::vector< usize > froms, ids;\n  \n    void dijkstra(usize s)\
    \ {\n      using pq_type = std::pair< cost_type, usize >;\n      std::priority_queue<\
    \ pq_type, std::vector<pq_type>, std::greater<pq_type> > pq;\n  \n      ds[s]\
    \ = 0;\n      pq.emplace(ds[s], s);\n  \n      while (not pq.empty()) {\n    \
    \    auto [cost, v] = pq.top();\n        pq.pop();\n  \n        if (ds[v] < cost)\
    \ continue;\n        for (auto &e: g[v]) {\n          if (chmin(ds[e.to], cost\
    \ + e.cost)) {\n            pq.emplace(ds[e.to], e.to);\n            froms[e.to]\
    \ = v;\n            ids[e.to] = e.id;\n          }\n        }\n      }\n    }\n\
    \  \n   public:\n    explicit Dijkstra(const Graph< cost_type > &g_, usize source)\
    \ : \n        g(g_), g_size(g.size()), ds(g_size, inf_), \n        froms(g_size,\
    \ undefined_), ids(g_size, undefined_) {\n      dijkstra(source);\n    }\n  \n\
    \    inline usize undefined() const {\n      return undefined_;\n    }\n  \n \
    \   inline cost_type inf() const {\n      return inf_;\n    }\n  \n    inline\
    \ cost_type dist(const usize v) const {\n      return ds[v];\n    }\n  \n    inline\
    \ usize from_on_shortest_path_tree(const usize v) const {\n      return froms[v];\n\
    \    }\n  \n    inline usize edge_label(const usize v) const {\n      return ids[v];\n\
    \    }\n  \n    inline Graph< cost_type > get_original_graph() const {\n     \
    \ return g;\n    }\n  \n    inline std::vector< cost_type > get_distances() const\
    \ {\n      return ds;\n    }\n  \n    inline std::vector< usize > get_shortest_path_tree()\
    \ const {\n      return froms;\n    }\n  \n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n}\n"
  code: "#include <limits>\n#include <utility>\n#include <queue>\n\n#include \"../cpp-template/header/change-minmax.hpp\"\
    \n#include \"graph-template.hpp\"\n\nnamespace luz {\n\n  template< typename cost_type\
    \ >\n  class Dijkstra {\n    static constexpr usize undefined_ = std::numeric_limits<usize>::max();\n\
    \    static constexpr cost_type inf_ = std::numeric_limits<cost_type>::max();\n\
    \  \n    Graph< cost_type > g;\n    usize g_size;\n    std::vector< cost_type\
    \ > ds;\n    std::vector< usize > froms, ids;\n  \n    void dijkstra(usize s)\
    \ {\n      using pq_type = std::pair< cost_type, usize >;\n      std::priority_queue<\
    \ pq_type, std::vector<pq_type>, std::greater<pq_type> > pq;\n  \n      ds[s]\
    \ = 0;\n      pq.emplace(ds[s], s);\n  \n      while (not pq.empty()) {\n    \
    \    auto [cost, v] = pq.top();\n        pq.pop();\n  \n        if (ds[v] < cost)\
    \ continue;\n        for (auto &e: g[v]) {\n          if (chmin(ds[e.to], cost\
    \ + e.cost)) {\n            pq.emplace(ds[e.to], e.to);\n            froms[e.to]\
    \ = v;\n            ids[e.to] = e.id;\n          }\n        }\n      }\n    }\n\
    \  \n   public:\n    explicit Dijkstra(const Graph< cost_type > &g_, usize source)\
    \ : \n        g(g_), g_size(g.size()), ds(g_size, inf_), \n        froms(g_size,\
    \ undefined_), ids(g_size, undefined_) {\n      dijkstra(source);\n    }\n  \n\
    \    inline usize undefined() const {\n      return undefined_;\n    }\n  \n \
    \   inline cost_type inf() const {\n      return inf_;\n    }\n  \n    inline\
    \ cost_type dist(const usize v) const {\n      return ds[v];\n    }\n  \n    inline\
    \ usize from_on_shortest_path_tree(const usize v) const {\n      return froms[v];\n\
    \    }\n  \n    inline usize edge_label(const usize v) const {\n      return ids[v];\n\
    \    }\n  \n    inline Graph< cost_type > get_original_graph() const {\n     \
    \ return g;\n    }\n  \n    inline std::vector< cost_type > get_distances() const\
    \ {\n      return ds;\n    }\n  \n    inline std::vector< usize > get_shortest_path_tree()\
    \ const {\n      return froms;\n    }\n  \n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n}\n"
  dependsOn:
  - src/cpp-template/header/change-minmax.hpp
  - src/graph/graph-template.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-07-13 02:17:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl-1-a.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
title: template
---

# Dijkstra's algorithm
## コンストラクタ
```cpp
Dijkstra(const Graph<cost_type> &g_, usize source);
```

### 計算量
- $O(E + V \log V)$
