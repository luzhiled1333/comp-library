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
  bundledCode: "#line 2 \"src/cpp-template/header/make-vector.hpp\"\n\n#line 2 \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include <cstdint>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n\
    \  using u64 = std::uint64_t;\n  \n} // namespace luz\n#line 4 \"src/cpp-template/header/make-vector.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\n  template <typename T>\n  std::vector<T>\
    \ make_vector(usize a, T b) {\n    return std::vector<T>(a, b);\n  }\n\n  template\
    \ <typename... Ts>\n  auto make_vector(usize a, Ts... ts) {\n    return std::vector<decltype(make_vector(ts...))>(a,\
    \ make_vector(ts...));\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template <typename T>\n  std::vector<T> make_vector(usize\
    \ a, T b) {\n    return std::vector<T>(a, b);\n  }\n\n  template <typename...\
    \ Ts>\n  auto make_vector(usize a, Ts... ts) {\n    return std::vector<decltype(make_vector(ts...))>(a,\
    \ make_vector(ts...));\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/cpp-template/header/make-vector.hpp
  requiredBy:
  - src/cpp-template/template.cpp
  - src/cpp-template/header/template-header.hpp
  timestamp: '2022-07-16 05:05:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1_1_a.test.cpp
documentation_of: src/cpp-template/header/make-vector.hpp
layout: document
title: make vector
---

## make_vector
```
(1) std::vector< T > make_vector(usize a, T b)
(2) auto make_vector(usize a, Ts... ts)
```

多次元の vector を返す。

たとえば
```cpp
auto dp = make_vector(n, m, e)
```
のようにすると、`dp[n][m]` が初期値 `e` で宣言される。

要素の型は初期値に依存する。
