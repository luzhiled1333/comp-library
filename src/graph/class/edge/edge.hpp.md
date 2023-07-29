---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/dynamic-graph.test.cpp
    title: test/aoj/grl_1_a/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/static-graph.test.cpp
    title: test/aoj/grl_1_a/static-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_b/dynamic-graph.test.cpp
    title: test/aoj/grl_1_b/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_b/static-graph.test.cpp
    title: test/aoj/grl_1_b/static-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_5_c/grl_5_c.test.cpp
    title: test/aoj/grl_5_c/grl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/offline-algorithm.test.cpp
    title: test/atcoder/abc258_e/offline-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/online-algorithm.test.cpp
    title: test/atcoder/abc258_e/online-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc291_e.test.cpp
    title: test/atcoder/abc291_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/class/edge/edge.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/graph/class/edge/edge.hpp\"\n\n#include <vector>\n\
    \nnamespace luz {\n\n  template < typename T >\n  class Edge {\n   public:\n \
    \   using cost_type = T;\n\n    usize from, to;\n    T cost;\n    usize id;\n\
    \    Edge() = default;\n    Edge(usize from_, usize to_, T cost_, usize id_)\n\
    \        : from(from_),\n          to(to_),\n          cost(cost_),\n        \
    \  id(id_) {}\n  };\n\n  template < typename T >\n  using Edges = std::vector<\
    \ Edge< T > >;\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename T >\n  class Edge {\n \
    \  public:\n    using cost_type = T;\n\n    usize from, to;\n    T cost;\n   \
    \ usize id;\n    Edge() = default;\n    Edge(usize from_, usize to_, T cost_,\
    \ usize id_)\n        : from(from_),\n          to(to_),\n          cost(cost_),\n\
    \          id(id_) {}\n  };\n\n  template < typename T >\n  using Edges = std::vector<\
    \ Edge< T > >;\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/class/edge/edge.hpp
  requiredBy: []
  timestamp: '2023-05-28 01:36:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  - unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  - test/atcoder/abc291_e.test.cpp
  - test/atcoder/abc258_e/offline-algorithm.test.cpp
  - test/atcoder/abc258_e/online-algorithm.test.cpp
  - test/aoj/grl_1_a/dynamic-graph.test.cpp
  - test/aoj/grl_1_a/static-graph.test.cpp
  - test/aoj/grl_1_b/dynamic-graph.test.cpp
  - test/aoj/grl_1_b/static-graph.test.cpp
  - test/aoj/grl_5_c/grl_5_c.test.cpp
  - test/library-checker/scc.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
documentation_of: src/graph/class/edge/edge.hpp
layout: document
redirect_from:
- /library/src/graph/class/edge/edge.hpp
- /library/src/graph/class/edge/edge.hpp.html
title: src/graph/class/edge/edge.hpp
---
