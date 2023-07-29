#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <cassert>
#include <vector>

namespace luz::geometry::common::internal {

  template < usize r, usize c, class T >
  class Mat {
    static constexpr usize n = r * c;

   protected:
    std::vector< T > as;

   public:
    using value_type = T;

    Mat(): as(n) {}

    T &at(const usize, const usize);
    const T &at(const usize, const usize) const;

    Mat operator+() const;
    Mat operator-() const;

    Mat &operator+=(const Mat &);
    Mat &operator-=(const Mat &);
    Mat operator+(const Mat &) const;
    Mat operator-(const Mat &) const;

    Mat &operator*=(const T &);
    Mat &operator/=(const T &);
    Mat operator*(const T &) const;
    Mat operator/(const T &) const;

    bool operator==(const Mat &) const;
    bool operator!=(const Mat &) const;

    // Implement (scalar) * (Matrix)
    friend Mat operator*(const T &scalar, const Mat< r, c, T > &mat) {
      return Mat< r, c, T >(mat) *= scalar;
    }
  };

  template < usize r, usize c, class T >
  T &Mat< r, c, T >::at(const usize i, const usize j) {
    assert(i < r and j < c);
    return as[i * c + j];
  }
  template < usize r, usize c, class T >
  const T &Mat< r, c, T >::at(const usize i, const usize j) const {
    assert(i < r and j < c);
    return as[i * c + j];
  }

  template < usize r, usize c, class T >
  Mat< r, c, T > Mat< r, c, T >::operator+() const {
    return *this;
  }
  template < usize r, usize c, class T >
  Mat< r, c, T > Mat< r, c, T >::operator-() const {
    return Mat() - *this;
  }

  template < usize r, usize c, class T >
  Mat< r, c, T > &Mat< r, c, T >::operator+=(
      const Mat< r, c, T > &rhs) {
    for (usize i: rep(0, n)) as[i] += rhs.as[i];
    return *this;
  }
  template < usize r, usize c, class T >
  Mat< r, c, T > &Mat< r, c, T >::operator-=(
      const Mat< r, c, T > &rhs) {
    for (usize i: rep(0, n)) as[i] -= rhs.as[i];
    return *this;
  }
  template < usize r, usize c, class T >
  Mat< r, c, T > Mat< r, c, T >::operator+(
      const Mat< r, c, T > &rhs) const {
    return Mat(*this) += rhs;
  }
  template < usize r, usize c, class T >
  Mat< r, c, T > Mat< r, c, T >::operator-(
      const Mat< r, c, T > &rhs) const {
    return Mat(*this) -= rhs;
  }

  template < usize r, usize c, class T >
  Mat< r, c, T > &Mat< r, c, T >::operator*=(const T &scalar) {
    for (T &a: as) a *= scalar;
    return *this;
  }
  template < usize r, usize c, class T >
  Mat< r, c, T > &Mat< r, c, T >::operator/=(const T &scalar) {
    for (T &a: as) a /= scalar;
    return *this;
  }
  template < usize r, usize c, class T >
  Mat< r, c, T > Mat< r, c, T >::operator*(const T &scalar) const {
    return Mat(*this) *= scalar;
  }
  template < usize r, usize c, class T >
  Mat< r, c, T > Mat< r, c, T >::operator/(const T &scalar) const {
    return Mat(*this) /= scalar;
  }

  template < usize r, usize c, class T >
  bool Mat< r, c, T >::operator==(const Mat &rhs) const {
    return as == rhs.as;
  }
  template < usize r, usize c, class T >
  bool Mat< r, c, T >::operator!=(const Mat &rhs) const {
    return as != rhs.as;
  }

} // namespace luz::geometry::common::internal
