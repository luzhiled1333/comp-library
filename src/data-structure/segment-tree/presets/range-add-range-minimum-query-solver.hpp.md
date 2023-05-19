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
    path: src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
    title: src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp
    title: src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
    title: src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp
    title: "\u533A\u9593\u66F4\u65B0+\u533A\u9593\u53D6\u5F97 \u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728 (Lazy Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/bit-width.hpp
    title: "\u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
      \u6700\u5C0F\u306Ebit\u5E45 (bit_width)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/count-trailing-0s.hpp
    title: "\u6700\u4E0B\u4F4Dbit\u304B\u3089\u9023\u7D9A\u3059\u308B 0 \u306E\u6570\
      \ (counting trailing 0s, countr_zero)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_h/range-minimum.test.cpp
    title: test/aoj/dsl_2_h/range-minimum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp\"\
    \n\n#line 2 \"src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp\"\
    \n\n#line 2 \"src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T >\n  class RangeAddQueryMonoid\
    \ {\n\n   public:\n    using value_type = T;\n\n    static constexpr T operation(T\
    \ a, T b) {\n      return a + b;\n    }\n\n    static constexpr T identity() {\n\
    \      return T();\n    }\n  };\n\n} // namespace luz::monoid\n#line 2 \"src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n\nnamespace luz::monoid {\n\n  template\
    \ < typename T >\n  class RangeMinimumQueryMonoid {\n\n    static constexpr T\
    \ identity_{std::numeric_limits< T >::max()};\n\n   public:\n    using value_type\
    \ = T;\n\n    static constexpr T operation(T a, T b) {\n      return std::min(a,\
    \ b);\n    }\n\n    static constexpr T identity() {\n      return identity_;\n\
    \    }\n  };\n\n} // namespace luz::monoid\n#line 5 \"src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp\"\
    \n\nnamespace luz::monoid {\n\n  template < typename T >\n  class RangeAddRangeMinimumQueryMonoid\
    \ {\n    using V  = RangeMinimumQueryMonoid< T >;\n    using VT = typename V::value_type;\n\
    \    using O  = RangeAddQueryMonoid< T >;\n    using OT = typename O::value_type;\n\
    \n   public:\n    using value_structure    = V;\n    using operator_structure\
    \ = O;\n\n    static constexpr T operation(VT a, OT b) {\n      return a + b;\n\
    \    }\n  };\n\n} // namespace luz::monoid\n#line 2 \"src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#line 6 \"\
    src/cpp-template/header/rep.hpp\"\n\nnamespace luz {\n\n  struct rep {\n    struct\
    \ itr {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n\
    \      void operator++() noexcept {\n        ++i;\n      }\n      constexpr usize\
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
    \ 2 \"src/utility/bit/bit-width.hpp\"\n\n#line 2 \"src/utility/bit/popcount.hpp\"\
    \n\n#line 4 \"src/utility/bit/popcount.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus <= 201703L);\n\n\
    #ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\n    x -= (x >>\
    \ 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);\n\
    \    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n    return x * 0x0101010101010101 >>\
    \ 56 & 0x7f;\n  }\n\n} // namespace luz\n#line 4 \"src/utility/bit/bit-width.hpp\"\
    \n\n#line 6 \"src/utility/bit/bit-width.hpp\"\n\nnamespace luz {\n\n  usize bit_width(u64\
    \ x) {\n    assert(__cplusplus <= 201703L);\n\n    if (x == 0) {\n      return\
    \ 0;\n    }\n\n#ifdef __GNUC__\n    return 64 - __builtin_clzll(x);\n#endif\n\n\
    \    x |= x >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >> 8;\n    x\
    \ |= x >> 16;\n    x |= x >> 32;\n    return popcount(x);\n  }\n\n} // namespace\
    \ luz\n#line 2 \"src/utility/bit/count-trailing-0s.hpp\"\n\n#line 4 \"src/utility/bit/count-trailing-0s.hpp\"\
    \n\n#line 6 \"src/utility/bit/count-trailing-0s.hpp\"\n\nnamespace luz {\n\n \
    \ usize countr_zero(u64 x) {\n    assert(__cplusplus <= 201703L);\n\n    if (x\
    \ == 0) {\n      return 64;\n    }\n\n#ifdef __GNUC__\n    return __builtin_ctzll(x);\n\
    #endif\n\n    return popcount((x & -x) - 1);\n  }\n\n} // namespace luz\n#line\
    \ 7 \"src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp\"\
    \n\n#line 9 \"src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp\"\
    \n#include <vector>\n\nnamespace luz {\n\n  template < class combined_structure\
    \ >\n  class RangeMappingRangeFoldSegmentTree {\n    using C  = combined_structure;\n\
    \    using V  = typename C::value_structure;\n    using VT = typename V::value_type;\n\
    \    using O  = typename C::operator_structure;\n    using OT = typename O::value_type;\n\
    \n    class node_type {\n     public:\n      VT value;\n      OT lazy;\n\n   \
    \   node_type(const VT value_, const OT lazy_)\n          : value(value_),\n \
    \           lazy(lazy_) {}\n\n      VT get() {\n        return C::operation(value,\
    \ lazy);\n      }\n    };\n\n    std::vector< node_type > tree;\n\n    void evaluate_lazy(OT\
    \ &x, const OT &y) {\n      x = O::operation(x, y);\n    }\n\n    void recalc(usize\
    \ index) {\n      tree[index].value = V::operation(tree[index << 1 | 0].get(),\n\
    \                                       tree[index << 1 | 1].get());\n    }\n\n\
    \    void recalc_bound(usize index) {\n      if (index == 0) return;\n\n     \
    \ const usize l = countr_zero(index) + 1;\n      const usize r = bit_width(index);\n\
    \      for (usize i: rep(l, r)) {\n        recalc(index >> i);\n      }\n    }\n\
    \n    void propagate(const usize index) {\n      evaluate_lazy(tree[index << 1\
    \ | 0].lazy, tree[index].lazy);\n      evaluate_lazy(tree[index << 1 | 1].lazy,\
    \ tree[index].lazy);\n      tree[index].lazy = O::identity();\n    }\n\n    void\
    \ propagate_bound(const usize index) {\n      if (index == 0) return;\n\n    \
    \  const usize l = countr_zero(index) + 1;\n      const usize r = bit_width(index);\n\
    \      for (usize i: rrep(l, r)) {\n        propagate(index >> i);\n      }\n\
    \    }\n\n   public:\n    using value_type = VT;\n\n    RangeMappingRangeFoldSegmentTree()\
    \ = default;\n\n    explicit RangeMappingRangeFoldSegmentTree(const usize n)\n\
    \        : tree(n * 2, node_type(V::identity(), O::identity())) {}\n\n    explicit\
    \ RangeMappingRangeFoldSegmentTree(const usize n,\n                          \
    \                    const VT v)\n        : RangeMappingRangeFoldSegmentTree(n)\
    \ {\n      build(std::vector< VT >(n, v));\n    }\n\n    explicit RangeMappingRangeFoldSegmentTree(\n\
    \        const std::vector< VT > &vs)\n        : RangeMappingRangeFoldSegmentTree(vs.size())\
    \ {\n      build(vs);\n    }\n\n    void build(const std::vector< VT > &vs) {\n\
    \      usize n = vs.size();\n      assert(2 * n == tree.size());\n      for (usize\
    \ i: rep(0, n)) {\n        tree[i + n] = node_type(vs[i], O::identity());\n  \
    \    }\n      for (usize index: rrep(1, n)) {\n        recalc(index);\n      }\n\
    \    }\n\n    usize size() const {\n      return tree.size() / 2;\n    }\n\n \
    \   void set(usize index, const VT x) {\n      assert(index < size());\n     \
    \ index += size();\n\n      const usize l = 1;\n      const usize r = bit_width(index);\n\
    \      for (usize i: rrep(l, r)) {\n        propagate(index >> i);\n      }\n\n\
    \      tree[index] = node_type(x, O::identity());\n\n      for (usize i: rep(l,\
    \ r)) {\n        recalc(index >> i);\n      }\n    }\n\n    void apply(usize index,\
    \ const OT &x) {\n      return apply(index, index + 1, x);\n    }\n\n    void\
    \ apply(usize first, usize last, const OT &x) {\n      assert(first <= last);\n\
    \      assert(last <= size());\n\n      first += size();\n      last += size();\n\
    \n      propagate_bound(first);\n      propagate_bound(last);\n\n      const usize\
    \ c_first = first;\n      const usize c_last  = last;\n\n      while (first !=\
    \ last) {\n        if (first & 1) {\n          evaluate_lazy(tree[first].lazy,\
    \ x);\n          first += 1;\n        }\n        first >>= 1;\n\n        if (last\
    \ & 1) {\n          last -= 1;\n          evaluate_lazy(tree[last].lazy, x);\n\
    \        }\n        last >>= 1;\n      }\n\n      recalc_bound(c_first);\n   \
    \   recalc_bound(c_last);\n    }\n\n    VT fold(usize index) {\n      return fold(index,\
    \ index + 1);\n    }\n\n    VT fold(usize first, usize last) {\n      assert(first\
    \ <= last);\n      assert(last <= size());\n\n      first += size();\n      last\
    \ += size();\n\n      propagate_bound(first);\n      recalc_bound(first);\n  \
    \    propagate_bound(last);\n      recalc_bound(last);\n\n      VT fold_l = V::identity();\n\
    \      VT fold_r = V::identity();\n\n      while (first != last) {\n        if\
    \ (first & 1) {\n          fold_l = V::operation(fold_l, tree[first].get());\n\
    \          first += 1;\n        }\n        first >>= 1;\n\n        if (last &\
    \ 1) {\n          last -= 1;\n          fold_r = V::operation(tree[last].get(),\
    \ fold_r);\n        }\n        last >>= 1;\n      }\n\n      return V::operation(fold_l,\
    \ fold_r);\n    }\n\n    VT fold_all() {\n      return (size() ? tree[1].get()\
    \ : V::identity());\n    }\n  };\n\n  template < class combined_structure >\n\
    \  using LazySegmentTree =\n      RangeMappingRangeFoldSegmentTree< combined_structure\
    \ >;\n\n} // namespace luz\n#line 5 \"src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T >\n  using RangeAddRangeMinimumQuerySolver\
    \ =\n      LazySegmentTree< monoid::RangeAddRangeMinimumQueryMonoid< T > >;\n\n\
    } // namespace luz\n"
  code: "#pragma once\n\n#include \"src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp\"\
    \n#include \"src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T >\n  using RangeAddRangeMinimumQuerySolver\
    \ =\n      LazySegmentTree< monoid::RangeAddRangeMinimumQueryMonoid< T > >;\n\n\
    } // namespace luz\n"
  dependsOn:
  - src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp
  - src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp
  - src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp
  - src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/utility/bit/bit-width.hpp
  - src/utility/bit/popcount.hpp
  - src/utility/bit/count-trailing-0s.hpp
  isVerificationFile: false
  path: src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
  requiredBy: []
  timestamp: '2023-05-03 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_h/range-minimum.test.cpp
documentation_of: src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
layout: document
title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA solver\
  \ (Range Add Range Minimum Query Solver)"
---

数列に対する区間加算クエリと区間最小クエリを処理するデータ構造。

内部ではセグメント木を用いているため、詳細な仕様などはそちらのドキュメントに追従する。

## コンストラクタ
```
(1) RangeAddRangeMinimumQuerySolver< T >(usize n)
(2) RangeAddRangeMinimumQuerySolver< T >(usize n, T v)
(3) RangeAddRangeMinimumQuerySolver< T >(std::vector< T > vs)
```

## note
初期化していない状態で加算をするとオーバーフローを引き起こすことがある。

そのようなことがしたい場合は、`C::operation` でオーバーフローを検出するようなコードを書くとよい。

```cpp
static constexpr T operation(VT a, OT b) {
  if (std::numeric_limits< VT >::min() - a > b) {
    return T::identity;
  }
  return a + b;
}
```