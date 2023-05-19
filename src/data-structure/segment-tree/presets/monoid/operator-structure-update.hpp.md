---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-maximum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-maximum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0\u30AF\u30A8\u30EA solver (Range Update Query\
      \ Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-maximum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Update Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Update Range Minimum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Update Range Sum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_d.test.cpp
    title: test/aoj/dsl_2_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_f/range-maximum.test.cpp
    title: test/aoj/dsl_2_f/range-maximum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_f/range-minimum.test.cpp
    title: test/aoj/dsl_2_f/range-minimum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_i.test.cpp
    title: test/aoj/dsl_2_i.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T, T ID >\n  class RangeUpdateQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return b == ID ? a : b;\n    }\n\n    static constexpr T identity()\
    \ {\n      return ID;\n    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\nnamespace luz::monoid {\n\n  template < typename T, T ID\
    \ >\n  class RangeUpdateQueryMonoid {\n\n   public:\n    using value_type = T;\n\
    \n    static constexpr T operation(T a, T b) {\n      return b == ID ? a : b;\n\
    \    }\n\n    static constexpr T identity() {\n      return ID;\n    }\n  };\n\
    \n} // namespace luz::monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-update-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-range-maximum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-update-maximum.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_i.test.cpp
  - test/aoj/dsl_2_f/range-minimum.test.cpp
  - test/aoj/dsl_2_f/range-maximum.test.cpp
  - test/aoj/dsl_2_d.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
- /library/src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp.html
title: src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
---
