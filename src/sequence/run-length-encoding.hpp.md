---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc259_c.test.cpp
    title: test/atcoder/abc259_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/sequence/run-length-encoding.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/sequence/run-length-encoding.hpp\"\n\n#include\
    \ <string>\n#include <utility>\n#include <vector>\n\nnamespace luz::impl {\n\n\
    \  template < typename T >\n  std::vector< std::pair< T, usize > > rle(\n    \
    \  const std::vector< T > &vs) {\n    std::vector< std::pair< T, usize > > result;\n\
    \    for (const auto &v: vs) {\n      if (result.empty() or result.back().first\
    \ != v) {\n        result.emplace_back(v, 0);\n      }\n      result.back().second++;\n\
    \    }\n    return result;\n  }\n\n} // namespace luz::impl\n\nnamespace luz {\n\
    \n  template < typename T >\n  std::vector< std::pair< T, usize > > run_length_encoding(\n\
    \      const std::vector< T > &vs) {\n    return impl::rle(vs);\n  }\n\n  std::vector<\
    \ std::pair< char, usize > > run_length_encoding(\n      const std::string &s)\
    \ {\n    std::vector< char > cs(s.begin(), s.end());\n    return impl::rle(cs);\n\
    \  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <string>\n#include <utility>\n#include <vector>\n\nnamespace luz::impl {\n\n\
    \  template < typename T >\n  std::vector< std::pair< T, usize > > rle(\n    \
    \  const std::vector< T > &vs) {\n    std::vector< std::pair< T, usize > > result;\n\
    \    for (const auto &v: vs) {\n      if (result.empty() or result.back().first\
    \ != v) {\n        result.emplace_back(v, 0);\n      }\n      result.back().second++;\n\
    \    }\n    return result;\n  }\n\n} // namespace luz::impl\n\nnamespace luz {\n\
    \n  template < typename T >\n  std::vector< std::pair< T, usize > > run_length_encoding(\n\
    \      const std::vector< T > &vs) {\n    return impl::rle(vs);\n  }\n\n  std::vector<\
    \ std::pair< char, usize > > run_length_encoding(\n      const std::string &s)\
    \ {\n    std::vector< char > cs(s.begin(), s.end());\n    return impl::rle(cs);\n\
    \  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/sequence/run-length-encoding.hpp
  requiredBy: []
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc259_c.test.cpp
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