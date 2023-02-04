---
title: std::pair の Hash
documentation_of: //src/utility/pair-hash.hpp
---

## PairHash
テンプレート実引数が組み込み型であるような `std::pair` の hash 関数を提供します。

そのままで使うことはおそらく多くなく、以下のように `std::unordered_map` や `std::unordered_set` などと組み合わせて使うことになるかと思います。

## usage
以下のようにして使います。

`F`, `S` として許容される型は `int`, `short`, `bool`, `long long`, `char` などの組み込み型です。`std::pair` の入れ子のような型では動かないため、`std::tuple` の Hash を使用するようにしてください。

### `std::unordered_map`
```cpp
std::unordered_map<
  std::pair< F, S >,
  ValueType,
  PairHash > mp;
```

### `std::unordered_multimap`
```cpp
std::unordered_multimap<
  std::pair< F, S >,
  ValueType,
  PairHash > mp;
```

### `std::unordered_set`
```cpp
std::unordered_set<
  std::pair< F, S >,
  PairHash > st;
```

### `std::unordered_multiset`
```cpp
std::unordered_multiset<
  std::pair< F, S >,
  PairHash > st;
```
