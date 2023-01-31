---
title: 一点更新+区間取得 セグメント木
documentation_of: //src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
---

## Appendix
[Segment Tree の細かい仕様について](/appendix-segment-tree)

## コンストラクタ
`PointMappingRangeFoldSegmentTree` のエイリアスとして `SegmentTree` を提供している。

```
(1) SegmentTree< V >(usize n)
(2) SegmentTree< V >(vector< VT > vs)
```

1. 列 $a$ を長さ $n$ の列で初期化する。各要素の初期値は `V::identity()` となる。
2. 列 $a$ を `vs` で初期化する。

### 制約
- $0 \leq n$

### 計算量
- $O(n)$


## build
```
void build(vector< VT > vs)
```

列 $(a_0, a_1, \dots, a_{n-1})$ を `vs` で初期化して再構築する。

### 制約
- $n$ と `vs.size()` が一致すること。

### 計算量
- $O(n)$


## size
```
usize size() const
```

扱っている列 $(a_0, a_1, \dots, a_{n - 1})$ の長さ $n$ を返す。

### 計算量
- $O(1)$


## set
```
void set(usize i, VT x)
```

$a_i$ を $x$ で更新する。

### 計算量
- $O(\log(n))$


## fold
```
(1) VT fold(usize i) const
(2) VT fold(usize l, usize r) const
(3) VT fold_all() const
```

1. $a_i$ を返す。
2. $a_l \cdot a_{l+1} \cdot \dotsm \cdot a_{r}$ を返す。$l = r$ のとき `V::identity()` が返る。
3. $a_0 \cdot a_1 \cdot \dotsm \cdot a_{n-1}$ を返す。

### 計算量
- (1): $O(1)$
- (2):
  - $O(\log(n))$
  - $d = r - l$ として $O(\log(d))$
- (3): $O(1)$

### 制約
1. $0 \leq i < n$
2. $0 \leq l \leq r \leq n$

## max_right
気が向いたらそのうち実装する

## min_left
気が向いたらそのうち実装する2
