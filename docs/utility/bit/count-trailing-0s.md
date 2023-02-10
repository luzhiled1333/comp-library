---
title: 最下位bitから連続する 0 の数 (counting trailing 0s, countr_zero)
documentation_of: //src/utility/bit/count-trailing-0s.hpp
---

## countr_zero
```
usize countr_zero(u64 n)
```

`n` を二進表記したとき、右からいくつ連続した $0$ が続くかを返す。

$n = 0$ のときは $64$ が返る。

### 計算量
- $O(\log \log n)$

### 制約
- C++17 以前であること。

C++20 以降では `std::countr_zero(T n)` を使用すること。
