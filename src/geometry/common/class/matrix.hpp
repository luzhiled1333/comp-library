#include "src/cpp-template/header/type-alias.hpp"

#include <array>

#include <iostream>

namespace luz {

  template < usize r, usize c, class T >
  class Matrix {
    static constexpr usize n = r * c;

    std::array< T, r * c > as;

   public:
    Matrix() : as() {}

    void debug() {
      for (usize i = 0; i < n; i++) {
        std::cerr << as[i] << " ";
      }
      std::cerr << std::endl;
    }

    T &at(const usize i, const usize j) {
      return as[i * c + j];
    }
    const T &at(const usize i, const usize j) const {
      return as[i * c + j];
    }

    Matrix< r, c, T > operator+() const;
    Matrix< r, c, T > operator-() const;

    Matrix< r, c, T > &operator+=(const Matrix< r, c, T > &op);
    Matrix< r, c, T > &operator-=(const Matrix< r, c, T > &op);
    Matrix< r, c, T > operator+(const Matrix< r, c, T > &op) const;
    Matrix< r, c, T > operator-(const Matrix< r, c, T > &op) const;

    Matrix< r, c, T > &operator*=(const T &scalar);
    Matrix< r, c, T > &operator/=(const T &scalar);
    Matrix< r, c, T > operator*(const T &scalar) const;
    Matrix< r, c, T > operator/(const T &scalar) const;

    T norm() const;

    const T &x() const {
      return as[0];
    }
    const T &y() const {
      return as[1];
    }
    const T &z() const {
      return as[2];
    }

    T &x() {
      return as[0];
    }
    T &y() {
      return as[1];
    }
    T &z() {
      return as[2];
    }
  };

} // namespace luz
