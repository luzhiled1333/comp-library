---
title: 区間加算クエリ solver (Range Add Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-add-query-solver.hpp
---

数列に対する区間加算クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeAddQuerySolver< T >(usize n)
(2) RangeAddQuerySolver< T >(usize n, T v)
(3) RangeAddQuerySolver< T >(std::vector< T > vs)
```
