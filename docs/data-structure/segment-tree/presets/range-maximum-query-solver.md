---
title: 一点更新 + 区間最大クエリ solver (Range Maximum Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
---

数列に対する一点更新クエリと区間最大クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeMaximumQuerySolver< T >(usize n)
(2) RangeMaximumQuerySolver< T >(usize n, T v)
(3) RangeMaximumQuerySolver< T >(std::vector< T > vs)
```
