---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1181.test.cpp
    title: test/aoj/1181.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1_1_a.test.cpp
    title: test/aoj/itp1_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/offline-algorithm.test.cpp
    title: test/atcoder/abc258_e/offline-algorithm.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc258_e/online-algorithm.test.cpp
    title: test/atcoder/abc258_e/online-algorithm.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc291_e.test.cpp
    title: test/atcoder/abc291_e.test.cpp
  - icon: ':x:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  - icon: ':x:'
    path: unit-test/sequence/compression.test.cpp
    title: unit-test/sequence/compression.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nnamespace luz {\n\n  template <\
    \ typename T >\n  std::ostream &operator<<(std::ostream &os,\n               \
    \            const std::vector< T > vs) {\n    for (usize i: rep(0, vs.size()))\
    \ {\n      os << vs[i] << (i + 1 != vs.size() ? \" \" : \"\");\n    }\n    return\
    \ os;\n  }\n\n  template < typename T >\n  std::istream &operator>>(std::istream\
    \ &is, std::vector< T > &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n\
    \    return is;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace luz {\n\n  template < typename T\
    \ >\n  std::ostream &operator<<(std::ostream &os,\n                          \
    \ const std::vector< T > vs) {\n    for (usize i: rep(0, vs.size())) {\n     \
    \ os << vs[i] << (i + 1 != vs.size() ? \" \" : \"\");\n    }\n    return os;\n\
    \  }\n\n  template < typename T >\n  std::istream &operator>>(std::istream &is,\
    \ std::vector< T > &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n    return\
    \ is;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/cpp-template/header/vector-ios.hpp
  requiredBy:
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/template.cpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - unit-test/sequence/compression.test.cpp
  - test/atcoder/abc291_e.test.cpp
  - test/atcoder/abc258_e/offline-algorithm.test.cpp
  - test/atcoder/abc258_e/online-algorithm.test.cpp
  - test/aoj/itp1_1_a.test.cpp
  - test/aoj/1181.test.cpp
  - test/library-checker/scc.test.cpp
documentation_of: src/cpp-template/header/vector-ios.hpp
layout: document
title: vector I/O
---

`std::vector` の入出力を定義する。

多次元の vector を出力した際、すべての要素が空白区切りで出力されてしまうことに注意。基本的には一次元の vector を出力することを想定している。
