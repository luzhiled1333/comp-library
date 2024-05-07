---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Add Range Minimum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-minimum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Minimum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Update Range Minimum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_a.test.cpp
    title: test/aoj/dsl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_f/range-minimum.test.cpp
    title: test/aoj/dsl_2_f/range-minimum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_h/range-minimum.test.cpp
    title: test/aoj/dsl_2_h/range-minimum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid {\n\n  template\
    \ < typename T >\n  class RangeMinimumQueryMonoid {\n\n    static constexpr T\
    \ identity_{std::numeric_limits< T >::max()};\n\n   public:\n    using value_type\
    \ = T;\n\n    static constexpr T operation(T a, T b) {\n      return std::min(a,\
    \ b);\n    }\n\n    static constexpr T identity() {\n      return identity_;\n\
    \    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid\
    \ {\n\n  template < typename T >\n  class RangeMinimumQueryMonoid {\n\n    static\
    \ constexpr T identity_{std::numeric_limits< T >::max()};\n\n   public:\n    using\
    \ value_type = T;\n\n    static constexpr T operation(T a, T b) {\n      return\
    \ std::min(a, b);\n    }\n\n    static constexpr T identity() {\n      return\
    \ identity_;\n    }\n  };\n\n} // namespace luz::monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
  - src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_h/range-minimum.test.cpp
  - test/aoj/dsl_2_f/range-minimum.test.cpp
  - test/aoj/dsl_2_a.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
- /library/src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp.html
title: src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
---
