---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/sequence/coordinate-complession.test.cpp
    title: unit-test/sequence/coordinate-complession.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n  \n} // namespace\
    \ luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\n\
    namespace luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept : i(i) {}\n      void operator++() noexcept { ++i;\
    \ }\n      constexpr usize operator*() const noexcept { return i; }\n      constexpr\
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
    \ }\n  };\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nnamespace luz {\n\n  template< typename\
    \ T >\n  std::ostream &operator<<(std::ostream &os, std::vector< T > &vs) {\n\
    \    for (usize i: rep(0, vs.size())) {\n      os << vs[i] << (i + 1 != vs.size()\
    \ ? \" \" : \"\");\n    }\n    return os;\n  }\n\n  template< typename T >\n \
    \ std::istream &operator>>(std::istream &is, std::vector< T > &vs) {\n    for\
    \ (T &v: vs) {\n      is >> v;\n    }\n    return is;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace luz {\n\n  template< typename T >\n\
    \  std::ostream &operator<<(std::ostream &os, std::vector< T > &vs) {\n    for\
    \ (usize i: rep(0, vs.size())) {\n      os << vs[i] << (i + 1 != vs.size() ? \"\
    \ \" : \"\");\n    }\n    return os;\n  }\n\n  template< typename T >\n  std::istream\
    \ &operator>>(std::istream &is, std::vector< T > &vs) {\n    for (T &v: vs) {\n\
    \      is >> v;\n    }\n    return is;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/cpp-template/header/vector-ios.hpp
  requiredBy:
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/template.cpp
  timestamp: '2022-07-21 10:59:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/sequence/coordinate-complession.test.cpp
  - test/aoj/itp1-1-a.test.cpp
documentation_of: src/cpp-template/header/vector-ios.hpp
layout: document
title: vector I/O
---

`std::vector` の入出力を定義する。

多次元の vector を出力した際、すべての要素が空白区切りで出力されてしまうことに注意。基本的には一次元の vector を出力することを想定している。
