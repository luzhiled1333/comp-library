---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/data-structure/disjoint-set-union.hpp
    title: Disjoint Set Union (Union Find)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc177/tasks/abc177_d
    links:
    - https://atcoder.jp/contests/abc177/tasks/abc177_d
  bundledCode: "#line 1 \"test/atcoder/abc177_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc177/tasks/abc177_d\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line\
    \ 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace luz\
    \ {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { ++i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rep(const usize f, const usize l) noexcept\n\
    \      : f(std::min(f, l)), l(l) {}\n    constexpr auto begin() const noexcept\
    \ { return f; }\n    constexpr auto end() const noexcept { return l; }\n  };\n\
    \n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { --i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rrep(const usize f, const usize l) noexcept\n\
    \      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr auto begin() const\
    \ noexcept { return f; }\n    constexpr auto end() const noexcept { return l;\
    \ }\n  };\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\
    \n\nnamespace luz {\n\n  template <typename T1, typename T2>\n  inline bool chmax(T1\
    \ &a, T2 b) {\n    return a < b and (a = b, true);\n  }\n\n  template <typename\
    \ T1, typename T2>\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a\
    \ = b, true);\n  }\n\n} // namespace luz\n#line 2 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#line 5 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 7 \"src/data-structure/disjoint-set-union.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion\
    \ {\n    usize n_;\n\n    // vals_[v] :=\n    //   if v is root node: -1 * component\
    \ size\n    //   otherwise: parent node\n    std::vector< isize > vals_;\n\n \
    \   void bound_check(usize v) const {\n      assert(v < n_);\n    }\n\n    usize\
    \ impl_leader(usize v) {\n      if (vals_[v] < 0) return v;\n      return vals_[v]\
    \ = leader(vals_[v]);\n    }\n\n   public:\n    DisjointSetUnion() = default;\n\
    \    explicit DisjointSetUnion(usize n): n_(n), vals_(n, -1) {}\n\n    usize size()\
    \ const {\n      return n_;\n    }\n\n    usize leader(usize v) {\n      bound_check(v);\n\
    \      return impl_leader(v);\n    }\n\n    bool same(usize u, usize v) {\n  \
    \    bound_check(u), bound_check(v);\n      return impl_leader(u) == impl_leader(v);\n\
    \    }\n\n    usize merge(usize u, usize v) {\n      bound_check(u); bound_check(v);\n\
    \n      isize x = impl_leader(u);\n      isize y = impl_leader(v);\n      if (x\
    \ == y) return x;\n      if (-vals_[x] < -vals_[y]) std::swap(x, y);\n      vals_[x]\
    \ += vals_[y];\n      vals_[y] = x;\n      return x;\n    }\n\n    usize group_size(usize\
    \ v) {\n      bound_check(v);\n      return -vals_[impl_leader(v)];\n    }\n\n\
    \    std::vector< std::vector< usize > > groups() {\n      std::vector< std::vector<\
    \ usize > > result(n_);\n\n      std::vector< usize > leaders(n_), g_sizes(n_);\n\
    \      for (usize v: rep(0, n_)) {\n        leaders[v] = impl_leader(v);\n   \
    \     g_sizes[leaders[v]]++;\n      }\n      for (usize v: rep(0, n_)) {\n   \
    \     result[v].reserve(g_sizes[v]);\n      }\n      for (usize v: rep(0, n_))\
    \ {\n        result[leaders[v]].emplace_back(v);\n      }\n\n      auto empty_check\
    \ = [](const std::vector< usize > &vs) {\n        return vs.empty();\n      };\n\
    \      result.erase(\n        std::remove_if(result.begin(), result.end(), empty_check),\n\
    \        result.end()\n      );\n\n      return result;\n    }\n\n  };\n\n} //\
    \ namespace luz\n#line 7 \"test/atcoder/abc177_d.test.cpp\"\n\n#include <iostream>\n\
    #line 10 \"test/atcoder/abc177_d.test.cpp\"\n\nnamespace luz {\n\n  void main_()\
    \ {\n    usize n, m;\n    std::cin >> n >> m;\n\n    DisjointSetUnion dsu(n);\n\
    \    for ([[maybe_unused]] usize _: rep(0, m)) {\n      usize u, v;\n      std::cin\
    \ >> u >> v;\n      dsu.merge(u - 1, v - 1);\n    }\n\n    usize ans1 = 0, ans2\
    \ = 0;\n    {\n      for (usize v: rep(0, n)) {\n        chmax(ans1, dsu.group_size(v));\n\
    \      }\n    }\n    {\n      auto groups = dsu.groups();\n      for (const auto\
    \ &group: groups) {\n        chmax(ans2, group.size());\n      }\n    }\n\n  \
    \  assert(ans1 == ans2);\n\n    usize ans = ans1;\n    std::cout << ans << std::endl;\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc177/tasks/abc177_d\n\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/change-minmax.hpp\"\n#include \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#include <iostream>\n#include <cassert>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    usize n, m;\n    std::cin >> n >> m;\n\n    DisjointSetUnion dsu(n);\n\
    \    for ([[maybe_unused]] usize _: rep(0, m)) {\n      usize u, v;\n      std::cin\
    \ >> u >> v;\n      dsu.merge(u - 1, v - 1);\n    }\n\n    usize ans1 = 0, ans2\
    \ = 0;\n    {\n      for (usize v: rep(0, n)) {\n        chmax(ans1, dsu.group_size(v));\n\
    \      }\n    }\n    {\n      auto groups = dsu.groups();\n      for (const auto\
    \ &group: groups) {\n        chmax(ans2, group.size());\n      }\n    }\n\n  \
    \  assert(ans1 == ans2);\n\n    usize ans = ans1;\n    std::cout << ans << std::endl;\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/change-minmax.hpp
  - src/data-structure/disjoint-set-union.hpp
  isVerificationFile: true
  path: test/atcoder/abc177_d.test.cpp
  requiredBy: []
  timestamp: '2022-08-06 17:20:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc177_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc177_d.test.cpp
- /verify/test/atcoder/abc177_d.test.cpp.html
title: test/atcoder/abc177_d.test.cpp
---
