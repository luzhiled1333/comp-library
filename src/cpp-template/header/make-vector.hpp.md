---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: src/cpp-template/header/template-header.hpp
  - icon: ':warning:'
    path: src/cpp-template/template.hpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/make-vector.hpp\"\n\nnamespace luz\
    \ {\n\n  template <typename T>\n  std::vector<T> make_vector(usize a, T b) {\n\
    \    return std::vector<T>(a, b);\n  }\n\n  template <typename... Ts>\n  auto\
    \ make_vector(usize a, Ts... ts) {\n    return std::vector<decltype(make_vector(ts...))>(a,\
    \ make_vector(ts...));\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\nnamespace luz {\n\n  template <typename T>\n  std::vector<T>\
    \ make_vector(usize a, T b) {\n    return std::vector<T>(a, b);\n  }\n\n  template\
    \ <typename... Ts>\n  auto make_vector(usize a, Ts... ts) {\n    return std::vector<decltype(make_vector(ts...))>(a,\
    \ make_vector(ts...));\n  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/make-vector.hpp
  requiredBy:
  - src/cpp-template/template.hpp
  - src/cpp-template/header/template-header.hpp
  timestamp: '2022-06-13 01:05:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1-1-a.test.cpp
documentation_of: src/cpp-template/header/make-vector.hpp
layout: document
redirect_from:
- /library/src/cpp-template/header/make-vector.hpp
- /library/src/cpp-template/header/make-vector.hpp.html
title: src/cpp-template/header/make-vector.hpp
---
