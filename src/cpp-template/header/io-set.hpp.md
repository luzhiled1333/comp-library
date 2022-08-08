---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    path: test/aoj/itp1_1_a.test.cpp
    title: test/aoj/itp1_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/io-set.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 4 \"src/cpp-template/header/io-set.hpp\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n\nnamespace luz {\n\n  void io_set(usize precision)\
    \ {\n    std::cout << std::fixed << std::setprecision(precision);\n    std::cerr\
    \ << std::fixed << std::setprecision(precision);\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n\nnamespace luz {\n\n  void io_set(usize precision)\
    \ {\n    std::cout << std::fixed << std::setprecision(precision);\n    std::cerr\
    \ << std::fixed << std::setprecision(precision);\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/cpp-template/header/io-set.hpp
  requiredBy:
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/template.cpp
  timestamp: '2022-07-16 05:05:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1_1_a.test.cpp
documentation_of: src/cpp-template/header/io-set.hpp
layout: document
title: specify output precision
---

## io_set
```
void io_set(usize precision)
```

`std::cout`, `std::cerr` において浮動小数点数を出力する際、小数点以下 `precision` 桁を出力することを指定する。
