---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2286.test.cpp
    title: test/aoj/2286.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/math/totient-enumeration.test.cpp
    title: unit-test/math/totient-enumeration.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/totient-enumeration.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr {\n      usize\
    \ i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n      void operator++()\
    \ noexcept {\n        ++i;\n      }\n      constexpr usize operator*() const noexcept\
    \ {\n        return i;\n      }\n      constexpr bool operator!=(const itr x)\
    \ const noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f,\
    \ l;\n    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 4 \"src/math/totient-enumeration.hpp\"\
    \n\n#include <cassert>\n#include <limits>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  template < typename T >\n  std::vector< T > totient_enumeration(T n)\
    \ {\n    static_assert(std::numeric_limits< T >::is_integer,\n               \
    \   \"T must be integer\");\n    assert(n >= 0);\n\n    n += 1;\n    std::vector<\
    \ T > totients(n);\n    for (T i: rep(0, n)) {\n      totients[i] = i;\n    }\n\
    \    for (T i: rep(2, n)) {\n      if (totients[i] != i) continue;\n      for\
    \ (T j = i; j < n; j += i) {\n        totients[j] = totients[j] / i * (i - 1);\n\
    \      }\n    }\n    return totients;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <cassert>\n#include <limits>\n#include <vector>\n\nnamespace luz {\n\n  template\
    \ < typename T >\n  std::vector< T > totient_enumeration(T n) {\n    static_assert(std::numeric_limits<\
    \ T >::is_integer,\n                  \"T must be integer\");\n    assert(n >=\
    \ 0);\n\n    n += 1;\n    std::vector< T > totients(n);\n    for (T i: rep(0,\
    \ n)) {\n      totients[i] = i;\n    }\n    for (T i: rep(2, n)) {\n      if (totients[i]\
    \ != i) continue;\n      for (T j = i; j < n; j += i) {\n        totients[j] =\
    \ totients[j] / i * (i - 1);\n      }\n    }\n    return totients;\n  }\n\n} //\
    \ namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/math/totient-enumeration.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2286.test.cpp
  - unit-test/math/totient-enumeration.test.cpp
documentation_of: src/math/totient-enumeration.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\
  \u306E\u5217\u6319"
---

## totient_enumeration
```
std::vector< T > totient_enumeration(T n)
```

$i$ 番目の要素が $\phi(i)$ であるような長さ $n+1$ の `vector` を返す。

### 計算量
- $O(n \log \log n)$

## 関連
`math/totient` を用いることで、 $\phi(n)$ を $O(\sqrt{n})$ で計算することができる。
