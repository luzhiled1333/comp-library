---
title: 区間更新 + 区間和クエリ solver (Range Update Range Sum Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
---

数列に対する区間更新クエリと区間和クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeUpdateRangeSumQuerySolver< T, ID >(usize n)
(2) RangeUpdateRangeSumQuerySolver< T, ID >(usize n, T v)
(3) RangeUpdateRangeSumQuerySolver< T, ID >(std::vector< T > vs)
```

### `ID` について
更新の自然な単位元は存在しないため、`ID` として「更新クエリとして与えられることのない型 `T` の値」を与える必要がある。
