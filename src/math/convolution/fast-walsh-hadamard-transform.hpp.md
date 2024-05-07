---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/bitwise-and-convolution.hpp
    title: src/math/convolution/bitwise-and-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/bitwise-xor-convolution.hpp
    title: src/math/convolution/bitwise-xor-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_and_convolution.test.cpp
    title: test/library-checker/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_xor_convolution.test.cpp
    title: test/library-checker/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 5 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename T, typename F >\n\
    \  void fast_walsh_hadamard_transform(std::vector< T > &f, F op) {\n    const\
    \ usize n = f.size();\n    assert((n & (n - 1)) == 0);\n    usize i = 1;\n   \
    \ while (i < n) {\n      usize j = 0;\n      while (j < n) {\n        for (usize\
    \ k: rep(0, i)) {\n          op(f[j + k], f[j + k + i]);\n        }\n        j\
    \ += i << 1;\n      }\n      i <<= 1;\n    }\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz {\n\n  template < typename T, typename F >\n  void fast_walsh_hadamard_transform(std::vector<\
    \ T > &f, F op) {\n    const usize n = f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n    usize i = 1;\n    while (i < n) {\n      usize j = 0;\n      while\
    \ (j < n) {\n        for (usize k: rep(0, i)) {\n          op(f[j + k], f[j +\
    \ k + i]);\n        }\n        j += i << 1;\n      }\n      i <<= 1;\n    }\n\
    \  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/math/convolution/fast-walsh-hadamard-transform.hpp
  requiredBy:
  - src/math/convolution/bitwise-and-convolution.hpp
  - src/math/convolution/bitwise-xor-convolution.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/bitwise_and_convolution.test.cpp
  - test/library-checker/bitwise_xor_convolution.test.cpp
  - test/atcoder/abc212_h.test.cpp
documentation_of: src/math/convolution/fast-walsh-hadamard-transform.hpp
layout: document
title: "\u9AD8\u901F\u30A6\u30A9\u30EB\u30B7\u30E5-\u30A2\u30C0\u30DE\u30FC\u30EB\u5909\
  \u63DB/\u9006\u5909\u63DB (Fast Walsh Hadamard Transform / Inverse Transform)"
---

# 高速ウォルシュ-アダマール変換 / 逆変換
