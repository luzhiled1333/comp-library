#include "src/cpp-template/header/type-alias.hpp"

#include <array>

#include <iostream>

namespace luz::internal {

  template < usize r, usize c, class T >
  class InternalMatrix {
    static constexpr usize n = r * c;

   protected:
    std::array< T, r * c > as;

   public:
    InternalMatrix() : as() {}

    void debug() {
      for (usize i = 0; i < n; i++) {
        std::cerr << as[i] << " ";
      }
      std::cerr << std::endl;
    }

    T &at(const usize i, const usize j);
    const T &at(const usize i, const usize j) const;


    InternalMatrix< r, c, T > operator+() const;
    InternalMatrix< r, c, T > operator-() const;

    InternalMatrix< r, c, T > &operator+=(const InternalMatrix< r, c, T > &op);
    InternalMatrix< r, c, T > &operator-=(const InternalMatrix< r, c, T > &op);
    InternalMatrix< r, c, T > operator+(const InternalMatrix< r, c, T > &op) const;
    InternalMatrix< r, c, T > operator-(const InternalMatrix< r, c, T > &op) const;

    InternalMatrix< r, c, T > &operator*=(const T &scalar);
    InternalMatrix< r, c, T > &operator/=(const T &scalar);
    InternalMatrix< r, c, T > operator*(const T &scalar) const;
    InternalMatrix< r, c, T > operator/(const T &scalar) const;

    T norm() const;
  };

  template< usize r, usize c, class T >
  T &InternalMatrix< r, c, T >::at(const usize i, const usize j) {
    return as[i * c + j];
  }
  template< usize r, usize c, class T >
  const T &InternalMatrix< r, c, T >::at(const usize i, const usize j) const {
    return as[i * c + j];
  }

} // namespace luz::internal

namespace luz {

  template < usize r, usize c, class T >
  class Matrix: public internal::InternalMatrix<r, c, T> {
   public:

    using internal::InternalMatrix<r, c, T>::InternalMatrix;
  };

  template< usize r, class T >
  class Matrix<r, 1, T>: public internal::InternalMatrix<r, 1, T> {
   public:

    using internal::InternalMatrix<r, 1, T>::InternalMatrix;

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
  };

} // namespace luz
