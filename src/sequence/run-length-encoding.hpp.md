---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
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
  bundledCode: "#line 2 \"src/sequence/run-length-encoding.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 4 \"src/sequence/run-length-encoding.hpp\"\
    \n\n#include <string>\n#include <utility>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  template < class T, class Iter >\n  std::vector< std::pair< T, usize\
    \ > > run_length_encoding(\n      Iter first, Iter last) {\n    std::vector< std::pair<\
    \ T, usize > > result;\n\n    while (first != last) {\n      if (result.empty()\
    \ or result.back().first != *first) {\n        result.emplace_back(*first, 0);\n\
    \      }\n\n      result.back().second++;\n      ++first;\n    }\n\n    return\
    \ result;\n  }\n\n  template < typename T >\n  std::vector< std::pair< T, usize\
    \ > > run_length_encoding(\n      const std::vector< T > &vs) {\n    return run_length_encoding(vs.begin(),\
    \ vs.end());\n  }\n\n  std::vector< std::pair< char, usize > > run_length_encoding(\n\
    \      const std::string &s) {\n    return run_length_encoding< char >(s.begin(),\
    \ s.end());\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <string>\n#include <utility>\n#include <vector>\n\nnamespace luz {\n\n  template\
    \ < class T, class Iter >\n  std::vector< std::pair< T, usize > > run_length_encoding(\n\
    \      Iter first, Iter last) {\n    std::vector< std::pair< T, usize > > result;\n\
    \n    while (first != last) {\n      if (result.empty() or result.back().first\
    \ != *first) {\n        result.emplace_back(*first, 0);\n      }\n\n      result.back().second++;\n\
    \      ++first;\n    }\n\n    return result;\n  }\n\n  template < typename T >\n\
    \  std::vector< std::pair< T, usize > > run_length_encoding(\n      const std::vector<\
    \ T > &vs) {\n    return run_length_encoding(vs.begin(), vs.end());\n  }\n\n \
    \ std::vector< std::pair< char, usize > > run_length_encoding(\n      const std::string\
    \ &s) {\n    return run_length_encoding< char >(s.begin(), s.end());\n  }\n\n\
    } // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/sequence/run-length-encoding.hpp
  requiredBy: []
  timestamp: '2023-08-11 19:35:51+09:00'
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
    run_length_encoding<T, Iter>(Iter first, Iter last)

(2) std::vector< std::pair< T, usize > >
    run_length_encoding<T>(const std::vector<T> &vs)

(3) std::vector< std::pair< char, usize > >
    run_length_encoding<T>(const std::string &s)
```

- (1) イテレータによる区間 $[first, last)$ をランレングス圧縮した結果を返す。
- (2) `std::vector<T>` をランレングス圧縮した結果を返す。
- (3) `std::string` をランレングス圧縮した結果を返す。

ランレングス圧縮の結果は `(値, 個数)` を要素とする `std::vector` で返される。

### 計算量
要素数を $n$ として $O(n)$
