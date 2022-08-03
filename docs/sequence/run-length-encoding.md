---
title: ランレングス圧縮 (連長圧縮, Run Length Encoding, RLE)
documentation_of: //src/sequence/run-length-encoding.hpp
---

## run_length_encoding
```
(1) std::vector< std::pair< T, usize > >
    run_length_encoding<T>(const std::vector<T> &vs)
(2) std::vector< std::pair< char, usize > >
    run_length_encoding<T>(const std::string &s)
```

`std::vector<T>` または `std::string` をランレングス圧縮し、 `(値, 個数)` を要素とする `vector` で返す。
