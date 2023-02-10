---
title: 値を表現するために必要な最小のbit幅 (bit_width)
documentation_of: //src/utility/bit/bit-width.hpp
---

## bit_width
```
usize bit_width(u64 x)
```

`x` を表現するために必要な最小のビット幅を求める。

$x = 0$ のときは $0$ が返る。

### 計算量
- $O(\log \log n)$

### 制約
- C++17 以前であること。

C++20 以降では `std::bit_width(T x)` を使用すること。

### appendix
立っている bit のうち最も大きい桁よりも小さい bit をすべて 1 で埋め、`popcount` でその数を取得している。
