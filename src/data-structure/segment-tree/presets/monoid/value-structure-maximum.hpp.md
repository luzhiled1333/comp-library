---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-add-maximum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-add-maximum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-maximum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-maximum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-maximum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Add Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-maximum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Update Range Maximum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_f/range-maximum.test.cpp
    title: test/aoj/dsl_2_f/range-maximum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_h/range-maximum.test.cpp
    title: test/aoj/dsl_2_h/range-maximum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc298_f.test.cpp
    title: test/atcoder/abc298_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid {\n\n  template\
    \ < typename T >\n  class RangeMaximumQueryMonoid {\n\n    static constexpr T\
    \ identity_{std::numeric_limits< T >::min()};\n\n   public:\n    using value_type\
    \ = T;\n\n    static constexpr T operation(T a, T b) {\n      return std::max(a,\
    \ b);\n    }\n\n    static constexpr T identity() {\n      return identity_;\n\
    \    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid\
    \ {\n\n  template < typename T >\n  class RangeMaximumQueryMonoid {\n\n    static\
    \ constexpr T identity_{std::numeric_limits< T >::min()};\n\n   public:\n    using\
    \ value_type = T;\n\n    static constexpr T operation(T a, T b) {\n      return\
    \ std::max(a, b);\n    }\n\n    static constexpr T identity() {\n      return\
    \ identity_;\n    }\n  };\n\n} // namespace luz::monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-update-maximum.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-add-maximum.hpp
  - src/data-structure/segment-tree/presets/range-update-range-maximum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-range-maximum-query-solver.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_f/range-maximum.test.cpp
  - test/aoj/dsl_2_h/range-maximum.test.cpp
  - test/atcoder/abc298_f.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
- /library/src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp.html
title: src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
---
