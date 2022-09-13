---
title: オイラーのトーシェント関数の列挙
documentation_of: //src/math/totient-enumeration.hpp
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
