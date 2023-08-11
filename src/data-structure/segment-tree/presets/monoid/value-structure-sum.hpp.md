---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-add-sum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-add-sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Add Range Sum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-sum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Sum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Update Range Sum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_b/segment-tree.test.cpp
    title: test/aoj/dsl_2_b/segment-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_g.test.cpp
    title: test/aoj/dsl_2_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_i.test.cpp
    title: test/aoj/dsl_2_i.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T >\n  class RangeSumQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return a + b;\n    }\n\n    static constexpr T identity() {\n\
    \      return T();\n    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\nnamespace luz::monoid {\n\n  template < typename T >\n  class\
    \ RangeSumQueryMonoid {\n\n   public:\n    using value_type = T;\n\n    static\
    \ constexpr T operation(T a, T b) {\n      return a + b;\n    }\n\n    static\
    \ constexpr T identity() {\n      return T();\n    }\n  };\n\n} // namespace luz::monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-sum-query-solver.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-add-sum.hpp
  - src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_i.test.cpp
  - test/aoj/dsl_2_b/segment-tree.test.cpp
  - test/aoj/dsl_2_g.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
- /library/src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp.html
title: src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
---
