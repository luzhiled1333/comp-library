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
    path: src/math/convolution/fast-walsh-hadamard-transform.hpp
    title: "\u9AD8\u901F\u30A6\u30A9\u30EB\u30B7\u30E5-\u30A2\u30C0\u30DE\u30FC\u30EB\
      \u5909\u63DB/\u9006\u5909\u63DB (Fast Walsh Hadamard Transform / Inverse Transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_and_convolution.test.cpp
    title: test/library-checker/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/convolution/bitwise-and-convolution.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#line 5 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename T,\
    \ typename F >\n  void fast_walsh_hadamard_transform(std::vector< T > &f, F op)\
    \ {\n    const usize n = f.size();\n    assert((n & (n - 1)) == 0);\n    usize\
    \ i = 1;\n    while (i < n) {\n      usize j = 0;\n      while (j < n) {\n   \
    \     for (usize k: rep(0, i)) {\n          op(f[j + k], f[j + k + i]);\n    \
    \    }\n        j += i << 1;\n      }\n      i <<= 1;\n    }\n  }\n\n} // namespace\
    \ luz\n#line 6 \"src/math/convolution/bitwise-and-convolution.hpp\"\n\n#line 9\
    \ \"src/math/convolution/bitwise-and-convolution.hpp\"\n\nnamespace luz {\n\n\
    \  template < typename T >\n  std::vector< T > bitwise_and_convolution(std::vector<\
    \ T > f,\n                                           std::vector< T > g) {\n \
    \   assert(f.size() == g.size());\n\n    auto zeta   = [](T &lo, T hi) { return\
    \ lo += hi; };\n    auto mobius = [](T &lo, T hi) { return lo -= hi; };\n    fast_walsh_hadamard_transform(f,\
    \ zeta);\n    fast_walsh_hadamard_transform(g, zeta);\n    for (usize i: rep(0,\
    \ f.size())) {\n      f[i] *= g[i];\n    }\n    fast_walsh_hadamard_transform(f,\
    \ mobius);\n    return f;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n#include \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ T >\n  std::vector< T > bitwise_and_convolution(std::vector< T > f,\n      \
    \                                     std::vector< T > g) {\n    assert(f.size()\
    \ == g.size());\n\n    auto zeta   = [](T &lo, T hi) { return lo += hi; };\n \
    \   auto mobius = [](T &lo, T hi) { return lo -= hi; };\n    fast_walsh_hadamard_transform(f,\
    \ zeta);\n    fast_walsh_hadamard_transform(g, zeta);\n    for (usize i: rep(0,\
    \ f.size())) {\n      f[i] *= g[i];\n    }\n    fast_walsh_hadamard_transform(f,\
    \ mobius);\n    return f;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/math/convolution/fast-walsh-hadamard-transform.hpp
  isVerificationFile: false
  path: src/math/convolution/bitwise-and-convolution.hpp
  requiredBy: []
  timestamp: '2022-08-29 17:30:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/bitwise_and_convolution.test.cpp
documentation_of: src/math/convolution/bitwise-and-convolution.hpp
layout: document
redirect_from:
- /library/src/math/convolution/bitwise-and-convolution.hpp
- /library/src/math/convolution/bitwise-and-convolution.hpp.html
title: src/math/convolution/bitwise-and-convolution.hpp
---
