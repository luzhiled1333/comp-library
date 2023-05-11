---
title: 強連結成分分解(Decomposition of Strongly Connected Components)
documentation_of: //src/graph/decomposition/strongly-connected-components.hpp
---

## コンストラクタ
```cpp
decomposition::StronglyConnectedComponents(const Graph< cost_type > &g)
```

有向グラフ `g` を強連結成分分解する。

### 計算量
- $O(\|E\| + \|V\|)$

## groups
```cpp
std::vector< std::vector< usize > > groups() const
```

次の条件を満たす、「頂点のリスト」のリストを返す。

- 全ての頂点がちょうど1つずつ、いずれかのリストに含まれる
- 内側のリストと強連結成分が一対一に対応する
- リストはトポロジカルソートされている

## group_ids
```cpp
std::vector< usize > group_ids() const
```

それぞれの頂点に対応する強連結成分の番号を格納したリストを返す。
