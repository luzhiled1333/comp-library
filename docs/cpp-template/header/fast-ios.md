---
title: Fast I/O
documentation_of: //src/cpp-template/header/fast-ios.hpp
---

## set_fast_ios
```
void set_fast_ios()
```

C++ の標準入出力ストリームが C の入出力と同期しないようにして高速にする。

この関数を呼び出したあと、これらが混ざるようなコードを書くと入力がおかしくなるので注意。
