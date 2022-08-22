---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/graph/graph-template.hpp\"\n\n#line 4 \"src/graph/graph-template.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ cost_type >\n  class Edge {\n   public:\n    usize from, to;\n    cost_type\
    \ cost;\n    usize id;\n    Edge() = default;\n    Edge(usize from_, usize to_,\
    \ cost_type cost_, usize id_)\n        : from(from_),\n          to(to_),\n  \
    \        cost(cost_),\n          id(id_) {}\n  };\n\n  template < typename cost_type\
    \ >\n  using Edges = std::vector< Edge< cost_type > >;\n\n  template < typename\
    \ cost_type >\n  class Graph {\n   protected:\n    std::vector< std::vector< Edge<\
    \ cost_type > > > g;\n    usize edge_count;\n\n   public:\n    Graph() = default;\n\
    \    explicit Graph(usize n): g(n), edge_count(0) {}\n\n    usize size() const\
    \ {\n      return g.size();\n    }\n\n    void add_directed_edge(usize from, usize\
    \ to, cost_type cost = 1) {\n      assert(from < size());\n      assert(to < size());\n\
    \      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void\
    \ add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n      assert(u\
    \ < size());\n      assert(v < size());\n      g[u].emplace_back(u, v, cost, edge_count);\n\
    \      g[v].emplace_back(v, u, cost, edge_count++);\n    }\n\n    inline Edges<\
    \ cost_type > &operator[](const usize &v) {\n      return g[v];\n    }\n\n   \
    \ inline const Edges< cost_type > &operator[](\n        const usize &v) const\
    \ {\n      return g[v];\n    }\n  };\n\n} // namespace luz\n#line 3 \"src/graph/functional-graph-utility.hpp\"\
    \n\n#line 5 \"src/graph/functional-graph-utility.hpp\"\n\nnamespace luz {\n\n\
    \  template < typename cost_type >\n  class FunctionalGraph: Graph< cost_type\
    \ > {\n    using Graph< cost_type >::Graph;\n    using Graph< cost_type >::g;\n\
    \    using Graph< cost_type >::size;\n    using Graph< cost_type >::add_directed_edge;\n\
    \n    usize LOG;\n    std::vector< std::vector< usize > > doubling_table;\n\n\
    \   public:\n    void add_edge(usize from, usize to, cost_type cost = 1) {\n \
    \     assert(from < size());\n      assert(to < size());\n      add_directed_edge(from,\
    \ to, cost);\n      assert(g[from].size() == 1);\n    }\n\n    void initialize_jump(const\
    \ u64 MAX_K) {\n      LOG = 0;\n      while (usize(1) << (LOG + 1) <= MAX_K) {\n\
    \        LOG++;\n      }\n\n      doubling_table.assign(LOG, std::vector< usize\
    \ >(size()));\n      for (usize v: rep(0, size())) {\n        doubling_table[0][v]\
    \ = (g[v].size() == 1 ? g[v][0].to : -1);\n      }\n      for (usize k: rep(1,\
    \ LOG)) {\n        for (usize v: rep(0, size())) {\n          usize pv = doubling_table[k\
    \ - 1][v];\n          if (pv == (usize)-1) {\n            doubling_table[k][v]\
    \ = pv;\n          } else {\n            doubling_table[k][v] = doubling_table[k\
    \ - 1][pv];\n          }\n        }\n      }\n    }\n\n    usize jump(usize v,\
    \ u64 k) {\n      if (k == 0) return v;\n      for (usize i: rep(0, LOG)) {\n\
    \        if ((k & 1) == 1) {\n          v = doubling_table[i][v];\n        }\n\
    \        k >>= 1;\n      }\n\n      return v;\n    }\n  };\n\n} // namespace luz\n"
  code: "#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/graph/graph-template.hpp\"\
    \n\n#include <cassert>\n\nnamespace luz {\n\n  template < typename cost_type >\n\
    \  class FunctionalGraph: Graph< cost_type > {\n    using Graph< cost_type >::Graph;\n\
    \    using Graph< cost_type >::g;\n    using Graph< cost_type >::size;\n    using\
    \ Graph< cost_type >::add_directed_edge;\n\n    usize LOG;\n    std::vector< std::vector<\
    \ usize > > doubling_table;\n\n   public:\n    void add_edge(usize from, usize\
    \ to, cost_type cost = 1) {\n      assert(from < size());\n      assert(to < size());\n\
    \      add_directed_edge(from, to, cost);\n      assert(g[from].size() == 1);\n\
    \    }\n\n    void initialize_jump(const u64 MAX_K) {\n      LOG = 0;\n      while\
    \ (usize(1) << (LOG + 1) <= MAX_K) {\n        LOG++;\n      }\n\n      doubling_table.assign(LOG,\
    \ std::vector< usize >(size()));\n      for (usize v: rep(0, size())) {\n    \
    \    doubling_table[0][v] = (g[v].size() == 1 ? g[v][0].to : -1);\n      }\n \
    \     for (usize k: rep(1, LOG)) {\n        for (usize v: rep(0, size())) {\n\
    \          usize pv = doubling_table[k - 1][v];\n          if (pv == (usize)-1)\
    \ {\n            doubling_table[k][v] = pv;\n          } else {\n            doubling_table[k][v]\
    \ = doubling_table[k - 1][pv];\n          }\n        }\n      }\n    }\n\n   \
    \ usize jump(usize v, u64 k) {\n      if (k == 0) return v;\n      for (usize\
    \ i: rep(0, LOG)) {\n        if ((k & 1) == 1) {\n          v = doubling_table[i][v];\n\
    \        }\n        k >>= 1;\n      }\n\n      return v;\n    }\n  };\n\n} //\
    \ namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: false
  path: src/graph/functional-graph-utility.hpp
  requiredBy: []
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/functional-graph-utility.hpp
layout: document
redirect_from:
- /library/src/graph/functional-graph-utility.hpp
- /library/src/graph/functional-graph-utility.hpp.html
title: src/graph/functional-graph-utility.hpp
---
