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
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/topological-ordering/lexical-order-topological-sort.hpp
    title: "\u8F9E\u66F8\u9806\u6700\u5927/\u6700\u5C0F\u306E\u30C8\u30DD\u30ED\u30B8\
      \u30AB\u30EB\u30BD\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc291/tasks/abc291_e
    links:
    - https://atcoder.jp/contests/abc291/tasks/abc291_e
  bundledCode: "#line 1 \"test/atcoder/abc291_e.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename T >\n  std::ostream\
    \ &operator<<(std::ostream &os,\n                           const std::vector<\
    \ T > vs) {\n    for (usize i: rep(0, vs.size())) {\n      os << vs[i] << (i +\
    \ 1 != vs.size() ? \" \" : \"\");\n    }\n    return os;\n  }\n\n  template <\
    \ typename T >\n  std::istream &operator>>(std::istream &is, std::vector< T >\
    \ &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n    return is;\n  }\n\n\
    } // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\n\n#line 4 \"src/graph/graph-template.hpp\"\
    \n\n#include <cassert>\n#line 7 \"src/graph/graph-template.hpp\"\n\nnamespace\
    \ luz {\n\n  template < typename cost_type >\n  class Edge {\n   public:\n   \
    \ usize from, to;\n    cost_type cost;\n    usize id;\n    Edge() = default;\n\
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
    \ 2 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\n\n\
    #include <queue>\n#line 5 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T, class Compare >\n  std::vector<\
    \ usize > lexical_order_topological_sort(\n      const Graph< T > &g) {\n    usize\
    \ n = g.size();\n\n    std::vector< usize > indegrees(n);\n    for (auto v: rep(0,\
    \ n)) {\n      for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n      }\n \
    \   }\n\n    std::priority_queue< usize, std::vector< usize >, Compare > pq;\n\
    \    for (usize v: rep(0, n)) {\n      if (indegrees[v]) continue;\n      pq.emplace(v);\n\
    \    }\n\n    std::vector< usize > result;\n    result.reserve(n);\n    while\
    \ (not pq.empty()) {\n      auto v = pq.top();\n      pq.pop();\n\n      result.emplace_back(v);\n\
    \      for (auto &&e: g[v]) {\n        if (--indegrees[e.to]) continue;\n    \
    \    pq.emplace(e.to);\n      }\n    }\n\n    if (result.size() != n) {\n    \
    \  return {};\n    }\n\n    return result;\n  }\n\n} // namespace luz\n#line 7\
    \ \"test/atcoder/abc291_e.test.cpp\"\n\n#include <functional>\n#line 10 \"test/atcoder/abc291_e.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    using graph = Graph< usize >;\n\n\
    \    usize n, m;\n    std::cin >> n >> m;\n\n    graph g(n);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, m)) {\n      usize t, f;\n      std::cin >> t >> f;\n      g.add_directed_edge(t\
    \ - 1, f - 1);\n    }\n\n    auto ord =\n        lexical_order_topological_sort<\
    \ usize,\n                                        std::greater< usize > >(g);\n\
    \    auto rev =\n        lexical_order_topological_sort< usize, std::less< usize\
    \ > >(\n            g);\n\n    if (ord == rev) {\n      std::cout << \"Yes\" <<\
    \ std::endl;\n\n      std::vector< usize > ans(n);\n      for (usize i: rep(0,\
    \ n)) {\n        ans[ord[i]] = i + 1;\n      }\n\n      std::cout << ans << std::endl;\n\
    \    } else {\n      std::cout << \"No\" << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/vector-ios.hpp\"\
    \n#include \"src/graph/graph-template.hpp\"\n#include \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n#include <functional>\n#include <iostream>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    using graph = Graph< usize >;\n\n    usize n, m;\n    std::cin >> n >>\
    \ m;\n\n    graph g(n);\n    for ([[maybe_unused]] usize _: rep(0, m)) {\n   \
    \   usize t, f;\n      std::cin >> t >> f;\n      g.add_directed_edge(t - 1, f\
    \ - 1);\n    }\n\n    auto ord =\n        lexical_order_topological_sort< usize,\n\
    \                                        std::greater< usize > >(g);\n    auto\
    \ rev =\n        lexical_order_topological_sort< usize, std::less< usize > >(\n\
    \            g);\n\n    if (ord == rev) {\n      std::cout << \"Yes\" << std::endl;\n\
    \n      std::vector< usize > ans(n);\n      for (usize i: rep(0, n)) {\n     \
    \   ans[ord[i]] = i + 1;\n      }\n\n      std::cout << ans << std::endl;\n  \
    \  } else {\n      std::cout << \"No\" << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/graph/graph-template.hpp
  - src/graph/topological-ordering/lexical-order-topological-sort.hpp
  isVerificationFile: true
  path: test/atcoder/abc291_e.test.cpp
  requiredBy: []
  timestamp: '2023-04-30 12:56:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc291_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc291_e.test.cpp
- /verify/test/atcoder/abc291_e.test.cpp.html
title: test/atcoder/abc291_e.test.cpp
---
