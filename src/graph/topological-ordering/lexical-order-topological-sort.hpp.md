---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc291_e.test.cpp
    title: test/atcoder/abc291_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/graph-template.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/graph/graph-template.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename cost_type >\n  class\
    \ Edge {\n   public:\n    usize from, to;\n    cost_type cost;\n    usize id;\n\
    \    Edge() = default;\n    Edge(usize from_, usize to_, cost_type cost_, usize\
    \ id_)\n        : from(from_),\n          to(to_),\n          cost(cost_),\n \
    \         id(id_) {}\n  };\n\n  template < typename cost_type >\n  using Edges\
    \ = std::vector< Edge< cost_type > >;\n\n  template < typename cost_type >\n \
    \ class Graph {\n   protected:\n    std::vector< std::vector< Edge< cost_type\
    \ > > > g;\n    usize edge_count;\n\n   public:\n    Graph() = default;\n    explicit\
    \ Graph(usize n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return\
    \ g.size();\n    }\n\n    void add_directed_edge(usize from, usize to, cost_type\
    \ cost = 1) {\n      assert(from < size());\n      assert(to < size());\n    \
    \  g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize\
    \ u, usize v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v\
    \ < size());\n      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    inline Edges< cost_type > &operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    inline const Edges< cost_type\
    \ > &operator[](\n        const usize &v) const {\n      return g[v];\n    }\n\
    \  };\n\n} // namespace luz\n#line 2 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n#include <queue>\n#line 5 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T, class Compare >\n  std::vector<\
    \ usize > lexical_order_topological_sort(\n      const Graph< T > &g) {\n    usize\
    \ n = g.size();\n\n    std::vector< usize > indegrees(n);\n    for (auto v: rep(0,\
    \ n)) {\n      for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n      }\n \
    \   }\n\n    std::priority_queue< usize, std::vector< usize >, Compare > pq;\n\
    \    for (usize v: rep(0, n)) {\n      if (indegrees[v]) continue;\n      pq.emplace(v);\n\
    \    }\n\n    std::vector< usize > result;\n    result.reserve(n);\n    while\
    \ (not pq.empty()) {\n      auto v = pq.top();\n      pq.pop();\n\n      result.emplace_back(v);\n\
    \      for (auto &&e: g[v]) {\n        if (--indegrees[e.to]) continue;\n    \
    \    pq.emplace(e.to);\n      }\n    }\n\n    if (result.size() != n) {\n    \
    \  return {};\n    }\n\n    return result;\n  }\n\n} // namespace luz\n"
  code: "#include \"src/graph/graph-template.hpp\"\n\n#include <queue>\n#include <vector>\n\
    \nnamespace luz {\n\n  template < typename T, class Compare >\n  std::vector<\
    \ usize > lexical_order_topological_sort(\n      const Graph< T > &g) {\n    usize\
    \ n = g.size();\n\n    std::vector< usize > indegrees(n);\n    for (auto v: rep(0,\
    \ n)) {\n      for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n      }\n \
    \   }\n\n    std::priority_queue< usize, std::vector< usize >, Compare > pq;\n\
    \    for (usize v: rep(0, n)) {\n      if (indegrees[v]) continue;\n      pq.emplace(v);\n\
    \    }\n\n    std::vector< usize > result;\n    result.reserve(n);\n    while\
    \ (not pq.empty()) {\n      auto v = pq.top();\n      pq.pop();\n\n      result.emplace_back(v);\n\
    \      for (auto &&e: g[v]) {\n        if (--indegrees[e.to]) continue;\n    \
    \    pq.emplace(e.to);\n      }\n    }\n\n    if (result.size() != n) {\n    \
    \  return {};\n    }\n\n    return result;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/graph/graph-template.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/topological-ordering/lexical-order-topological-sort.hpp
  requiredBy: []
  timestamp: '2023-04-30 12:56:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc291_e.test.cpp
documentation_of: src/graph/topological-ordering/lexical-order-topological-sort.hpp
layout: document
title: "\u8F9E\u66F8\u9806\u6700\u5927/\u6700\u5C0F\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\
  \u30EB\u30BD\u30FC\u30C8"
---

## lexical_order_topological_sort
```cpp
std::vector< usize >
lexical_order_topological_sort(
  const Graph< cost_type > &g
)
```

辞書順最大、または辞書順最小のトポロジカル順序を求める。

非連結な場合や DAG でない場合は空の `std::vector` が返る。

### usage
#### 辞書順最小を求める場合
```cpp
lexical_order_topological_sort< cost_type, std::greater< usize > >(g)
```

#### 辞書順最大を求める場合
```cpp
lexical_order_topological_sort< cost_type, std::less< usize > >(g)
```

### 制約
- グラフ `g` は DAG であること
- `Compare` には `std::greater< usize >` または `std::less< usize >` が渡されること。

### 計算量
- $O(\|E\| + \|V\| \log \|V\|)$
