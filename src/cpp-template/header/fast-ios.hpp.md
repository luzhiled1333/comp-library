---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1_1_a.test.cpp
    title: test/aoj/itp1_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/fast-ios.hpp\"\n\n#include <iostream>\n\
    \nnamespace luz {\n\n  void set_fast_ios() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include <iostream>\n\nnamespace luz {\n\n  void set_fast_ios()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n  }\n\n\
    } // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/fast-ios.hpp
  requiredBy:
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/template.cpp
  timestamp: '2022-07-16 04:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1_1_a.test.cpp
  - test/library-checker/scc.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
documentation_of: src/cpp-template/header/fast-ios.hpp
layout: document
title: Fast I/O
---

## set_fast_ios
```
void set_fast_ios()
```

C++ の標準入出力ストリームが C の入出力と同期しないようにして高速にする。

この関数を呼び出したあと、これらが混ざるようなコードを書くと入力がおかしくなるので注意。
