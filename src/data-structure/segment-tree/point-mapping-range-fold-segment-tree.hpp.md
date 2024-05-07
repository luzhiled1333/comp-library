---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-minimum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Minimum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-sum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Sum Query Solver)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_a.test.cpp
    title: test/aoj/dsl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_b/segment-tree.test.cpp
    title: test/aoj/dsl_2_b/segment-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc298_f.test.cpp
    title: test/atcoder/abc298_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/data-structure/segment-tree/point-mapping-range-fold-segment-tree.test.cpp
    title: unit-test/data-structure/segment-tree/point-mapping-range-fold-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp\"\
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
    \ luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz {\n\n  template < class value_structure >\n  class PointMappingRangeFoldSegmentTree\
    \ {\n    using V  = value_structure;\n    using VT = typename V::value_type;\n\
    \n    std::vector< VT > tree;\n\n    void evaluate(usize index) {\n      tree[index]\
    \ =\n          V::operation(tree[index << 1 | 0], tree[index << 1 | 1]);\n   \
    \ }\n\n   public:\n    using value_type = VT;\n\n    PointMappingRangeFoldSegmentTree()\
    \ = default;\n\n    explicit PointMappingRangeFoldSegmentTree(const usize n)\n\
    \        : tree(n * 2, V::identity()) {}\n\n    explicit PointMappingRangeFoldSegmentTree(const\
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
    \ luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
  requiredBy:
  - src/data-structure/segment-tree/presets/range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-sum-query-solver.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/data-structure/segment-tree/point-mapping-range-fold-segment-tree.test.cpp
  - test/atcoder/abc298_f.test.cpp
  - test/aoj/dsl_2_a.test.cpp
  - test/aoj/dsl_2_b/segment-tree.test.cpp
documentation_of: src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
layout: document
title: "\u4E00\u70B9\u66F4\u65B0+\u533A\u9593\u53D6\u5F97 \u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---

## Appendix
[Segment Tree の細かい仕様について]({{ site.baseurl }}/appendix-segment-tree)

## コンストラクタ
`PointMappingRangeFoldSegmentTree` のエイリアスとして `SegmentTree` を提供している。

```
(1) SegmentTree< V >(usize n)
(2) SegmentTree< V >(usize n, VT v)
(3) SegmentTree< V >(vector< VT > vs)
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
void build(vector< VT > vs)
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
void set(usize i, VT x)
```

$a_i \leftarrow x$ で更新する。

### 計算量
- $O(\log(n))$

## fold
```
(1) VT fold(usize i) const
(2) VT fold(usize l, usize r) const
(3) VT fold_all() const
```

1. $a_i$ を返す。
2. $a_l \cdot a_{l+1} \cdot \dotsm \cdot a_{r-1}$ を返す。$l = r$ のとき `V::identity()` が返る。
3. $a_0 \cdot a_1 \cdot \dotsm \cdot a_{n-1}$ を返す。

### 制約
1. $0 \leq i < n$
2. $0 \leq l \leq r \leq n$

### 計算量
- (1): $O(1)$
- (2):
  - $O(\log(n))$
  - $d = r - l$ として $O(\log(d))$
- (3): $O(1)$

## max_right
気が向いたらそのうち実装する

## min_left
気が向いたらそのうち実装する2
