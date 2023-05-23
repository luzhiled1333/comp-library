---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/class/dynamic-graph.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/graph/class/dynamic-graph.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename Edge\
    \ >\n  class DynamicGraph {\n    using cost_type = typename Edge::cost_type;\n\
    \n    using Edges = std::vector< Edge >;\n\n   protected:\n    std::vector< Edges\
    \ > g;\n    usize edge_count;\n\n   public:\n    DynamicGraph() = default;\n \
    \   explicit DynamicGraph(usize n): g(n), edge_count(0) {}\n\n    usize size()\
    \ const {\n      return g.size();\n    }\n\n    void add_directed_edge(usize from,\
    \ usize to, cost_type cost = 1) {\n      assert(from < size());\n      assert(to\
    \ < size());\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\
    \n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n     \
    \ assert(u < size());\n      assert(v < size());\n      assert(u != v);\n    \
    \  g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v, u, cost,\
    \ edge_count++);\n    }\n\n    Edges operator[](const usize &v) {\n      return\
    \ g[v];\n    }\n\n    const Edges operator[](const usize &v) const {\n      return\
    \ g[v];\n    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename Edge\
    \ >\n  class DynamicGraph {\n    using cost_type = typename Edge::cost_type;\n\
    \n    using Edges = std::vector< Edge >;\n\n   protected:\n    std::vector< Edges\
    \ > g;\n    usize edge_count;\n\n   public:\n    DynamicGraph() = default;\n \
    \   explicit DynamicGraph(usize n): g(n), edge_count(0) {}\n\n    usize size()\
    \ const {\n      return g.size();\n    }\n\n    void add_directed_edge(usize from,\
    \ usize to, cost_type cost = 1) {\n      assert(from < size());\n      assert(to\
    \ < size());\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\
    \n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n     \
    \ assert(u < size());\n      assert(v < size());\n      assert(u != v);\n    \
    \  g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v, u, cost,\
    \ edge_count++);\n    }\n\n    Edges operator[](const usize &v) {\n      return\
    \ g[v];\n    }\n\n    const Edges operator[](const usize &v) const {\n      return\
    \ g[v];\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/class/dynamic-graph.hpp
  requiredBy: []
  timestamp: '2023-05-23 22:57:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/class/dynamic-graph.hpp
layout: document
redirect_from:
- /library/src/graph/class/dynamic-graph.hpp
- /library/src/graph/class/dynamic-graph.hpp.html
title: src/graph/class/dynamic-graph.hpp
---
