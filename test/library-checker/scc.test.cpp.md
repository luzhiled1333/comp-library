---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/fast-ios.hpp
    title: Fast I/O
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
    path: src/graph/decomposition/strongly-connected-components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(Decomposition of Strongly Connected\
      \ Components, SCC)"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library-checker/scc.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/scc\n\n#line 2 \"src/cpp-template/header/fast-ios.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void set_fast_ios() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 6 \"src/cpp-template/header/vector-ios.hpp\"\
    \n#include <vector>\n\nnamespace luz {\n\n  template < typename T >\n  std::ostream\
    \ &operator<<(std::ostream &os,\n                           const std::vector<\
    \ T > vs) {\n    for (usize i: rep(0, vs.size())) {\n      os << vs[i] << (i +\
    \ 1 != vs.size() ? \" \" : \"\");\n    }\n    return os;\n  }\n\n  template <\
    \ typename T >\n  std::istream &operator>>(std::istream &is, std::vector< T >\
    \ &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n    return is;\n  }\n\n\
    } // namespace luz\n#line 2 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\n\nnamespace luz {\n\
    \n  template < typename T1, typename T2 >\n  inline bool chmax(T1 &a, T2 b) {\n\
    \    return a < b and (a = b, true);\n  }\n\n  template < typename T1, typename\
    \ T2 >\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\n\n#line\
    \ 4 \"src/graph/graph-template.hpp\"\n\n#include <cassert>\n#line 7 \"src/graph/graph-template.hpp\"\
    \n\nnamespace luz {\n\n  template < typename cost_type >\n  class Edge {\n   public:\n\
    \    usize from, to;\n    cost_type cost;\n    usize id;\n    Edge() = default;\n\
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
    \ 7 \"src/graph/decomposition/strongly-connected-components.hpp\"\n\n#line 9 \"\
    src/graph/decomposition/strongly-connected-components.hpp\"\n\nnamespace luz::decomposition\
    \ {\n\n  template < typename cost_type >\n  class StronglyConnectedComponents\
    \ {\n    Graph< cost_type > g;\n    usize g_size;\n    std::vector< usize > low,\
    \ ord, visited, group_id;\n    usize ord_cnt, group_cnt;\n\n    void dfs(usize\
    \ v) {\n      low[v] = ord[v] = ord_cnt++;\n      visited.emplace_back(v);\n \
    \     for (auto& e: g[v]) {\n        if (ord[e.to] == g_size) {\n          dfs(e.to);\n\
    \          chmin(low[v], low[e.to]);\n        } else {\n          chmin(low[v],\
    \ ord[e.to]);\n        }\n      }\n      if (low[v] == ord[v]) {\n        while\
    \ (true) {\n          usize u = visited.back();\n          visited.pop_back();\n\
    \          ord[u]      = g_size + 1;\n          group_id[u] = group_cnt;\n   \
    \       if (u == v) break;\n        }\n        group_cnt++;\n      }\n    }\n\n\
    \   public:\n    explicit StronglyConnectedComponents(const Graph< cost_type >&\
    \ g_)\n        : g(g_),\n          g_size(g.size()),\n          low(g_size),\n\
    \          ord(g_size, g_size),\n          group_id(g_size),\n          ord_cnt(0),\n\
    \          group_cnt(0) {\n      visited.reserve(g_size);\n      for (usize v:\
    \ rep(0, g_size)) {\n        if (ord[v] == g_size) {\n          dfs(v);\n    \
    \    }\n      }\n      for (auto& id: group_id) {\n        id = group_cnt - id\
    \ - 1;\n      }\n    }\n\n    std::vector< std::vector< usize > > groups() const\
    \ {\n      std::vector< usize > counts(group_cnt);\n      for (usize i: rep(0,\
    \ g_size)) {\n        counts[group_id[i]]++;\n      }\n      std::vector< std::vector<\
    \ usize > > groups(group_cnt);\n      for (usize i: rep(0, group_cnt)) {\n   \
    \     groups[i].reserve(counts[i]);\n      }\n      for (usize i: rep(0, g_size))\
    \ {\n        groups[group_id[i]].emplace_back(i);\n      }\n      return groups;\n\
    \    }\n\n    std::vector< usize > group_ids() const {\n      return group_id;\n\
    \    }\n  };\n\n} // namespace luz::decomposition\n#line 9 \"test/library-checker/scc.test.cpp\"\
    \n\n#line 12 \"test/library-checker/scc.test.cpp\"\n\nnamespace luz {\n\n  void\
    \ main_() {\n    usize n, m;\n    std::cin >> n >> m;\n    Graph< i32 > g(n);\n\
    \    for ([[maybe_unused]] usize _: rep(0, m)) {\n      usize u, v;\n      std::cin\
    \ >> u >> v;\n      g.add_directed_edge(u, v);\n    }\n    decomposition::StronglyConnectedComponents<\
    \ i32 > scc(g);\n    auto groups = scc.groups();\n    std::cout << groups.size()\
    \ << std::endl;\n    for (auto& group: groups) {\n      std::cout << group.size()\
    \ << \" \" << group << \" \" << std::endl;\n    }\n  }\n\n} // namespace luz\n\
    \nint main() {\n  luz::set_fast_ios();\n\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc\n\n#include\
    \ \"src/cpp-template/header/fast-ios.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/cpp-template/header/vector-ios.hpp\"\
    \n#include \"src/graph/decomposition/strongly-connected-components.hpp\"\n#include\
    \ \"src/graph/graph-template.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nnamespace luz {\n\n  void main_() {\n    usize n, m;\n    std::cin >> n >> m;\n\
    \    Graph< i32 > g(n);\n    for ([[maybe_unused]] usize _: rep(0, m)) {\n   \
    \   usize u, v;\n      std::cin >> u >> v;\n      g.add_directed_edge(u, v);\n\
    \    }\n    decomposition::StronglyConnectedComponents< i32 > scc(g);\n    auto\
    \ groups = scc.groups();\n    std::cout << groups.size() << std::endl;\n    for\
    \ (auto& group: groups) {\n      std::cout << group.size() << \" \" << group <<\
    \ \" \" << std::endl;\n    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::set_fast_ios();\n\
    \n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/fast-ios.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/graph/decomposition/strongly-connected-components.hpp
  - src/cpp-template/header/change-minmax.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: true
  path: test/library-checker/scc.test.cpp
  requiredBy: []
  timestamp: '2023-05-19 12:00:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/scc.test.cpp
- /verify/test/library-checker/scc.test.cpp.html
title: test/library-checker/scc.test.cpp
---
