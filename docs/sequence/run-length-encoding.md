---
title: ランレングス圧縮 (連長圧縮, Run Length Encoding, RLE)
documentation_of: //src/sequence/run-length-encoding.hpp
---

## run_length_encoding
```
(1) std::vector< std::pair< T, usize > >
    run_length_encoding<T, Iter>(Iter first, Iter last)

(2) std::vector< std::pair< T, usize > >
    run_length_encoding<T>(const std::vector<T> &vs)

(3) std::vector< std::pair< char, usize > >
    run_length_encoding<T>(const std::string &s)
```

- (1) イテレータによる区間 $[first, last)$ をランレングス圧縮した結果を返す。
- (2) `std::vector<T>` をランレングス圧縮した結果を返す。
- (3) `std::string` をランレングス圧縮した結果を返す。

ランレングス圧縮の結果は `(値, 個数)` を要素とする `std::vector` で返される。

### 計算量
要素数を $n$ として $O(n)$
