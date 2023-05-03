---
title: 区間 chmax クエリ solver (Range ChangeMax Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-chmax-query-solver.hpp
---

数列に対する区間chmaxクエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeChmaxQuerySolver< T >(usize n)
(2) RangeChmaxQuerySolver< T >(usize n, T v)
(3) RangeChmaxQuerySolver< T >(std::vector< T > vs)
```
