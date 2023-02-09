---
title: population count (popcount)
documentation_of: //src/utility/bit/popcount.hpp
---

## popcount
```
usize popcount(u64 x)
```

`x` を二進表記したときの1の数を返す。

### 計算量
- $O(\log \log n)$

### 制約
- C++17 以前であること。

C++20 以降では `std::popcount(T x)` を使用すること。

### appendix
基本方針として、「 $2^i$ bit ごとに区切り、それぞれの区間ごとにいくつ立っている bit があったか」を計算している。
