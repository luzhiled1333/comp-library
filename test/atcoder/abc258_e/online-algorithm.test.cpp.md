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
    path: src/graph/online-query-jump-on-functional-graph.hpp
    title: "(online) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$\
      \ \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Online Jump On Functional\
      \ Graph)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/bit-width.hpp
    title: "\u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
      \u6700\u5C0F\u306Ebit\u5E45 (bit_width)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc258/tasks/abc258_e
    links:
    - https://atcoder.jp/contests/abc258/tasks/abc258_e
  bundledCode: "#line 1 \"test/atcoder/abc258_e/online-algorithm.test.cpp\"\n// verification-helper:\
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
    \ 2 \"src/graph/online-query-jump-on-functional-graph.hpp\"\n\n#line 2 \"src/utility/bit/bit-width.hpp\"\
    \n\n#line 2 \"src/utility/bit/popcount.hpp\"\n\n#line 4 \"src/utility/bit/popcount.hpp\"\
    \n\n#line 6 \"src/utility/bit/popcount.hpp\"\n\nnamespace luz {\n\n  usize popcount(u64\
    \ x) {\n    assert(__cplusplus <= 201703L);\n\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n\
    #endif\n\n    x -= (x >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333)\
    \ + ((x >> 2) & 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n\
    #line 4 \"src/utility/bit/bit-width.hpp\"\n\n#line 6 \"src/utility/bit/bit-width.hpp\"\
    \n\nnamespace luz {\n\n  usize bit_width(u64 x) {\n    assert(__cplusplus <= 201703L);\n\
    \n    if (x == 0) {\n      return 0;\n    }\n\n#ifdef __GNUC__\n    return 64\
    \ - __builtin_clzll(x);\n#endif\n\n    x |= x >> 1;\n    x |= x >> 2;\n    x |=\
    \ x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n    return\
    \ popcount(x);\n  }\n\n} // namespace luz\n#line 7 \"src/graph/online-query-jump-on-functional-graph.hpp\"\
    \n\n#line 9 \"src/graph/online-query-jump-on-functional-graph.hpp\"\n#include\
    \ <utility>\n#line 11 \"src/graph/online-query-jump-on-functional-graph.hpp\"\n\
    \nnamespace luz {\n\n  template < typename cost_type >\n  class OnlineJumpOnFunctionalGraphQuery\
    \ {\n    usize g_size;\n    Graph< cost_type > g;\n\n    usize LOG;\n    std::vector<\
    \ std::vector< usize > > doubling_table;\n\n    std::vector< usize > loop_id,\
    \ loop_size, loop_pos;\n    std::vector< std::vector< usize > > loops;\n\n   \
    \ void check_functional_graph() const {\n      for (usize v: rep(0, g_size)) {\n\
    \        assert(g[v].size() == 1);\n      }\n    }\n\n    void build_doubling_table()\
    \ {\n      for (usize k: rep(0, LOG)) {\n        for (usize v: rep(0, g_size))\
    \ {\n          doubling_table[k][v] =\n              (k ? doubling_table[k - 1][doubling_table[k\
    \ - 1][v]]\n                 : g[v][0].to);\n        }\n      }\n    }\n\n   \
    \ std::vector< usize > get_indegrees() const {\n      std::vector< usize > indegrees(g_size);\n\
    \      for (usize v: rep(0, g_size)) {\n        indegrees[g[v][0].to]++;\n   \
    \   }\n      return indegrees;\n    }\n\n    void delete_leaves(std::vector< usize\
    \ > &indegrees) {\n      std::vector< usize > leaves;\n      leaves.reserve(g_size);\n\
    \n      for (usize v: rep(0, g_size)) {\n        if (indegrees[v] > 0) {\n   \
    \       continue;\n        }\n        leaves.emplace_back(v);\n      }\n\n   \
    \   while (not leaves.empty()) {\n        usize v = leaves.back();\n        leaves.pop_back();\n\
    \n        usize u = g[v][0].to;\n        indegrees[u]--;\n\n        if (indegrees[u]\
    \ == 0) {\n          leaves.emplace_back(u);\n        }\n      }\n    }\n\n  \
    \  void construct_loops() {\n      std::vector< usize > indegrees = get_indegrees();\n\
    \      delete_leaves(indegrees);\n\n      for (usize v: rep(0, g_size)) {\n  \
    \      if (indegrees[v] == 0) {\n          continue;\n        }\n\n        usize\
    \ cur = v;\n        std::vector< usize > loop;\n\n        do {\n          loop_id[cur]\
    \  = loops.size();\n          loop_pos[cur] = loop.size();\n          loop.emplace_back(cur);\n\
    \          indegrees[cur] = 0;\n          cur            = g[cur][0].to;\n   \
    \     } while (cur != v);\n\n        do {\n          loop_size[cur] = loop.size();\n\
    \          cur            = g[cur][0].to;\n        } while (cur != v);\n\n   \
    \     loops.emplace_back(std::move(loop));\n      }\n    }\n\n    usize jump_small(usize\
    \ v, usize k) const {\n      assert(k < g_size);\n\n      for (usize i: rep(0,\
    \ LOG)) {\n        if ((k & 1) == 1) {\n          v = doubling_table[i][v];\n\
    \        }\n        k >>= 1;\n      }\n      return v;\n    }\n\n   public:\n\
    \    OnlineJumpOnFunctionalGraphQuery(const Graph< cost_type > &g_)\n        :\
    \ g_size(g_.size()),\n          g(g_),\n          LOG(bit_width(g_size - 1)),\n\
    \          doubling_table(LOG, std::vector< usize >(g_size)),\n          loop_id(g_size,\
    \ -1),\n          loop_size(g_size),\n          loop_pos(g_size, -1) {\n     \
    \ check_functional_graph();\n      assert(g_size != 0);\n\n      build_doubling_table();\n\
    \      construct_loops();\n    }\n\n    usize jump(usize v, u64 k) const {\n \
    \     assert(v < g_size);\n\n      if (k == 0) {\n        return v;\n      }\n\
    \n      if (k < g_size) {\n        return jump_small(v, k);\n      }\n\n     \
    \ v = jump_small(v, g_size - 1);\n      k -= (g_size - 1);\n\n      const auto\
    \ &loop = loops[loop_id[v]];\n      k += loop_pos[v];\n      k %= loop_size[v];\n\
    \      return loop[k];\n    }\n  };\n\n} // namespace luz\n#line 8 \"test/atcoder/abc258_e/online-algorithm.test.cpp\"\
    \n\n#line 10 \"test/atcoder/abc258_e/online-algorithm.test.cpp\"\n#include <numeric>\n\
    #line 12 \"test/atcoder/abc258_e/online-algorithm.test.cpp\"\n\nnamespace luz\
    \ {\n\n  void main_() {\n    usize n, q, x;\n    std::cin >> n >> q >> x;\n\n\
    \    std::vector< i64 > ws(n);\n    std::cin >> ws;\n\n    i64 sum_w = std::accumulate(ws.begin(),\
    \ ws.end(), i64());\n    i64 xp    = x % sum_w;\n    std::vector< i64 > ans(n,\
    \ x / sum_w * n);\n\n    ws.resize(2 * n + 1);\n    for (usize i: rep(0, n)) {\n\
    \      ws[n + i] = ws[i];\n    }\n    for (usize i: rrep(0, 2 * n)) {\n      ws[i]\
    \ += ws[i + 1];\n    }\n\n    Graph< i32 > fg(n);\n    usize r = 0;\n    for (usize\
    \ l: rep(0, n)) {\n      while (ws[l] - ws[r] < xp) {\n        r++;\n      }\n\
    \n      fg.add_directed_edge(l, r % n);\n      ans[l] += r - l;\n    }\n\n   \
    \ OnlineJumpOnFunctionalGraphQuery online_jump_solver(fg);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, q)) {\n      u64 k;\n      std::cin >> k;\n      usize v = online_jump_solver.jump(0,\
    \ k - 1);\n      std::cout << ans[v] << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc258/tasks/abc258_e\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/cpp-template/header/vector-ios.hpp\"\n#include \"src/graph/graph-template.hpp\"\
    \n#include \"src/graph/online-query-jump-on-functional-graph.hpp\"\n\n#include\
    \ <iostream>\n#include <numeric>\n#include <vector>\n\nnamespace luz {\n\n  void\
    \ main_() {\n    usize n, q, x;\n    std::cin >> n >> q >> x;\n\n    std::vector<\
    \ i64 > ws(n);\n    std::cin >> ws;\n\n    i64 sum_w = std::accumulate(ws.begin(),\
    \ ws.end(), i64());\n    i64 xp    = x % sum_w;\n    std::vector< i64 > ans(n,\
    \ x / sum_w * n);\n\n    ws.resize(2 * n + 1);\n    for (usize i: rep(0, n)) {\n\
    \      ws[n + i] = ws[i];\n    }\n    for (usize i: rrep(0, 2 * n)) {\n      ws[i]\
    \ += ws[i + 1];\n    }\n\n    Graph< i32 > fg(n);\n    usize r = 0;\n    for (usize\
    \ l: rep(0, n)) {\n      while (ws[l] - ws[r] < xp) {\n        r++;\n      }\n\
    \n      fg.add_directed_edge(l, r % n);\n      ans[l] += r - l;\n    }\n\n   \
    \ OnlineJumpOnFunctionalGraphQuery online_jump_solver(fg);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, q)) {\n      u64 k;\n      std::cin >> k;\n      usize v = online_jump_solver.jump(0,\
    \ k - 1);\n      std::cout << ans[v] << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/graph/graph-template.hpp
  - src/graph/online-query-jump-on-functional-graph.hpp
  - src/utility/bit/bit-width.hpp
  - src/utility/bit/popcount.hpp
  isVerificationFile: true
  path: test/atcoder/abc258_e/online-algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 04:43:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc258_e/online-algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc258_e/online-algorithm.test.cpp
- /verify/test/atcoder/abc258_e/online-algorithm.test.cpp.html
title: test/atcoder/abc258_e/online-algorithm.test.cpp
---