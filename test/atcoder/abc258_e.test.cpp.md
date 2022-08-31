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
    path: src/graph/functional-graph-utility.hpp
    title: src/graph/functional-graph-utility.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc258/tasks/abc259_e
    links:
    - https://atcoder.jp/contests/abc258/tasks/abc259_e
  bundledCode: "#line 1 \"test/atcoder/abc258_e.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc258/tasks/abc259_e\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ 3 \"src/graph/functional-graph-utility.hpp\"\n\n#line 5 \"src/graph/functional-graph-utility.hpp\"\
    \n\nnamespace luz {\n\n  template < typename cost_type >\n  class FunctionalGraph:\
    \ Graph< cost_type > {\n    using Graph< cost_type >::Graph;\n    using Graph<\
    \ cost_type >::g;\n    using Graph< cost_type >::size;\n    using Graph< cost_type\
    \ >::add_directed_edge;\n\n    usize LOG;\n    std::vector< std::vector< usize\
    \ > > doubling_table;\n\n   public:\n    void add_edge(usize from, usize to, cost_type\
    \ cost = 1) {\n      assert(from < size());\n      assert(to < size());\n    \
    \  add_directed_edge(from, to, cost);\n      assert(g[from].size() == 1);\n  \
    \  }\n\n    void initialize_jump(const u64 MAX_K) {\n      LOG = 0;\n      while\
    \ (usize(1) << (LOG + 1) <= MAX_K) {\n        LOG++;\n      }\n\n      doubling_table.assign(LOG,\
    \ std::vector< usize >(size()));\n      for (usize v: rep(0, size())) {\n    \
    \    doubling_table[0][v] = (g[v].size() == 1 ? g[v][0].to : -1);\n      }\n \
    \     for (usize k: rep(1, LOG)) {\n        for (usize v: rep(0, size())) {\n\
    \          usize pv = doubling_table[k - 1][v];\n          if (pv == (usize)-1)\
    \ {\n            doubling_table[k][v] = pv;\n          } else {\n            doubling_table[k][v]\
    \ = doubling_table[k - 1][pv];\n          }\n        }\n      }\n    }\n\n   \
    \ usize jump(usize v, u64 k) {\n      if (k == 0) return v;\n      for (usize\
    \ i: rep(0, LOG)) {\n        if ((k & 1) == 1) {\n          v = doubling_table[i][v];\n\
    \        }\n        k >>= 1;\n      }\n\n      return v;\n    }\n  };\n\n} //\
    \ namespace luz\n#line 7 \"test/atcoder/abc258_e.test.cpp\"\n\n#line 9 \"test/atcoder/abc258_e.test.cpp\"\
    \n#include <numeric>\n#line 11 \"test/atcoder/abc258_e.test.cpp\"\n\nnamespace\
    \ luz {\n\n  void main_() {\n    usize n, q, x;\n    std::cin >> n >> q >> x;\n\
    \n    std::vector< i64 > ws(n);\n    std::cin >> ws;\n\n    i64 sum_w = std::accumulate(ws.begin(),\
    \ ws.end(), i64());\n    i64 xp    = x % sum_w;\n    std::vector< i64 > ans(n,\
    \ x / sum_w * n);\n\n    ws.resize(2 * n + 1);\n    for (usize i: rep(0, n)) {\n\
    \      ws[n + i] = ws[i];\n    }\n    for (usize i: rrep(0, 2 * n)) {\n      ws[i]\
    \ += ws[i + 1];\n    }\n\n    FunctionalGraph< i32 > fg(n);\n    usize r = 0;\n\
    \    for (usize l: rep(0, n)) {\n      while (ws[l] - ws[r] < xp) {\n        r++;\n\
    \      }\n\n      fg.add_edge(l, r % n);\n      ans[l] += r - l;\n    }\n\n  \
    \  fg.initialize_jump(1e13);\n\n    for ([[maybe_unused]] usize _: rep(0, q))\
    \ {\n      u64 k;\n      std::cin >> k;\n      usize v = fg.jump(0, k - 1);\n\
    \      std::cout << ans[v] << std::endl;\n    }\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc258/tasks/abc259_e\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/cpp-template/header/vector-ios.hpp\"\n#include \"src/graph/functional-graph-utility.hpp\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  void main_() {\n    usize n, q, x;\n    std::cin >> n >> q >> x;\n\n\
    \    std::vector< i64 > ws(n);\n    std::cin >> ws;\n\n    i64 sum_w = std::accumulate(ws.begin(),\
    \ ws.end(), i64());\n    i64 xp    = x % sum_w;\n    std::vector< i64 > ans(n,\
    \ x / sum_w * n);\n\n    ws.resize(2 * n + 1);\n    for (usize i: rep(0, n)) {\n\
    \      ws[n + i] = ws[i];\n    }\n    for (usize i: rrep(0, 2 * n)) {\n      ws[i]\
    \ += ws[i + 1];\n    }\n\n    FunctionalGraph< i32 > fg(n);\n    usize r = 0;\n\
    \    for (usize l: rep(0, n)) {\n      while (ws[l] - ws[r] < xp) {\n        r++;\n\
    \      }\n\n      fg.add_edge(l, r % n);\n      ans[l] += r - l;\n    }\n\n  \
    \  fg.initialize_jump(1e13);\n\n    for ([[maybe_unused]] usize _: rep(0, q))\
    \ {\n      u64 k;\n      std::cin >> k;\n      usize v = fg.jump(0, k - 1);\n\
    \      std::cout << ans[v] << std::endl;\n    }\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/graph/functional-graph-utility.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: true
  path: test/atcoder/abc258_e.test.cpp
  requiredBy: []
  timestamp: '2022-08-31 11:28:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc258_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc258_e.test.cpp
- /verify/test/atcoder/abc258_e.test.cpp.html
title: test/atcoder/abc258_e.test.cpp
---
