---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA solver (Range Add Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-chmax-query-solver.hpp
    title: "\u533A\u9593 chmax \u30AF\u30A8\u30EA solver (Range ChangeMax Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-chmin-query-solver.hpp
    title: "\u533A\u9593 chmin \u30AF\u30A8\u30EA solver (Range ChangeMin Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0\u30AF\u30A8\u30EA solver (Range Update Query\
      \ Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_d.test.cpp
    title: test/aoj/dsl_2_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_e.test.cpp
    title: test/aoj/dsl_2_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_f/range-chmax.test.cpp
    title: test/atcoder/abc179_f/range-chmax.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_f/range-chmin.test.cpp
    title: test/atcoder/abc179_f/range-chmin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp\"\
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
    \ 2 \"src/utility/bit/bit-width.hpp\"\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/utility/bit/popcount.hpp\"\n\n#line 5 \"src/utility/bit/popcount.hpp\"\
    \n\n#include <cassert>\n\nnamespace luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus\
    \ <= 201703L);\n\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\
    \n    x -= (x >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) +\
    \ ((x >> 2) & 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n\
    #line 6 \"src/utility/bit/bit-width.hpp\"\n\n#line 8 \"src/utility/bit/bit-width.hpp\"\
    \n\nnamespace luz {\n\n  usize bit_width(u64 x) {\n    assert(__cplusplus <= 201703L);\n\
    \n    if (x == 0) {\n      return 0;\n    }\n\n#ifdef __GNUC__\n    return 64\
    \ - __builtin_clzll(x);\n#endif\n\n    x |= x >> 1;\n    x |= x >> 2;\n    x |=\
    \ x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n    return\
    \ popcount(x);\n  }\n\n} // namespace luz\n#line 2 \"src/utility/bit/count-trailing-0s.hpp\"\
    \n\n#line 6 \"src/utility/bit/count-trailing-0s.hpp\"\n\n#line 8 \"src/utility/bit/count-trailing-0s.hpp\"\
    \n\nnamespace luz {\n\n  usize countr_zero(u64 x) {\n    assert(__cplusplus <=\
    \ 201703L);\n\n    if (x == 0) {\n      return 64;\n    }\n\n#ifdef __GNUC__\n\
    \    return __builtin_ctzll(x);\n#endif\n\n    return popcount((x & -x) - 1);\n\
    \  }\n\n} // namespace luz\n#line 7 \"src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp\"\
    \n\n#line 9 \"src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp\"\
    \n#include <vector>\n\nnamespace luz {\n\n  template < class operator_structure\
    \ >\n  class RangeMappingPointFoldSegmentTree {\n    using O  = operator_structure;\n\
    \    using OT = typename O::value_type;\n\n    std::vector< OT > tree;\n\n   \
    \ void evaluate_lazy(OT &x, const OT &y) {\n      x = O::operation(x, y);\n  \
    \  }\n\n    void propagate(const usize index) {\n      evaluate_lazy(tree[index\
    \ << 1 | 0], tree[index]);\n      evaluate_lazy(tree[index << 1 | 1], tree[index]);\n\
    \      tree[index] = O::identity();\n    }\n\n    void propagate_bound(const usize\
    \ index) {\n      if (index == 0) return;\n\n      const usize l = countr_zero(index)\
    \ + 1;\n      const usize r = bit_width(index);\n      for (usize i: rrep(l, r))\
    \ {\n        propagate(index >> i);\n      }\n    }\n\n   public:\n    using value_type\
    \ = OT;\n\n    RangeMappingPointFoldSegmentTree() = default;\n\n    explicit RangeMappingPointFoldSegmentTree(const\
    \ usize n)\n        : tree(n * 2, O::identity()) {}\n\n    explicit RangeMappingPointFoldSegmentTree(const\
    \ usize n, OT v)\n        : RangeMappingPointFoldSegmentTree(n) {\n      build(std::vector<\
    \ OT >(n, v));\n    }\n\n    explicit RangeMappingPointFoldSegmentTree(\n    \
    \    const std::vector< OT > &vs)\n        : RangeMappingPointFoldSegmentTree(vs.size())\
    \ {\n      build(vs);\n    }\n\n    void build(const std::vector< OT > &vs) {\n\
    \      for (usize i: rep(0, vs.size())) {\n        tree[i + size()] = vs[i];\n\
    \      }\n    }\n\n    usize size() const {\n      return tree.size() / 2;\n \
    \   }\n\n    void set(usize index, const OT x) {\n      assert(index < size());\n\
    \      index += size();\n\n      const usize l = 1;\n      const usize r = bit_width(index);\n\
    \      for (usize i: rrep(l, r)) {\n        propagate(index >> i);\n      }\n\n\
    \      tree[index] = node_type(x, O::identity());\n    }\n\n    void apply(usize\
    \ index, const OT &x) {\n      return apply(index, index + 1, x);\n    }\n\n \
    \   void apply(usize first, usize last, const OT &x) {\n      assert(first <=\
    \ last);\n      assert(last <= size());\n\n      first += size();\n      last\
    \ += size();\n\n      propagate_bound(first);\n      propagate_bound(last);\n\n\
    \      while (first != last) {\n        if (first & 1) {\n          evaluate_lazy(tree[first],\
    \ x);\n          first += 1;\n        }\n        first >>= 1;\n\n        if (last\
    \ & 1) {\n          last -= 1;\n          evaluate_lazy(tree[last], x);\n    \
    \    }\n        last >>= 1;\n      }\n    }\n\n    OT fold(usize index) {\n  \
    \    assert(index < size());\n\n      index += size();\n\n      OT result = tree[index];\n\
    \      while (index != 1) {\n        index >>= 1;\n        evaluate_lazy(result,\
    \ tree[index]);\n      }\n      return result;\n    }\n  };\n\n  template < class\
    \ operator_structure >\n  using DualSegmentTree =\n      RangeMappingPointFoldSegmentTree<\
    \ operator_structure >;\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n#include \"src/utility/bit/bit-width.hpp\"\
    \n#include \"src/utility/bit/count-trailing-0s.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < class operator_structure >\n  class\
    \ RangeMappingPointFoldSegmentTree {\n    using O  = operator_structure;\n   \
    \ using OT = typename O::value_type;\n\n    std::vector< OT > tree;\n\n    void\
    \ evaluate_lazy(OT &x, const OT &y) {\n      x = O::operation(x, y);\n    }\n\n\
    \    void propagate(const usize index) {\n      evaluate_lazy(tree[index << 1\
    \ | 0], tree[index]);\n      evaluate_lazy(tree[index << 1 | 1], tree[index]);\n\
    \      tree[index] = O::identity();\n    }\n\n    void propagate_bound(const usize\
    \ index) {\n      if (index == 0) return;\n\n      const usize l = countr_zero(index)\
    \ + 1;\n      const usize r = bit_width(index);\n      for (usize i: rrep(l, r))\
    \ {\n        propagate(index >> i);\n      }\n    }\n\n   public:\n    using value_type\
    \ = OT;\n\n    RangeMappingPointFoldSegmentTree() = default;\n\n    explicit RangeMappingPointFoldSegmentTree(const\
    \ usize n)\n        : tree(n * 2, O::identity()) {}\n\n    explicit RangeMappingPointFoldSegmentTree(const\
    \ usize n, OT v)\n        : RangeMappingPointFoldSegmentTree(n) {\n      build(std::vector<\
    \ OT >(n, v));\n    }\n\n    explicit RangeMappingPointFoldSegmentTree(\n    \
    \    const std::vector< OT > &vs)\n        : RangeMappingPointFoldSegmentTree(vs.size())\
    \ {\n      build(vs);\n    }\n\n    void build(const std::vector< OT > &vs) {\n\
    \      for (usize i: rep(0, vs.size())) {\n        tree[i + size()] = vs[i];\n\
    \      }\n    }\n\n    usize size() const {\n      return tree.size() / 2;\n \
    \   }\n\n    void set(usize index, const OT x) {\n      assert(index < size());\n\
    \      index += size();\n\n      const usize l = 1;\n      const usize r = bit_width(index);\n\
    \      for (usize i: rrep(l, r)) {\n        propagate(index >> i);\n      }\n\n\
    \      tree[index] = node_type(x, O::identity());\n    }\n\n    void apply(usize\
    \ index, const OT &x) {\n      return apply(index, index + 1, x);\n    }\n\n \
    \   void apply(usize first, usize last, const OT &x) {\n      assert(first <=\
    \ last);\n      assert(last <= size());\n\n      first += size();\n      last\
    \ += size();\n\n      propagate_bound(first);\n      propagate_bound(last);\n\n\
    \      while (first != last) {\n        if (first & 1) {\n          evaluate_lazy(tree[first],\
    \ x);\n          first += 1;\n        }\n        first >>= 1;\n\n        if (last\
    \ & 1) {\n          last -= 1;\n          evaluate_lazy(tree[last], x);\n    \
    \    }\n        last >>= 1;\n      }\n    }\n\n    OT fold(usize index) {\n  \
    \    assert(index < size());\n\n      index += size();\n\n      OT result = tree[index];\n\
    \      while (index != 1) {\n        index >>= 1;\n        evaluate_lazy(result,\
    \ tree[index]);\n      }\n      return result;\n    }\n  };\n\n  template < class\
    \ operator_structure >\n  using DualSegmentTree =\n      RangeMappingPointFoldSegmentTree<\
    \ operator_structure >;\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/utility/bit/bit-width.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/utility/bit/popcount.hpp
  - src/utility/bit/count-trailing-0s.hpp
  isVerificationFile: false
  path: src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-add-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-chmin-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-chmax-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-query-solver.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_d.test.cpp
  - test/aoj/dsl_2_e.test.cpp
  - test/atcoder/abc179_f/range-chmax.test.cpp
  - test/atcoder/abc179_f/range-chmin.test.cpp
documentation_of: src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp
layout: document
title: "\u533A\u9593\u66F4\u65B0 + \u4E00\u70B9\u53D6\u5F97 \u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728 (Dual Segment Tree)"
---

## Appendix
[Segment Tree の細かい仕様について]({{ site.baseurl }}/appendix-segment-tree)

## コンストラクタ
`RangeMappingPointFoldSegmentTree` のエイリアスとして `DualSegmentTree` を提供している。

```
(1) DualSegmentTree< O >(usize n)
(2) DualSegmentTree< O >(usize n, OT v)
(3) DualSegmentTree< O >(std::vector< OT > vs)
```

1. 列 $a$ を長さ $n$ の列で初期化する。各要素の初期値は `V::identity()` となる。
2. 列 $a$ を長さ $n$ の列で初期化する。各要素の初期値は `v` となる。
3. 列 $a$ を `vs` で初期化する。

### 制約
- $0 \leq n$

### 計算量
- $O(n)$

## build
```
void build(vector< OT > vs)
```

列 $(a_0, a_1, \dots, a_{n-1})$ を `vs` で初期化して再構築する。

### 制約
- $n$ と `vs.size()` が一致すること。

### 計算量
- $O(n)$

## size
```
usize size() const
```

扱っている列 $(a_0, a_1, \dots, a_{n - 1})$ の長さ $n$ を返す。

### 計算量
- $O(1)$

## set
```
void set(usize i, OT x)
```

$a_i \leftarrow x$ で更新する。

### 制約
- $0 \leq i < n$

### 計算量
- $O(\log(n))$

## apply
```
(1) void apply(usize i, OT x)
(2) void apply(usize l, usize r, OT x)
```

1. $a_i \leftarrow f(a_i)$ で更新する。
2. 任意の $l \leq i < r$ について $a_i \leftarrow f(a_i)$ で更新する。

### 制約
1. $0 \leq i < n$
2. $0 \leq l \leq r \leq n$

### 計算量
- $O(\log(n))$

## fold
```
VT fold(usize i) const
```

$a_i$ を返す。

### 制約
- $0 \leq i < n$

### 計算量
- $O(\log(n))$
