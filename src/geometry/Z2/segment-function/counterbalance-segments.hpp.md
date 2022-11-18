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
    path: src/geometry/Z2/class/line.hpp
    title: src/geometry/Z2/class/line.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/segment.hpp
    title: src/geometry/Z2/class/segment.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/compare/compare-xy.hpp
    title: src/geometry/Z2/compare/compare-xy.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/constants/ccw-constants.hpp
    title: src/geometry/Z2/constants/ccw-constants.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/normalize/line-normalize.hpp
    title: src/geometry/Z2/normalize/line-normalize.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/ccw.hpp
    title: src/geometry/Z2/operation/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/cross-product.hpp
    title: src/geometry/Z2/operation/cross-product.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/inner-product.hpp
    title: src/geometry/Z2/operation/inner-product.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/square.hpp
    title: $x^2 (x \in \mathbb{Z})$
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/utility/next-idx.hpp
    title: src/geometry/Z2/utility/next-idx.hpp
  - icon: ':heavy_check_mark:'
    path: src/sequence/compression.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/4011.test.cpp
    title: test/aoj/4011.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/segment-function/counterbalance-segments.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/geometry/Z2/class/segment.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/class/point.hpp\"\n\n#line 2 \"src/geometry/Z2/class/vector.hpp\"\
    \n\n#include <vector>\n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  class\
    \ Vector {\n\n    Z x_, y_;\n\n   public:\n    Vector(): x_(0), y_(0) {}\n   \
    \ Vector(Z x, Z y): x_(x), y_(y) {}\n\n    Z x() const {\n      return x_;\n \
    \   }\n\n    Z y() const {\n      return y_;\n    }\n\n    bool operator==(const\
    \ Vector &v) const {\n      return x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool\
    \ operator!=(const Vector &v) const {\n      return x_ != v.x_ or y_ != v.y_;\n\
    \    }\n\n    Vector &operator+=(const Vector &v) {\n      x_ += v.x_;\n     \
    \ y_ += v.y_;\n      return *this;\n    }\n    Vector &operator-=(const Vector\
    \ &v) {\n      x_ -= v.x_;\n      y_ -= v.y_;\n      return *this;\n    }\n\n\
    \    Vector operator+(const Vector &v) const {\n      return Vector(*this) +=\
    \ v;\n    }\n    Vector operator-(const Vector &v) const {\n      return Vector(*this)\
    \ -= v;\n    }\n\n    Vector operator+() const {\n      return *this;\n    }\n\
    \    Vector operator-() const {\n      return Vector() - *this;\n    }\n  };\n\
    \n  template < typename Z >\n  using Vectors = std::vector< Vector< Z > >;\n\n\
    } // namespace luz::Z2\n#line 4 \"src/geometry/Z2/class/point.hpp\"\n\n#line 6\
    \ \"src/geometry/Z2/class/point.hpp\"\n\nnamespace luz::Z2 {\n\n  template < typename\
    \ Z >\n  using Point = Vector< Z >;\n\n  template < typename Z >\n  using Points\
    \ = std::vector< Point< Z > >;\n\n} // namespace luz::Z2\n#line 4 \"src/geometry/Z2/class/segment.hpp\"\
    \n\n#include <cassert>\n#line 7 \"src/geometry/Z2/class/segment.hpp\"\n\nnamespace\
    \ luz::Z2 {\n\n  template < typename Z >\n  class Segment {\n    Point< Z > p0_,\
    \ p1_;\n\n   public:\n    Segment() = default;\n\n    Segment(Point< Z > p0, Point<\
    \ Z > p1): p0_(p0), p1_(p1) {\n      assert(p0 != p1);\n    }\n\n    Point< Z\
    \ > p0() const {\n      return p0_;\n    }\n\n    Point< Z > p1() const {\n  \
    \    return p1_;\n    }\n  };\n\n  template < typename Z >\n  using Segments =\
    \ std::vector< Segment< Z > >;\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/compare/compare-xy.hpp\"\
    \n\n#line 4 \"src/geometry/Z2/compare/compare-xy.hpp\"\n\nnamespace luz::Z2 {\n\
    \n  template < typename Z >\n  class CompareXY {\n   public:\n    bool operator()(const\
    \ Vector< Z > &v0,\n                    const Vector< Z > &v1) const noexcept\
    \ {\n      if (v0.x() != v1.x()) return v0.x() < v1.x();\n      return v0.y()\
    \ < v1.y();\n    }\n  };\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/normalize/line-normalize.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/class/line.hpp\"\n\n#line 4 \"src/geometry/Z2/class/line.hpp\"\
    \n\n#line 7 \"src/geometry/Z2/class/line.hpp\"\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  class Line {\n    Point< Z > p0_, p1_;\n\n   public:\n   \
    \ Line() = default;\n\n    Line(Point< Z > p0, Point< Z > p1): p0_(p0), p1_(p1)\
    \ {\n      assert(p0 != p1);\n    }\n\n    Point< Z > p0() const {\n      return\
    \ p0_;\n    }\n\n    Point< Z > p1() const {\n      return p1_;\n    }\n  };\n\
    \n  template < typename Z >\n  using Lines = std::vector< Line< Z > >;\n\n} //\
    \ namespace luz::Z2\n#line 4 \"src/geometry/Z2/normalize/line-normalize.hpp\"\n\
    \n#line 6 \"src/geometry/Z2/normalize/line-normalize.hpp\"\n#include <numeric>\n\
    #include <tuple>\n#include <type_traits>\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  std::tuple< Z, Z, Z > normalize_l(const Line< Z > &l) {\n\
    \    static_assert(std::is_signed< Z >::value == true);\n    Z a = l.p1().y()\
    \ - l.p0().y();\n    Z b = l.p0().x() - l.p1().x();\n    {\n      Z g = std::gcd(a,\
    \ b);\n      a /= g;\n      b /= g;\n    }\n    Z c = a * l.p0().x() + b * l.p0().y();\n\
    \n    std::tuple< Z, Z, Z > p(+a, +b, +c), m(-a, -b, -c);\n    return std::max(p,\
    \ m);\n  }\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/operation/ccw.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/constants/ccw-constants.hpp\"\n\nnamespace luz::Z2::constants::ccw\
    \ {\n\n  constexpr i32 COUNTER_CLOCKWISE = +1;\n  constexpr i32 CLOCKWISE    \
    \     = -1;\n  constexpr i32 ONLINE_BACK       = +2; // c-a-b\n  constexpr i32\
    \ ONLINE_FRONT      = -2; // a-b-c\n  constexpr i32 ON_SEGMENT        = 0;  //\
    \ a-c-b\n\n} // namespace luz::Z2::constants::ccw\n#line 2 \"src/geometry/Z2/operation/cross-product.hpp\"\
    \n\n#line 4 \"src/geometry/Z2/operation/cross-product.hpp\"\n\nnamespace luz::Z2\
    \ {\n\n  template < typename Z >\n  Z cross_product(const Vector< Z > &a, const\
    \ Vector< Z > &b) {\n    return a.x() * b.y() - a.y() * b.x();\n  }\n\n} // namespace\
    \ luz::Z2\n#line 2 \"src/geometry/Z2/operation/inner-product.hpp\"\n\n#line 4\
    \ \"src/geometry/Z2/operation/inner-product.hpp\"\n\nnamespace luz::Z2 {\n\n \
    \ template < typename Z >\n  Z inner_product(const Vector< Z > &a, const Vector<\
    \ Z > &b) {\n    return a.x() * b.x() + a.y() * b.y();\n  }\n\n} // namespace\
    \ luz::Z2\n#line 2 \"src/geometry/Z2/operation/square-norm.hpp\"\n\n#line 2 \"\
    src/geometry/Z2/operation/square.hpp\"\n\nnamespace luz::Z2 {\n\n  template <\
    \ typename Z >\n  Z square(const Z x) {\n    return x * x;\n  }\n\n} // namespace\
    \ luz::Z2\n#line 5 \"src/geometry/Z2/operation/square-norm.hpp\"\n\nnamespace\
    \ luz::Z2 {\n\n  template < typename Z >\n  Z square_norm(Vector< Z > v) {\n \
    \   return square(v.x()) + square(v.y());\n  }\n\n} // namespace luz::Z2\n#line\
    \ 9 \"src/geometry/Z2/operation/ccw.hpp\"\n\nnamespace luz::Z2::impl_ccw {\n\n\
    \  using namespace constants::ccw;\n\n  template < typename Z >\n  i32 ccw(const\
    \ Vector< Z > &a, Vector< Z > b, Vector< Z > c) {\n    b -= a;\n    c -= a;\n\n\
    \    Z cp = cross_product(b, c);\n    if (cp > 0) return COUNTER_CLOCKWISE;\n\
    \    if (cp < 0) return CLOCKWISE;\n    if (inner_product(b, c) < 0) return ONLINE_BACK;\n\
    \    if (square_norm(b) < square_norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    \  }\n\n} // namespace luz::Z2::impl_ccw\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  i32 ccw(const Vector< Z > &a, const Vector< Z > &b,\n    \
    \      const Vector< Z > &c) {\n    return impl_ccw::ccw(a, b, c);\n  }\n\n} //\
    \ namespace luz::Z2\n#line 2 \"src/geometry/Z2/utility/next-idx.hpp\"\n\n#line\
    \ 4 \"src/geometry/Z2/utility/next-idx.hpp\"\n\nnamespace luz::Z2 {\n\n  inline\
    \ usize next_idx(usize idx, usize size) {\n    return idx + 1 == size ? 0 : idx\
    \ + 1;\n  }\n\n} // namespace luz::Z2\n#line 2 \"src/sequence/compression.hpp\"\
    \n\n#line 5 \"src/sequence/compression.hpp\"\n\n#line 8 \"src/sequence/compression.hpp\"\
    \n#include <functional>\n#line 10 \"src/sequence/compression.hpp\"\n\nnamespace\
    \ luz {\n\n  template < class T, class Compare = std::less< T > >\n  class Compressor\
    \ {\n    std::vector< T > vs_;\n    std::vector< T > zip_;\n    std::vector< usize\
    \ > ziped_vs_;\n\n   public:\n    explicit Compressor(std::vector< T > vs)\n \
    \       : vs_(vs),\n          zip_(vs),\n          ziped_vs_(vs.size()) {\n  \
    \    std::sort(zip_.begin(), zip_.end(), Compare());\n      zip_.erase(std::unique(zip_.begin(),\
    \ zip_.end()), zip_.end());\n      for (usize i: rep(0, vs.size())) {\n      \
    \  ziped_vs_[i] = compress(vs[i]);\n      }\n    }\n\n    std::vector< usize >\
    \ compressed_vector() const {\n      return ziped_vs_;\n    }\n\n    usize compress(T\
    \ v) const {\n      auto iter = std::lower_bound(zip_.begin(), zip_.end(), v);\n\
    \      assert(*iter == v);\n      return iter - zip_.begin();\n    }\n\n    T\
    \ expand(usize i) const {\n      assert(i < zip_.size());\n      return zip_[i];\n\
    \    }\n  };\n\n} // namespace luz\n#line 11 \"src/geometry/Z2/segment-function/counterbalance-segments.hpp\"\
    \n\n#include <cmath>\n#line 14 \"src/geometry/Z2/segment-function/counterbalance-segments.hpp\"\
    \n#include <utility>\n#line 16 \"src/geometry/Z2/segment-function/counterbalance-segments.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Segments< Z > counterbalance_segments(\n\
    \      const Segments< Z > &segments) {\n    usize n = segments.size();\n\n  \
    \  std::vector< std::tuple< Z, Z, Z > > normalized_lines(n);\n    for (usize i:\
    \ rep(0, n)) {\n      normalized_lines[i] =\n          normalize_l(Line(segments[i].p0(),\
    \ segments[i].p1()));\n    }\n\n    Compressor compressor(normalized_lines);\n\
    \    std::vector< usize > line_idxs = compressor.compressed_vector();\n    usize\
    \ line_count =\n        (*std::max_element(line_idxs.begin(), line_idxs.end()))\
    \ + 1;\n\n    using event_type = std::pair< Point< Z >, i32 >;\n    std::vector<\
    \ std::vector< event_type > > events_each_line(\n        line_count);\n    for\
    \ (usize i: rep(0, n)) {\n      usize l_idx = line_idxs[i];\n      events_each_line[l_idx].emplace_back(segments[i].p0(),\
    \ +1);\n      events_each_line[l_idx].emplace_back(segments[i].p1(), -1);\n  \
    \  }\n\n    auto cmp = [](const event_type &e0, const event_type &e1) {\n    \
    \  CompareXY< Z > comp;\n      if (e0.first != e1.first) return comp(e0.first,\
    \ e1.first);\n      return e0.second < e1.second;\n    };\n\n    Segments< Z >\
    \ result;\n    for (auto &events: events_each_line) {\n      std::sort(events.begin(),\
    \ events.end(), cmp);\n\n      for (usize i: rep(1, events.size())) {\n      \
    \  i32 prev = events[i - 1].second;\n        events[i].second += prev;\n     \
    \   if (events[i - 1].first == events[i].first) continue;\n        if (std::abs(prev)\
    \ != 1) continue;\n\n        Point< Z > from = events[i - 1].first;\n        Point<\
    \ Z > to   = events[i].first;\n        if (prev == -1) std::swap(from, to);\n\
    \        Segment< Z > seg(from, to);\n\n        if (not result.empty()) {\n  \
    \        Segment< Z > prev_seg = result.back();\n          Vector< Z > a = prev_seg.p0(),\
    \ b = prev_seg.p1();\n          Vector< Z > c = seg.p0(), d = seg.p1();\n    \
    \      if (b == c and std::abs(ccw(a, c, d)) != 1) {\n            seg = Segment(a,\
    \ d);\n            result.pop_back();\n          }\n          if (a == d and std::abs(ccw(c,\
    \ a, b)) != 1) {\n            seg = Segment(c, b);\n            result.pop_back();\n\
    \          }\n        }\n\n        result.emplace_back(seg);\n      }\n    }\n\
    \n    return result;\n  }\n} // namespace luz::Z2\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n#include \"src/geometry/Z2/class/segment.hpp\"\
    \n#include \"src/geometry/Z2/compare/compare-xy.hpp\"\n#include \"src/geometry/Z2/normalize/line-normalize.hpp\"\
    \n#include \"src/geometry/Z2/operation/ccw.hpp\"\n#include \"src/geometry/Z2/utility/next-idx.hpp\"\
    \n#include \"src/sequence/compression.hpp\"\n\n#include <cmath>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace luz::Z2 {\n\n  template < typename\
    \ Z >\n  Segments< Z > counterbalance_segments(\n      const Segments< Z > &segments)\
    \ {\n    usize n = segments.size();\n\n    std::vector< std::tuple< Z, Z, Z >\
    \ > normalized_lines(n);\n    for (usize i: rep(0, n)) {\n      normalized_lines[i]\
    \ =\n          normalize_l(Line(segments[i].p0(), segments[i].p1()));\n    }\n\
    \n    Compressor compressor(normalized_lines);\n    std::vector< usize > line_idxs\
    \ = compressor.compressed_vector();\n    usize line_count =\n        (*std::max_element(line_idxs.begin(),\
    \ line_idxs.end())) + 1;\n\n    using event_type = std::pair< Point< Z >, i32\
    \ >;\n    std::vector< std::vector< event_type > > events_each_line(\n       \
    \ line_count);\n    for (usize i: rep(0, n)) {\n      usize l_idx = line_idxs[i];\n\
    \      events_each_line[l_idx].emplace_back(segments[i].p0(), +1);\n      events_each_line[l_idx].emplace_back(segments[i].p1(),\
    \ -1);\n    }\n\n    auto cmp = [](const event_type &e0, const event_type &e1)\
    \ {\n      CompareXY< Z > comp;\n      if (e0.first != e1.first) return comp(e0.first,\
    \ e1.first);\n      return e0.second < e1.second;\n    };\n\n    Segments< Z >\
    \ result;\n    for (auto &events: events_each_line) {\n      std::sort(events.begin(),\
    \ events.end(), cmp);\n\n      for (usize i: rep(1, events.size())) {\n      \
    \  i32 prev = events[i - 1].second;\n        events[i].second += prev;\n     \
    \   if (events[i - 1].first == events[i].first) continue;\n        if (std::abs(prev)\
    \ != 1) continue;\n\n        Point< Z > from = events[i - 1].first;\n        Point<\
    \ Z > to   = events[i].first;\n        if (prev == -1) std::swap(from, to);\n\
    \        Segment< Z > seg(from, to);\n\n        if (not result.empty()) {\n  \
    \        Segment< Z > prev_seg = result.back();\n          Vector< Z > a = prev_seg.p0(),\
    \ b = prev_seg.p1();\n          Vector< Z > c = seg.p0(), d = seg.p1();\n    \
    \      if (b == c and std::abs(ccw(a, c, d)) != 1) {\n            seg = Segment(a,\
    \ d);\n            result.pop_back();\n          }\n          if (a == d and std::abs(ccw(c,\
    \ a, b)) != 1) {\n            seg = Segment(c, b);\n            result.pop_back();\n\
    \          }\n        }\n\n        result.emplace_back(seg);\n      }\n    }\n\
    \n    return result;\n  }\n} // namespace luz::Z2\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/geometry/Z2/class/segment.hpp
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/class/vector.hpp
  - src/geometry/Z2/compare/compare-xy.hpp
  - src/geometry/Z2/normalize/line-normalize.hpp
  - src/geometry/Z2/class/line.hpp
  - src/geometry/Z2/operation/ccw.hpp
  - src/geometry/Z2/constants/ccw-constants.hpp
  - src/geometry/Z2/operation/cross-product.hpp
  - src/geometry/Z2/operation/inner-product.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  - src/geometry/Z2/operation/square.hpp
  - src/geometry/Z2/utility/next-idx.hpp
  - src/sequence/compression.hpp
  isVerificationFile: false
  path: src/geometry/Z2/segment-function/counterbalance-segments.hpp
  requiredBy: []
  timestamp: '2022-11-18 16:59:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/4011.test.cpp
documentation_of: src/geometry/Z2/segment-function/counterbalance-segments.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2/segment-function/counterbalance-segments.hpp
- /library/src/geometry/Z2/segment-function/counterbalance-segments.hpp.html
title: src/geometry/Z2/segment-function/counterbalance-segments.hpp
---
