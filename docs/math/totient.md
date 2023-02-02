---
title: オイラーのトーシェント関数 (オイラーの $\phi$ 関数, Euler's totient function)
documentation_of: //src/math/totient.hpp
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
