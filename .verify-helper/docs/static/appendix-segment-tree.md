# Segment Tree の細かい仕様について

Segment Tree はモノイドの列 $a = (a_0, a_1, \dots, a_{n-1})$ を扱うデータ構造。

各種演算の計算量と亜種が提供する演算の表は以下の通り。

|                         | Normal       | Dual         | Lazy         |
| ----------------------- | ------------ | ------------ | ------------ |
| コンストラクタ          | $O(n)$       | $O(n)$       | $O(n)$       |
| `build(vs)`             | $O(n)$       | $O(n)$       | $O(n)$       |
| `size()`                | $O(1)$       | $O(1)$       | $O(1)$       |
| `set(index, x)`         | $O(\log(n))$ | $O(\log(n))$ | $O(\log(n))$ |
| `apply(index, x)`       | x            | $O(\log(n))$ | $O(\log(n))$ |
| `apply(first, last, x)` | x            | $O(\log(n))$ | $O(\log(n))$ |
| `fold(index)`           | $O(1)$       | $O(\log(n))$ | $O(\log(n))$ |
| `fold(first, last)`     | $O(\log(n))$ | x            | $O(\log(n))$ |
| `fold_all()`            | $O(1)$       | x            | $O(1)$       |
| `max_right(l, fn)`      | $O(\log(n))$ | x            | $O(\log(n))$ |
| `min_left(r, fn)`       | $O(\log(n))$ | x            | $O(\log(n))$ |

Segment Tree とその亜種が要求するものは以下の通り。

| 型                               | Normal | Dual | Lazy |
| -------------------------------- | ------ | ---- | ---- |
| `value_structure`                | o      | x    | o    |
| `operator_structure`             | x      | o    | o    |

また、各ドキュメントでは次のように省略されて記載されている。

| 型                               | 省略形 |
| -------------------------------- | ------ |
| `value_structure`                | `V`    |
| `value_structure::value_type`    | `VT`   |
| `operator_structure`             | `O`    |
| `operator_structure::value_type` | `OT`   |
