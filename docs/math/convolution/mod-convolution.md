---
title: Number Theoretic Transform
documentation_of: //src/math/convolution/mod-convoltion.hpp
---

## mod_convolution

```cpp
std::vector< modint > modint_convolution(std::vector< modint > f, std::vector< modint > g)
```

`f` と `g` の畳み込みを返す。

### 計算量

- $O((n + m) \log (n + m))$
  - `f` の長さを `n`、`g` の長さを `m` とする
