---
title: 辞書順最大/最小のトポロジカルソート
documentation_of: //src/graph/topological-ordering/lexical-order-topological-sort.hpp
---

## lexical_order_topological_sort
```cpp
std::vector< usize >
lexical_order_topological_sort(
  const Graph< cost_type > &g
)
```

辞書順最大、または辞書順最小のトポロジカル順序を求める。

### usage
#### 辞書順最小を求める場合
```cpp
lexical_order_topological_sort< cost_type, std::greater< usize > >(g)
```

#### 辞書順最大を求める場合
```cpp
lexical_order_topological_sort< cost_type, std::less< usize > >(g)
```

### 制約
- グラフ `g` は DAG であること
- `Compare` には `std::greater< usize >` または `std::less< usize >` が渡されること。

### 計算量
- $O(E + V \log V)$
