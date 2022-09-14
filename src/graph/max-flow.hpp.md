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
    path: test/aoj/grl_6_a.test.cpp
    title: test/aoj/grl_6_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/max-flow.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/graph/max-flow.hpp\"\
    \n\n#line 7 \"src/graph/max-flow.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ cap_type >\n  class MaxFlowGraph {\n    static constexpr cap_type INF_ =\n \
    \       std::numeric_limits< cap_type >::max();\n\n    struct Edge {\n      usize\
    \ to_;\n      cap_type cap_;\n      usize rev_;\n      Edge() = default;\n   \
    \   Edge(usize to, cap_type cap, usize rev)\n          : to_(to),\n          \
    \  cap_(cap),\n            rev_(rev) {}\n    };\n\n    usize g_size_;\n    std::vector<\
    \ i32 > min_cost_;\n    std::vector< usize > iter_;\n    std::vector< std::vector<\
    \ Edge > > graph_;\n\n    bool build_augment_path(usize s, usize t) {\n      min_cost_.assign(g_size_,\
    \ -1);\n      std::queue< usize > que;\n      que.push(s);\n      min_cost_[s]\
    \ = 0;\n      while (not que.empty() and min_cost_[t] == -1) {\n        usize\
    \ v = que.front();\n        que.pop();\n        for (const auto &e: graph_[v])\
    \ {\n          if (e.cap_ > 0 and min_cost_[e.to_] == -1) {\n            min_cost_[e.to_]\
    \ = min_cost_[v] + 1;\n            que.push(e.to_);\n          }\n        }\n\
    \      }\n      return min_cost_[t] != -1;\n    }\n\n    cap_type find_augment_path(usize\
    \ v, usize t,\n                               cap_type flow_limit) {\n      if\
    \ (v == t) return flow_limit;\n      for (usize &i = iter_[v]; i < graph_[v].size();\
    \ i++) {\n        Edge &e = graph_[v][i];\n        if (e.cap_ > 0 and min_cost_[v]\
    \ + 1 == min_cost_[e.to_]) {\n          cap_type d = find_augment_path(\n    \
    \          e.to_, t, std::min(flow_limit, e.cap_));\n          if (d > 0) {\n\
    \            e.cap_ -= d;\n            graph_[e.to_][e.rev_].cap_ += d;\n    \
    \        return d;\n          }\n        }\n      }\n      return 0;\n    }\n\n\
    \   public:\n    MaxFlowGraph() = default;\n\n    explicit MaxFlowGraph(usize\
    \ n): g_size_(n), graph_(n) {}\n\n    void add_directed_edge(usize from, usize\
    \ to, cap_type cap) {\n      assert(from < g_size_);\n      assert(to < g_size_);\n\
    \      assert(from != to);\n      graph_[from].emplace_back(to, cap, graph_[to].size());\n\
    \      graph_[to].emplace_back(from, 0, graph_[from].size() - 1);\n    }\n\n \
    \   inline cap_type inf() const {\n      return INF_;\n    }\n\n    cap_type max_flow(usize\
    \ s, usize t) {\n      return max_flow(s, t, inf());\n    }\n\n    cap_type max_flow(usize\
    \ s, usize t, cap_type flow_limit) {\n      assert(s < g_size_);\n      assert(t\
    \ < g_size_);\n      assert(s != t);\n      cap_type flow = 0, add = 0;\n    \
    \  while (build_augment_path(s, t) and flow < flow_limit) {\n        iter_.assign(g_size_,\
    \ 0);\n        do {\n          add = find_augment_path(s, t, flow_limit - add);\n\
    \          flow += add;\n        } while (add > 0);\n      }\n      return flow;\n\
    \    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <limits>\n#include <queue>\n#include <vector>\n\nnamespace luz {\n\n\
    \  template < typename cap_type >\n  class MaxFlowGraph {\n    static constexpr\
    \ cap_type INF_ =\n        std::numeric_limits< cap_type >::max();\n\n    struct\
    \ Edge {\n      usize to_;\n      cap_type cap_;\n      usize rev_;\n      Edge()\
    \ = default;\n      Edge(usize to, cap_type cap, usize rev)\n          : to_(to),\n\
    \            cap_(cap),\n            rev_(rev) {}\n    };\n\n    usize g_size_;\n\
    \    std::vector< i32 > min_cost_;\n    std::vector< usize > iter_;\n    std::vector<\
    \ std::vector< Edge > > graph_;\n\n    bool build_augment_path(usize s, usize\
    \ t) {\n      min_cost_.assign(g_size_, -1);\n      std::queue< usize > que;\n\
    \      que.push(s);\n      min_cost_[s] = 0;\n      while (not que.empty() and\
    \ min_cost_[t] == -1) {\n        usize v = que.front();\n        que.pop();\n\
    \        for (const auto &e: graph_[v]) {\n          if (e.cap_ > 0 and min_cost_[e.to_]\
    \ == -1) {\n            min_cost_[e.to_] = min_cost_[v] + 1;\n            que.push(e.to_);\n\
    \          }\n        }\n      }\n      return min_cost_[t] != -1;\n    }\n\n\
    \    cap_type find_augment_path(usize v, usize t,\n                          \
    \     cap_type flow_limit) {\n      if (v == t) return flow_limit;\n      for\
    \ (usize &i = iter_[v]; i < graph_[v].size(); i++) {\n        Edge &e = graph_[v][i];\n\
    \        if (e.cap_ > 0 and min_cost_[v] + 1 == min_cost_[e.to_]) {\n        \
    \  cap_type d = find_augment_path(\n              e.to_, t, std::min(flow_limit,\
    \ e.cap_));\n          if (d > 0) {\n            e.cap_ -= d;\n            graph_[e.to_][e.rev_].cap_\
    \ += d;\n            return d;\n          }\n        }\n      }\n      return\
    \ 0;\n    }\n\n   public:\n    MaxFlowGraph() = default;\n\n    explicit MaxFlowGraph(usize\
    \ n): g_size_(n), graph_(n) {}\n\n    void add_directed_edge(usize from, usize\
    \ to, cap_type cap) {\n      assert(from < g_size_);\n      assert(to < g_size_);\n\
    \      assert(from != to);\n      graph_[from].emplace_back(to, cap, graph_[to].size());\n\
    \      graph_[to].emplace_back(from, 0, graph_[from].size() - 1);\n    }\n\n \
    \   inline cap_type inf() const {\n      return INF_;\n    }\n\n    cap_type max_flow(usize\
    \ s, usize t) {\n      return max_flow(s, t, inf());\n    }\n\n    cap_type max_flow(usize\
    \ s, usize t, cap_type flow_limit) {\n      assert(s < g_size_);\n      assert(t\
    \ < g_size_);\n      assert(s != t);\n      cap_type flow = 0, add = 0;\n    \
    \  while (build_augment_path(s, t) and flow < flow_limit) {\n        iter_.assign(g_size_,\
    \ 0);\n        do {\n          add = find_augment_path(s, t, flow_limit - add);\n\
    \          flow += add;\n        } while (add > 0);\n      }\n      return flow;\n\
    \    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/max-flow.hpp
  requiredBy: []
  timestamp: '2022-09-14 15:07:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_6_a.test.cpp
documentation_of: src/graph/max-flow.hpp
layout: document
redirect_from:
- /library/src/graph/max-flow.hpp
- /library/src/graph/max-flow.hpp.html
title: src/graph/max-flow.hpp
---
