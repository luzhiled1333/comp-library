---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-lowest-common-ancestor.hpp
    title: src/graph/offline-query-lowest-common-ancestor.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-1-a.test.cpp
    title: test/aoj/dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-5-c.test.cpp
    title: test/aoj/grl-5-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 2 \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include <cstdint>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n\
    \  using u64 = std::uint64_t;\n  \n} // namespace luz\n#line 4 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  class DisjointSetUnion {\n    usize n_;\n\n    // vals_[v] :=\n    //\
    \ if v is root node: -1 * component size\n    // otherwise: parent node\n    std::vector<\
    \ isize > vals_;\n\n    void bound_check(usize v) {\n      assert(v < n_);\n \
    \   }\n\n    usize impl_leader(usize v) {\n      if (vals_[v] < 0) return v;\n\
    \      return vals_[v] = leader(vals_[v]);\n    }\n\n   public:\n    DisjointSetUnion()\
    \ = default;\n    explicit DisjointSetUnion(usize n): n_(n), vals_(n, -1) {}\n\
    \n    usize size() const {\n      return vals_.size();\n    }\n\n    usize leader(usize\
    \ v) {\n      bound_check(v);\n      return impl_leader(v);\n    }\n\n    bool\
    \ same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n      return\
    \ impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize u, usize v)\
    \ {\n      bound_check(u); bound_check(v);\n\n      isize x = impl_leader(u);\n\
    \      isize y = impl_leader(v);\n      if (x == y) return x;\n      if (-vals_[x]\
    \ < -vals_[y]) std::swap(x, y);\n      vals_[x] += vals_[y];\n      vals_[y] =\
    \ x;\n      return x;\n    }\n\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  class\
    \ DisjointSetUnion {\n    usize n_;\n\n    // vals_[v] :=\n    // if v is root\
    \ node: -1 * component size\n    // otherwise: parent node\n    std::vector< isize\
    \ > vals_;\n\n    void bound_check(usize v) {\n      assert(v < n_);\n    }\n\n\
    \    usize impl_leader(usize v) {\n      if (vals_[v] < 0) return v;\n      return\
    \ vals_[v] = leader(vals_[v]);\n    }\n\n   public:\n    DisjointSetUnion() =\
    \ default;\n    explicit DisjointSetUnion(usize n): n_(n), vals_(n, -1) {}\n\n\
    \    usize size() const {\n      return vals_.size();\n    }\n\n    usize leader(usize\
    \ v) {\n      bound_check(v);\n      return impl_leader(v);\n    }\n\n    bool\
    \ same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n      return\
    \ impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize u, usize v)\
    \ {\n      bound_check(u); bound_check(v);\n\n      isize x = impl_leader(u);\n\
    \      isize y = impl_leader(v);\n      if (x == y) return x;\n      if (-vals_[x]\
    \ < -vals_[y]) std::swap(x, y);\n      vals_[x] += vals_[y];\n      vals_[y] =\
    \ x;\n      return x;\n    }\n\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/data-structure/disjoint-set-union.hpp
  requiredBy:
  - src/graph/offline-query-lowest-common-ancestor.hpp
  timestamp: '2022-07-23 10:16:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl-5-c.test.cpp
  - test/aoj/dsl-1-a.test.cpp
documentation_of: src/data-structure/disjoint-set-union.hpp
layout: document
redirect_from:
- /library/src/data-structure/disjoint-set-union.hpp
- /library/src/data-structure/disjoint-set-union.hpp.html
title: src/data-structure/disjoint-set-union.hpp
---
