---
title: pair I/O
documentation_of: //src/cpp-template/header/pair-ios.hpp
---

`std::pair` の入出力を定義する。

入力は `first`, `second` の順に行われる。

出力は `(first, second)` の形式で行われるが、これはデバッグプリントなどのために用いることを想定しており、安全のため、解として出力したい場合は `p.first`, `p.second` のように書くようにしている。
