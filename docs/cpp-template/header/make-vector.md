---
title: input
documentation_of: //src/cpp-template/header/make-vector.hpp
---

## input
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
