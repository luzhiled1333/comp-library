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
    path: src/data-structure/disjoint-set-union.hpp
    title: Disjoint Set Union (Union Find)
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-lowest-common-ancestor.hpp
    title: src/graph/offline-query-lowest-common-ancestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/grl-5-c.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line\
    \ 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace luz\
    \ {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { ++i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rep(const usize f, const usize l) noexcept\n\
    \      : f(std::min(f, l)), l(l) {}\n    constexpr auto begin() const noexcept\
    \ { return f; }\n    constexpr auto end() const noexcept { return l; }\n  };\n\
    \n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { --i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rrep(const usize f, const usize l) noexcept\n\
    \      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr auto begin() const\
    \ noexcept { return f; }\n    constexpr auto end() const noexcept { return l;\
    \ }\n  };\n\n} // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\n\n\
    #include <vector>\n#include <cassert>\n\n#line 7 \"src/graph/graph-template.hpp\"\
    \n\nnamespace luz {\n\n  template< typename cost_type >\n  class Edge {\n   public:\n\
    \    usize from, to;\n    cost_type cost;\n    usize id;\n    Edge() = default;\n\
    \    Edge(usize from_, usize to_, cost_type cost_, usize id_):\n      from(from_),\
    \ to(to_), cost(cost_), id(id_) {}\n  };\n\n  template< typename cost_type >\n\
    \  using Edges = std::vector< Edge<cost_type> >;\n\n  template< typename cost_type\
    \ >\n  class Graph {\n   protected:\n    std::vector< std::vector<Edge<cost_type>>\
    \ > g;\n    usize edge_count;\n\n   public:\n    Graph() = default;\n    explicit\
    \ Graph(usize n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return\
    \ g.size();\n    }\n\n    void add_directed_edge(usize from, usize to, cost_type\
    \ cost = 1) {\n      assert(from < size());\n      assert(to   < size());\n  \
    \    g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize\
    \ u, usize v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v\
    \ < size());\n      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    inline Edges< cost_type > &operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    inline const Edges< cost_type\
    \ > &operator[](const usize &v) const {\n      return g[v];\n    }\n  };\n\n}\n\
    #line 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 5 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#line 9 \"src/data-structure/disjoint-set-union.hpp\"\n\nnamespace luz {\n\
    \n  class DisjointSetUnion {\n    usize n_;\n\n    // vals_[v] :=\n    //   if\
    \ v is root node: -1 * component size\n    //   otherwise: parent node\n    std::vector<\
    \ isize > vals_;\n\n    void bound_check(usize v) const {\n      assert(v < n_);\n\
    \    }\n\n    usize impl_leader(usize v) {\n      if (vals_[v] < 0) return v;\n\
    \      return vals_[v] = leader(vals_[v]);\n    }\n\n   public:\n    DisjointSetUnion()\
    \ = default;\n    explicit DisjointSetUnion(usize n): n_(n), vals_(n, -1) {}\n\
    \n    usize size() const {\n      return n_;\n    }\n\n    usize leader(usize\
    \ v) {\n      bound_check(v);\n      return impl_leader(v);\n    }\n\n    bool\
    \ same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n      return\
    \ impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize u, usize v)\
    \ {\n      bound_check(u); bound_check(v);\n\n      isize x = impl_leader(u);\n\
    \      isize y = impl_leader(v);\n      if (x == y) return x;\n      if (-vals_[x]\
    \ < -vals_[y]) std::swap(x, y);\n      vals_[x] += vals_[y];\n      vals_[y] =\
    \ x;\n      return x;\n    }\n\n    usize group_size(usize v) {\n      bound_check(v);\n\
    \      return -vals_[impl_leader(v)];\n    }\n\n    std::vector< std::vector<\
    \ usize > > groups() {\n      std::vector< std::vector< usize > > result(n_);\n\
    \n      std::vector< usize > leaders(n_), g_sizes(n_);\n      for (usize v: rep(0,\
    \ n_)) {\n        leaders[v] = impl_leader(v);\n        g_sizes[leaders[v]]++;\n\
    \      }\n      for (usize v: rep(0, n_)) {\n        result[v].reserve(g_sizes[v]);\n\
    \      }\n      for (usize v: rep(0, n_)) {\n        result[leaders[v]].emplace_back(v);\n\
    \      }\n\n      auto empty_check = [](const std::vector< usize > &vs) {\n  \
    \      return vs.empty();\n      };\n      result.erase(\n        std::remove_if(result.begin(),\
    \ result.end(), empty_check),\n        result.end()\n      );\n\n      return\
    \ result;\n    }\n\n  };\n\n} // namespace luz\n#line 5 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\
    \n\n#line 7 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\n#include <utility>\n\
    #include <unordered_map>\n#line 10 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\
    \n\nnamespace luz {\n\n  template< typename cost_type >\n  class OfflineLCAQuery\
    \ {\n    usize g_size_;\n    Graph< cost_type > g_;\n\n    usize query_count_;\n\
    \    std::vector< std::vector< std::pair< usize, usize > > > qs_;\n\n    std::vector<\
    \ std::unordered_map< usize, usize > > to_qi_;\n\n    DisjointSetUnion dsu_;\n\
    \    std::vector< bool > visited_;\n    std::vector< usize > ancestors_;\n\n \
    \   std::vector< usize > query_results_;\n\n    void bound_check(usize v) const\
    \ {\n      assert(v < g_size_);\n    }\n\n    void dfs(usize v) {\n      visited_[v]\
    \ = true;\n      ancestors_[v] = v;\n\n      for (const auto &e: g_[v]) {\n  \
    \      if (visited_[e.to]) continue;\n        dfs(e.to);\n        dsu_.merge(v,\
    \ e.to);\n        ancestors_[dsu_.leader(v)] = v;\n      }\n\n      for (const\
    \ auto &[u, qi]: qs_[v]) {\n        if (not visited_[u]) continue;\n        query_results_[qi]\
    \ = ancestors_[dsu_.leader(u)];\n      }\n    }\n\n   public:\n    using Queries\
    \ = std::vector< std::pair< usize, usize > >;\n\n    OfflineLCAQuery(Graph< cost_type\
    \ > &g):\n      g_size_(g.size()), g_(g),\n      query_count_(0), qs_(g_size_),\
    \ to_qi_(g_size_),\n      dsu_(g_size_), visited_(g_size_, false), ancestors_(g_size_)\
    \ {}\n\n    usize add_query(usize u, usize v) {\n      bound_check(u);\n     \
    \ bound_check(v);\n      qs_[u].emplace_back(v, query_count_);\n      qs_[v].emplace_back(u,\
    \ query_count_);\n      to_qi_[u][v] = to_qi_[v][u] = query_count_;\n      return\
    \ query_count_++;\n    }\n\n    void build(usize root) {\n      bound_check(root);\n\
    \      query_results_.resize(query_count_);\n      dfs(root);\n    }\n\n    usize\
    \ lca(usize u, usize v) {\n      bound_check(u);\n      bound_check(v);\n    \
    \  assert(to_qi_[u].count(v));\n      usize qi = to_qi_[u][v];\n      return query_results_[qi];\n\
    \    }\n\n  };\n\n} // namespace luz\n#line 7 \"test/aoj/grl-5-c.test.cpp\"\n\n\
    #include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n;\n   \
    \ std::cin >> n;\n\n    Graph< i32 > g(n);\n    for (usize v: rep(0, n)) {\n \
    \     usize k;\n      std::cin >> k;\n\n      for ([[maybe_unused]] usize _: rep(0,\
    \ k)) {\n        usize u;\n        std::cin >> u;\n        g.add_undirected_edge(u,\
    \ v);\n      }\n    }\n\n    OfflineLCAQuery offline_lcas(g);\n\n    usize q;\n\
    \    std::cin >> q;\n\n    std::vector< std::pair< usize, usize > > qs(q);\n \
    \   for (auto &[u, v]: qs) {\n      std::cin >> u >> v;\n      offline_lcas.add_query(u,\
    \ v);\n    }\n\n    offline_lcas.build(0);\n    for (const auto &[u, v]: qs) {\n\
    \      std::cout << offline_lcas.lca(u, v) << std::endl;\n    }\n\n  }\n\n} //\
    \ namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\n\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/graph/graph-template.hpp\"\n#include \"src/graph/offline-query-lowest-common-ancestor.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n;\n\
    \    std::cin >> n;\n\n    Graph< i32 > g(n);\n    for (usize v: rep(0, n)) {\n\
    \      usize k;\n      std::cin >> k;\n\n      for ([[maybe_unused]] usize _:\
    \ rep(0, k)) {\n        usize u;\n        std::cin >> u;\n        g.add_undirected_edge(u,\
    \ v);\n      }\n    }\n\n    OfflineLCAQuery offline_lcas(g);\n\n    usize q;\n\
    \    std::cin >> q;\n\n    std::vector< std::pair< usize, usize > > qs(q);\n \
    \   for (auto &[u, v]: qs) {\n      std::cin >> u >> v;\n      offline_lcas.add_query(u,\
    \ v);\n    }\n\n    offline_lcas.build(0);\n    for (const auto &[u, v]: qs) {\n\
    \      std::cout << offline_lcas.lca(u, v) << std::endl;\n    }\n\n  }\n\n} //\
    \ namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/graph/graph-template.hpp
  - src/graph/offline-query-lowest-common-ancestor.hpp
  - src/data-structure/disjoint-set-union.hpp
  isVerificationFile: true
  path: test/aoj/grl-5-c.test.cpp
  requiredBy: []
  timestamp: '2022-08-06 20:47:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl-5-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl-5-c.test.cpp
- /verify/test/aoj/grl-5-c.test.cpp.html
title: test/aoj/grl-5-c.test.cpp
---
