---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-jump-on-tree.hpp
    title: "(offine) \u6728\u306E\u30D1\u30B9 $u-v$ \u4E0A\u306E $k$ \u756A\u76EE\u306E\
      \u9802\u70B9 (Offline Jump On Tree)"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-level-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3 Level Ancestor (Offline Level Ancestor)"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-lowest-common-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\u7956\u5148 (Offline\
      \ Lowest Common Ancestor)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_5_c.test.cpp
    title: test/aoj/grl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/utility/pair-hash.test.cpp
    title: unit-test/utility/pair-hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/pair-hash.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/utility/pair-hash.hpp\"\n\n#include <functional>\n\
    #include <utility>\n\nnamespace luz {\n\n  class PairHash {\n    template < typename\
    \ T >\n    usize hash_combine(usize hr, const T &x) const {\n      usize h = std::hash<\
    \ T >()(x);\n      return hr ^ (h + (hr << 11) + (hr >> 13));\n    }\n\n   public:\n\
    \    template < typename F, typename S >\n    usize operator()(const std::pair<\
    \ F, S > &p) const {\n      return hash_combine(hash_combine(0, p.first), p.second);\n\
    \    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <functional>\n#include <utility>\n\nnamespace luz {\n\n  class PairHash {\n\
    \    template < typename T >\n    usize hash_combine(usize hr, const T &x) const\
    \ {\n      usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr << 11) +\
    \ (hr >> 13));\n    }\n\n   public:\n    template < typename F, typename S >\n\
    \    usize operator()(const std::pair< F, S > &p) const {\n      return hash_combine(hash_combine(0,\
    \ p.first), p.second);\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/utility/pair-hash.hpp
  requiredBy:
  - src/graph/offline-query-level-ancestor.hpp
  - src/graph/offline-query-jump-on-tree.hpp
  - src/graph/offline-query-lowest-common-ancestor.hpp
  timestamp: '2023-02-04 15:43:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_5_c.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
  - unit-test/utility/pair-hash.test.cpp
documentation_of: src/utility/pair-hash.hpp
layout: document
title: "std::pair \u306E Hash"
---

## PairHash
テンプレート実引数が組み込み型であるような `std::pair` の hash 関数を提供します。

そのままで使うことはおそらく多くなく、以下のように `std::unordered_map` や `std::unordered_set` などと組み合わせて使うことになるかと思います。

## usage
`PairHash` は、 `std::hash< T >()(x)` が動作するような型 `T` の組 `(F, S)` によって構成された `std::pair< F, S >` に対して動作します。

ユーザ定義の構造体については、`std::hash` のオーバーロードをすることによって動作させることができます。

`std::pair` の入れ子のような型では動作しないため、`std::tuple` とその Hash を使用するようにしてください。

### `std::unordered_map`
```cpp
std::unordered_map<
  std::pair< F, S >,
  ValueType,
  PairHash > mp;
```

### `std::unordered_multimap`
```cpp
std::unordered_multimap<
  std::pair< F, S >,
  ValueType,
  PairHash > mp;
```

### `std::unordered_set`
```cpp
std::unordered_set<
  std::pair< F, S >,
  PairHash > st;
```

### `std::unordered_multiset`
```cpp
std::unordered_multiset<
  std::pair< F, S >,
  PairHash > st;
```