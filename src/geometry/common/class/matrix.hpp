#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <iostream>
#include <vector>

namespace luz::internal {

  template < usize r, usize c, class T >
  class InternalMatrix {
    static constexpr usize n = r * c;

   protected:
    std::vector< T > as;

   public:
    using value_type = T;

    InternalMatrix(): as(r * c) {}

    T &at(const usize, const usize);
    const T &at(const usize, const usize) const;

    InternalMatrix operator+() const;
    InternalMatrix operator-() const;

    InternalMatrix &operator+=(const InternalMatrix &);
    InternalMatrix &operator-=(const InternalMatrix &);
    InternalMatrix operator+(const InternalMatrix &) const;
    InternalMatrix operator-(const InternalMatrix &) const;

    InternalMatrix &operator*=(const T &);
    InternalMatrix &operator/=(const T &);
    InternalMatrix operator*(const T &) const;
    InternalMatrix operator/(const T &) const;

    bool operator==(const InternalMatrix &) const;
    bool operator!=(const InternalMatrix &) const;

    // Implement (scalar) * (Matrix)
    friend InternalMatrix operator*(
        const T &scalar, const InternalMatrix< r, c, T > &mat) {
      return InternalMatrix< r, c, T >(mat) *= scalar;
    }
  };

  template < usize r, usize c, class T >
  T &InternalMatrix< r, c, T >::at(const usize i, const usize j) {
    assert(i < r and j < c);
    return as[i * c + j];
  }
  template < usize r, usize c, class T >
  const T &InternalMatrix< r, c, T >::at(const usize i,
                                         const usize j) const {
    assert(i < r and j < c);
    return as[i * c + j];
  }

  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > InternalMatrix< r, c, T >::operator+()
      const {
    return *this;
  }
  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > InternalMatrix< r, c, T >::operator-()
      const {
    return InternalMatrix() - *this;
  }

  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > &InternalMatrix< r, c, T >::operator+=(
      const InternalMatrix< r, c, T > &rhs) {
    for (usize i: rep(0, n)) as[i] += rhs.as[i];
    return *this;
  }
  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > &InternalMatrix< r, c, T >::operator-=(
      const InternalMatrix< r, c, T > &rhs) {
    for (usize i: rep(0, n)) as[i] -= rhs.as[i];
    return *this;
  }
  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > InternalMatrix< r, c, T >::operator+(
      const InternalMatrix< r, c, T > &rhs) const {
    return InternalMatrix(*this) += rhs;
  }
  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > InternalMatrix< r, c, T >::operator-(
      const InternalMatrix< r, c, T > &rhs) const {
    return InternalMatrix(*this) -= rhs;
  }

  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > &InternalMatrix< r, c, T >::operator*=(
      const T &scalar) {
    for (T &a: as) a *= scalar;
    return *this;
  }
  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > &InternalMatrix< r, c, T >::operator/=(
      const T &scalar) {
    for (T &a: as) a /= scalar;
    return *this;
  }
  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > InternalMatrix< r, c, T >::operator*(
      const T &scalar) const {
    return InternalMatrix(*this) *= scalar;
  }
  template < usize r, usize c, class T >
  InternalMatrix< r, c, T > InternalMatrix< r, c, T >::operator/(
      const T &scalar) const {
    return InternalMatrix(*this) /= scalar;
  }

  template < usize r, usize c, class T >
  bool InternalMatrix< r, c, T >::operator==(
      const InternalMatrix &rhs) const {
    return as == rhs.as;
  }
  template < usize r, usize c, class T >
  bool InternalMatrix< r, c, T >::operator!=(
      const InternalMatrix &rhs) const {
    return as != rhs.as;
  }

} // namespace luz::internal

namespace luz {

  template < usize r, usize c, class T >
  class Matrix: public internal::InternalMatrix< r, c, T > {
    using internal_mat = internal::InternalMatrix< r, c, T >;

   public:
    using internal_mat::InternalMatrix;

    Matrix(const internal_mat &mat) : internal_mat::InternalMatrix(mat) {}
  };

  template < usize d, class T >
  class Vector: public internal::InternalMatrix< d, 1, T > {
    using internal_mat = internal::InternalMatrix< d, 1, T >;

   public:
    using internal::InternalMatrix< d, 1, T >::InternalMatrix;

    Vector(const internal_mat &mat): internal_mat::InternalMatrix(mat) {}

    const T &x() const {
      return this->as[0];
    }
    const T &y() const {
      return this->as[1];
    }
    const T &z() const {
      return this->as[2];
    }

    T &x() {
      return this->as[0];
    }
    T &y() {
      return this->as[1];
    }
    T &z() {
      return this->as[2];
    }

    T norm() const {
      T result{};
      for (T a: this->as) result += a * a;
      return result;
    }
  };

} // namespace luz
