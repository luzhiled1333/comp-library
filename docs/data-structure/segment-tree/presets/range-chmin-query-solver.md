---
title: 区間 chmin クエリ solver (Range ChangeMin Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-chmin-query-solver.hpp
---

数列に対する区間chminクエリを処理するデータ構造

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeChminQuerySolver< T >(usize n)
(2) RangeChminQuerySolver< T >(usize n, T v)
(3) RangeChminQuerySolver< T >(std::vector< T > vs)
```
