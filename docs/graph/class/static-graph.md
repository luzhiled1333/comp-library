---
title: 静的なグラフ構造体
documentation_of: //src/graph/class/static-graph.hpp
---

## コンストラクタ
```
StaticGraph< edge >(usize n)
```

頂点数 `n` のグラフを定義する。

### 制約
- $0 \leq n$

## initialize
```
void initialize()
```

辺の追加を終え、各辺へのアクセスを可能にする。

### 制約
- 辺を使う前にちょうど1度だけ呼ばれること。

### `edge` の制約
- 辺のコストを表す型として `cost_type` が公開されていること。
- 辺の始点、終点、コスト、辺番号としてメンバ変数 `from`, `to`, `cost`, `id` をもつこと。また、この順にコンストラクタを呼べること。

## size
```
usize size()
```

グラフの頂点数を返す。

## add_directed_edge
```
void add_directed_edge(usize from, usize to, cost_type cost = 1)
```

`from` から `to` へのコスト`cost`の有向辺をグラフに追加する。 `cost` を指定しなかった場合、その辺のコストは 1 になる。

辺には追加された順に 0-indexed で辺番号が割り振られる。

### 制約
- `initialize()` が**呼ばれていない**こと。

## add_undirected_edge
```
void add_undirected_edge(usize u, usize v, cost_type cost = 1)
```

`u` から `v` へのコスト `cost` の無向辺をグラフに追加する。 `cost` を指定しなかった場合、その辺のコストは 1 になる。

辺には追加された順に 0-indexed で辺番号が割り振られる。

### 制約
- `initialize()` が**呼ばれていない**こと。

## operator[]
```
(1)       Edges &operator[](const usize &v)
(2) const Edges &operator[](const usize &v) const
```

`v` を始点とする辺のリストを返す。

### 制約
- `initialize()` が**呼ばれている**こと。

