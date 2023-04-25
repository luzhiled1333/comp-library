---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/segment-function/counterbalance-segments.hpp
    title: src/geometry/Z2/segment-function/counterbalance-segments.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/4011.test.cpp
    title: test/aoj/4011.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/sequence/compression.test.cpp
    title: unit-test/sequence/compression.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/sequence/compression.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\n\
    namespace luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       ++i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
    \ l)),\n          l(l) {}\n    constexpr auto begin() const noexcept {\n     \
    \ return f;\n    }\n    constexpr auto end() const noexcept {\n      return l;\n\
    \    }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       --i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rrep(const usize f, const usize l) noexcept\n        : f(l - 1),\n\
    \          l(std::min(f, l) - 1) {}\n    constexpr auto begin() const noexcept\
    \ {\n      return f;\n    }\n    constexpr auto end() const noexcept {\n     \
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/sequence/compression.hpp\"\
    \n\n#line 7 \"src/sequence/compression.hpp\"\n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < class T, class Compare =\
    \ std::less< T > >\n  class Compressor {\n    std::vector< T > vs_;\n    std::vector<\
    \ T > zip_;\n    std::vector< usize > ziped_vs_;\n\n   public:\n    explicit Compressor(std::vector<\
    \ T > vs)\n        : vs_(vs),\n          zip_(vs),\n          ziped_vs_(vs.size())\
    \ {\n      std::sort(zip_.begin(), zip_.end(), Compare());\n      zip_.erase(std::unique(zip_.begin(),\
    \ zip_.end()), zip_.end());\n      for (usize i: rep(0, vs.size())) {\n      \
    \  ziped_vs_[i] = compress(vs[i]);\n      }\n    }\n\n    std::vector< usize >\
    \ compressed_vector() const {\n      return ziped_vs_;\n    }\n\n    usize compress(T\
    \ v) const {\n      auto iter = std::lower_bound(zip_.begin(), zip_.end(), v);\n\
    \      assert(*iter == v);\n      return iter - zip_.begin();\n    }\n\n    T\
    \ expand(usize i) const {\n      assert(i < zip_.size());\n      return zip_[i];\n\
    \    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n\nnamespace luz {\n\n  template < class\
    \ T, class Compare = std::less< T > >\n  class Compressor {\n    std::vector<\
    \ T > vs_;\n    std::vector< T > zip_;\n    std::vector< usize > ziped_vs_;\n\n\
    \   public:\n    explicit Compressor(std::vector< T > vs)\n        : vs_(vs),\n\
    \          zip_(vs),\n          ziped_vs_(vs.size()) {\n      std::sort(zip_.begin(),\
    \ zip_.end(), Compare());\n      zip_.erase(std::unique(zip_.begin(), zip_.end()),\
    \ zip_.end());\n      for (usize i: rep(0, vs.size())) {\n        ziped_vs_[i]\
    \ = compress(vs[i]);\n      }\n    }\n\n    std::vector< usize > compressed_vector()\
    \ const {\n      return ziped_vs_;\n    }\n\n    usize compress(T v) const {\n\
    \      auto iter = std::lower_bound(zip_.begin(), zip_.end(), v);\n      assert(*iter\
    \ == v);\n      return iter - zip_.begin();\n    }\n\n    T expand(usize i) const\
    \ {\n      assert(i < zip_.size());\n      return zip_[i];\n    }\n  };\n\n} //\
    \ namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/sequence/compression.hpp
  requiredBy:
  - src/geometry/Z2/segment-function/counterbalance-segments.hpp
  timestamp: '2022-08-24 11:33:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/sequence/compression.test.cpp
  - test/aoj/4011.test.cpp
documentation_of: src/sequence/compression.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

## コンストラクタ
```
Compressor<T, Compare>(std::vector<T> vs)
```

引数で与えられた `vector` を 0-indexed で座標圧縮する。

簡単のため、以下では与えられた `vector` のサイズを $n$ とし、重複を除いた要素数を $m$ とする。

### Compare について
`Compare` にはデフォルトで `std::less` が与えられている。

内部的に `std::sort` を用いているため、`Compare` は狭義の弱順序を満たす必要がある。
狭義の弱順序とは以下の性質をすべて満たすものである。
- 任意の `a` について `not (a < a)`
- `a < b` ならば `not (b < a)`
- `a < b` かつ `b < c` ならば `a < c`

座標圧縮後の要素 `a, b` の `a < b` の結果と `Compare()(a, b)` の結果は一致するようになっている。

### 計算量
- `Compare()` を $O(1)$ として $O(n \log n)$


## compressed_vector
```
std::vector< usize > compressed_vector() const
```

コンストラクタに与えられた `vector` を座標圧縮した結果を返す。

### 計算量
- $O(n)$


## compress
```
usize compress(T v) const
```

座標圧縮の結果、$v$ がどこに mapping されたかを再計算して返す。

### 制約
- $v$ はコンストラクタに与えられた `vector` の要素である。

### 計算量
- $O(\log n)$


## expand
```
T expand(usize i) const
```

$i$ に対応する座標圧縮前の要素を返す。

### 制約
- $0 \leq i \lt m$

### 計算量
- $O(1)$
