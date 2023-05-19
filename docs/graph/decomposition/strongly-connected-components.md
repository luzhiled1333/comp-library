---
title: 強連結成分分解(Decomposition of Strongly Connected Components, SCC)
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

$K$ を強連結成分の個数として、強連結成分の頂点のリストのリスト $L=(L_0, L_1, \cdots, L_K)$ を返す。

$L$ はトポロジカルソートされている。すなわち、`g` の各辺 $(u_i, v_i)$ について、頂点 $v_i$ を含む強連結成分が頂点 $u_i$ を含む強連結成分より前に出現しない。

## group_ids
```cpp
std::vector< usize > group_ids() const
```

それぞれの頂点に対応する強連結成分の番号を格納したリストを返す。
