---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/data-structure/disjoint-set-union.hpp
    title: Disjoint Set Union (Union Find)
  - icon: ':heavy_check_mark:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/class/static-graph.hpp
    title: "\u9759\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\u7956\u5148 (Offline\
      \ Lowest Common Ancestor)"
  - icon: ':heavy_check_mark:'
    path: src/utility/pair-hash.hpp
    title: "std::pair \u306E Hash"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/grl_5_c/grl_5_c.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        ++i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rep(const usize f, const usize l)\
    \ noexcept\n        : f(std::min(f, l)),\n          l(l) {}\n    constexpr auto\
    \ begin() const noexcept {\n      return f;\n    }\n    constexpr auto end() const\
    \ noexcept {\n      return l;\n    }\n  };\n\n  struct rrep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        --i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rrep(const usize f, const usize l)\
    \ noexcept\n        : f(l - 1),\n          l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept {\n      return f;\n    }\n    constexpr auto end()\
    \ const noexcept {\n      return l;\n    }\n  };\n\n} // namespace luz\n#line\
    \ 2 \"src/graph/class/edge/edge.hpp\"\n\n#line 4 \"src/graph/class/edge/edge.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\n  template < typename T >\n  class\
    \ Edge {\n   public:\n    using cost_type = T;\n\n    usize from, to;\n    T cost;\n\
    \    usize id;\n    Edge() = default;\n    Edge(usize from_, usize to_, T cost_,\
    \ usize id_)\n        : from(from_),\n          to(to_),\n          cost(cost_),\n\
    \          id(id_) {}\n  };\n\n  template < typename T >\n  using Edges = std::vector<\
    \ Edge< T > >;\n\n} // namespace luz\n#line 2 \"src/graph/class/static-graph.hpp\"\
    \n\n#line 5 \"src/graph/class/static-graph.hpp\"\n\n#line 7 \"src/graph/class/static-graph.hpp\"\
    \n#include <cassert>\n#line 9 \"src/graph/class/static-graph.hpp\"\n\nnamespace\
    \ luz::internal {\n\n  template < typename Iterator >\n  class OutgoingEdges {\n\
    \    Iterator f, l;\n\n   public:\n    OutgoingEdges(Iterator f, Iterator l):\
    \ f(f), l(l) {}\n\n    Iterator begin() const {\n      return f;\n    }\n    Iterator\
    \ end() const {\n      return l;\n    }\n    usize size() const {\n      return\
    \ l - f;\n    }\n\n    auto &operator[](usize k) {\n      assert(k < size());\n\
    \      return begin()[k];\n    }\n    const auto &operator[](usize k) const {\n\
    \      assert(k < size());\n      return begin()[k];\n    }\n  };\n\n} // namespace\
    \ luz::internal\n\nnamespace luz {\n\n  template < typename Edge >\n  class StaticGraph\
    \ {\n\n    using Edges          = std::vector< Edge >;\n    using iterator   \
    \    = typename Edges::iterator;\n    using const_iterator = typename Edges::const_iterator;\n\
    \n    template < typename Iterator >\n    using Es = internal::OutgoingEdges<\
    \ Iterator >;\n\n   protected:\n    bool initialized;\n    usize vertex_count;\n\
    \    usize edge_count;\n\n    Edges edges;\n    std::vector< usize > outdegrees;\n\
    \n   public:\n    using cost_type = typename Edge::cost_type;\n\n    StaticGraph()\
    \ = default;\n    explicit StaticGraph(usize n)\n        : initialized(false),\n\
    \          vertex_count(n),\n          edge_count(0),\n          outdegrees(vertex_count)\
    \ {}\n\n    usize size() const {\n      return vertex_count;\n    }\n\n    void\
    \ initialize() {\n      assert(not initialized);\n\n      outdegrees.emplace_back(0);\n\
    \      for (usize i: rrep(0, size())) {\n        outdegrees[i] += outdegrees[i\
    \ + 1];\n      }\n\n      std::sort(edges.begin(), edges.end(),\n            \
    \    [](const Edge &e1, const Edge &e2) {\n        return e1.from != e2.from ?\
    \ e1.from > e2.from : e1.to < e2.to;\n      });\n\n      initialized = true;\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      assert(not initialized);\n      assert(from < size());\n      assert(to\
    \ < size());\n      edges.emplace_back(from, to, cost, edge_count++);\n      outdegrees[from]++;\n\
    \    }\n\n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n\
    \      assert(not initialized);\n      assert(u < size());\n      assert(v < size());\n\
    \      assert(u != v);\n      edges.emplace_back(u, v, cost, edge_count);\n  \
    \    outdegrees[u]++;\n      edges.emplace_back(v, u, cost, edge_count++);\n \
    \     outdegrees[v]++;\n    }\n\n    Es< iterator > operator[](const usize &v)\
    \ {\n      assert(initialized);\n      return Es< iterator >(edges.begin() + outdegrees[v\
    \ + 1],\n                            edges.begin() + outdegrees[v]);\n    }\n\n\
    \    const Es< const_iterator > operator[](const usize &v) const {\n      assert(initialized);\n\
    \      return Es< const_iterator >(edges.cbegin() + outdegrees[v + 1],\n     \
    \                             edges.cbegin() + outdegrees[v]);\n    }\n  };\n\n\
    } // namespace luz\n#line 2 \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
    \n\n#line 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 5 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#line 9 \"src/data-structure/disjoint-set-union.hpp\"\n\nnamespace luz {\n\
    \n  class DisjointSetUnion {\n    usize n;\n\n    // vals[v] :=\n    //   if v\
    \ is root node: -1 * component size\n    //   otherwise: parent node\n    std::vector<\
    \ isize > vals;\n\n    void bound_check(usize v) const {\n      assert(v < n);\n\
    \    }\n\n    usize impl_leader(usize v) {\n      if (vals[v] < 0) return v;\n\
    \      return vals[v] = leader(vals[v]);\n    }\n\n   public:\n    DisjointSetUnion()\
    \ = default;\n    explicit DisjointSetUnion(usize n): n(n), vals(n, -1) {}\n\n\
    \    usize size() const {\n      return n;\n    }\n\n    usize leader(usize v)\
    \ {\n      bound_check(v);\n      return impl_leader(v);\n    }\n\n    bool same(usize\
    \ u, usize v) {\n      bound_check(u), bound_check(v);\n      return impl_leader(u)\
    \ == impl_leader(v);\n    }\n\n    usize merge(usize u, usize v) {\n      bound_check(u);\n\
    \      bound_check(v);\n\n      isize x = impl_leader(u);\n      isize y = impl_leader(v);\n\
    \      if (x == y) return x;\n      if (-vals[x] < -vals[y]) std::swap(x, y);\n\
    \      vals[x] += vals[y];\n      vals[y] = x;\n      return x;\n    }\n\n   \
    \ usize group_size(usize v) {\n      bound_check(v);\n      return -vals[impl_leader(v)];\n\
    \    }\n\n    std::vector< std::vector< usize > > groups() {\n      std::vector<\
    \ std::vector< usize > > result(n);\n\n      std::vector< usize > leaders(n),\
    \ g_sizes(n);\n      for (usize v: rep(0, n)) {\n        leaders[v] = impl_leader(v);\n\
    \        g_sizes[leaders[v]]++;\n      }\n      for (usize v: rep(0, n)) {\n \
    \       result[v].reserve(g_sizes[v]);\n      }\n      for (usize v: rep(0, n))\
    \ {\n        result[leaders[v]].emplace_back(v);\n      }\n\n      auto empty_check\
    \ = [](const std::vector< usize > &vs) {\n        return vs.empty();\n      };\n\
    \      result.erase(\n          std::remove_if(result.begin(), result.end(), empty_check),\n\
    \          result.end());\n\n      return result;\n    }\n  };\n\n} // namespace\
    \ luz\n#line 2 \"src/utility/pair-hash.hpp\"\n\n#line 4 \"src/utility/pair-hash.hpp\"\
    \n\n#include <functional>\n#include <utility>\n\nnamespace luz {\n\n  class PairHash\
    \ {\n    template < typename T >\n    usize hash_combine(usize hr, const T &x)\
    \ const {\n      usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr <<\
    \ 11) + (hr >> 13));\n    }\n\n   public:\n    template < typename F, typename\
    \ S >\n    usize operator()(const std::pair< F, S > &p) const {\n      return\
    \ hash_combine(hash_combine(0, p.first), p.second);\n    }\n  };\n\n} // namespace\
    \ luz\n#line 7 \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
    \n\n#line 9 \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
    \n#include <unordered_map>\n#line 12 \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
    \n\nnamespace luz {\n\n  template < class G >\n  class OfflineLCAQuery {\n   \
    \ using graph     = G;\n    using cost_type = typename G::cost_type;\n    usize\
    \ g_size;\n    graph g;\n\n    usize query_count;\n    std::vector< std::vector<\
    \ usize > > qs;\n\n    DisjointSetUnion dsu;\n    std::vector< bool > visited;\n\
    \    std::vector< usize > ancestors;\n\n    using query_type = std::pair< usize,\
    \ usize >;\n    std::unordered_map< query_type, usize, PairHash > results;\n\n\
    \    void bound_check(usize v) const {\n      assert(v < g_size);\n    }\n\n \
    \   void dfs(usize v) {\n      visited[v]   = true;\n      ancestors[v] = v;\n\
    \n      for (const auto &e: g[v]) {\n        if (visited[e.to]) continue;\n  \
    \      dfs(e.to);\n        dsu.merge(v, e.to);\n        ancestors[dsu.leader(v)]\
    \ = v;\n      }\n\n      for (const auto &u: qs[v]) {\n        if (not visited[u])\
    \ continue;\n        results[query_type(u, v)] = results[query_type(v, u)] =\n\
    \            ancestors[dsu.leader(u)];\n      }\n    }\n\n   public:\n    using\
    \ Queries = std::vector< std::pair< usize, usize > >;\n\n    OfflineLCAQuery(G\
    \ &g)\n        : g_size(g.size()),\n          g(g),\n          query_count(0),\n\
    \          qs(g_size),\n          dsu(g_size),\n          visited(g_size, false),\n\
    \          ancestors(g_size) {}\n\n    void add_query(usize u, usize v) {\n  \
    \    bound_check(u);\n      bound_check(v);\n      qs[u].emplace_back(v);\n  \
    \    qs[v].emplace_back(u);\n      query_count++;\n    }\n\n    void build(usize\
    \ root) {\n      bound_check(root);\n      results.reserve(2 * query_count);\n\
    \      dfs(root);\n    }\n\n    usize lca(usize u, usize v) {\n      bound_check(u);\n\
    \      bound_check(v);\n      query_type qi(u, v);\n      assert(results.count(qi));\n\
    \      return results[qi];\n    }\n  };\n\n} // namespace luz\n#line 9 \"test/aoj/grl_5_c/grl_5_c.test.cpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    using edge\
    \  = Edge< i32 >;\n    using graph = StaticGraph< edge >;\n\n    usize n;\n  \
    \  std::cin >> n;\n\n    graph g(n);\n    for (usize v: rep(0, n)) {\n      usize\
    \ k;\n      std::cin >> k;\n\n      for ([[maybe_unused]] usize _: rep(0, k))\
    \ {\n        usize u;\n        std::cin >> u;\n        g.add_undirected_edge(u,\
    \ v);\n      }\n    }\n\n    g.initialize();\n\n    OfflineLCAQuery offline_lcas(g);\n\
    \n    usize q;\n    std::cin >> q;\n\n    std::vector< std::pair< usize, usize\
    \ > > qs(q);\n    for (auto &[u, v]: qs) {\n      std::cin >> u >> v;\n      offline_lcas.add_query(u,\
    \ v);\n    }\n\n    offline_lcas.build(0);\n    for (const auto &[u, v]: qs) {\n\
    \      std::cout << offline_lcas.lca(u, v) << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/graph/class/edge/edge.hpp\"\
    \n#include \"src/graph/class/static-graph.hpp\"\n#include \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    using edge\
    \  = Edge< i32 >;\n    using graph = StaticGraph< edge >;\n\n    usize n;\n  \
    \  std::cin >> n;\n\n    graph g(n);\n    for (usize v: rep(0, n)) {\n      usize\
    \ k;\n      std::cin >> k;\n\n      for ([[maybe_unused]] usize _: rep(0, k))\
    \ {\n        usize u;\n        std::cin >> u;\n        g.add_undirected_edge(u,\
    \ v);\n      }\n    }\n\n    g.initialize();\n\n    OfflineLCAQuery offline_lcas(g);\n\
    \n    usize q;\n    std::cin >> q;\n\n    std::vector< std::pair< usize, usize\
    \ > > qs(q);\n    for (auto &[u, v]: qs) {\n      std::cin >> u >> v;\n      offline_lcas.add_query(u,\
    \ v);\n    }\n\n    offline_lcas.build(0);\n    for (const auto &[u, v]: qs) {\n\
    \      std::cout << offline_lcas.lca(u, v) << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/class/static-graph.hpp
  - src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp
  - src/data-structure/disjoint-set-union.hpp
  - src/utility/pair-hash.hpp
  isVerificationFile: true
  path: test/aoj/grl_5_c/grl_5_c.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_5_c/grl_5_c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_5_c/grl_5_c.test.cpp
- /verify/test/aoj/grl_5_c/grl_5_c.test.cpp.html
title: test/aoj/grl_5_c/grl_5_c.test.cpp
---
