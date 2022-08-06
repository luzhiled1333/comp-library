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
    path: test/aoj/grl-5-c.test.cpp
    title: test/aoj/grl-5-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\n#include\
    \ <vector>\n#include <utility>\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\
    \n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include\
    \ <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize\
    \ = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n  \n} // namespace\
    \ luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\n\
    namespace luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept : i(i) {}\n      void operator++() noexcept { ++i;\
    \ }\n      constexpr usize operator*() const noexcept { return i; }\n      constexpr\
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
    \ }\n  };\n\n} // namespace luz\n#line 2 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#line 5 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 7 \"src/data-structure/disjoint-set-union.hpp\"\
    \n#include <cassert>\n#line 9 \"src/data-structure/disjoint-set-union.hpp\"\n\n\
    namespace luz {\n\n  class DisjointSetUnion {\n    usize n_;\n\n    // vals_[v]\
    \ :=\n    //   if v is root node: -1 * component size\n    //   otherwise: parent\
    \ node\n    std::vector< isize > vals_;\n\n    void bound_check(usize v) const\
    \ {\n      assert(v < n_);\n    }\n\n    usize impl_leader(usize v) {\n      if\
    \ (vals_[v] < 0) return v;\n      return vals_[v] = leader(vals_[v]);\n    }\n\
    \n   public:\n    DisjointSetUnion() = default;\n    explicit DisjointSetUnion(usize\
    \ n): n_(n), vals_(n, -1) {}\n\n    usize size() const {\n      return n_;\n \
    \   }\n\n    usize leader(usize v) {\n      bound_check(v);\n      return impl_leader(v);\n\
    \    }\n\n    bool same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n\
    \      return impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize\
    \ u, usize v) {\n      bound_check(u); bound_check(v);\n\n      isize x = impl_leader(u);\n\
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
    \ result;\n    }\n\n  };\n\n} // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\
    \n\n#line 5 \"src/graph/graph-template.hpp\"\n\n#line 7 \"src/graph/graph-template.hpp\"\
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
    #line 8 \"src/graph/offline-query-lowest-common-ancestor.hpp\"\n\nnamespace luz\
    \ {\n\n  template< typename cost_type >\n  class OfflineLCAQuery: Graph< cost_type\
    \ > {\n    using Graph< cost_type >::g;\n\n    std::vector< std::vector< std::pair<\
    \ usize, usize > > > qs;\n\n    DisjointSetUnion dsu;\n    std::vector< bool >\
    \ visited;\n    std::vector< usize > ancestors;\n\n    void dfs(usize v, std::vector<\
    \ usize > &ret) {\n      visited[v] = true;\n      ancestors[v] = v;\n\n     \
    \ for (const auto &e: g[v]) {\n        if (visited[e.to]) continue;\n        dfs(e.to,\
    \ ret);\n        dsu.merge(v, e.to);\n        ancestors[dsu.leader(v)] = v;\n\
    \      }\n\n      for (const auto &[u, qi]: qs[v]) {\n        if (not visited[u])\
    \ continue;\n        ret[qi] = ancestors[dsu.leader(u)];\n      }\n    }\n\n \
    \  public:\n    using Queries = std::vector< std::pair< usize, usize > >;\n\n\
    \    using Graph< cost_type >::Graph;\n    using Graph< cost_type >::add_undirected_edge;\n\
    \    using Graph< cost_type >::size;\n\n    std::vector< usize > solve(const Queries\
    \ &queries, usize root) {\n      usize q = queries.size();\n      qs.resize(size());\n\
    \      for (usize qi: rep(0, q)) {\n        const auto [u, v] = queries[qi];\n\
    \        qs[u].emplace_back(v, qi);\n        qs[v].emplace_back(u, qi);\n    \
    \  }\n\n      dsu = DisjointSetUnion(size());\n      visited.assign(size(), false);\n\
    \      ancestors.resize(size());\n\n      std::vector< usize > ret(q);\n     \
    \ dfs(root, ret);\n      qs.clear();\n      return ret;\n    }\n\n  };\n\n} //\
    \ namespace luz\n"
  code: "#include <vector>\n#include <utility>\n\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/data-structure/disjoint-set-union.hpp\"\
    \n#include \"src/graph/graph-template.hpp\"\n\nnamespace luz {\n\n  template<\
    \ typename cost_type >\n  class OfflineLCAQuery: Graph< cost_type > {\n    using\
    \ Graph< cost_type >::g;\n\n    std::vector< std::vector< std::pair< usize, usize\
    \ > > > qs;\n\n    DisjointSetUnion dsu;\n    std::vector< bool > visited;\n \
    \   std::vector< usize > ancestors;\n\n    void dfs(usize v, std::vector< usize\
    \ > &ret) {\n      visited[v] = true;\n      ancestors[v] = v;\n\n      for (const\
    \ auto &e: g[v]) {\n        if (visited[e.to]) continue;\n        dfs(e.to, ret);\n\
    \        dsu.merge(v, e.to);\n        ancestors[dsu.leader(v)] = v;\n      }\n\
    \n      for (const auto &[u, qi]: qs[v]) {\n        if (not visited[u]) continue;\n\
    \        ret[qi] = ancestors[dsu.leader(u)];\n      }\n    }\n\n   public:\n \
    \   using Queries = std::vector< std::pair< usize, usize > >;\n\n    using Graph<\
    \ cost_type >::Graph;\n    using Graph< cost_type >::add_undirected_edge;\n  \
    \  using Graph< cost_type >::size;\n\n    std::vector< usize > solve(const Queries\
    \ &queries, usize root) {\n      usize q = queries.size();\n      qs.resize(size());\n\
    \      for (usize qi: rep(0, q)) {\n        const auto [u, v] = queries[qi];\n\
    \        qs[u].emplace_back(v, qi);\n        qs[v].emplace_back(u, qi);\n    \
    \  }\n\n      dsu = DisjointSetUnion(size());\n      visited.assign(size(), false);\n\
    \      ancestors.resize(size());\n\n      std::vector< usize > ret(q);\n     \
    \ dfs(root, ret);\n      qs.clear();\n      return ret;\n    }\n\n  };\n\n} //\
    \ namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/data-structure/disjoint-set-union.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: false
  path: src/graph/offline-query-lowest-common-ancestor.hpp
  requiredBy: []
  timestamp: '2022-08-06 17:20:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl-5-c.test.cpp
documentation_of: src/graph/offline-query-lowest-common-ancestor.hpp
layout: document
redirect_from:
- /library/src/graph/offline-query-lowest-common-ancestor.hpp
- /library/src/graph/offline-query-lowest-common-ancestor.hpp.html
title: src/graph/offline-query-lowest-common-ancestor.hpp
---
