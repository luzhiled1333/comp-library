---
title: (online) Functional Graph 上の頂点 $v$ から $k$ 回移動した先の頂点 (Online Jump On Functional Graph)
documentation_of: //src/graph/functional-graph/online-query/online-query-jump-on-functional-graph.hpp
---

Functional Graph において、頂点 $v$ からちょうど $k$ 本の辺を辿って到達する頂点を求めるクエリをオンラインで処理する。このようなクエリを $jump(v, k)$ と表記する。

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
OnlineJumpOnFunctionalGraphQuery(const G &g)
```

$jump$ クエリを求めるグラフ $g$ を渡す。

内部では $g$ を loop と tree に分解し、ダブリングテーブルを構築している。

### 制約
- $g$ は Functional Graph である。
  - $g$ の任意の任意の頂点の出次数は $1$ であるとも言い換えられる。
- $1 \leq \|V\|$

### 計算量
- $O(\|V\| \log \|V\|)$

## jump
```
usize jump(usize v, u64 k)
```

$jump(v, k)$ を返す。

### 制約
- $0 \leq v < \|V\|$

### 計算量
- $O(\log \|V\|)$
