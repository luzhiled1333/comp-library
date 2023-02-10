---
title: 最上位bitから連続する 0 の数 (counting leading 0s, countl_zero)
documentation_of: //src/utility/bit/count-leading-0s.hpp
---

## countl_zero
```
usize countl_zero(u64 x)
```

`x` を二進表記したとき、左からいくつ連続した $0$ が続くかを返す。

$x = 0$ のときは $64$ が返る。

### 計算量
- $O(\log \log n)$

### 制約
- C++17 以前であること。

C++20 以降では `std::countl_zero(T x)` を使用すること。

### appendix
立っている bit のうち最も大きい桁よりも小さい bit をすべて 1 で埋め、`popcount` でその数を取得している。
