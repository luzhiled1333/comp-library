---
title: 区間加算 + 区間最大クエリ solver (Range Add Range Maximum Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-add-range-maximum-query-solver.hpp
---

数列に対する区間加算クエリと区間最大クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeAddRangeMaximumQuerySolver< T >(usize n)
(2) RangeAddRangeMaximumQuerySolver< T >(usize n, T v)
(3) RangeAddRangeMaximumQuerySolver< T >(std::vector< T > vs)
```

## note
初期化していない状態で加算をするとオーバーフローを引き起こすことがある。

そのようなことがしたい場合は、`C::operation` でオーバーフローを検出するようなコードを書くとよい。

```cpp
static constexpr T operation(VT a, OT b) {
  if (std::numeric_limits< VT >::max() - a < b) {
    return T::identity;
  }
  return a + b;
}
```
