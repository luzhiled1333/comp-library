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
    path: src/graph/offline-query-jump-on-functional-graph.hpp
    title: "(offine) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$\
      \ \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Offline Jump On Functional\
      \ Graph)"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-level-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3 Level Ancestor (Offline Level Ancestor)"
  - icon: ':heavy_check_mark:'
    path: src/utility/pair-hash.hpp
    title: "std::pair \u306E Hash"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc258/tasks/abc258_e
    links:
    - https://atcoder.jp/contests/abc258/tasks/abc258_e
  bundledCode: "#line 1 \"test/atcoder/abc258_e/offline-algorithm.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc258/tasks/abc258_e\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ 2 \"src/graph/offline-query-jump-on-functional-graph.hpp\"\n\n#line 2 \"src/graph/offline-query-level-ancestor.hpp\"\
    \n\n#line 2 \"src/utility/pair-hash.hpp\"\n\n#line 4 \"src/utility/pair-hash.hpp\"\
    \n\n#include <functional>\n#include <utility>\n\nnamespace luz {\n\n  class PairHash\
    \ {\n    template < typename T >\n    usize hash_combine(usize hr, const T &x)\
    \ const {\n      usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr <<\
    \ 11) + (hr >> 13));\n    }\n\n   public:\n    template < typename F, typename\
    \ S >\n    usize operator()(const std::pair< F, S > &p) const {\n      return\
    \ hash_combine(hash_combine(0, p.first), p.second);\n    }\n  };\n\n} // namespace\
    \ luz\n#line 7 \"src/graph/offline-query-level-ancestor.hpp\"\n\n#line 9 \"src/graph/offline-query-level-ancestor.hpp\"\
    \n#include <optional>\n#include <unordered_map>\n#line 13 \"src/graph/offline-query-level-ancestor.hpp\"\
    \n\nnamespace luz {\n\n  template < typename cost_type >\n  class OfflineLAQuery\
    \ {\n    usize g_size_;\n    Graph< cost_type > g_;\n\n    usize query_count_;\n\
    \    std::vector< std::vector< usize > > qs_;\n\n    std::vector< bool > visited_;\n\
    \    std::vector< usize > path_;\n\n    using query_type = std::pair< usize, usize\
    \ >;\n    std::unordered_map< query_type, std::optional< usize >, PairHash >\n\
    \        results_;\n\n    void bound_check(usize v) const {\n      assert(v <\
    \ g_size_);\n    }\n\n    void dfs(usize v) {\n      visited_[v] = true;\n   \
    \   path_.emplace_back(v);\n\n      for (const auto &level: qs_[v]) {\n      \
    \  if (level < path_.size()) {\n          results_[query_type(v, level)] = path_[level];\n\
    \        }\n      }\n\n      for (const auto &e: g_[v]) {\n        if (visited_[e.to])\
    \ continue;\n        dfs(e.to);\n      }\n\n      path_.pop_back();\n    }\n\n\
    \   public:\n    explicit OfflineLAQuery() = default;\n\n    explicit OfflineLAQuery(Graph<\
    \ cost_type > &g)\n        : g_size_(g.size()),\n          g_(g),\n          query_count_(0),\n\
    \          qs_(g_size_),\n          visited_(g_size_, false) {}\n\n    void add_query(usize\
    \ v, usize level) {\n      bound_check(v);\n      qs_[v].emplace_back(level);\n\
    \      query_count_++;\n    }\n\n    void build(usize root) {\n      bound_check(root);\n\
    \      results_.reserve(query_count_);\n      path_.reserve(g_size_);\n      dfs(root);\n\
    \    }\n\n    std::optional< usize > la(usize v, usize level) const {\n      bound_check(v);\n\
    \      query_type qi(v, level);\n      assert(results_.count(qi));\n      return\
    \ (*results_.find(qi)).second;\n    }\n  };\n\n} // namespace luz\n#line 8 \"\
    src/graph/offline-query-jump-on-functional-graph.hpp\"\n\n#line 12 \"src/graph/offline-query-jump-on-functional-graph.hpp\"\
    \n\nnamespace luz {\n  template < typename cost_type >\n  class OfflineJumpOnFunctionalGraphQuery\
    \ {\n    usize g_size;\n    Graph< cost_type > g;\n\n    Graph< usize > tree;\n\
    \    usize tree_root;\n    std::vector< usize > tree_depth, subtree_roots;\n\n\
    \    std::vector< usize > loop_id, loop_size, loop_pos;\n    std::vector< std::vector<\
    \ usize > > loops;\n\n    using query_type = std::pair< usize, u64 >;\n    std::vector<\
    \ query_type > qs;\n    std::unordered_map< query_type, usize, PairHash > result;\n\
    \n    void dfs_on_subtree(usize v, usize p) {\n      for (auto &e: tree[v]) {\n\
    \        usize u = e.to;\n        if (u == p) continue;\n        subtree_roots[u]\
    \ = subtree_roots[v];\n        tree_depth[u]    = tree_depth[v] + 1;\n       \
    \ dfs_on_subtree(u, v);\n      }\n    }\n\n    std::vector< usize > get_indegrees()\
    \ const {\n      std::vector< usize > indegrees(g_size);\n      for (usize v:\
    \ rep(0, g_size)) {\n        indegrees[g[v][0].to]++;\n      }\n      return indegrees;\n\
    \    }\n\n    void construct_tree(std::vector< usize > &indegrees) {\n      std::vector<\
    \ usize > leaves;\n      leaves.reserve(g_size);\n\n      for (usize v: rep(0,\
    \ g_size)) {\n        if (indegrees[v] > 0) {\n          continue;\n        }\n\
    \        leaves.emplace_back(v);\n      }\n\n      while (not leaves.empty())\
    \ {\n        usize child = leaves.back();\n        leaves.pop_back();\n\n    \
    \    usize parent = g[child][0].to;\n        indegrees[parent]--;\n\n        tree.add_undirected_edge(parent,\
    \ child);\n\n        if (indegrees[parent] == 0) {\n          leaves.emplace_back(parent);\n\
    \        }\n      }\n\n      for (usize v: rep(0, g_size)) {\n        if (indegrees[v]\
    \ == 0) {\n          continue;\n        }\n        subtree_roots[v] = v;\n   \
    \     tree.add_undirected_edge(tree_root, v);\n        dfs_on_subtree(v, tree_root);\n\
    \      }\n    }\n\n    void construct_loops(std::vector< usize > &indegrees) {\n\
    \      for (usize v: rep(0, g_size)) {\n        if (indegrees[v] == 0) {\n   \
    \       continue;\n        }\n\n        usize cur = v;\n        std::vector< usize\
    \ > loop;\n        do {\n          loop_id[cur]  = loops.size();\n          loop_pos[cur]\
    \ = loop.size();\n          loop.emplace_back(cur);\n          indegrees[cur]\
    \ = 0;\n          cur            = g[cur][0].to;\n        } while (cur != v);\n\
    \n        do {\n          loop_size[cur] = loop.size();\n          cur       \
    \     = g[cur][0].to;\n        } while (cur != v);\n\n        loops.emplace_back(std::move(loop));\n\
    \      }\n    }\n\n   public:\n    explicit OfflineJumpOnFunctionalGraphQuery(\n\
    \        const Graph< cost_type > &g_)\n        : g_size(g_.size()),\n       \
    \   g(g_),\n          tree(g_size + 1),\n          tree_root(g_size),\n      \
    \    tree_depth(g_size),\n          subtree_roots(g_size),\n          loop_id(g_size),\n\
    \          loop_size(g_size),\n          loop_pos(g_size) {\n      for (usize\
    \ v: rep(0, g_size)) {\n        assert(g[v].size() == 1);\n      }\n\n      std::vector<\
    \ usize > indegrees = get_indegrees();\n      construct_tree(indegrees);\n   \
    \   construct_loops(indegrees);\n    }\n\n    void add_query(usize v, u64 k) {\n\
    \      qs.emplace_back(v, k);\n    }\n\n    void build() {\n      OfflineLAQuery\
    \ la_solver(tree);\n      result.reserve(qs.size());\n      for (auto [v, k]:\
    \ qs) {\n        if (k < tree_depth[v]) {\n          la_solver.add_query(v, tree_depth[v]\
    \ - k + 1);\n        } else {\n          query_type qi(v, k);\n          k -=\
    \ tree_depth[v];\n          usize root       = subtree_roots[v];\n          const\
    \ auto &loop = loops[loop_id[root]];\n          k += loop_pos[root];\n       \
    \   k %= loop_size[root];\n          result[qi] = loop[k];\n        }\n      }\n\
    \      la_solver.build(g_size);\n\n      for (auto [v, k]: qs) {\n        if (tree_depth[v]\
    \ <= k) {\n          continue;\n        }\n        query_type qi(v, k);\n    \
    \    result[qi] = la_solver.la(v, tree_depth[v] - k + 1).value();\n      }\n \
    \   }\n\n    usize jump(usize v, u64 k) const {\n      query_type qi(v, k);\n\
    \      assert(result.count(qi));\n      return result.find(qi)->second;\n    }\n\
    \  };\n} // namespace luz\n#line 8 \"test/atcoder/abc258_e/offline-algorithm.test.cpp\"\
    \n\n#line 10 \"test/atcoder/abc258_e/offline-algorithm.test.cpp\"\n#include <numeric>\n\
    #line 12 \"test/atcoder/abc258_e/offline-algorithm.test.cpp\"\n\nnamespace luz\
    \ {\n\n  void main_() {\n    usize n, q, x;\n    std::cin >> n >> q >> x;\n\n\
    \    std::vector< i64 > ws(n);\n    std::cin >> ws;\n\n    i64 sum_w = std::accumulate(ws.begin(),\
    \ ws.end(), i64());\n    i64 xp    = x % sum_w;\n    std::vector< i64 > ans(n,\
    \ x / sum_w * n);\n\n    ws.resize(2 * n + 1);\n    for (usize i: rep(0, n)) {\n\
    \      ws[n + i] = ws[i];\n    }\n    for (usize i: rrep(0, 2 * n)) {\n      ws[i]\
    \ += ws[i + 1];\n    }\n\n    Graph< i32 > fg(n);\n    usize r = 0;\n    for (usize\
    \ l: rep(0, n)) {\n      while (ws[l] - ws[r] < xp) {\n        r++;\n      }\n\
    \n      fg.add_directed_edge(l, r % n);\n      ans[l] += r - l;\n    }\n\n   \
    \ std::vector< u64 > qs(q);\n    OfflineJumpOnFunctionalGraphQuery\n        offline_jump_on_functional_graph_solver(fg);\n\
    \    for (usize i: rep(0, q)) {\n      std::cin >> qs[i];\n      --qs[i];\n  \
    \    offline_jump_on_functional_graph_solver.add_query(0, qs[i]);\n    }\n   \
    \ offline_jump_on_functional_graph_solver.build();\n    for (usize i: rep(0, q))\
    \ {\n      std::cout << ans[offline_jump_on_functional_graph_solver.jump(\n  \
    \                     0, qs[i])]\n                << std::endl;\n    }\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc258/tasks/abc258_e\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/cpp-template/header/vector-ios.hpp\"\n#include \"src/graph/graph-template.hpp\"\
    \n#include \"src/graph/offline-query-jump-on-functional-graph.hpp\"\n\n#include\
    \ <iostream>\n#include <numeric>\n#include <vector>\n\nnamespace luz {\n\n  void\
    \ main_() {\n    usize n, q, x;\n    std::cin >> n >> q >> x;\n\n    std::vector<\
    \ i64 > ws(n);\n    std::cin >> ws;\n\n    i64 sum_w = std::accumulate(ws.begin(),\
    \ ws.end(), i64());\n    i64 xp    = x % sum_w;\n    std::vector< i64 > ans(n,\
    \ x / sum_w * n);\n\n    ws.resize(2 * n + 1);\n    for (usize i: rep(0, n)) {\n\
    \      ws[n + i] = ws[i];\n    }\n    for (usize i: rrep(0, 2 * n)) {\n      ws[i]\
    \ += ws[i + 1];\n    }\n\n    Graph< i32 > fg(n);\n    usize r = 0;\n    for (usize\
    \ l: rep(0, n)) {\n      while (ws[l] - ws[r] < xp) {\n        r++;\n      }\n\
    \n      fg.add_directed_edge(l, r % n);\n      ans[l] += r - l;\n    }\n\n   \
    \ std::vector< u64 > qs(q);\n    OfflineJumpOnFunctionalGraphQuery\n        offline_jump_on_functional_graph_solver(fg);\n\
    \    for (usize i: rep(0, q)) {\n      std::cin >> qs[i];\n      --qs[i];\n  \
    \    offline_jump_on_functional_graph_solver.add_query(0, qs[i]);\n    }\n   \
    \ offline_jump_on_functional_graph_solver.build();\n    for (usize i: rep(0, q))\
    \ {\n      std::cout << ans[offline_jump_on_functional_graph_solver.jump(\n  \
    \                     0, qs[i])]\n                << std::endl;\n    }\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/graph/graph-template.hpp
  - src/graph/offline-query-jump-on-functional-graph.hpp
  - src/graph/offline-query-level-ancestor.hpp
  - src/utility/pair-hash.hpp
  isVerificationFile: true
  path: test/atcoder/abc258_e/offline-algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-02-10 00:06:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc258_e/offline-algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc258_e/offline-algorithm.test.cpp
- /verify/test/atcoder/abc258_e/offline-algorithm.test.cpp.html
title: test/atcoder/abc258_e/offline-algorithm.test.cpp
---
