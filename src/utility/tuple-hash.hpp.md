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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/utility/tuple-hash.test.cpp
    title: unit-test/utility/tuple-hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/tuple-hash.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/utility/tuple-hash.hpp\"\n\n#include <functional>\n\
    #include <tuple>\n#include <utility>\n\nnamespace luz::impl_tuple_hash {\n\n \
    \ template < usize Index >\n  class ImplTupleHash {\n   public:\n    template\
    \ < typename T >\n    usize hash_combine(const T &x, usize hr) const {\n     \
    \ usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr << 11) + (hr >> 13));\n\
    \    }\n\n    template < class Tuple >\n    usize operator()(const Tuple &t) const\
    \ noexcept {\n      usize hr = ImplTupleHash< Index - 1 >()(t);\n      return\
    \ hash_combine(std::get< Index - 1 >(t), hr);\n    }\n  };\n\n  template <>\n\
    \  class ImplTupleHash< 0 > {\n   public:\n    template < class Tuple >\n    usize\
    \ operator()([[maybe_unused]] const Tuple &_) const noexcept {\n      return 0;\n\
    \    }\n  };\n\n} // namespace luz::impl_tuple_hash\n\nnamespace luz {\n\n  class\
    \ TupleHash {\n    template < usize Index >\n    using ImplTupleHash = impl_tuple_hash::ImplTupleHash<\
    \ Index >;\n\n   public:\n    template < class... Args >\n    usize operator()(const\
    \ std::tuple< Args... > &t) const {\n      using Tuple = std::tuple< Args... >;\n\
    \      return ImplTupleHash< std::tuple_size< Tuple >::value >()(t);\n    }\n\
    \  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <functional>\n#include <tuple>\n#include <utility>\n\nnamespace luz::impl_tuple_hash\
    \ {\n\n  template < usize Index >\n  class ImplTupleHash {\n   public:\n    template\
    \ < typename T >\n    usize hash_combine(const T &x, usize hr) const {\n     \
    \ usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr << 11) + (hr >> 13));\n\
    \    }\n\n    template < class Tuple >\n    usize operator()(const Tuple &t) const\
    \ noexcept {\n      usize hr = ImplTupleHash< Index - 1 >()(t);\n      return\
    \ hash_combine(std::get< Index - 1 >(t), hr);\n    }\n  };\n\n  template <>\n\
    \  class ImplTupleHash< 0 > {\n   public:\n    template < class Tuple >\n    usize\
    \ operator()([[maybe_unused]] const Tuple &_) const noexcept {\n      return 0;\n\
    \    }\n  };\n\n} // namespace luz::impl_tuple_hash\n\nnamespace luz {\n\n  class\
    \ TupleHash {\n    template < usize Index >\n    using ImplTupleHash = impl_tuple_hash::ImplTupleHash<\
    \ Index >;\n\n   public:\n    template < class... Args >\n    usize operator()(const\
    \ std::tuple< Args... > &t) const {\n      using Tuple = std::tuple< Args... >;\n\
    \      return ImplTupleHash< std::tuple_size< Tuple >::value >()(t);\n    }\n\
    \  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/utility/tuple-hash.hpp
  requiredBy:
  - src/graph/offline-query-jump-on-tree.hpp
  timestamp: '2023-02-04 15:43:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/jump_on_tree.test.cpp
  - unit-test/utility/tuple-hash.test.cpp
documentation_of: src/utility/tuple-hash.hpp
layout: document
title: "std::tuple \u306E Hash"
---

## TupleHash
テンプレート実引数が組み込み型であるような `std::tuple` の hash 関数を提供します。

そのままで使うことはおそらく多くなく、以下のように `std::unordered_map` や `std::unordered_set` などと組み合わせて使うことになるかと思います。

再帰で実装されている都合上、`std::tuple` のもつ型が多くなるとコンパイルができなくなることがあります。

## usage
`Tuple` は、 `std::hash< T >()(x)` が動作するような型 `T` の列 `(Args...)` によって構成された `std::tuple< Args... >` に対して動作します。

ユーザ定義の構造体については、`std::hash` のオーバーロードをすることによって動作させることができます。

例として、`std::tuple< bool, char, short, int, long, long logn >` のような型で動作します。

### `std::unordered_map`
```cpp
std::unordered_map<
  std::tuple< Args... >,
  ValueType,
  TupleHash > mp;
```

### `std::unordered_multimap`
```cpp
std::unordered_multimap<
  std::tuple< Args... >,
  ValueType,
  TupleHash > mp;
```

### `std::unordered_set`
```cpp
std::unordered_set<
  std::tuple< Args... >,
  TupleHash > st;
```

### `std::unordered_multiset`
```cpp
std::unordered_multiset<
  std::tuple< Args... >,
  TupleHash > st;
```
