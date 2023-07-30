---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-min.hpp
    title: chmin
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/change-min.hpp\"\n\nnamespace luz {\n\n\
    \  template < typename T1, typename T2 >\n  inline bool chmin(T1 &a, T2 b) {\n\
    \    return a > b and (a = b, true);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 6 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#include <vector>\n\nnamespace luz::decomposition {\n\n  template < class\
    \ G >\n  class StronglyConnectedComponents {\n    using graph     = G;\n    using\
    \ cost_type = typename graph::cost_type;\n\n    graph g;\n    usize g_size;\n\
    \    std::vector< usize > low, ord, visited, group_id;\n    usize ord_cnt, group_cnt;\n\
    \n    void dfs(usize v) {\n      low[v] = ord[v] = ord_cnt++;\n      visited.emplace_back(v);\n\
    \      for (auto& e: g[v]) {\n        if (ord[e.to] == g_size) {\n          dfs(e.to);\n\
    \          chmin(low[v], low[e.to]);\n        } else {\n          chmin(low[v],\
    \ ord[e.to]);\n        }\n      }\n      if (low[v] == ord[v]) {\n        while\
    \ (true) {\n          usize u = visited.back();\n          visited.pop_back();\n\
    \          ord[u]      = g_size + 1;\n          group_id[u] = group_cnt;\n   \
    \       if (u == v) break;\n        }\n        group_cnt++;\n      }\n    }\n\n\
    \   public:\n    explicit StronglyConnectedComponents(const graph& g_)\n     \
    \   : g(g_),\n          g_size(g.size()),\n          low(g_size),\n          ord(g_size,\
    \ g_size),\n          group_id(g_size),\n          ord_cnt(0),\n          group_cnt(0)\
    \ {\n      visited.reserve(g_size);\n      for (usize v: rep(0, g_size)) {\n \
    \       if (ord[v] == g_size) {\n          dfs(v);\n        }\n      }\n     \
    \ for (auto& id: group_id) {\n        id = group_cnt - id - 1;\n      }\n    }\n\
    \n    std::vector< std::vector< usize > > groups() const {\n      std::vector<\
    \ usize > counts(group_cnt);\n      for (usize i: rep(0, g_size)) {\n        counts[group_id[i]]++;\n\
    \      }\n      std::vector< std::vector< usize > > groups(group_cnt);\n     \
    \ for (usize i: rep(0, group_cnt)) {\n        groups[i].reserve(counts[i]);\n\
    \      }\n      for (usize i: rep(0, g_size)) {\n        groups[group_id[i]].emplace_back(i);\n\
    \      }\n      return groups;\n    }\n\n    std::vector< usize > group_ids()\
    \ const {\n      return group_id;\n    }\n  };\n\n} // namespace luz::decomposition\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/change-min.hpp\"\n#include\
    \ \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <vector>\n\nnamespace luz::decomposition {\n\n  template < class\
    \ G >\n  class StronglyConnectedComponents {\n    using graph     = G;\n    using\
    \ cost_type = typename graph::cost_type;\n\n    graph g;\n    usize g_size;\n\
    \    std::vector< usize > low, ord, visited, group_id;\n    usize ord_cnt, group_cnt;\n\
    \n    void dfs(usize v) {\n      low[v] = ord[v] = ord_cnt++;\n      visited.emplace_back(v);\n\
    \      for (auto& e: g[v]) {\n        if (ord[e.to] == g_size) {\n          dfs(e.to);\n\
    \          chmin(low[v], low[e.to]);\n        } else {\n          chmin(low[v],\
    \ ord[e.to]);\n        }\n      }\n      if (low[v] == ord[v]) {\n        while\
    \ (true) {\n          usize u = visited.back();\n          visited.pop_back();\n\
    \          ord[u]      = g_size + 1;\n          group_id[u] = group_cnt;\n   \
    \       if (u == v) break;\n        }\n        group_cnt++;\n      }\n    }\n\n\
    \   public:\n    explicit StronglyConnectedComponents(const graph& g_)\n     \
    \   : g(g_),\n          g_size(g.size()),\n          low(g_size),\n          ord(g_size,\
    \ g_size),\n          group_id(g_size),\n          ord_cnt(0),\n          group_cnt(0)\
    \ {\n      visited.reserve(g_size);\n      for (usize v: rep(0, g_size)) {\n \
    \       if (ord[v] == g_size) {\n          dfs(v);\n        }\n      }\n     \
    \ for (auto& id: group_id) {\n        id = group_cnt - id - 1;\n      }\n    }\n\
    \n    std::vector< std::vector< usize > > groups() const {\n      std::vector<\
    \ usize > counts(group_cnt);\n      for (usize i: rep(0, g_size)) {\n        counts[group_id[i]]++;\n\
    \      }\n      std::vector< std::vector< usize > > groups(group_cnt);\n     \
    \ for (usize i: rep(0, group_cnt)) {\n        groups[i].reserve(counts[i]);\n\
    \      }\n      for (usize i: rep(0, g_size)) {\n        groups[group_id[i]].emplace_back(i);\n\
    \      }\n      return groups;\n    }\n\n    std::vector< usize > group_ids()\
    \ const {\n      return group_id;\n    }\n  };\n\n} // namespace luz::decomposition\n"
  dependsOn:
  - src/cpp-template/header/change-min.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/decomposition/strongly-connected-components.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/scc.test.cpp
documentation_of: src/graph/decomposition/strongly-connected-components.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(Decomposition of Strongly Connected\
  \ Components, SCC)"
---

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```cpp
decomposition::StronglyConnectedComponents(const G &g)
```

有向グラフ `g` を強連結成分分解する。

### 計算量
- $O(\|E\| + \|V\|)$

## groups
```cpp
std::vector< std::vector< usize > > groups() const
```

$K$ を強連結成分の個数として、強連結成分の頂点のリストのリスト $L=(L_0, L_1, \cdots, L_K)$ を返す。

$L$ はトポロジカルソートされている。すなわち、`g` の各辺 $(u_i, v_i)$ について、頂点 $v_i$ を含む強連結成分が頂点 $u_i$ を含む強連結成分より前に出現しない。

## group_ids
```cpp
std::vector< usize > group_ids() const
```

それぞれの頂点に対応する強連結成分の番号を格納したリストを返す。
