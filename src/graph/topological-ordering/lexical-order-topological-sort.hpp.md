---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
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
  bundledCode: "#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 2 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n#include <queue>\n#include <vector>\n\nnamespace luz {\n\n  template < class\
    \ G, class Compare >\n  std::vector< usize > lexical_order_topological_sort(const\
    \ G &g) {\n    usize n = g.size();\n\n    std::vector< usize > indegrees(n);\n\
    \    for (auto v: rep(0, n)) {\n      for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n\
    \      }\n    }\n\n    std::priority_queue< usize, std::vector< usize >, Compare\
    \ > pq;\n    for (usize v: rep(0, n)) {\n      if (indegrees[v]) continue;\n \
    \     pq.emplace(v);\n    }\n\n    std::vector< usize > result;\n    result.reserve(n);\n\
    \    while (not pq.empty()) {\n      auto v = pq.top();\n      pq.pop();\n\n \
    \     result.emplace_back(v);\n      for (auto &&e: g[v]) {\n        if (--indegrees[e.to])\
    \ continue;\n        pq.emplace(e.to);\n      }\n    }\n\n    if (result.size()\
    \ != n) {\n      return {};\n    }\n\n    return result;\n  }\n\n} // namespace\
    \ luz\n"
  code: "#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include <queue>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < class G, class Compare >\n\
    \  std::vector< usize > lexical_order_topological_sort(const G &g) {\n    usize\
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
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/topological-ordering/lexical-order-topological-sort.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc291_e.test.cpp
documentation_of: src/graph/topological-ordering/lexical-order-topological-sort.hpp
layout: document
title: "\u8F9E\u66F8\u9806\u6700\u5927/\u6700\u5C0F\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\
  \u30EB\u30BD\u30FC\u30C8"
---

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## lexical_order_topological_sort
```cpp
std::vector< usize >
lexical_order_topological_sort(
  const G &g
)
```

辞書順最大、または辞書順最小のトポロジカル順序を求める。

非連結な場合や DAG でない場合は空の `std::vector` が返る。

### usage
#### 辞書順最小を求める場合
```cpp
lexical_order_topological_sort< G, std::greater< usize > >(g)
```

#### 辞書順最大を求める場合
```cpp
lexical_order_topological_sort< G, std::less< usize > >(g)
```

### 制約
- `Compare` には `std::greater< usize >` または `std::less< usize >` が渡されること。

### 計算量
- $O(\|E\| + \|V\| \log \|V\|)$
