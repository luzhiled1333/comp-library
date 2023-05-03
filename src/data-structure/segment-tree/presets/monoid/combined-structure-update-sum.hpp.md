---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
    title: src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
    title: src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Update Range Sum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_i.test.cpp
    title: test/aoj/dsl_2_i.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T, T ID >\n  class RangeUpdateQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return b == ID ? a : b;\n    }\n\n    static constexpr T identity()\
    \ {\n      return ID;\n    }\n  };\n\n} // namespace luz::monoid\n#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T >\n  class RangeSumQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return a + b;\n    }\n\n    static constexpr T identity() {\n\
    \      return T();\n    }\n  };\n\n} // namespace luz::monoid\n#line 6 \"src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T, T ID >\n  class RangeUpdateRangeSumQueryMonoid\
    \ {\n\n    class node_type {\n      using F = node_type;\n\n     public:\n   \
    \   T value;\n      usize count;\n\n      node_type(): value(), count() {}\n \
    \     node_type(T v, usize c): value(v), count(c) {}\n\n      F operator+(const\
    \ F &b) {\n        return F(value + b.value, count + b.count);\n      }\n    };\n\
    \n    using V  = RangeSumQueryMonoid< node_type >;\n    using VT = typename V::value_type;\n\
    \    using O  = RangeUpdateQueryMonoid< T, ID >;\n    using OT = typename O::value_type;\n\
    \n   public:\n    using value_structure    = V;\n    using operator_structure\
    \ = O;\n\n    static constexpr VT operation(VT a, OT b) {\n      return b == ID\
    \ ? a : VT(b * a.count, a.count);\n    }\n  };\n\n} // namespace luz::monoid\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n#include\
    \ \"src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp\"\
    \n#include \"src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T, T ID >\n  class RangeUpdateRangeSumQueryMonoid\
    \ {\n\n    class node_type {\n      using F = node_type;\n\n     public:\n   \
    \   T value;\n      usize count;\n\n      node_type(): value(), count() {}\n \
    \     node_type(T v, usize c): value(v), count(c) {}\n\n      F operator+(const\
    \ F &b) {\n        return F(value + b.value, count + b.count);\n      }\n    };\n\
    \n    using V  = RangeSumQueryMonoid< node_type >;\n    using VT = typename V::value_type;\n\
    \    using O  = RangeUpdateQueryMonoid< T, ID >;\n    using OT = typename O::value_type;\n\
    \n   public:\n    using value_structure    = V;\n    using operator_structure\
    \ = O;\n\n    static constexpr VT operation(VT a, OT b) {\n      return b == ID\
    \ ? a : VT(b * a.count, a.count);\n    }\n  };\n\n} // namespace luz::monoid\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp
  - src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_i.test.cpp
documentation_of: src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
layout: document
redirect_from:
- /library/src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
- /library/src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp.html
title: src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp
---
