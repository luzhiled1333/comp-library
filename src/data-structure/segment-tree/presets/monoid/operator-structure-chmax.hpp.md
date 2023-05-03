---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-chmax-query-solver.hpp
    title: "\u533A\u9593 chmax \u30AF\u30A8\u30EA solver (Range ChangeMax Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_f/range-chmax.test.cpp
    title: test/atcoder/abc179_f/range-chmax.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/operator-structure-chmax.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid {\n\n  template\
    \ < typename T >\n  class RangeChmaxQueryMonoid {\n    static constexpr T identity_{std::numeric_limits<\
    \ T >::min()};\n\n   public:\n    using value_type = T;\n\n    static constexpr\
    \ T operation(T a, T b) {\n      return std::max(a, b);\n    }\n\n    static constexpr\
    \ T identity() {\n      return identity_;\n    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid\
    \ {\n\n  template < typename T >\n  class RangeChmaxQueryMonoid {\n    static\
    \ constexpr T identity_{std::numeric_limits< T >::min()};\n\n   public:\n    using\
    \ value_type = T;\n\n    static constexpr T operation(T a, T b) {\n      return\
    \ std::max(a, b);\n    }\n\n    static constexpr T identity() {\n      return\
    \ identity_;\n    }\n  };\n\n} // namespace luz::monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/operator-structure-chmax.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-chmax-query-solver.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc179_f/range-chmax.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/operator-structure-chmax.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/operator-structure-chmax.hpp
- /library/src/data-structure/segment-tree/presets/monoid/operator-structure-chmax.hpp.html
title: src/data-structure/segment-tree/presets/monoid/operator-structure-chmax.hpp
---
