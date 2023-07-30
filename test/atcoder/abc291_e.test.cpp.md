---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':question:'
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  - icon: ':question:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':question:'
    path: src/graph/class/static-graph.hpp
    title: "\u9759\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/topological-ordering/lexical-order-topological-sort.hpp
    title: "\u8F9E\u66F8\u9806\u6700\u5927/\u6700\u5C0F\u306E\u30C8\u30DD\u30ED\u30B8\
      \u30AB\u30EB\u30BD\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc291/tasks/abc291_e
    links:
    - https://atcoder.jp/contests/abc291/tasks/abc291_e
  bundledCode: "#line 1 \"test/atcoder/abc291_e.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename T >\n  std::ostream\
    \ &operator<<(std::ostream &os,\n                           const std::vector<\
    \ T > vs) {\n    for (usize i: rep(0, vs.size())) {\n      os << vs[i] << (i +\
    \ 1 != vs.size() ? \" \" : \"\");\n    }\n    return os;\n  }\n\n  template <\
    \ typename T >\n  std::istream &operator>>(std::istream &is, std::vector< T >\
    \ &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n    return is;\n  }\n\n\
    } // namespace luz\n#line 2 \"src/graph/class/edge/edge.hpp\"\n\n#line 4 \"src/graph/class/edge/edge.hpp\"\
    \n\n#line 6 \"src/graph/class/edge/edge.hpp\"\n\nnamespace luz {\n\n  template\
    \ < typename T >\n  class Edge {\n   public:\n    using cost_type = T;\n\n   \
    \ usize from, to;\n    T cost;\n    usize id;\n    Edge() = default;\n    Edge(usize\
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
    \    }\n  };\n\n} // namespace luz\n#line 2 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n#include <queue>\n#line 5 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\nnamespace luz {\n\n  template < class G, class Compare >\n  std::vector< usize\
    \ > lexical_order_topological_sort(const G &g) {\n    usize n = g.size();\n\n\
    \    std::vector< usize > indegrees(n);\n    for (auto v: rep(0, n)) {\n     \
    \ for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n      }\n    }\n\n    std::priority_queue<\
    \ usize, std::vector< usize >, Compare > pq;\n    for (usize v: rep(0, n)) {\n\
    \      if (indegrees[v]) continue;\n      pq.emplace(v);\n    }\n\n    std::vector<\
    \ usize > result;\n    result.reserve(n);\n    while (not pq.empty()) {\n    \
    \  auto v = pq.top();\n      pq.pop();\n\n      result.emplace_back(v);\n    \
    \  for (auto &&e: g[v]) {\n        if (--indegrees[e.to]) continue;\n        pq.emplace(e.to);\n\
    \      }\n    }\n\n    if (result.size() != n) {\n      return {};\n    }\n\n\
    \    return result;\n  }\n\n} // namespace luz\n#line 8 \"test/atcoder/abc291_e.test.cpp\"\
    \n\n#include <functional>\n#line 11 \"test/atcoder/abc291_e.test.cpp\"\n\nnamespace\
    \ luz {\n\n  void main_() {\n    using edge  = Edge< usize >;\n    using graph\
    \ = StaticGraph< edge >;\n\n    usize n, m;\n    std::cin >> n >> m;\n\n    graph\
    \ g(n);\n    for ([[maybe_unused]] usize _: rep(0, m)) {\n      usize t, f;\n\
    \      std::cin >> t >> f;\n      g.add_directed_edge(t - 1, f - 1);\n    }\n\
    \    g.initialize();\n\n    auto ord =\n        lexical_order_topological_sort<\
    \ graph,\n                                        std::greater< usize > >(g);\n\
    \    auto rev =\n        lexical_order_topological_sort< graph, std::less< usize\
    \ > >(\n            g);\n\n    if (ord == rev) {\n      std::cout << \"Yes\" <<\
    \ std::endl;\n\n      std::vector< usize > ans(n);\n      for (usize i: rep(0,\
    \ n)) {\n        ans[ord[i]] = i + 1;\n      }\n\n      std::cout << ans << std::endl;\n\
    \    } else {\n      std::cout << \"No\" << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/vector-ios.hpp\"\
    \n#include \"src/graph/class/edge/edge.hpp\"\n#include \"src/graph/class/static-graph.hpp\"\
    \n#include \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n#include <functional>\n#include <iostream>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    using edge  = Edge< usize >;\n    using graph = StaticGraph< edge >;\n\
    \n    usize n, m;\n    std::cin >> n >> m;\n\n    graph g(n);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, m)) {\n      usize t, f;\n      std::cin >> t >> f;\n      g.add_directed_edge(t\
    \ - 1, f - 1);\n    }\n    g.initialize();\n\n    auto ord =\n        lexical_order_topological_sort<\
    \ graph,\n                                        std::greater< usize > >(g);\n\
    \    auto rev =\n        lexical_order_topological_sort< graph, std::less< usize\
    \ > >(\n            g);\n\n    if (ord == rev) {\n      std::cout << \"Yes\" <<\
    \ std::endl;\n\n      std::vector< usize > ans(n);\n      for (usize i: rep(0,\
    \ n)) {\n        ans[ord[i]] = i + 1;\n      }\n\n      std::cout << ans << std::endl;\n\
    \    } else {\n      std::cout << \"No\" << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/class/static-graph.hpp
  - src/graph/topological-ordering/lexical-order-topological-sort.hpp
  isVerificationFile: true
  path: test/atcoder/abc291_e.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc291_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc291_e.test.cpp
- /verify/test/atcoder/abc291_e.test.cpp.html
title: test/atcoder/abc291_e.test.cpp
---
