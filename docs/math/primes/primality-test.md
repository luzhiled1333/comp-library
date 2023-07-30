---
title: 高速素数判定
documentation_of: //src/math/primes/primality-test.hpp
---

## is_prime
```
bool is_prime(u64 n)
```

$n$ が素数であるかどうかを判定する。

### 計算量
- $O((\log n)^{2})$

### note
witnesses は以下を参考にした。

- [Deterministic variants of the Miller-Rabin primality test](http://miller-rabin.appspot.com/)
