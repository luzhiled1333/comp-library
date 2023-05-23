---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/data-structure/fenwick-tree.hpp
    title: Fenwick Tree (Binary Indexed Tree, BIT)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/dsl_2_b/fenwick-tree.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\n\n#line 2 \"src/data-structure/fenwick-tree.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/data-structure/fenwick-tree.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ T >\n  class FenwickTree {\n    usize n_;\n    std::vector< T > vals_;\n\n \
    \   T sum(usize k) const {\n      T result(0);\n      while (k > 0) {\n      \
    \  result += vals_[k];\n        k -= k & -k;\n      }\n      return result;\n\
    \    }\n\n   public:\n    FenwickTree() = default;\n\n    explicit FenwickTree(usize\
    \ n): n_(n), vals_(n + 1, T()) {}\n\n    explicit FenwickTree(const std::vector<\
    \ T > &as)\n        : n_(as.size()),\n          vals_(as.size() + 1, T()) {\n\
    \      for (usize i: rep(1, as.size() + 1)) {\n        vals_[i] = as[i - 1];\n\
    \      }\n      for (usize i: rep(1, as.size() + 1)) {\n        usize j = i +\
    \ (i & -i);\n        if (j <= as.size()) {\n          vals_[j] += vals_[i];\n\
    \        }\n      }\n    }\n\n    void add(usize k, const T &v) {\n      assert(0\
    \ <= k and k < n_);\n      k++;\n      while (k <= n_) {\n        vals_[k] +=\
    \ v;\n        k += k & -k;\n      }\n    }\n\n    T sum(usize l, usize r) const\
    \ {\n      assert(0 <= l and l <= r and r <= n_);\n      return sum(r) - sum(l);\n\
    \    }\n  };\n\n} // namespace luz\n#line 4 \"test/aoj/dsl_2_b/fenwick-tree.test.cpp\"\
    \n\n#line 7 \"test/aoj/dsl_2_b/fenwick-tree.test.cpp\"\n\n#include <iostream>\n\
    \nnamespace luz {\n\n  void main_() {\n    usize n, q;\n    std::cin >> n >> q;\n\
    \n    FenwickTree< u32 > ft(n);\n    for ([[maybe_unused]] usize _: rep(0, q))\
    \ {\n      usize com, x, y;\n      std::cin >> com >> x >> y;\n\n      if (not\
    \ com) {\n        ft.add(x - 1, y);\n      } else {\n        std::cout << ft.sum(x\
    \ - 1, y) << std::endl;\n      }\n    }\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\n\
    \n#include \"src/data-structure/fenwick-tree.hpp\"\n\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include <iostream>\n\
    \nnamespace luz {\n\n  void main_() {\n    usize n, q;\n    std::cin >> n >> q;\n\
    \n    FenwickTree< u32 > ft(n);\n    for ([[maybe_unused]] usize _: rep(0, q))\
    \ {\n      usize com, x, y;\n      std::cin >> com >> x >> y;\n\n      if (not\
    \ com) {\n        ft.add(x - 1, y);\n      } else {\n        std::cout << ft.sum(x\
    \ - 1, y) << std::endl;\n      }\n    }\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::main_();\n}\n"
  dependsOn:
  - src/data-structure/fenwick-tree.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: true
  path: test/aoj/dsl_2_b/fenwick-tree.test.cpp
  requiredBy: []
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_2_b/fenwick-tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_b/fenwick-tree.test.cpp
- /verify/test/aoj/dsl_2_b/fenwick-tree.test.cpp.html
title: test/aoj/dsl_2_b/fenwick-tree.test.cpp
---