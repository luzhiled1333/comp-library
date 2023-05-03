---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
    title: src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
    title: src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Update Range Minimum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_f/range-minimum.test.cpp
    title: test/aoj/dsl_2_f/range-minimum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp\"\
    \n\n#line 2 \"src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T, T ID >\n  class RangeUpdateQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return b == ID ? a : b;\n    }\n\n    static constexpr T identity()\
    \ {\n      return ID;\n    }\n  };\n\n} // namespace luz::monoid\n#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid {\n\n  template\
    \ < typename T >\n  class RangeMinimumQueryMonoid {\n\n    static constexpr T\
    \ identity_{std::numeric_limits< T >::max()};\n\n   public:\n    using value_type\
    \ = T;\n\n    static constexpr T operation(T a, T b) {\n      return std::min(a,\
    \ b);\n    }\n\n    static constexpr T identity() {\n      return identity_;\n\
    \    }\n  };\n\n} // namespace luz::monoid\n#line 5 \"src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T, T ID >\n  class RangeUpdateRangeMinimumQueryMonoid\
    \ {\n    using V  = RangeMinimumQueryMonoid< T >;\n    using VT = typename V::value_type;\n\
    \    using O  = RangeUpdateQueryMonoid< T, ID >;\n    using OT = typename O::value_type;\n\
    \n   public:\n    using value_structure    = V;\n    using operator_structure\
    \ = O;\n\n    static constexpr T operation(VT a, OT b) {\n      return b == ID\
    \ ? a : b;\n    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\n#include \"src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp\"\
    \n#include \"src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T, T ID >\n  class RangeUpdateRangeMinimumQueryMonoid\
    \ {\n    using V  = RangeMinimumQueryMonoid< T >;\n    using VT = typename V::value_type;\n\
    \    using O  = RangeUpdateQueryMonoid< T, ID >;\n    using OT = typename O::value_type;\n\
    \n   public:\n    using value_structure    = V;\n    using operator_structure\
    \ = O;\n\n    static constexpr T operation(VT a, OT b) {\n      return b == ID\
    \ ? a : b;\n    }\n  };\n\n} // namespace luz::monoid\n"
  dependsOn:
  - src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
  - src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_f/range-minimum.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
- /library/src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp.html
title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp
---
