---
title: 区間加算 + 区間和クエリ solver (Range Add Range Sum Query Solver)
documentation_of: //src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp
---

数列に対する区間加算クエリと区間和クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(2) RangeAddRangeSumQuerySolver< T >(usize n, T v)
(3) RangeAddRangeSumQuerySolver< T >(std::vector< T > vs)
```

## note
区間 mapping と区間和を実現するため、`V` には頂点が管理する要素数をもたせている。

そのため、使用する際は `(2)` の形式のコンストラクタで `{初期値, 1}` を与えて使用することを推奨している。

`(1)` のコンストラクタでも正常にコンパイルができてしまうが、正しく動作しないため注意。
