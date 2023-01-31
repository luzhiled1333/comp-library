---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1_1_a.test.cpp
    title: test/aoj/itp1_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/pair-ios.hpp\"\n\n#include <iostream>\n\
    #include <utility>\n\nnamespace luz {\n\n  template < typename T1, typename T2\
    \ >\n  std::ostream &operator<<(std::ostream &os, std::pair< T1, T2 > p) {\n \
    \   os << \"(\" << p.first << \", \" << p.second << \")\";\n    return os;\n \
    \ }\n\n  template < typename T1, typename T2 >\n  std::istream &operator>>(std::istream\
    \ &is, std::pair< T1, T2 > &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    \  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include <iostream>\n#include <utility>\n\nnamespace luz\
    \ {\n\n  template < typename T1, typename T2 >\n  std::ostream &operator<<(std::ostream\
    \ &os, std::pair< T1, T2 > p) {\n    os << \"(\" << p.first << \", \" << p.second\
    \ << \")\";\n    return os;\n  }\n\n  template < typename T1, typename T2 >\n\
    \  std::istream &operator>>(std::istream &is, std::pair< T1, T2 > &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/pair-ios.hpp
  requiredBy:
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/template.cpp
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1_1_a.test.cpp
documentation_of: src/cpp-template/header/pair-ios.hpp
layout: document
title: pair I/O
---

`std::pair` の入出力を定義する。

入力は `first`, `second` の順に行われる。

出力は `(first, second)` の形式で行われるが、これはデバッグプリントなどのために用いることを想定しており、安全のため、解として出力したい場合は `p.first`, `p.second` のように書くようにしている。
