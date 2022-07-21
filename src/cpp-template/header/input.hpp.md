---
data:
  _extendedDependsOn:
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
    path: test/aoj/grl-1-a.test.cpp
    title: test/aoj/grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/input.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 4 \"src/cpp-template/header/input.hpp\"\n\n#include\
    \ <iostream>\n\nnamespace luz {\n\n  template< typename T = i64 > T input() {\n\
    \    T tmp;\n    std::cin >> tmp;\n    return tmp;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <iostream>\n\nnamespace luz {\n\n  template< typename T = i64 > T input() {\n\
    \    T tmp;\n    std::cin >> tmp;\n    return tmp;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/cpp-template/header/input.hpp
  requiredBy:
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/template.cpp
  timestamp: '2022-07-16 05:05:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc212_h.test.cpp
  - test/aoj/itp1-1-a.test.cpp
  - test/aoj/grl-1-a.test.cpp
documentation_of: src/cpp-template/header/input.hpp
layout: document
title: input
---

## input
```
T input()
```

値を一つ受け取って返す。

unused variable との相性がよい。
