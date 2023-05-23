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
  bundledCode: "#line 2 \"src/graph/class/edge.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/graph/class/edge.hpp\"\n\n#include <vector>\n\
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
  path: src/graph/class/edge.hpp
  requiredBy: []
  timestamp: '2023-05-23 22:57:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/class/edge.hpp
layout: document
redirect_from:
- /library/src/graph/class/edge.hpp
- /library/src/graph/class/edge.hpp.html
title: src/graph/class/edge.hpp
---
