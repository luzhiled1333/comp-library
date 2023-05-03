---
title: 区間加算 + 区間最小クエリ solver (Range Add Range Minimum Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
---

数列に対する区間加算クエリと区間最小クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeAddRangeMinimumQuerySolver< T >(usize n)
(2) RangeAddRangeMinimumQuerySolver< T >(usize n, T v)
(3) RangeAddRangeMinimumQuerySolver< T >(std::vector< T > vs)
```

## note
初期化していない状態で加算をするとオーバーフローを引き起こすことがある。

そのようなことがしたい場合は、`C::operation` でオーバーフローを検出するようなコードを書くとよい。

```cpp
static constexpr T operation(VT a, OT b) {
  if (std::numeric_limits< VT >::min() - a > b) {
    return T::identity;
  }
  return a + b;
}
```
