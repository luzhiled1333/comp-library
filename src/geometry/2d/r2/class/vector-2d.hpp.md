---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':warning:'
    path: src/geometry/2d/common/class/vector-2d.hpp
    title: src/geometry/2d/common/class/vector-2d.hpp
  - icon: ':warning:'
    path: src/geometry/common/class/column-vector.hpp
    title: src/geometry/common/class/column-vector.hpp
  - icon: ':warning:'
    path: src/geometry/common/class/internal/matrix.hpp
    title: src/geometry/common/class/internal/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/2d/r2/class/vector-2d.hpp\"\n\n#line 2 \"src/geometry/2d/common/class/vector-2d.hpp\"\
    \n\n#line 2 \"src/geometry/common/class/column-vector.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 2 \"src/geometry/common/class/internal/matrix.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 4 \"src/cpp-template/header/rep.hpp\"\
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
    \ 5 \"src/geometry/common/class/internal/matrix.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz::geometry::common::internal {\n\n  template\
    \ < usize r, usize c, class T >\n  class Mat {\n    static constexpr usize n =\
    \ r * c;\n\n   protected:\n    std::vector< T > as;\n\n   public:\n    using value_type\
    \ = T;\n\n    Mat(): as(n) {}\n\n    T &at(const usize, const usize);\n    const\
    \ T &at(const usize, const usize) const;\n\n    Mat operator+() const;\n    Mat\
    \ operator-() const;\n\n    Mat &operator+=(const Mat &);\n    Mat &operator-=(const\
    \ Mat &);\n    Mat operator+(const Mat &) const;\n    Mat operator-(const Mat\
    \ &) const;\n\n    Mat &operator*=(const T &);\n    Mat &operator/=(const T &);\n\
    \    Mat operator*(const T &) const;\n    Mat operator/(const T &) const;\n\n\
    \    bool operator==(const Mat &) const;\n    bool operator!=(const Mat &) const;\n\
    \n    // Implement (scalar) * (Matrix)\n    friend Mat operator*(const T &scalar,\
    \ const Mat< r, c, T > &mat) {\n      return Mat< r, c, T >(mat) *= scalar;\n\
    \    }\n  };\n\n  template < usize r, usize c, class T >\n  T &Mat< r, c, T >::at(const\
    \ usize i, const usize j) {\n    assert(i < r and j < c);\n    return as[i * c\
    \ + j];\n  }\n  template < usize r, usize c, class T >\n  const T &Mat< r, c,\
    \ T >::at(const usize i, const usize j) const {\n    assert(i < r and j < c);\n\
    \    return as[i * c + j];\n  }\n\n  template < usize r, usize c, class T >\n\
    \  Mat< r, c, T > Mat< r, c, T >::operator+() const {\n    return *this;\n  }\n\
    \  template < usize r, usize c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator-()\
    \ const {\n    return Mat() - *this;\n  }\n\n  template < usize r, usize c, class\
    \ T >\n  Mat< r, c, T > &Mat< r, c, T >::operator+=(\n      const Mat< r, c, T\
    \ > &rhs) {\n    for (usize i: rep(0, n)) as[i] += rhs.as[i];\n    return *this;\n\
    \  }\n  template < usize r, usize c, class T >\n  Mat< r, c, T > &Mat< r, c, T\
    \ >::operator-=(\n      const Mat< r, c, T > &rhs) {\n    for (usize i: rep(0,\
    \ n)) as[i] -= rhs.as[i];\n    return *this;\n  }\n  template < usize r, usize\
    \ c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator+(\n      const Mat<\
    \ r, c, T > &rhs) const {\n    return Mat(*this) += rhs;\n  }\n  template < usize\
    \ r, usize c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator-(\n      const\
    \ Mat< r, c, T > &rhs) const {\n    return Mat(*this) -= rhs;\n  }\n\n  template\
    \ < usize r, usize c, class T >\n  Mat< r, c, T > &Mat< r, c, T >::operator*=(const\
    \ T &scalar) {\n    for (T &a: as) a *= scalar;\n    return *this;\n  }\n  template\
    \ < usize r, usize c, class T >\n  Mat< r, c, T > &Mat< r, c, T >::operator/=(const\
    \ T &scalar) {\n    for (T &a: as) a /= scalar;\n    return *this;\n  }\n  template\
    \ < usize r, usize c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator*(const\
    \ T &scalar) const {\n    return Mat(*this) *= scalar;\n  }\n  template < usize\
    \ r, usize c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator/(const T &scalar)\
    \ const {\n    return Mat(*this) /= scalar;\n  }\n\n  template < usize r, usize\
    \ c, class T >\n  bool Mat< r, c, T >::operator==(const Mat &rhs) const {\n  \
    \  return as == rhs.as;\n  }\n  template < usize r, usize c, class T >\n  bool\
    \ Mat< r, c, T >::operator!=(const Mat &rhs) const {\n    return as != rhs.as;\n\
    \  }\n\n} // namespace luz::geometry::common::internal\n#line 5 \"src/geometry/common/class/column-vector.hpp\"\
    \n\nnamespace luz::geometry::common {\n\n  template < usize d, class T >\n  class\
    \ ColumnVector: public internal::Mat< d, 1, T > {\n    using internal_mat = internal::Mat<\
    \ d, 1, T >;\n\n   public:\n    using internal::Mat< d, 1, T >::Mat;\n\n    ColumnVector(const\
    \ internal_mat &mat): internal_mat::Mat(mat) {}\n\n    T norm() const {\n    \
    \  T result{};\n      for (T a: this->as) result += a * a;\n      return result;\n\
    \    }\n  };\n\n} // namespace luz::geometry::common\n#line 4 \"src/geometry/2d/common/class/vector-2d.hpp\"\
    \n\nnamespace luz::geometry::common {\n\n  template < class T >\n  class Vector2d:\
    \ public ColumnVector< 2, T > {\n    using c_vec = ColumnVector< 2, T >;\n\n \
    \  public:\n    Vector2d(const c_vec &vec): c_vec::ColumnVector(vec) {}\n    Vector2d(const\
    \ T x_, const T y_) {\n      x() = x_;\n      y() = y_;\n    }\n\n    const T\
    \ &x() const {\n      return this->as[0];\n    }\n    const T &y() const {\n \
    \     return this->as[1];\n    }\n\n    T &x() {\n      return this->as[0];\n\
    \    }\n    T &y() {\n      return this->as[1];\n    }\n  };\n\n} // namespace\
    \ luz::geometry::common\n#line 4 \"src/geometry/2d/r2/class/vector-2d.hpp\"\n\n\
    #include <type_traits>\n\nnamespace luz::geometry::r2 {\n\n  template < class\
    \ R >\n  class Vector2d: public luz::geometry::common::Vector2d< R > {\n    static_assert(std::is_floating_point<\
    \ R >::value);\n\n   public:\n    Vector2d() = default;\n\n    bool operator==(const\
    \ Vector2d &rhs) const {\n      // TODO\n      return false;\n    }\n  };\n\n\
    } // namespace luz::geometry::r2\n"
  code: "#pragma once\n\n#include \"src/geometry/2d/common/class/vector-2d.hpp\"\n\
    \n#include <type_traits>\n\nnamespace luz::geometry::r2 {\n\n  template < class\
    \ R >\n  class Vector2d: public luz::geometry::common::Vector2d< R > {\n    static_assert(std::is_floating_point<\
    \ R >::value);\n\n   public:\n    Vector2d() = default;\n\n    bool operator==(const\
    \ Vector2d &rhs) const {\n      // TODO\n      return false;\n    }\n  };\n\n\
    } // namespace luz::geometry::r2\n"
  dependsOn:
  - src/geometry/2d/common/class/vector-2d.hpp
  - src/geometry/common/class/column-vector.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/geometry/common/class/internal/matrix.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: false
  path: src/geometry/2d/r2/class/vector-2d.hpp
  requiredBy: []
  timestamp: '2023-05-23 15:46:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/2d/r2/class/vector-2d.hpp
layout: document
redirect_from:
- /library/src/geometry/2d/r2/class/vector-2d.hpp
- /library/src/geometry/2d/r2/class/vector-2d.hpp.html
title: src/geometry/2d/r2/class/vector-2d.hpp
---