---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-add-maximum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-add-maximum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-add-sum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-add-sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA solver (Range Add Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-maximum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Add Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Add Range Minimum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Add Range Sum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_e.test.cpp
    title: test/aoj/dsl_2_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_g.test.cpp
    title: test/aoj/dsl_2_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_h/range-maximum.test.cpp
    title: test/aoj/dsl_2_h/range-maximum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_h/range-minimum.test.cpp
    title: test/aoj/dsl_2_h/range-minimum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T >\n  class RangeAddQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return a + b;\n    }\n\n    static constexpr T identity() {\n\
    \      return T();\n    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\nnamespace luz::monoid {\n\n  template < typename T >\n  class\
    \ RangeAddQueryMonoid {\n\n   public:\n    using value_type = T;\n\n    static\
    \ constexpr T operation(T a, T b) {\n      return a + b;\n    }\n\n    static\
    \ constexpr T identity() {\n      return T();\n    }\n  };\n\n} // namespace luz::monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-query-solver.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-add-sum.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-add-maximum.hpp
  - src/data-structure/segment-tree/presets/range-add-range-maximum-query-solver.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_h/range-minimum.test.cpp
  - test/aoj/dsl_2_h/range-maximum.test.cpp
  - test/aoj/dsl_2_e.test.cpp
  - test/aoj/dsl_2_g.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp
- /library/src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp.html
title: src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp
---
