---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/2d/common/class/vector-2d.hpp
    title: src/geometry/2d/common/class/vector-2d.hpp
  - icon: ':warning:'
    path: src/geometry/2d/r2/class/vector-2d.hpp
    title: src/geometry/2d/r2/class/vector-2d.hpp
  - icon: ':warning:'
    path: src/geometry/2d/z2/class/vector-2d.hpp
    title: src/geometry/2d/z2/class/vector-2d.hpp
  - icon: ':warning:'
    path: src/geometry/common/class/column-vector.hpp
    title: src/geometry/common/class/column-vector.hpp
  - icon: ':warning:'
    path: src/geometry/common/class/matrix.hpp
    title: "\u884C\u5217"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/common/class/internal/matrix.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \  }\n\n} // namespace luz::geometry::common::internal\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz::geometry::common::internal {\n\n  template < usize r, usize c,\
    \ class T >\n  class Mat {\n    static constexpr usize n = r * c;\n\n   protected:\n\
    \    std::vector< T > as;\n\n   public:\n    using value_type = T;\n\n    Mat():\
    \ as(n) {}\n\n    T &at(const usize, const usize);\n    const T &at(const usize,\
    \ const usize) const;\n\n    Mat operator+() const;\n    Mat operator-() const;\n\
    \n    Mat &operator+=(const Mat &);\n    Mat &operator-=(const Mat &);\n    Mat\
    \ operator+(const Mat &) const;\n    Mat operator-(const Mat &) const;\n\n   \
    \ Mat &operator*=(const T &);\n    Mat &operator/=(const T &);\n    Mat operator*(const\
    \ T &) const;\n    Mat operator/(const T &) const;\n\n    bool operator==(const\
    \ Mat &) const;\n    bool operator!=(const Mat &) const;\n\n    // Implement (scalar)\
    \ * (Matrix)\n    friend Mat operator*(const T &scalar, const Mat< r, c, T > &mat)\
    \ {\n      return Mat< r, c, T >(mat) *= scalar;\n    }\n  };\n\n  template <\
    \ usize r, usize c, class T >\n  T &Mat< r, c, T >::at(const usize i, const usize\
    \ j) {\n    assert(i < r and j < c);\n    return as[i * c + j];\n  }\n  template\
    \ < usize r, usize c, class T >\n  const T &Mat< r, c, T >::at(const usize i,\
    \ const usize j) const {\n    assert(i < r and j < c);\n    return as[i * c +\
    \ j];\n  }\n\n  template < usize r, usize c, class T >\n  Mat< r, c, T > Mat<\
    \ r, c, T >::operator+() const {\n    return *this;\n  }\n  template < usize r,\
    \ usize c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator-() const {\n \
    \   return Mat() - *this;\n  }\n\n  template < usize r, usize c, class T >\n \
    \ Mat< r, c, T > &Mat< r, c, T >::operator+=(\n      const Mat< r, c, T > &rhs)\
    \ {\n    for (usize i: rep(0, n)) as[i] += rhs.as[i];\n    return *this;\n  }\n\
    \  template < usize r, usize c, class T >\n  Mat< r, c, T > &Mat< r, c, T >::operator-=(\n\
    \      const Mat< r, c, T > &rhs) {\n    for (usize i: rep(0, n)) as[i] -= rhs.as[i];\n\
    \    return *this;\n  }\n  template < usize r, usize c, class T >\n  Mat< r, c,\
    \ T > Mat< r, c, T >::operator+(\n      const Mat< r, c, T > &rhs) const {\n \
    \   return Mat(*this) += rhs;\n  }\n  template < usize r, usize c, class T >\n\
    \  Mat< r, c, T > Mat< r, c, T >::operator-(\n      const Mat< r, c, T > &rhs)\
    \ const {\n    return Mat(*this) -= rhs;\n  }\n\n  template < usize r, usize c,\
    \ class T >\n  Mat< r, c, T > &Mat< r, c, T >::operator*=(const T &scalar) {\n\
    \    for (T &a: as) a *= scalar;\n    return *this;\n  }\n  template < usize r,\
    \ usize c, class T >\n  Mat< r, c, T > &Mat< r, c, T >::operator/=(const T &scalar)\
    \ {\n    for (T &a: as) a /= scalar;\n    return *this;\n  }\n  template < usize\
    \ r, usize c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator*(const T &scalar)\
    \ const {\n    return Mat(*this) *= scalar;\n  }\n  template < usize r, usize\
    \ c, class T >\n  Mat< r, c, T > Mat< r, c, T >::operator/(const T &scalar) const\
    \ {\n    return Mat(*this) /= scalar;\n  }\n\n  template < usize r, usize c, class\
    \ T >\n  bool Mat< r, c, T >::operator==(const Mat &rhs) const {\n    return as\
    \ == rhs.as;\n  }\n  template < usize r, usize c, class T >\n  bool Mat< r, c,\
    \ T >::operator!=(const Mat &rhs) const {\n    return as != rhs.as;\n  }\n\n}\
    \ // namespace luz::geometry::common::internal\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/geometry/common/class/internal/matrix.hpp
  requiredBy:
  - src/geometry/common/class/column-vector.hpp
  - src/geometry/common/class/matrix.hpp
  - src/geometry/2d/common/class/vector-2d.hpp
  - src/geometry/2d/r2/class/vector-2d.hpp
  - src/geometry/2d/z2/class/vector-2d.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/common/class/internal/matrix.hpp
layout: document
redirect_from:
- /library/src/geometry/common/class/internal/matrix.hpp
- /library/src/geometry/common/class/internal/matrix.hpp.html
title: src/geometry/common/class/internal/matrix.hpp
---
