---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
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
  bundledCode: "#line 2 \"src/graph/class/static-graph.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/graph/class/static-graph.hpp\"\
    \n\n#line 7 \"src/graph/class/static-graph.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace luz::internal {\n\n  template < typename Iterator >\n\
    \  class OutgoingEdges {\n    Iterator f, l;\n\n   public:\n    OutgoingEdges(Iterator\
    \ f, Iterator l): f(f), l(l) {}\n\n    Iterator begin() const {\n      return\
    \ f;\n    }\n    Iterator end() const {\n      return l;\n    }\n    usize size()\
    \ const {\n      return l - f;\n    }\n\n    auto &&operator[](usize k) {\n  \
    \    assert(k < size());\n      return begin()[k];\n    }\n  };\n\n} // namespace\
    \ luz::internal\n\nnamespace luz {\n\n  template < typename Edge >\n  class StaticGraph\
    \ {\n    using cost_type = typename Edge::cost_type;\n\n    using Edges      \
    \    = std::vector< Edge >;\n    using iterator       = typename Edges::iterator;\n\
    \    using const_iterator = typename Edges::const_iterator;\n\n    template <\
    \ typename Iterator >\n    using Es = internal::OutgoingEdges< Iterator >;\n\n\
    \   protected:\n    bool constructed;\n    usize vertex_count;\n    usize edge_count;\n\
    \n    Edges edges;\n    std::vector< usize > outdegrees;\n\n   public:\n    StaticGraph()\
    \ = default;\n    explicit StaticGraph(usize n)\n        : constructed(false),\n\
    \          vertex_count(n),\n          edge_count(0),\n          outdegrees(vertex_count)\
    \ {}\n\n    usize size() const {\n      return vertex_count;\n    }\n\n    void\
    \ construct() {\n      assert(not constructed);\n\n      outdegrees.emplace_back(0);\n\
    \      for (usize i: rrep(0, size())) {\n        outdegrees[i] += outdegrees[i\
    \ + 1];\n      }\n\n      std::sort(edges.begin(), edges.end(),\n            \
    \    [](const Edge &e1, const Edge &e2) {\n        return e1.from != e2.from ?\
    \ e1.from > e2.from : e1.to < e2.to;\n      });\n\n      constructed = true;\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      assert(not constructed);\n      assert(from < size());\n      assert(to\
    \ < size());\n      edges.emplace_back(from, to, cost, edge_count++);\n      outdegrees[from]++;\n\
    \    }\n\n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n\
    \      assert(not constructed);\n      assert(u < size());\n      assert(v < size());\n\
    \      assert(u != v);\n      edges.emplace_back(u, v, cost, edge_count);\n  \
    \    outdegrees[u]++;\n      edges.emplace_back(v, u, cost, edge_count++);\n \
    \     outdegrees[v]++;\n    }\n\n    Es< iterator > operator[](const usize &v)\
    \ {\n      assert(constructed);\n      return Es< iterator >(edges.begin() + outdegrees[v\
    \ + 1],\n                            edges.begin() + outdegrees[v]);\n    }\n\n\
    \    const Es< const_iterator > &operator[](const usize &v) const {\n      assert(constructed);\n\
    \      return Es< const_iterator >(edges.begin() + outdegrees[v + 1],\n      \
    \                            edges.begin() + outdegrees[v]);\n    }\n  };\n\n\
    } // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz::internal {\n\n  template < typename Iterator\
    \ >\n  class OutgoingEdges {\n    Iterator f, l;\n\n   public:\n    OutgoingEdges(Iterator\
    \ f, Iterator l): f(f), l(l) {}\n\n    Iterator begin() const {\n      return\
    \ f;\n    }\n    Iterator end() const {\n      return l;\n    }\n    usize size()\
    \ const {\n      return l - f;\n    }\n\n    auto &&operator[](usize k) {\n  \
    \    assert(k < size());\n      return begin()[k];\n    }\n  };\n\n} // namespace\
    \ luz::internal\n\nnamespace luz {\n\n  template < typename Edge >\n  class StaticGraph\
    \ {\n    using cost_type = typename Edge::cost_type;\n\n    using Edges      \
    \    = std::vector< Edge >;\n    using iterator       = typename Edges::iterator;\n\
    \    using const_iterator = typename Edges::const_iterator;\n\n    template <\
    \ typename Iterator >\n    using Es = internal::OutgoingEdges< Iterator >;\n\n\
    \   protected:\n    bool constructed;\n    usize vertex_count;\n    usize edge_count;\n\
    \n    Edges edges;\n    std::vector< usize > outdegrees;\n\n   public:\n    StaticGraph()\
    \ = default;\n    explicit StaticGraph(usize n)\n        : constructed(false),\n\
    \          vertex_count(n),\n          edge_count(0),\n          outdegrees(vertex_count)\
    \ {}\n\n    usize size() const {\n      return vertex_count;\n    }\n\n    void\
    \ construct() {\n      assert(not constructed);\n\n      outdegrees.emplace_back(0);\n\
    \      for (usize i: rrep(0, size())) {\n        outdegrees[i] += outdegrees[i\
    \ + 1];\n      }\n\n      std::sort(edges.begin(), edges.end(),\n            \
    \    [](const Edge &e1, const Edge &e2) {\n        return e1.from != e2.from ?\
    \ e1.from > e2.from : e1.to < e2.to;\n      });\n\n      constructed = true;\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      assert(not constructed);\n      assert(from < size());\n      assert(to\
    \ < size());\n      edges.emplace_back(from, to, cost, edge_count++);\n      outdegrees[from]++;\n\
    \    }\n\n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n\
    \      assert(not constructed);\n      assert(u < size());\n      assert(v < size());\n\
    \      assert(u != v);\n      edges.emplace_back(u, v, cost, edge_count);\n  \
    \    outdegrees[u]++;\n      edges.emplace_back(v, u, cost, edge_count++);\n \
    \     outdegrees[v]++;\n    }\n\n    Es< iterator > operator[](const usize &v)\
    \ {\n      assert(constructed);\n      return Es< iterator >(edges.begin() + outdegrees[v\
    \ + 1],\n                            edges.begin() + outdegrees[v]);\n    }\n\n\
    \    const Es< const_iterator > &operator[](const usize &v) const {\n      assert(constructed);\n\
    \      return Es< const_iterator >(edges.begin() + outdegrees[v + 1],\n      \
    \                            edges.begin() + outdegrees[v]);\n    }\n  };\n\n\
    } // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/class/static-graph.hpp
  requiredBy: []
  timestamp: '2023-05-23 22:57:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/class/static-graph.hpp
layout: document
redirect_from:
- /library/src/graph/class/static-graph.hpp
- /library/src/graph/class/static-graph.hpp.html
title: src/graph/class/static-graph.hpp
---
