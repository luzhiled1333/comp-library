---
title: 高速なローリングハッシュ (Fast Rolling Hash with $\mod 2^{61} - 1$)
documentation_of: //src/sequence/fast-rolling-hash.hpp
---

## FastRollingHash
ハッシュの列を扱ういくつかの関数を提供するクラス。

あらかじめ実体化しておき、列の生成や操作はその実体を通して行う必要がある。

```
(1) FastRollingHash froll;
(2) FastRollingHash froll(u64 b);
```

- (1) `froll` として実体化する。base は実行時にランダムな原始根がとられる。
- (2) base を `b` と指定し、 `froll` として実体化する。

以下、実体の変数名を `froll` であるとする。

## Hs
```
using Hs = std::vector< u64 >;
```

ハッシュの列の型。 `std::vector< u64 >` のエイリアスとなっている。

## build
```
template< class Iter >
Hs froll.build(Iter first, Iter last)
```

Iterator `first` と `last` を渡すことで、 $[first, last)$ のハッシュ列を生成する。

### 計算量
- 要素数を $n$ として $O(n)$

## query
```
u64 froll.query(const Hs &s, usize l, usize r)
```

ハッシュ列とその区間 $[l, r)$ を指定し、与えられた区間の hash を計算して返す。

### 計算量
- $O(1)$

## combine
```
u64 froll.combine(u64 h1, u64 h2, usize h2len)
```

2 つのハッシュ $h1, h2$ と $h2$ の長さ `h2len` を渡すことで、もとの 2 つの列を連結した列のハッシュを返す。

### 計算量
- $O(1)$

## lcp
```
usize froll.lcp(const Hs &a, usize l1, usize r1,
                const Hs &b, usize l2, usize r2)
```

列 $A$ のハッシュ列 `a` とその区間 $[l1, r1)$、列 $B$ のハッシュ列 `b` とその区間 $[l2, r2)$ を渡すことで、列 $A$ の区間 $[l1, r1)$ と列 $B$ の区間 $[l2, r2)$ の最長共通接頭辞 (Longest Common Prefix) の長さを返す。

### 計算量
- 2 つの区間の長さの最小値を $n$ として $O(\log n)$
