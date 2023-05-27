---
title: 辞書順最大/最小のトポロジカルソート
documentation_of: //src/graph/topological-ordering/lexical-order-topological-sort.hpp
---

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## lexical_order_topological_sort
```cpp
std::vector< usize >
lexical_order_topological_sort(
  const G &g
)
```

辞書順最大、または辞書順最小のトポロジカル順序を求める。

非連結な場合や DAG でない場合は空の `std::vector` が返る。

### usage
#### 辞書順最小を求める場合
```cpp
lexical_order_topological_sort< G, std::greater< usize > >(g)
```

#### 辞書順最大を求める場合
```cpp
lexical_order_topological_sort< G, std::less< usize > >(g)
```

### 制約
- `Compare` には `std::greater< usize >` または `std::less< usize >` が渡されること。

### 計算量
- $O(\|E\| + \|V\| \log \|V\|)$
