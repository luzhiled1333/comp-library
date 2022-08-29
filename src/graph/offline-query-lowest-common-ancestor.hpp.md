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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_5_c.test.cpp
    title: test/aoj/grl_5_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr {\n      usize\
    \ i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n      void operator++()\
    \ noexcept {\n        ++i;\n      }\n      constexpr usize operator*() const noexcept\
    \ {\n        return i;\n      }\n      constexpr bool operator!=(const itr x)\
    \ const noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f,\
    \ l;\n    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#line 5 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 7 \"src/data-structure/disjoint-set-union.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion\
    \ {\n    usize n_;\n\n    // vals_[v] :=\n    //   if v is root node: -1 * component\
    \ size\n    //   otherwise: parent node\n    std::vector< isize > vals_;\n\n \
    \   void bound_check(usize v) const {\n      assert(v < n_);\n    }\n\n    usize\
    \ impl_leader(usize v) {\n      if (vals_[v] < 0) return v;\n      return vals_[v]\
    \ = leader(vals_[v]);\n    }\n\n   public:\n    DisjointSetUnion() = default;\n\
    \    explicit DisjointSetUnion(usize n): n_(n), vals_(n, -1) {}\n\n    usize size()\
    \ const {\n      return n_;\n    }\n\n    usize leader(usize v) {\n      bound_check(v);\n\
    \      return impl_leader(v);\n    }\n\n    bool same(usize u, usize v) {\n  \
    \    bound_check(u), bound_check(v);\n      return impl_leader(u) == impl_leader(v);\n\
    \    }\n\n    usize merge(usize u, usize v) {\n      bound_check(u);\n      bound_check(v);\n\
    \n      isize x = impl_leader(u);\n      isize y = impl_leader(v);\n      if (x\
    \ == y) return x;\n      if (-vals_[x] < -vals_[y]) std::swap(x, y);\n      vals_[x]\
    \ += vals_[y];\n      vals_[y] = x;\n      return x;\n    }\n\n    usize group_size(usize\
    \ v) {\n      bound_check(v);\n      return -vals_[impl_leader(v)];\n    }\n\n\
    \    std::vector< std::vector< usize > > groups() {\n      std::vector< std::vector<\
    \ usize > > result(n_);\n\n      std::vector< usize > leaders(n_), g_sizes(n_);\n\
    \      for (usize v: rep(0, n_)) {\n        leaders[v] = impl_leader(v);\n   \
    \     g_sizes[leaders[v]]++;\n      }\n      for (usize v: rep(0, n_)) {\n   \
    \     result[v].reserve(g_sizes[v]);\n      }\n      for (usize v: rep(0, n_))\
    \ {\n        result[leaders[v]].emplace_back(v);\n      }\n\n      auto empty_check\
    \ = [](const std::vector< usize > &vs) {\n        return vs.empty();\n      };\n\
    \      result.erase(\n          std::remove_if(result.begin(), result.end(), empty_check),\n\
    \          result.end());\n\n      return result;\n    }\n  };\n\n} // namespace\
    \ luz\n#line 2 \"src/graph/graph-template.hpp\"\n\n#line 4 \"src/graph/graph-template.hpp\"\
    \n\n#line 7 \"src/graph/graph-template.hpp\"\n\nnamespace luz {\n\n  template\
    \ < typename cost_type >\n  class Edge {\n   public:\n    usize from, to;\n  \
    \  cost_type cost;\n    usize id;\n    Edge() = default;\n    Edge(usize from_,\
    \ usize to_, cost_type cost_, usize id_)\n        : from(from_),\n          to(to_),\n\
    \          cost(cost_),\n          id(id_) {}\n  };\n\n  template < typename cost_type\
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
    \ {\n      return g[v];\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\
    \n\n#line 7 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\n#include <unordered_map>\n\
    #include <utility>\n#line 10 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\
    \n\nnamespace luz {\n\n  template < typename cost_type >\n  class OfflineLCAQuery\
    \ {\n    usize g_size_;\n    Graph< cost_type > g_;\n\n    usize query_count_;\n\
    \    std::vector< std::vector< std::pair< usize, usize > > > qs_;\n\n    std::vector<\
    \ std::unordered_map< usize, usize > > to_qi_;\n\n    DisjointSetUnion dsu_;\n\
    \    std::vector< bool > visited_;\n    std::vector< usize > ancestors_;\n\n \
    \   std::vector< usize > query_results_;\n\n    void bound_check(usize v) const\
    \ {\n      assert(v < g_size_);\n    }\n\n    void dfs(usize v) {\n      visited_[v]\
    \   = true;\n      ancestors_[v] = v;\n\n      for (const auto &e: g_[v]) {\n\
    \        if (visited_[e.to]) continue;\n        dfs(e.to);\n        dsu_.merge(v,\
    \ e.to);\n        ancestors_[dsu_.leader(v)] = v;\n      }\n\n      for (const\
    \ auto &[u, qi]: qs_[v]) {\n        if (not visited_[u]) continue;\n        query_results_[qi]\
    \ = ancestors_[dsu_.leader(u)];\n      }\n    }\n\n   public:\n    using Queries\
    \ = std::vector< std::pair< usize, usize > >;\n\n    OfflineLCAQuery(Graph< cost_type\
    \ > &g)\n        : g_size_(g.size()),\n          g_(g),\n          query_count_(0),\n\
    \          qs_(g_size_),\n          to_qi_(g_size_),\n          dsu_(g_size_),\n\
    \          visited_(g_size_, false),\n          ancestors_(g_size_) {}\n\n   \
    \ usize add_query(usize u, usize v) {\n      bound_check(u);\n      bound_check(v);\n\
    \      qs_[u].emplace_back(v, query_count_);\n      qs_[v].emplace_back(u, query_count_);\n\
    \      to_qi_[u][v] = to_qi_[v][u] = query_count_;\n      return query_count_++;\n\
    \    }\n\n    void build(usize root) {\n      bound_check(root);\n      query_results_.resize(query_count_);\n\
    \      dfs(root);\n    }\n\n    usize lca(usize u, usize v) {\n      bound_check(u);\n\
    \      bound_check(v);\n      assert(to_qi_[u].count(v));\n      usize qi = to_qi_[u][v];\n\
    \      return query_results_[qi];\n    }\n  };\n\n} // namespace luz\n"
  code: "#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/data-structure/disjoint-set-union.hpp\"\n#include \"src/graph/graph-template.hpp\"\
    \n\n#include <cassert>\n#include <unordered_map>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename cost_type >\n  class OfflineLCAQuery\
    \ {\n    usize g_size_;\n    Graph< cost_type > g_;\n\n    usize query_count_;\n\
    \    std::vector< std::vector< std::pair< usize, usize > > > qs_;\n\n    std::vector<\
    \ std::unordered_map< usize, usize > > to_qi_;\n\n    DisjointSetUnion dsu_;\n\
    \    std::vector< bool > visited_;\n    std::vector< usize > ancestors_;\n\n \
    \   std::vector< usize > query_results_;\n\n    void bound_check(usize v) const\
    \ {\n      assert(v < g_size_);\n    }\n\n    void dfs(usize v) {\n      visited_[v]\
    \   = true;\n      ancestors_[v] = v;\n\n      for (const auto &e: g_[v]) {\n\
    \        if (visited_[e.to]) continue;\n        dfs(e.to);\n        dsu_.merge(v,\
    \ e.to);\n        ancestors_[dsu_.leader(v)] = v;\n      }\n\n      for (const\
    \ auto &[u, qi]: qs_[v]) {\n        if (not visited_[u]) continue;\n        query_results_[qi]\
    \ = ancestors_[dsu_.leader(u)];\n      }\n    }\n\n   public:\n    using Queries\
    \ = std::vector< std::pair< usize, usize > >;\n\n    OfflineLCAQuery(Graph< cost_type\
    \ > &g)\n        : g_size_(g.size()),\n          g_(g),\n          query_count_(0),\n\
    \          qs_(g_size_),\n          to_qi_(g_size_),\n          dsu_(g_size_),\n\
    \          visited_(g_size_, false),\n          ancestors_(g_size_) {}\n\n   \
    \ usize add_query(usize u, usize v) {\n      bound_check(u);\n      bound_check(v);\n\
    \      qs_[u].emplace_back(v, query_count_);\n      qs_[v].emplace_back(u, query_count_);\n\
    \      to_qi_[u][v] = to_qi_[v][u] = query_count_;\n      return query_count_++;\n\
    \    }\n\n    void build(usize root) {\n      bound_check(root);\n      query_results_.resize(query_count_);\n\
    \      dfs(root);\n    }\n\n    usize lca(usize u, usize v) {\n      bound_check(u);\n\
    \      bound_check(v);\n      assert(to_qi_[u].count(v));\n      usize qi = to_qi_[u][v];\n\
    \      return query_results_[qi];\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/data-structure/disjoint-set-union.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: false
  path: src/graph/offline-query-lowest-common-ancestor.hpp
  requiredBy: []
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_5_c.test.cpp
documentation_of: src/graph/offline-query-lowest-common-ancestor.hpp
layout: document
redirect_from:
- /library/src/graph/offline-query-lowest-common-ancestor.hpp
- /library/src/graph/offline-query-lowest-common-ancestor.hpp.html
title: src/graph/offline-query-lowest-common-ancestor.hpp
---