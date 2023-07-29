---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl_1_d.test.cpp
    title: test/aoj/ntl_1_d.test.cpp
  - icon: ':x:'
    path: unit-test/math/totient.test.cpp
    title: unit-test/math/totient.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/totient.hpp\"\n\n#include <cassert>\n#include <limits>\n\
    \nnamespace luz {\n\n  template < typename T >\n  T totient(T n) {\n    static_assert(std::numeric_limits<\
    \ T >::is_integer,\n                  \"T must be integer\");\n    assert(n >=\
    \ 0);\n    T t = n, p = 2;\n    while (p * p <= n) {\n      if (n % p == 0) {\n\
    \        t -= t / p;\n        while (n % p == 0) {\n          n /= p;\n      \
    \  }\n      }\n      p++;\n    }\n    if (n > 1) {\n      t -= t / n;\n    }\n\
    \    return t;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n\nnamespace luz {\n\
    \n  template < typename T >\n  T totient(T n) {\n    static_assert(std::numeric_limits<\
    \ T >::is_integer,\n                  \"T must be integer\");\n    assert(n >=\
    \ 0);\n    T t = n, p = 2;\n    while (p * p <= n) {\n      if (n % p == 0) {\n\
    \        t -= t / p;\n        while (n % p == 0) {\n          n /= p;\n      \
    \  }\n      }\n      p++;\n    }\n    if (n > 1) {\n      t -= t / n;\n    }\n\
    \    return t;\n  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/totient.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - unit-test/math/totient.test.cpp
  - test/aoj/ntl_1_d.test.cpp
documentation_of: src/math/totient.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\
  \ (\u30AA\u30A4\u30E9\u30FC\u306E $\\phi$ \u95A2\u6570, Euler's totient function)"
---

## totient
```
T totient(T n)
```

非負整数 $n$ に対し、$n$ と互いに素であるような $1$ 以上 $n$ 以下の自然数の個数 $\phi (n)$ を返す。

### 計算量
- $O(\sqrt n)$

## 関連
`math/totient-enumeration` を用いることで、 $n$ 以下の任意の $i$ について $\phi(i)$ を $O(n \log \log n)$ で計算することができる。
