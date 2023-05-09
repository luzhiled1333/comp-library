#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <array>
#include <cassert>
#include <iostream>

namespace luz::internal {

  template < usize r, usize c, class T >
  class InternalMatrix {
    static constexpr usize n = r * c;

   protected:
    std::array< T, r * c > as;

   public:
    InternalMatrix(): as() {}

    T &at(const usize i, const usize j);
    const T &at(const usize i, const usize j) const;

    InternalMatrix< r, c, T > operator+() const;
    InternalMatrix< r, c, T > operator-() const;

    InternalMatrix< r, c, T > &operator+=(
        const InternalMatrix< r, c, T > &rhs);
    InternalMatrix< r, c, T > &operator-=(
        const InternalMatrix< r, c, T > &rhs);
    InternalMatrix< r, c, T > operator+(
        const InternalMatrix< r, c, T > &rhs) const;
    InternalMatrix< r, c, T > operator-(
        const InternalMatrix< r, c, T > &rhs) const;

    InternalMatrix< r, c, T > &operator*=(const T &scalar);
    InternalMatrix< r, c, T > &operator/=(const T &scalar);
    InternalMatrix< r, c, T > operator*(const T &scalar) const;
    InternalMatrix< r, c, T > operator/(const T &scalar) const;
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

} // namespace luz::internal

namespace luz {

  template < usize r, usize c, class T >
  class Matrix: public internal::InternalMatrix< r, c, T > {
   public:
    using internal::InternalMatrix< r, c, T >::InternalMatrix;
  };

  template < usize r, class T >
  class Matrix< r, 1, T >
      : public internal::InternalMatrix< r, 1, T > {
   public:
    using internal::InternalMatrix< r, 1, T >::InternalMatrix;

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
