---
title: 一点更新 + 区間和クエリ solver (Range Sum Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-sum-query-solver.hpp
---

数列に対する一点更新クエリと区間和クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeSumQuerySolver< T >(usize n)
(2) RangeSumQuerySolver< T >(usize n, T v)
(3) RangeSumQuerySolver< T >(std::vector< T > vs)
```
