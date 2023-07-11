---
title: ワイルドカードパターンマッチング
documentation_of: //src/sequence/wildcard-pattern-matching.hpp
---

## wildcard_pattern_matching
```
template< modint, class T, class Iter >
std::vector< i32 >
wildcard_pattern_matching(Iter f1, Iter l1, Iter f2, Iter l2, T wildcard)
```

イテレータ $[f1, l1)$, $[f2, l2)$ のワイルドカードありパターンマッチングの結果を返す。

result の配列の $i$ 番目には $[f1 + i, f1 + i + (l2 - f2))$ と $[f2, l2)$ がマッチしている場合には 1 が、マッチしていない場合は 0 が格納されている。

`wildcard` にはワイルドカードと扱うべき値を渡す。

`T` と `Iter` についてはおそらく推論が効くが、`modint` については効かないと思われるため明示するとよい。

### 計算量
- $n = l1 - f1, m = l2 - f2$ として $O((n + m) \log (n + m))$

### note: 衝突について
内部的に $mod M$ で計算しているため、「取りうる値の2乗程度 * 長さ」が $M$ を超える場合は値が十分ランダムであっても $expected O(1/M)$ で誤判定をしてしまう。

本来はマッチしない文字列がマッチしたと検出されることはあっても、本来はマッチする文字列がマッチしないことはないため、`modint` として複数のものを渡し、その結果の and を取るほうが実用上安全である。

### note: 値の取りうる範囲について
列の値が取りうる値として 0 が含まれている場合、何らかの手段を用いて $[1, k)$ への単射で写しておく必要がある。
