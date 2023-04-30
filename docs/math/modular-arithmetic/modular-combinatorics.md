---
title: mod 組合せ (mod combinatorics)
documentation_of: //src/math/modular-arithmetic/modular-combinatorics.hpp
---

## コンストラクタ
```
Combinatorics<mint>(usize n = 0)
```

### 制約
- $0 \leq n$

### 計算量
- $n + f(p)$
  - $f(p)$ を `mint` の除算にかかる計算量とする。
  - `mint` が扱う $mod$ を $P$ として $O(\log P)$ であることが多い。

## factorial
```
mint factorial(usize n)
```

$n!$ を計算する。

### 制約
- $0 \leq n$

### 計算量
- $O(1)$

## factorial_inverse 
```
mint factorial_inverse(usize n)
```

$(n!)^{-1}$ を計算する。

### 制約
- $0 \leq n$

### 計算量
- $O(1)$

## inverse 
```
mint inverse(usize n)
```

$n^{-1}$ を計算する。

### 制約
- $0 \leq n$

### 計算量
- $O(1)$

## permutation
```
mint permutation(isize n, isize r)
mint P(isize n, isize r)
```

$_n\mathrm{P}_r$ を計算する。

$r < 0$ または $n < r$ のときは $0$ が返る。

### 計算量
- $O(1)$

## combination
```
mint combination(isize n, isize r)
mint C(isize n, isize r)
```

$_n\mathrm{C}_r$ を計算する。

$r < 0$ または $n < r$ のときは $0$ が返る。

### 計算量
- $O(1)$

## combination_with_repetitions
```
mint combination_with_repetitions(isize n, isize r)
mint H(isize n, isize r)
```

$_n\mathrm{H}_r$ を計算する。

$r < 0$ または $n < 0$ のときは $0$ が返る。

ボール $n$ 個、箱$k$ 個の場合は $_k\mathrm{H}_n$ であることに注意。

### 計算量
- $O(1)$
