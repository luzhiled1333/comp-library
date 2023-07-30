---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-min.hpp
    title: chmin
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/fast-ios.hpp
    title: Fast I/O
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
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  - icon: ':heavy_check_mark:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/class/static-graph.hpp
    title: "\u9759\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/decomposition/strongly-connected-components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(Decomposition of Strongly Connected\
      \ Components, SCC)"
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
    \    std::cin.tie(nullptr);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
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
    \ 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#line 6 \"src/cpp-template/header/vector-ios.hpp\"\n#include <vector>\n\n\
    namespace luz {\n\n  template < typename T >\n  std::ostream &operator<<(std::ostream\
    \ &os,\n                           const std::vector< T > vs) {\n    for (usize\
    \ i: rep(0, vs.size())) {\n      os << vs[i] << (i + 1 != vs.size() ? \" \" :\
    \ \"\");\n    }\n    return os;\n  }\n\n  template < typename T >\n  std::istream\
    \ &operator>>(std::istream &is, std::vector< T > &vs) {\n    for (T &v: vs) {\n\
    \      is >> v;\n    }\n    return is;\n  }\n\n} // namespace luz\n#line 2 \"\
    src/graph/class/edge/edge.hpp\"\n\n#line 4 \"src/graph/class/edge/edge.hpp\"\n\
    \n#line 6 \"src/graph/class/edge/edge.hpp\"\n\nnamespace luz {\n\n  template <\
    \ typename T >\n  class Edge {\n   public:\n    using cost_type = T;\n\n    usize\
    \ from, to;\n    T cost;\n    usize id;\n    Edge() = default;\n    Edge(usize\
    \ from_, usize to_, T cost_, usize id_)\n        : from(from_),\n          to(to_),\n\
    \          cost(cost_),\n          id(id_) {}\n  };\n\n  template < typename T\
    \ >\n  using Edges = std::vector< Edge< T > >;\n\n} // namespace luz\n#line 2\
    \ \"src/graph/class/static-graph.hpp\"\n\n#line 5 \"src/graph/class/static-graph.hpp\"\
    \n\n#line 7 \"src/graph/class/static-graph.hpp\"\n#include <cassert>\n#line 9\
    \ \"src/graph/class/static-graph.hpp\"\n\nnamespace luz::internal {\n\n  template\
    \ < typename Iterator >\n  class OutgoingEdges {\n    Iterator f, l;\n\n   public:\n\
    \    OutgoingEdges(Iterator f, Iterator l): f(f), l(l) {}\n\n    Iterator begin()\
    \ const {\n      return f;\n    }\n    Iterator end() const {\n      return l;\n\
    \    }\n    usize size() const {\n      return l - f;\n    }\n\n    auto &operator[](usize\
    \ k) {\n      assert(k < size());\n      return begin()[k];\n    }\n    const\
    \ auto &operator[](usize k) const {\n      assert(k < size());\n      return begin()[k];\n\
    \    }\n  };\n\n} // namespace luz::internal\n\nnamespace luz {\n\n  template\
    \ < typename Edge >\n  class StaticGraph {\n\n    using Edges          = std::vector<\
    \ Edge >;\n    using iterator       = typename Edges::iterator;\n    using const_iterator\
    \ = typename Edges::const_iterator;\n\n    template < typename Iterator >\n  \
    \  using Es = internal::OutgoingEdges< Iterator >;\n\n   protected:\n    bool\
    \ initialized;\n    usize vertex_count;\n    usize edge_count;\n\n    Edges edges;\n\
    \    std::vector< usize > outdegrees;\n\n   public:\n    using cost_type = typename\
    \ Edge::cost_type;\n\n    StaticGraph() = default;\n    explicit StaticGraph(usize\
    \ n)\n        : initialized(false),\n          vertex_count(n),\n          edge_count(0),\n\
    \          outdegrees(vertex_count) {}\n\n    usize size() const {\n      return\
    \ vertex_count;\n    }\n\n    void initialize() {\n      assert(not initialized);\n\
    \n      outdegrees.emplace_back(0);\n      for (usize i: rrep(0, size())) {\n\
    \        outdegrees[i] += outdegrees[i + 1];\n      }\n\n      std::sort(edges.begin(),\
    \ edges.end(),\n                [](const Edge &e1, const Edge &e2) {\n       \
    \ return e1.from != e2.from ? e1.from > e2.from : e1.to < e2.to;\n      });\n\n\
    \      initialized = true;\n    }\n\n    void add_directed_edge(usize from, usize\
    \ to, cost_type cost = 1) {\n      assert(not initialized);\n      assert(from\
    \ < size());\n      assert(to < size());\n      edges.emplace_back(from, to, cost,\
    \ edge_count++);\n      outdegrees[from]++;\n    }\n\n    void add_undirected_edge(usize\
    \ u, usize v, cost_type cost = 1) {\n      assert(not initialized);\n      assert(u\
    \ < size());\n      assert(v < size());\n      assert(u != v);\n      edges.emplace_back(u,\
    \ v, cost, edge_count);\n      outdegrees[u]++;\n      edges.emplace_back(v, u,\
    \ cost, edge_count++);\n      outdegrees[v]++;\n    }\n\n    Es< iterator > operator[](const\
    \ usize &v) {\n      assert(initialized);\n      return Es< iterator >(edges.begin()\
    \ + outdegrees[v + 1],\n                            edges.begin() + outdegrees[v]);\n\
    \    }\n\n    const Es< const_iterator > operator[](const usize &v) const {\n\
    \      assert(initialized);\n      return Es< const_iterator >(edges.cbegin()\
    \ + outdegrees[v + 1],\n                                  edges.cbegin() + outdegrees[v]);\n\
    \    }\n  };\n\n} // namespace luz\n#line 2 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/change-min.hpp\"\n\nnamespace luz {\n\n\
    \  template < typename T1, typename T2 >\n  inline bool chmin(T1 &a, T2 b) {\n\
    \    return a > b and (a = b, true);\n  }\n\n} // namespace luz\n#line 6 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#line 8 \"src/graph/decomposition/strongly-connected-components.hpp\"\n\n\
    namespace luz::decomposition {\n\n  template < class G >\n  class StronglyConnectedComponents\
    \ {\n    using graph     = G;\n    using cost_type = typename graph::cost_type;\n\
    \n    graph g;\n    usize g_size;\n    std::vector< usize > low, ord, visited,\
    \ group_id;\n    usize ord_cnt, group_cnt;\n\n    void dfs(usize v) {\n      low[v]\
    \ = ord[v] = ord_cnt++;\n      visited.emplace_back(v);\n      for (auto& e: g[v])\
    \ {\n        if (ord[e.to] == g_size) {\n          dfs(e.to);\n          chmin(low[v],\
    \ low[e.to]);\n        } else {\n          chmin(low[v], ord[e.to]);\n       \
    \ }\n      }\n      if (low[v] == ord[v]) {\n        while (true) {\n        \
    \  usize u = visited.back();\n          visited.pop_back();\n          ord[u]\
    \      = g_size + 1;\n          group_id[u] = group_cnt;\n          if (u == v)\
    \ break;\n        }\n        group_cnt++;\n      }\n    }\n\n   public:\n    explicit\
    \ StronglyConnectedComponents(const graph& g_)\n        : g(g_),\n          g_size(g.size()),\n\
    \          low(g_size),\n          ord(g_size, g_size),\n          group_id(g_size),\n\
    \          ord_cnt(0),\n          group_cnt(0) {\n      visited.reserve(g_size);\n\
    \      for (usize v: rep(0, g_size)) {\n        if (ord[v] == g_size) {\n    \
    \      dfs(v);\n        }\n      }\n      for (auto& id: group_id) {\n       \
    \ id = group_cnt - id - 1;\n      }\n    }\n\n    std::vector< std::vector< usize\
    \ > > groups() const {\n      std::vector< usize > counts(group_cnt);\n      for\
    \ (usize i: rep(0, g_size)) {\n        counts[group_id[i]]++;\n      }\n     \
    \ std::vector< std::vector< usize > > groups(group_cnt);\n      for (usize i:\
    \ rep(0, group_cnt)) {\n        groups[i].reserve(counts[i]);\n      }\n     \
    \ for (usize i: rep(0, g_size)) {\n        groups[group_id[i]].emplace_back(i);\n\
    \      }\n      return groups;\n    }\n\n    std::vector< usize > group_ids()\
    \ const {\n      return group_id;\n    }\n  };\n\n} // namespace luz::decomposition\n\
    #line 11 \"test/library-checker/scc.test.cpp\"\n\n#line 14 \"test/library-checker/scc.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    using edge  = Edge< i32 >;\n    using\
    \ graph = StaticGraph< edge >;\n\n    usize n, m;\n    std::cin >> n >> m;\n \
    \   graph g(n);\n    for ([[maybe_unused]] usize _: rep(0, m)) {\n      usize\
    \ u, v;\n      std::cin >> u >> v;\n      g.add_directed_edge(u, v);\n    }\n\n\
    \    g.initialize();\n    decomposition::StronglyConnectedComponents scc(g);\n\
    \n    auto groups = scc.groups();\n    std::cout << groups.size() << std::endl;\n\
    \    for (auto& group: groups) {\n      std::cout << group.size() << \" \" <<\
    \ group << \" \" << std::endl;\n    }\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::set_fast_ios();\n\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc\n\n#include\
    \ \"src/cpp-template/header/fast-ios.hpp\"\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/cpp-template/header/vector-ios.hpp\"\n#include \"src/graph/class/edge/edge.hpp\"\
    \n#include \"src/graph/class/static-graph.hpp\"\n#include \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    using edge  = Edge< i32 >;\n    using graph = StaticGraph< edge >;\n\n\
    \    usize n, m;\n    std::cin >> n >> m;\n    graph g(n);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, m)) {\n      usize u, v;\n      std::cin >> u >> v;\n      g.add_directed_edge(u,\
    \ v);\n    }\n\n    g.initialize();\n    decomposition::StronglyConnectedComponents\
    \ scc(g);\n\n    auto groups = scc.groups();\n    std::cout << groups.size() <<\
    \ std::endl;\n    for (auto& group: groups) {\n      std::cout << group.size()\
    \ << \" \" << group << \" \" << std::endl;\n    }\n  }\n\n} // namespace luz\n\
    \nint main() {\n  luz::set_fast_ios();\n\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/fast-ios.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/class/static-graph.hpp
  - src/graph/decomposition/strongly-connected-components.hpp
  - src/cpp-template/header/change-min.hpp
  isVerificationFile: true
  path: test/library-checker/scc.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/scc.test.cpp
- /verify/test/library-checker/scc.test.cpp.html
title: test/library-checker/scc.test.cpp
---
