---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':question:'
    path: src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
    title: "\u4E00\u70B9\u66F4\u65B0+\u533A\u9593\u53D6\u5F97 \u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':question:'
    path: src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
    title: src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc298_f.test.cpp
    title: test/atcoder/abc298_f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp\"\
    \n\n#line 2 \"src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        ++i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rep(const usize f, const usize l)\
    \ noexcept\n        : f(std::min(f, l)),\n          l(l) {}\n    constexpr auto\
    \ begin() const noexcept {\n      return f;\n    }\n    constexpr auto end() const\
    \ noexcept {\n      return l;\n    }\n  };\n\n  struct rrep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        --i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rrep(const usize f, const usize l)\
    \ noexcept\n        : f(l - 1),\n          l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept {\n      return f;\n    }\n    constexpr auto end()\
    \ const noexcept {\n      return l;\n    }\n  };\n\n} // namespace luz\n#line\
    \ 5 \"src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp\"\
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
    \ luz\n#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp\"\
    \n\n#line 4 \"src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp\"\
    \n#include <limits>\n\nnamespace luz::monoid {\n\n  template < typename T >\n\
    \  class RangeMaximumQueryMonoid {\n\n    static constexpr T identity_{std::numeric_limits<\
    \ T >::min()};\n\n   public:\n    using value_type = T;\n\n    static constexpr\
    \ T operation(T a, T b) {\n      return std::max(a, b);\n    }\n\n    static constexpr\
    \ T identity() {\n      return identity_;\n    }\n  };\n\n} // namespace luz::monoid\n\
    #line 5 \"src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T >\n  using RangeMaximumQuerySolver\
    \ =\n      SegmentTree< monoid::RangeMaximumQueryMonoid< T > >;\n\n} // namespace\
    \ luz\n"
  code: "#pragma once\n\n#include \"src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp\"\
    \n#include \"src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T >\n  using RangeMaximumQuerySolver\
    \ =\n      SegmentTree< monoid::RangeMaximumQueryMonoid< T > >;\n\n} // namespace\
    \ luz\n"
  dependsOn:
  - src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc298_f.test.cpp
documentation_of: src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
layout: document
title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA solver\
  \ (Range Maximum Query Solver)"
---

数列に対する一点更新クエリと区間最大クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeMaximumQuerySolver< T >(usize n)
(2) RangeMaximumQuerySolver< T >(usize n, T v)
(3) RangeMaximumQuerySolver< T >(std::vector< T > vs)
```
