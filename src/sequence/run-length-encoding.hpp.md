---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/abc259_c.cpp
    title: test/atcoder/abc259_c.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/sequence/run-length-encoding.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 4 \"src/sequence/run-length-encoding.hpp\"\n\n\
    #include <vector>\n#include <string>\n#include <utility>\n\nnamespace luz {\n\
    namespace impl {\n\n  template< typename T >\n  std::vector< std::pair< T, usize\
    \ > > rle(const std::vector< T > &vs) {\n    std::vector< std::pair< T, usize\
    \ > > result;\n    for (const auto &v: vs) {\n      if (result.empty() or result.back().first\
    \ != v) {\n        result.emplace_back(v, 0);\n      }\n      result.back().second++;\n\
    \    }\n\n    return result;\n  }\n\n} // namespace impl\n} // namespace luz\n\
    \nnamespace luz {\n\n  template< typename T >\n  std::vector< std::pair< T, usize\
    \ > > run_length_encoding(const std::vector< T > &vs) {\n    return impl::rle(vs);\n\
    \  }\n  \n  std::vector< std::pair< char, usize > > run_length_encoding(const\
    \ std::string &s) {\n    std::vector< char > cs(s.begin(), s.end());\n    return\
    \ impl::rle(cs);\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <vector>\n#include <string>\n#include <utility>\n\nnamespace luz {\nnamespace\
    \ impl {\n\n  template< typename T >\n  std::vector< std::pair< T, usize > > rle(const\
    \ std::vector< T > &vs) {\n    std::vector< std::pair< T, usize > > result;\n\
    \    for (const auto &v: vs) {\n      if (result.empty() or result.back().first\
    \ != v) {\n        result.emplace_back(v, 0);\n      }\n      result.back().second++;\n\
    \    }\n\n    return result;\n  }\n\n} // namespace impl\n} // namespace luz\n\
    \nnamespace luz {\n\n  template< typename T >\n  std::vector< std::pair< T, usize\
    \ > > run_length_encoding(const std::vector< T > &vs) {\n    return impl::rle(vs);\n\
    \  }\n  \n  std::vector< std::pair< char, usize > > run_length_encoding(const\
    \ std::string &s) {\n    std::vector< char > cs(s.begin(), s.end());\n    return\
    \ impl::rle(cs);\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/sequence/run-length-encoding.hpp
  requiredBy:
  - test/atcoder/abc259_c.cpp
  timestamp: '2022-08-04 03:41:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/sequence/run-length-encoding.hpp
layout: document
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (\u9023\u9577\u5727\u7E2E\
  , Run Length Encoding, RLE)"
---

## run_length_encoding
```
(1) std::vector< std::pair< T, usize > >
    run_length_encoding<T>(const std::vector<T> &vs)
(2) std::vector< std::pair< char, usize > >
    run_length_encoding<T>(const std::string &s)
```

`std::vector<T>` または `std::string` をランレングス圧縮し、 `(値, 個数)` を要素とする `vector` で返す。
