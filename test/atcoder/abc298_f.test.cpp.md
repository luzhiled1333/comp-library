---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-max.hpp
    title: chmax
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
    path: src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
    title: "\u4E00\u70B9\u66F4\u65B0+\u533A\u9593\u53D6\u5F97 \u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
    title: src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
    title: "\u4E00\u70B9\u66F4\u65B0 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/sequence/compression.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc298/tasks/abc298_f
    links:
    - https://atcoder.jp/contests/abc298/tasks/abc298_f
  bundledCode: "#line 1 \"test/atcoder/abc298_f.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc298/tasks/abc298_f\n\n#line 2 \"src/cpp-template/header/change-max.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T1, typename T2 >\n  inline bool\
    \ chmax(T1 &a, T2 b) {\n    return a < b and (a = b, true);\n  }\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\
    \nnamespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr {\n      usize\
    \ i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n      void operator++()\
    \ noexcept {\n        ++i;\n      }\n      constexpr usize operator*() const noexcept\
    \ {\n        return i;\n      }\n      constexpr bool operator!=(const itr x)\
    \ const noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f,\
    \ l;\n    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp\"\
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
    \ luz\n#line 2 \"src/sequence/compression.hpp\"\n\n#line 5 \"src/sequence/compression.hpp\"\
    \n\n#line 8 \"src/sequence/compression.hpp\"\n#include <functional>\n#line 10\
    \ \"src/sequence/compression.hpp\"\n\nnamespace luz {\n\n  template < class T,\
    \ class Compare = std::less< T > >\n  class Compressor {\n    std::vector< T >\
    \ vs;\n    std::vector< T > zip;\n    std::vector< usize > ziped_vs;\n\n   public:\n\
    \    explicit Compressor(std::vector< T > vs)\n        : vs(vs),\n          zip(vs),\n\
    \          ziped_vs(vs.size()) {\n      std::sort(zip.begin(), zip.end(), Compare());\n\
    \      zip.erase(std::unique(zip.begin(), zip.end()), zip.end());\n      for (usize\
    \ i: rep(0, vs.size())) {\n        ziped_vs[i] = compress(vs[i]);\n      }\n \
    \   }\n\n    std::vector< usize > compressed_vector() const {\n      return ziped_vs;\n\
    \    }\n\n    usize compress(T v) const {\n      auto iter = std::lower_bound(zip.begin(),\
    \ zip.end(), v);\n      assert(*iter == v);\n      return iter - zip.begin();\n\
    \    }\n\n    T expand(usize i) const {\n      assert(i < zip.size());\n     \
    \ return zip[i];\n    }\n  };\n\n} // namespace luz\n#line 9 \"test/atcoder/abc298_f.test.cpp\"\
    \n\n#line 11 \"test/atcoder/abc298_f.test.cpp\"\n#include <iostream>\n#line 13\
    \ \"test/atcoder/abc298_f.test.cpp\"\n\nnamespace luz {\n\n  void main_() {\n\
    \    usize n;\n    std::cin >> n;\n\n    std::vector< usize > rs, cs;\n    std::vector<\
    \ i32 > xs(n);\n\n    { // input and compression\n      std::vector< u32 > as(n),\
    \ bs(n);\n      for (usize i: rep(0, n)) {\n        std::cin >> as[i] >> bs[i]\
    \ >> xs[i];\n      }\n\n      Compressor< u32 > r_cp(as), c_cp(bs);\n      rs\
    \ = r_cp.compressed_vector();\n      cs = c_cp.compressed_vector();\n    }\n\n\
    \    std::vector< std::tuple< usize, usize, i32 > > qs(n);\n    for (usize i:\
    \ rep(0, n)) {\n      qs[i] = {rs[i], cs[i], xs[i]};\n    }\n\n    std::sort(qs.begin(),\
    \ qs.end());\n\n    RangeMaximumQuerySolver< i64 > seg(n, 0);\n    auto seg_add\
    \ = [&](usize idx, i64 x) {\n      seg.set(idx, seg.fold(idx) + x);\n    };\n\n\
    \    for (usize i: rep(0, n)) {\n      seg_add(cs[i], xs[i]);\n    }\n\n    usize\
    \ m = *max_element(rs.begin(), rs.end()) + 1;\n\n    i64 ans   = 0;\n    usize\
    \ idx = 0;\n\n    for (usize r: rep(0, m)) {\n      usize prev_idx = idx;\n\n\
    \      i64 max = 0;\n      while (idx < qs.size() and std::get< 0 >(qs[idx]) ==\
    \ r) {\n        i32 x = std::get< 2 >(qs[idx]);\n        max += x;\n\n       \
    \ i32 c = std::get< 1 >(qs[idx]);\n        seg_add(c, -x);\n\n        idx++;\n\
    \      }\n\n      max += seg.fold_all();\n      chmax(ans, max);\n\n      for\
    \ (usize i: rep(prev_idx, idx)) {\n        auto [_, c, x] = qs[i];\n        seg_add(c,\
    \ x);\n      }\n    }\n\n    std::cout << ans << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc298/tasks/abc298_f\n\
    \n#include \"src/cpp-template/header/change-max.hpp\"\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp\"\
    \n#include \"src/sequence/compression.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace luz {\n\n  void main_() {\n    usize\
    \ n;\n    std::cin >> n;\n\n    std::vector< usize > rs, cs;\n    std::vector<\
    \ i32 > xs(n);\n\n    { // input and compression\n      std::vector< u32 > as(n),\
    \ bs(n);\n      for (usize i: rep(0, n)) {\n        std::cin >> as[i] >> bs[i]\
    \ >> xs[i];\n      }\n\n      Compressor< u32 > r_cp(as), c_cp(bs);\n      rs\
    \ = r_cp.compressed_vector();\n      cs = c_cp.compressed_vector();\n    }\n\n\
    \    std::vector< std::tuple< usize, usize, i32 > > qs(n);\n    for (usize i:\
    \ rep(0, n)) {\n      qs[i] = {rs[i], cs[i], xs[i]};\n    }\n\n    std::sort(qs.begin(),\
    \ qs.end());\n\n    RangeMaximumQuerySolver< i64 > seg(n, 0);\n    auto seg_add\
    \ = [&](usize idx, i64 x) {\n      seg.set(idx, seg.fold(idx) + x);\n    };\n\n\
    \    for (usize i: rep(0, n)) {\n      seg_add(cs[i], xs[i]);\n    }\n\n    usize\
    \ m = *max_element(rs.begin(), rs.end()) + 1;\n\n    i64 ans   = 0;\n    usize\
    \ idx = 0;\n\n    for (usize r: rep(0, m)) {\n      usize prev_idx = idx;\n\n\
    \      i64 max = 0;\n      while (idx < qs.size() and std::get< 0 >(qs[idx]) ==\
    \ r) {\n        i32 x = std::get< 2 >(qs[idx]);\n        max += x;\n\n       \
    \ i32 c = std::get< 1 >(qs[idx]);\n        seg_add(c, -x);\n\n        idx++;\n\
    \      }\n\n      max += seg.fold_all();\n      chmax(ans, max);\n\n      for\
    \ (usize i: rep(prev_idx, idx)) {\n        auto [_, c, x] = qs[i];\n        seg_add(c,\
    \ x);\n      }\n    }\n\n    std::cout << ans << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/change-max.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp
  - src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp
  - src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp
  - src/sequence/compression.hpp
  isVerificationFile: true
  path: test/atcoder/abc298_f.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc298_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc298_f.test.cpp
- /verify/test/atcoder/abc298_f.test.cpp.html
title: test/atcoder/abc298_f.test.cpp
---
