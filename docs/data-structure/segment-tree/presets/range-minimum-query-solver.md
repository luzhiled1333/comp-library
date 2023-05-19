---
title: 一点更新 + 区間最小クエリ solver (Range Minimum Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-minimum-query-solver.hpp
---

数列に対する一点更新クエリと区間最小クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeMinimumQuerySolver< T >(usize n)
(2) RangeMinimumQuerySolver< T >(usize n, T v)
(3) RangeMinimumQuerySolver< T >(std::vector< T > vs)
```
