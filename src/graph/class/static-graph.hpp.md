---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/static-graph.test.cpp
    title: test/aoj/grl_1_a/static-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_b/static-graph.test.cpp
    title: test/aoj/grl_1_b/static-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_5_c/grl_5_c.test.cpp
    title: test/aoj/grl_5_c/grl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/offline-algorithm.test.cpp
    title: test/atcoder/abc258_e/offline-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/online-algorithm.test.cpp
    title: test/atcoder/abc258_e/online-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc291_e.test.cpp
    title: test/atcoder/abc291_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/class/static-graph.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/graph/class/static-graph.hpp\"\
    \n\n#line 7 \"src/graph/class/static-graph.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace luz::internal {\n\n  template < typename Iterator >\n\
    \  class OutgoingEdges {\n    Iterator f, l;\n\n   public:\n    OutgoingEdges(Iterator\
    \ f, Iterator l): f(f), l(l) {}\n\n    Iterator begin() const {\n      return\
    \ f;\n    }\n    Iterator end() const {\n      return l;\n    }\n    usize size()\
    \ const {\n      return l - f;\n    }\n\n    auto &operator[](usize k) {\n   \
    \   assert(k < size());\n      return begin()[k];\n    }\n    const auto &operator[](usize\
    \ k) const {\n      assert(k < size());\n      return begin()[k];\n    }\n  };\n\
    \n} // namespace luz::internal\n\nnamespace luz {\n\n  template < typename Edge\
    \ >\n  class StaticGraph {\n\n    using Edges          = std::vector< Edge >;\n\
    \    using iterator       = typename Edges::iterator;\n    using const_iterator\
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
    \    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz::internal {\n\n  template < typename Iterator\
    \ >\n  class OutgoingEdges {\n    Iterator f, l;\n\n   public:\n    OutgoingEdges(Iterator\
    \ f, Iterator l): f(f), l(l) {}\n\n    Iterator begin() const {\n      return\
    \ f;\n    }\n    Iterator end() const {\n      return l;\n    }\n    usize size()\
    \ const {\n      return l - f;\n    }\n\n    auto &operator[](usize k) {\n   \
    \   assert(k < size());\n      return begin()[k];\n    }\n    const auto &operator[](usize\
    \ k) const {\n      assert(k < size());\n      return begin()[k];\n    }\n  };\n\
    \n} // namespace luz::internal\n\nnamespace luz {\n\n  template < typename Edge\
    \ >\n  class StaticGraph {\n\n    using Edges          = std::vector< Edge >;\n\
    \    using iterator       = typename Edges::iterator;\n    using const_iterator\
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
    \    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/class/static-graph.hpp
  requiredBy: []
  timestamp: '2023-05-28 01:36:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  - unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  - test/atcoder/abc291_e.test.cpp
  - test/atcoder/abc258_e/offline-algorithm.test.cpp
  - test/atcoder/abc258_e/online-algorithm.test.cpp
  - test/aoj/grl_1_a/static-graph.test.cpp
  - test/aoj/grl_1_b/static-graph.test.cpp
  - test/aoj/grl_5_c/grl_5_c.test.cpp
  - test/library-checker/scc.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
documentation_of: src/graph/class/static-graph.hpp
layout: document
title: "\u9759\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
---

## コンストラクタ
```
StaticGraph< edge >(usize n)
```

頂点数 `n` のグラフを定義する。

### 制約
- $0 \leq n$

## initialize
```
void initialize()
```

辺の追加を終え、各辺へのアクセスを可能にする。

### 制約
- 辺を使う前にちょうど1度だけ呼ばれること。

### `edge` の制約
- 辺のコストを表す型として `cost_type` が公開されていること。
- 辺の始点、終点、コスト、辺番号としてメンバ変数 `from`, `to`, `cost`, `id` をもつこと。また、この順にコンストラクタを呼べること。

## size
```
usize size()
```

グラフの頂点数を返す。

## add_directed_edge
```
void add_directed_edge(usize from, usize to, cost_type cost = 1)
```

`from` から `to` へのコスト`cost`の有向辺をグラフに追加する。 `cost` を指定しなかった場合、その辺のコストは 1 になる。

辺には追加された順に 0-indexed で辺番号が割り振られる。

### 制約
- `initialize()` が**呼ばれていない**こと。

## add_undirected_edge
```
void add_undirected_edge(usize u, usize v, cost_type cost = 1)
```

`u` から `v` へのコスト `cost` の無向辺をグラフに追加する。 `cost` を指定しなかった場合、その辺のコストは 1 になる。

辺には追加された順に 0-indexed で辺番号が割り振られる。

### 制約
- `initialize()` が**呼ばれていない**こと。

## operator[]
```
(1)       Edges &operator[](const usize &v)
(2) const Edges &operator[](const usize &v) const
```

`v` を始点とする辺のリストを返す。

### 制約
- `initialize()` が**呼ばれている**こと。

