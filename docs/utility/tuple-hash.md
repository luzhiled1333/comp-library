---
title: std::tuple の Hash
documentation_of: //src/utility/tuple-hash.hpp
---

## TupleHash
テンプレート実引数が組み込み型であるような `std::tuple` の hash 関数を提供します。

そのままで使うことはおそらく多くなく、以下のように `std::unordered_map` や `std::unordered_set` などと組み合わせて使うことになるかと思います。

再帰で実装されている都合上、`std::tuple` のもつ型が多くなるとコンパイルができなくなることがあります。

## usage
以下のようにして使います。

`Args...` として許容される型は `int`, `short`, `bool`, `long long`, `char` などの組み込み型です。例として、`std::tuple< bool, char, short, int, long, long logn >` のような型でも動作します。

### `std::unordered_map`
```cpp
std::unordered_map<
  std::tuple< Args... >,
  ValueType,
  TupleHash > mp;
```

### `std::unordered_multimap`
```cpp
std::unordered_multimap<
  std::tuple< Args... >,
  ValueType,
  TupleHash > mp;
```

### `std::unordered_set`
```cpp
std::unordered_set<
  std::tuple< Args... >,
  TupleHash > st;
```

### `std::unordered_multiset`
```cpp
std::unordered_multiset<
  std::tuple< Args... >,
  TupleHash > st;
```
