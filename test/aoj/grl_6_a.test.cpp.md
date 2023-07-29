---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/input.hpp
    title: input
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/graph/flow/max-flow.hpp
    title: src/graph/flow/max-flow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/grl_6_a.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\n\n#line 2 \"src/cpp-template/header/input.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/input.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  template < typename T = i64 >\n\
    \  T input() {\n    T tmp;\n    std::cin >> tmp;\n    return tmp;\n  }\n\n} //\
    \ namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 2 \"src/graph/flow/max-flow.hpp\"\n\n#line 5 \"src/graph/flow/max-flow.hpp\"\
    \n\n#line 7 \"src/graph/flow/max-flow.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ cap_type >\n  class MaxFlowGraph {\n    static constexpr cap_type INF =\n  \
    \      std::numeric_limits< cap_type >::max();\n\n    struct Edge {\n      usize\
    \ to;\n      cap_type cap;\n      usize rev;\n      Edge() = default;\n      Edge(usize\
    \ to, cap_type cap, usize rev)\n          : to(to),\n            cap(cap),\n \
    \           rev(rev) {}\n    };\n\n    usize g_size;\n    std::vector< i32 > min_cost;\n\
    \    std::vector< usize > iter;\n    std::vector< std::vector< Edge > > graph;\n\
    \n    bool build_augment_path(usize s, usize t) {\n      min_cost.assign(g_size,\
    \ -1);\n      std::queue< usize > que;\n      que.push(s);\n      min_cost[s]\
    \ = 0;\n      while (not que.empty() and min_cost[t] == -1) {\n        usize v\
    \ = que.front();\n        que.pop();\n        for (const auto &e: graph[v]) {\n\
    \          if (e.cap > 0 and min_cost[e.to] == -1) {\n            min_cost[e.to]\
    \ = min_cost[v] + 1;\n            que.push(e.to);\n          }\n        }\n  \
    \    }\n      return min_cost[t] != -1;\n    }\n\n    cap_type find_augment_path(usize\
    \ v, usize t,\n                               cap_type flow_limit) {\n      if\
    \ (v == t) return flow_limit;\n      for (usize &i = iter[v]; i < graph[v].size();\
    \ i++) {\n        Edge &e = graph[v][i];\n        if (e.cap > 0 and min_cost[v]\
    \ + 1 == min_cost[e.to]) {\n          cap_type d =\n              find_augment_path(e.to,\
    \ t, std::min(flow_limit, e.cap));\n          if (d > 0) {\n            e.cap\
    \ -= d;\n            graph[e.to][e.rev].cap += d;\n            return d;\n   \
    \       }\n        }\n      }\n      return 0;\n    }\n\n   public:\n    MaxFlowGraph()\
    \ = default;\n\n    explicit MaxFlowGraph(usize n): g_size(n), graph(n) {}\n\n\
    \    void add_directed_edge(usize from, usize to, cap_type cap) {\n      assert(from\
    \ < g_size);\n      assert(to < g_size);\n      assert(from != to);\n      graph[from].emplace_back(to,\
    \ cap, graph[to].size());\n      graph[to].emplace_back(from, 0, graph[from].size()\
    \ - 1);\n    }\n\n    inline cap_type inf() const {\n      return INF;\n    }\n\
    \n    cap_type max_flow(usize s, usize t) {\n      return max_flow(s, t, inf());\n\
    \    }\n\n    cap_type max_flow(usize s, usize t, cap_type flow_limit) {\n   \
    \   assert(s < g_size);\n      assert(t < g_size);\n      assert(s != t);\n  \
    \    cap_type flow = 0, add = 0;\n      while (build_augment_path(s, t) and flow\
    \ < flow_limit) {\n        iter.assign(g_size, 0);\n        do {\n          add\
    \ = find_augment_path(s, t, flow_limit - add);\n          flow += add;\n     \
    \   } while (add > 0);\n      }\n      return flow;\n    }\n  };\n\n} // namespace\
    \ luz\n#line 8 \"test/aoj/grl_6_a.test.cpp\"\n\n#line 10 \"test/aoj/grl_6_a.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    usize n, m;\n    std::cin >> n >>\
    \ m;\n\n    MaxFlowGraph< u32 > g(n);\n    for ([[maybe_unused]] usize _: rep(0,\
    \ m)) {\n      usize u, v;\n      u32 c;\n      std::cin >> u >> v >> c;\n   \
    \   g.add_directed_edge(u, v, c);\n    }\n    std::cout << g.max_flow(0, n - 1)\
    \ << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\n\
    \n#include \"src/cpp-template/header/input.hpp\"\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/graph/flow/max-flow.hpp\"\n\n#include <iostream>\n\nnamespace\
    \ luz {\n\n  void main_() {\n    usize n, m;\n    std::cin >> n >> m;\n\n    MaxFlowGraph<\
    \ u32 > g(n);\n    for ([[maybe_unused]] usize _: rep(0, m)) {\n      usize u,\
    \ v;\n      u32 c;\n      std::cin >> u >> v >> c;\n      g.add_directed_edge(u,\
    \ v, c);\n    }\n    std::cout << g.max_flow(0, n - 1) << std::endl;\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/input.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/flow/max-flow.hpp
  isVerificationFile: true
  path: test/aoj/grl_6_a.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_6_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_6_a.test.cpp
- /verify/test/aoj/grl_6_a.test.cpp.html
title: test/aoj/grl_6_a.test.cpp
---
