---
data:
  _extendedDependsOn:
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
    path: src/graph/single-source-shortest-path/in-unweighted-graph.hpp
    title: "\u91CD\u307F\u306A\u3057\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
      \ (Single Source Shortest Path in Unweighted Graph, BFS)"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/offline-query/offline-query-level-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3 Level Ancestor (Offline Level Ancestor)"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\u7956\u5148 (Offline\
      \ Lowest Common Ancestor)"
  - icon: ':heavy_check_mark:'
    path: src/utility/pair-hash.hpp
    title: "std::pair \u306E Hash"
  - icon: ':heavy_check_mark:'
    path: src/utility/tuple-hash.hpp
    title: "std::tuple \u306E Hash"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/tree/offline-query/offline-query-jump-on-tree.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 2 \"src/graph/single-source-shortest-path/in-unweighted-graph.hpp\"\n\n#line\
    \ 4 \"src/graph/single-source-shortest-path/in-unweighted-graph.hpp\"\n\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\nnamespace luz::sssp {\n\n \
    \ template < class G >\n  class InUnweightedGraph {\n    using cost_type = typename\
    \ G::cost_type;\n    using graph     = G;\n\n    static constexpr usize undefined_\
    \ =\n        std::numeric_limits< usize >::max();\n    static constexpr usize\
    \ inf_ = std::numeric_limits< usize >::max();\n\n    graph g;\n    usize g_size;\n\
    \    usize source;\n\n    std::vector< usize > ds, parents, ids;\n\n    void bfs(usize\
    \ s) {\n      std::queue< usize > que;\n\n      ds[s] = 0;\n      que.emplace(s);\n\
    \n      while (not que.empty()) {\n        usize v = que.front();\n        que.pop();\n\
    \n        for (const auto &e: g[v]) {\n          usize u = e.to;\n          if\
    \ (ds[u] != inf()) {\n            continue;\n          }\n\n          ds[u] =\
    \ ds[v] + 1;\n          que.emplace(u);\n          parents[u] = v;\n         \
    \ ids[u]     = e.id;\n        }\n      }\n    }\n\n   public:\n    explicit InUnweightedGraph(const\
    \ graph &g_, usize source_)\n        : g(g_),\n          g_size(g.size()),\n \
    \         source(source_),\n          ds(g_size, inf()),\n          parents(g_size,\
    \ undefined()),\n          ids(g_size, undefined()) {\n      bfs(source);\n  \
    \  }\n\n    graph get_original_graph() const {\n      return g;\n    }\n\n   \
    \ inline usize inf() const {\n      return inf_;\n    }\n\n    inline usize distance(const\
    \ usize v) const {\n      return ds[v];\n    }\n\n    inline std::vector< usize\
    \ > get_distances() const {\n      return ds;\n    }\n\n    inline usize undefined()\
    \ const {\n      return undefined_;\n    }\n\n    inline usize parent(const usize\
    \ v) const {\n      return parents[v];\n    }\n\n    inline std::vector< usize\
    \ > get_parents() const {\n      return parents;\n    }\n\n    inline usize edge_label(const\
    \ usize v) const {\n      return ids[v];\n    }\n\n    inline std::vector< usize\
    \ > get_edge_labels() const {\n      return ids;\n    }\n  };\n\n} // namespace\
    \ luz::sssp\n#line 2 \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\
    \n\n#line 2 \"src/utility/pair-hash.hpp\"\n\n#line 4 \"src/utility/pair-hash.hpp\"\
    \n\n#include <functional>\n#include <utility>\n\nnamespace luz {\n\n  class PairHash\
    \ {\n    template < typename T >\n    usize hash_combine(usize hr, const T &x)\
    \ const {\n      usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr <<\
    \ 11) + (hr >> 13));\n    }\n\n   public:\n    template < typename F, typename\
    \ S >\n    usize operator()(const std::pair< F, S > &p) const {\n      return\
    \ hash_combine(hash_combine(0, p.first), p.second);\n    }\n  };\n\n} // namespace\
    \ luz\n#line 6 \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\
    \n\n#include <cassert>\n#include <optional>\n#include <unordered_map>\n#line 12\
    \ \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\n\nnamespace\
    \ luz {\n\n  template < class G >\n  class OfflineLAQuery {\n    using graph \
    \    = G;\n    using cost_type = typename graph::cost_type;\n\n    usize g_size;\n\
    \    graph g;\n\n    usize query_count;\n    std::vector< std::vector< usize >\
    \ > qs;\n\n    std::vector< bool > visited;\n    std::vector< usize > path;\n\n\
    \    using query_type = std::pair< usize, usize >;\n    std::unordered_map< query_type,\
    \ std::optional< usize >, PairHash >\n        results;\n\n    void bound_check(usize\
    \ v) const {\n      assert(v < g_size);\n    }\n\n    void dfs(usize v) {\n  \
    \    visited[v] = true;\n      path.emplace_back(v);\n\n      for (const auto\
    \ &level: qs[v]) {\n        if (level < path.size()) {\n          results[query_type(v,\
    \ level)] = path[level];\n        }\n      }\n\n      for (const auto &e: g[v])\
    \ {\n        if (visited[e.to]) continue;\n        dfs(e.to);\n      }\n\n   \
    \   path.pop_back();\n    }\n\n   public:\n    explicit OfflineLAQuery() = default;\n\
    \n    explicit OfflineLAQuery(graph &g)\n        : g_size(g.size()),\n       \
    \   g(g),\n          query_count(0),\n          qs(g_size),\n          visited(g_size,\
    \ false) {}\n\n    void add_query(usize v, usize level) {\n      bound_check(v);\n\
    \      qs[v].emplace_back(level);\n      query_count++;\n    }\n\n    void build(usize\
    \ root) {\n      bound_check(root);\n      results.reserve(query_count);\n   \
    \   path.reserve(g_size);\n      dfs(root);\n    }\n\n    std::optional< usize\
    \ > la(usize v, usize level) const {\n      bound_check(v);\n      query_type\
    \ qi(v, level);\n      assert(results.count(qi));\n      return (*results.find(qi)).second;\n\
    \    }\n  };\n\n} // namespace luz\n#line 2 \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
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
    \ luz\n#line 7 \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
    \n\n#line 12 \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
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
    \      return results[qi];\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/utility/tuple-hash.hpp\"\
    \n\n#line 4 \"src/utility/tuple-hash.hpp\"\n\n#line 6 \"src/utility/tuple-hash.hpp\"\
    \n#include <tuple>\n#line 8 \"src/utility/tuple-hash.hpp\"\n\nnamespace luz::impl_tuple_hash\
    \ {\n\n  template < usize Index >\n  class ImplTupleHash {\n   public:\n    template\
    \ < typename T >\n    usize hash_combine(const T &x, usize hr) const {\n     \
    \ usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr << 11) + (hr >> 13));\n\
    \    }\n\n    template < class Tuple >\n    usize operator()(const Tuple &t) const\
    \ noexcept {\n      usize hr = ImplTupleHash< Index - 1 >()(t);\n      return\
    \ hash_combine(std::get< Index - 1 >(t), hr);\n    }\n  };\n\n  template <>\n\
    \  class ImplTupleHash< 0 > {\n   public:\n    template < class Tuple >\n    usize\
    \ operator()([[maybe_unused]] const Tuple &_) const noexcept {\n      return 0;\n\
    \    }\n  };\n\n} // namespace luz::impl_tuple_hash\n\nnamespace luz {\n\n  class\
    \ TupleHash {\n    template < usize Index >\n    using ImplTupleHash = impl_tuple_hash::ImplTupleHash<\
    \ Index >;\n\n   public:\n    template < class... Args >\n    usize operator()(const\
    \ std::tuple< Args... > &t) const {\n      using Tuple = std::tuple< Args... >;\n\
    \      return ImplTupleHash< std::tuple_size< Tuple >::value >()(t);\n    }\n\
    \  };\n\n} // namespace luz\n#line 9 \"src/graph/tree/offline-query/offline-query-jump-on-tree.hpp\"\
    \n\n#line 15 \"src/graph/tree/offline-query/offline-query-jump-on-tree.hpp\"\n\
    \nnamespace luz {\n\n  template < class G >\n  class OfflineJumpOnTreeQuery {\n\
    \    using graph     = G;\n    using cost_type = typename graph::cost_type;\n\n\
    \    usize g_size;\n    G g;\n    OfflineLCAQuery< graph > lca;\n    OfflineLAQuery<\
    \ graph > la;\n\n    using query_type = std::tuple< usize, usize, usize >;\n\n\
    \    std::vector< query_type > qs;\n\n    std::vector< query_type > converted_qs;\n\
    \    std::unordered_map< query_type, std::optional< usize >,\n               \
    \         TupleHash >\n        results;\n\n    void bound_check(usize v) const\
    \ {\n      assert(v < g_size);\n    }\n\n   public:\n    explicit OfflineJumpOnTreeQuery(graph\
    \ &g)\n        : g_size(g.size()),\n          g(g),\n          lca(g),\n     \
    \     la(g) {}\n\n    void add_query(usize start, usize end, usize distance) {\n\
    \      bound_check(start);\n      bound_check(end);\n      qs.emplace_back(start,\
    \ end, distance);\n    }\n\n    void build(usize root) {\n      bound_check(root);\n\
    \      for (const auto &[s, t, _]: qs) {\n        lca.add_query(s, t);\n     \
    \ }\n\n      lca.build(root);\n\n      sssp::InUnweightedGraph sssp_solver(g,\
    \ root);\n      std::vector< usize > depths = sssp_solver.get_distances();\n\n\
    \      converted_qs.reserve(qs.size());\n      results.reserve(qs.size());\n\n\
    \      for (usize i: rep(0, qs.size())) {\n        const auto &[s, t, d] = qs[i];\n\
    \        usize r               = lca.lca(s, t);\n        usize distance_sr   \
    \  = depths[s] - depths[r];\n        usize distance_rt     = depths[t] - depths[r];\n\
    \n        if (d <= distance_sr) {\n          converted_qs.emplace_back(i, s,\n\
    \                                    depths[r] + distance_sr - d);\n        }\
    \ else if (d <= distance_sr + distance_rt) {\n          converted_qs.emplace_back(i,\
    \ t,\n                                    depths[r] + d - distance_sr);\n    \
    \    } else {\n          results[qs[i]] = std::nullopt;\n        }\n      }\n\n\
    \      for (const auto &[_, v, k]: converted_qs) {\n        la.add_query(v, k);\n\
    \      }\n\n      la.build(root);\n\n      for (const auto &[i, v, k]: converted_qs)\
    \ {\n        results[qs[i]] = la.la(v, k);\n      }\n    }\n\n    std::optional<\
    \ usize > jump_on_tree(usize start, usize end,\n                             \
    \           usize distance) const {\n      bound_check(start);\n      bound_check(end);\n\
    \      query_type qi(start, end, distance);\n      assert(results.count(qi));\n\
    \      return (*results.find(qi)).second;\n    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n#include \"src/graph/single-source-shortest-path/in-unweighted-graph.hpp\"\
    \n#include \"src/graph/tree/offline-query/offline-query-level-ancestor.hpp\"\n\
    #include \"src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp\"\
    \n#include \"src/utility/tuple-hash.hpp\"\n\n#include <cassert>\n#include <optional>\n\
    #include <tuple>\n#include <unordered_map>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  template < class G >\n  class OfflineJumpOnTreeQuery {\n    using graph\
    \     = G;\n    using cost_type = typename graph::cost_type;\n\n    usize g_size;\n\
    \    G g;\n    OfflineLCAQuery< graph > lca;\n    OfflineLAQuery< graph > la;\n\
    \n    using query_type = std::tuple< usize, usize, usize >;\n\n    std::vector<\
    \ query_type > qs;\n\n    std::vector< query_type > converted_qs;\n    std::unordered_map<\
    \ query_type, std::optional< usize >,\n                        TupleHash >\n \
    \       results;\n\n    void bound_check(usize v) const {\n      assert(v < g_size);\n\
    \    }\n\n   public:\n    explicit OfflineJumpOnTreeQuery(graph &g)\n        :\
    \ g_size(g.size()),\n          g(g),\n          lca(g),\n          la(g) {}\n\n\
    \    void add_query(usize start, usize end, usize distance) {\n      bound_check(start);\n\
    \      bound_check(end);\n      qs.emplace_back(start, end, distance);\n    }\n\
    \n    void build(usize root) {\n      bound_check(root);\n      for (const auto\
    \ &[s, t, _]: qs) {\n        lca.add_query(s, t);\n      }\n\n      lca.build(root);\n\
    \n      sssp::InUnweightedGraph sssp_solver(g, root);\n      std::vector< usize\
    \ > depths = sssp_solver.get_distances();\n\n      converted_qs.reserve(qs.size());\n\
    \      results.reserve(qs.size());\n\n      for (usize i: rep(0, qs.size())) {\n\
    \        const auto &[s, t, d] = qs[i];\n        usize r               = lca.lca(s,\
    \ t);\n        usize distance_sr     = depths[s] - depths[r];\n        usize distance_rt\
    \     = depths[t] - depths[r];\n\n        if (d <= distance_sr) {\n          converted_qs.emplace_back(i,\
    \ s,\n                                    depths[r] + distance_sr - d);\n    \
    \    } else if (d <= distance_sr + distance_rt) {\n          converted_qs.emplace_back(i,\
    \ t,\n                                    depths[r] + d - distance_sr);\n    \
    \    } else {\n          results[qs[i]] = std::nullopt;\n        }\n      }\n\n\
    \      for (const auto &[_, v, k]: converted_qs) {\n        la.add_query(v, k);\n\
    \      }\n\n      la.build(root);\n\n      for (const auto &[i, v, k]: converted_qs)\
    \ {\n        results[qs[i]] = la.la(v, k);\n      }\n    }\n\n    std::optional<\
    \ usize > jump_on_tree(usize start, usize end,\n                             \
    \           usize distance) const {\n      bound_check(start);\n      bound_check(end);\n\
    \      query_type qi(start, end, distance);\n      assert(results.count(qi));\n\
    \      return (*results.find(qi)).second;\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/single-source-shortest-path/in-unweighted-graph.hpp
  - src/graph/tree/offline-query/offline-query-level-ancestor.hpp
  - src/utility/pair-hash.hpp
  - src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp
  - src/data-structure/disjoint-set-union.hpp
  - src/utility/tuple-hash.hpp
  isVerificationFile: false
  path: src/graph/tree/offline-query/offline-query-jump-on-tree.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/jump_on_tree.test.cpp
