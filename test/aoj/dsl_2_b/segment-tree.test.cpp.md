---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
    title: "\u4E00\u70B9\u66F4\u65B0+\u533A\u9593\u53D6\u5F97 \u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
    title: src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-sum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Sum Query Solver)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/dsl_2_b/segment-tree.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\n\
    namespace luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       ++i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
    \ l)),\n          l(l) {}\n    constexpr auto begin() const noexcept {\n     \
    \ return f;\n    }\n    constexpr auto end() const noexcept {\n      return l;\n\
    \    }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       --i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rrep(const usize f, const usize l) noexcept\n        : f(l - 1),\n\
    \          l(std::min(f, l) - 1) {}\n    constexpr auto begin() const noexcept\
    \ {\n      return f;\n    }\n    constexpr auto end() const noexcept {\n     \
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/data-structure/segment-tree/presets/range-sum-query-solver.hpp\"\
    \n\n#line 2 \"src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp\"\
    \n\n#line 5 \"src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < class\
    \ value_structure >\n  class PointMappingRangeFoldSegmentTree {\n    using V \
    \ = value_structure;\n    using VT = typename V::value_type;\n\n    std::vector<\
    \ VT > tree;\n\n    void evaluate(usize index) {\n      tree[index] =\n      \
    \    V::operation(tree[index << 1 | 0], tree[index << 1 | 1]);\n    }\n\n   public:\n\
    \    using value_type = VT;\n\n    PointMappingRangeFoldSegmentTree() = default;\n\
    \n    explicit PointMappingRangeFoldSegmentTree(const usize n)\n        : tree(n\
    \ * 2, V::identity()) {}\n\n    explicit PointMappingRangeFoldSegmentTree(const\
    \ usize n, VT v)\n        : PointMappingRangeFoldSegmentTree(n) {\n      build(std::vector<\
    \ VT >(n, v));\n    }\n\n    explicit PointMappingRangeFoldSegmentTree(\n    \
    \    const std::vector< VT > &vs)\n        : PointMappingRangeFoldSegmentTree(vs.size())\
    \ {\n      build(vs);\n    }\n\n    void build(const std::vector< VT > &vs) {\n\
    \      usize n = vs.size();\n      assert(2 * n == tree.size());\n      std::copy(vs.begin(),\
    \ vs.end(), tree.begin() + n);\n      for (usize index: rrep(1, n)) {\n      \
    \  evaluate(index);\n      }\n    }\n\n    usize size() const {\n      return\
    \ tree.size() / 2;\n    }\n\n    void set(usize index, const VT x) {\n      assert(index\
    \ < size());\n      index += size();\n      tree[index] = x;\n\n      while (index\
    \ != 1) {\n        index >>= 1;\n        evaluate(index);\n      }\n    }\n\n\
    \    VT fold(usize index) const {\n      assert(index < size());\n\n      return\
    \ tree[index + size()];\n    }\n\n    VT fold(usize first, usize last) const {\n\
    \      assert(first <= last);\n      assert(last <= size());\n\n      first +=\
    \ size();\n      last += size();\n\n      VT fold_l = V::identity();\n      VT\
    \ fold_r = V::identity();\n\n      while (first != last) {\n        if (first\
    \ & 1) {\n          fold_l = V::operation(fold_l, tree[first]);\n          first\
    \ += 1;\n        }\n        first >>= 1;\n\n        if (last & 1) {\n        \
    \  last -= 1;\n          fold_r = V::operation(tree[last], fold_r);\n        }\n\
    \        last >>= 1;\n      }\n\n      return V::operation(fold_l, fold_r);\n\
    \    }\n\n    VT fold_all() const {\n      return (size() ? tree[1] : V::identity());\n\
    \    }\n  };\n\n  template < class value_structure >\n  using SegmentTree =\n\
    \      PointMappingRangeFoldSegmentTree< value_structure >;\n\n} // namespace\
    \ luz\n#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T >\n  class RangeSumQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return a + b;\n    }\n\n    static constexpr T identity() {\n\
    \      return T();\n    }\n  };\n\n} // namespace luz::monoid\n#line 5 \"src/data-structure/segment-tree/presets/range-sum-query-solver.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T >\n  using RangeSumQuerySolver\
    \ =\n      SegmentTree< monoid::RangeSumQueryMonoid< T > >;\n\n} // namespace\
    \ luz\n#line 6 \"test/aoj/dsl_2_b/segment-tree.test.cpp\"\n\n#include <iostream>\n\
    \nnamespace luz {\n\n  void main_() {\n    usize n, q;\n    std::cin >> n >> q;\n\
    \n    RangeSumQuerySolver< u32 > seg(n);\n    for ([[maybe_unused]] usize _: rep(0,\
    \ q)) {\n      usize com, x, y;\n      std::cin >> com >> x >> y;\n\n      if\
    \ (not com) {\n        seg.set(x - 1, y + seg.fold(x - 1));\n      } else {\n\
    \        std::cout << seg.fold(x - 1, y) << std::endl;\n      }\n    }\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/data-structure/segment-tree/presets/range-sum-query-solver.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n, q;\n\
    \    std::cin >> n >> q;\n\n    RangeSumQuerySolver< u32 > seg(n);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, q)) {\n      usize com, x, y;\n      std::cin >> com >> x >>\
    \ y;\n\n      if (not com) {\n        seg.set(x - 1, y + seg.fold(x - 1));\n \
    \     } else {\n        std::cout << seg.fold(x - 1, y) << std::endl;\n      }\n\
    \    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/data-structure/segment-tree/presets/range-sum-query-solver.hpp
  - src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
  - src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp
  isVerificationFile: true
  path: test/aoj/dsl_2_b/segment-tree.test.cpp
  requiredBy: []
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_2_b/segment-tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_b/segment-tree.test.cpp
- /verify/test/aoj/dsl_2_b/segment-tree.test.cpp.html
title: test/aoj/dsl_2_b/segment-tree.test.cpp
---
