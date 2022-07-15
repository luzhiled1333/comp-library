---
title: chmin / chmax
documentation_of: //src/cpp-template/header/change-minmax.hpp
---

## chmin
```
bool chmin(T1 &a, T2 b)
```

`a` よりも `b` のほうが小さいとき `a` の値を `b` に変更する。
更新があったときのみ `true` を返す。

## chmax
```
bool chmax(T1 &a, T2 b)
```

`a` よりも `b` のほうが大きいとき `a` の値を `b` に変更する。
更新があったときのみ `true` を返す。