documentation_of: src/graph/tree/offline-query/offline-query-jump-on-tree.hpp
layout: document
title: "(offine) \u6728\u306E\u30D1\u30B9 $u-v$ \u4E0A\u306E $k$ \u756A\u76EE\u306E\
  \u9802\u70B9 (Offline Jump On Tree)"
---

以下では、静的で辺重みのない木について考える。特に断りがない場合、頂点 $u$ と $v$ の距離は $u$, $v$ 間を経由する最小の辺数とする。

木上のパス $u-v$ 上の頂点のうち $u$ からの距離が $k$ であるような頂点を求めるクエリをオフラインで処理する。このようなクエリを $jump(u, v, k)$ と表記する。

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
OfflineJumpOnTreeQuery(const G &g)
```

## add_query
```
void add_query(usize u, usize v, usize k)
```

$jump(u, v, k)$ を求めるクエリを追加する。

後述する `build` をした後、`jump_on_tree(u, v, k)` によって $jump(u, v, k)$ を得ることができる。

### 制約
- $0 \leq u, v < \|V\|$

### 計算量
- $O(1)$

## build
```
void build(usize root)
```

頂点 `root` を根とする根付き木上での $jump$ クエリを計算する。

`root` は解に影響しないため何が選ばれても問題はない。

### 制約
- $0 \leq root < \|V\|$

### 計算量
- $O((\|V\| + Q) \alpha (\|V\|))$
  - 追加されたクエリの数を $Q$ とする
  - アッカーマン関数の逆関数を $\alpha(n)$ とする

## jump_on_tree
```
std::optional< usize >
jump_on_tree(usize u, usize v, usize k)
```

$jump(u, v, k)$ を `std::optional` でラップして返す。

パス $u-v$ 上に $u$ からの距離が $k$ であるような頂点が存在しない場合は `std::nullopt` が返る。

### 使用例
$jump(u, v, k)$ が存在するときは $jump(u, v, k)$ となる頂点の番号を、そのような頂点が存在しない場合は `-1` を出力するサンプル

```
OfflineJumpOnTreeQuery jump_query(g);

...

auto jump = jump_query.jump_on_tree(u, v, k);

if (jump) {
  std::cout << jump.value() << std::endl;
} else {
  std::cout << -1 << std::endl;
}
```

### 制約
- `add_query(u, v)` が呼ばれており、かつその後に `build(root)` が呼ばれていること。

### 計算量
- $O(1)$
